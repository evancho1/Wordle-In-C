#include "wordle_implementation.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

// see wordle_implementation.h
bool evaluate_guess(const char *secret, const char *guess, char *result) {
  assert(secret);
  assert(guess);
  assert(result);
 
  int guess_length = strlen(guess);
  assert(strlen(secret) == guess_length);
  
  const int ch_to_ascii = 32;
  int count[128] = {}; // # of ASCII characters
  for (int index = 0; index < guess_length; ++index) {
    count[*(secret + index)]++; 
  }

  for (int index = 0; index < guess_length; ++index) {
    if (secret[index] == guess[index]) {
      result[index] = guess[index] - ch_to_ascii; 
    } else if (count[*(guess + index)] != 0) {
      result[index] = guess[index];
    } else {
      result[index] = '-'; 
    }
  }
  return !strcmp(guess, secret);
}

// see wordle_implementation.h
void available_letters(char *guesses[], char *results[], int num_guesses,
                       char *alphabet) {
  assert(num_guesses >= 0);
  const char letter_to_ascii = 'a';
  const int guess_length = 5;

  for (int index = 0; index < 26; ++index) {
    alphabet[index] = index + letter_to_ascii; 
  } 

  for (int i = 0; i < num_guesses; i++) {
    for (int ch = 0; ch < guess_length; ++ch) {
      if ((results[i])[ch] == '-') {
        alphabet[(guesses[i])[ch] - letter_to_ascii] = '-';
      } else {
        alphabet[(guesses[i])[ch] - letter_to_ascii] = 
          toupper((guesses[i])[ch]); 
      }
    }
  }
}

// see wordle_implementation.h
bool valid_guess(char *guesses[], char *results[], int num_guesses,
                      const char *next_guess) {
  assert(num_guesses >= 0);
  int guess_len = 5;
  
  if (num_guesses != 0) {
    guess_len = strlen(guesses[0]);
    int next_guess_len = strlen(next_guess);
    assert(next_guess_len == guess_len);
  }
  
  // assert each guess is of proper length
  for (int i = 0; i < num_guesses; ++i) {
    assert(guesses[i]);
    int temp_guess_len = strlen(guesses[i]);
    assert(temp_guess_len == guess_len);
  }

  bool in_next = false;

  for (int i = 0; i < num_guesses; ++i) {
    for (int j = 0; j < guess_len; ++j) {
      in_next = false;
      if ((results[i])[j] >= 'A' && (results[i])[j] <= 'Z') {
        if (next_guess[j] != tolower((results[i])[j])) {
          return false; 
        }
      } else if ((results[i])[j] >= 'a' && (results[i])[j] <= 'z') {
        for (int k = 0; k < guess_len; ++k) {
          if ((results[i])[j] == next_guess[k]) {
            if (j == k) { 
              return false;
            }
            in_next = true; 
          }
        } 
        if (!in_next) {
          return false; 
        }
      } else {
        for (int k = 0; k < guess_len; ++k) {
          if ((guesses[i])[j] == next_guess[k]) {
            return false; 
          }
        }
      }
    }
  }
  return true;
}
