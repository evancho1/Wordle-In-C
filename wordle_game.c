// This program allows you to play Wordle interactively in the C console 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle_implementation.h"

int main(void) {
  char guess1[100] = "";
  char guess2[100] = "";
  char guess3[100] = "";
  char guess4[100] = "";
  char guess5[100] = "";
  char guess6[100] = "";
  char result1[100] = "";
  char result2[100] = "";
  char result3[100] = "";
  char result4[100] = "";
  char result5[100] = "";
  char result6[100] = "";
  char *guesses[6] = {guess1, guess2, guess3, guess4, guess5, guess6};
  char *results[6] = {result1, result2, result3, result4, result5, result6};
  char alphabet[27] = "";
 
  char *secret_word = "mango";
  
  int num_guesses = 0;
  while (1) {
    char *current_word = guesses[num_guesses];
    printf("-----------------------------------------------\n");
    for (int i = 0; i < num_guesses; ++i) {
      printf("  [%d] %s => %s\n", i + 1, guesses[i], results[i]);
    }
    available_letters(guesses, results, num_guesses, alphabet);
    printf("  %s\n", alphabet);
    printf("Enter guess #%d:\n", num_guesses + 1);
    
    result = scanf("%s", current_word);
    if (result == EOF) {
      printf("Exiting (EOF detected)\n");
      exit(1);
    }
    if (strlen(current_word) != 5) {
      printf("Your guess is not 5 letters long.\n");
      continue;
    }
    if (!valid_guess(guesses, results, num_guesses, current_word)) {
      printf("Your guess is not valid.\n");
      continue;
    }
    if (evaluate_guess(secret_word, current_word, results[num_guesses])) {
      printf("Your guess is correct! The secret word was: %s\n", secret_word);
      exit(0);
    }
    ++num_guesses;
    if (num_guesses == 6) {
      printf("You ran out of guesses. The secret word was: %s\n", secret_word);
      exit(0);
    }
  }
}

