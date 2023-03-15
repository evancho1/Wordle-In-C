// This module contains the functions required to play Wordle in C

#include <stdbool.h>

/* 
all the guess and secret word characters must be lowercase
all result characters are: lowercase if the letter exists in secret, but in a different position
lowercase if the letter is in secret but in a different position
uppercase if the letter is in the right position
- if the letter is not in the secret word
*/

/*
evaluate_guess(secret, guess, result) returns whether or not secret is equal to guess and modifies result characters 
e.g. evaluate_guess("maybe", "beach", result) => false; result => "-ea--"
     evaluate_guess("maybe", "mayos", result) => false; result => "MAY--"
requires: result is sufficiently large [not asserted]
          strlen(secret) == strlen(guess)
effects: result will be modified
*/
bool evaluate_guess(const char *secret, const char *guess, char *result);

/*
available_letters(guesses, results, num_guesses, alphabet) determines the status of each alphabet letter in the secret word, based on results of existing guesses.
The result is stored in alphabet as an "alphabet string" (null terminated), where each character is:
  - if the letter is not in the secret word
  lowercase if the status of the letter is unknown
  uppercase if the letter is in the secret word
e.g. char alphabet[27]
     char *guesses[2] = { "beach", "mayos" };
     char *results[2] = { "-ea--", "MAY--" };
     available_letters(guesses, results, 2, alphabet);
     alphabet => "A--dEfg-ijklMn-pqr-tuvwxYz"
requires: first "num_guesses" elements in guesses and results are valid
          strings of the same length
          alphabet is sufficiently large
          num_guesses >= 0
effects: alphabet is modified
*/
void available_letters(char *guesses[], char *results[], int num_guesses,
                       char *alphabet);

/*
valid_guess(guesses, results, num_guesses, next_guess) evaluates ehether or not next_guess is a valid attempt, given existing guesses
  and the following requirements:
  A previously correctly positioned letter must be used in the same spot in next_guess
  A letter from the secret word that showed up in a wrong spot in guesses cannot be used in the same spot in next_guess.
  A letter from the secret word that showed up in a wrong spot in guesses should be used in next_guess.
  A letter that was previous identified as not part of the secret word cannot be used in next_guess.
e.g. char *guesses[1] = { "beach" };
     char *results[1] = { "-Ea--" }
     valid_guess(guesses, results, 1, "baker") => false
     valid_guess(guesses, results, 1, "heath") => true
     valid_guess(guesses, results, 1, "teams") => false
requires: first "num_guesses" elements in guesses and results are valid
          strings of the same length
          length of next_guess matches length of strings in guesses
          num_guesses >= 0
*/
bool valid_guess(char *guesses[], char *results[], int num_guesses,
                      const char *next_guess);
