// this module provides functions that can be used to play Wordle

#include <stdbool.h>

// all the guess and secret word characters must be lowercase
// all result characters are: lowercase if the letter exists in secret, but in a different position
//   lowercase if the letter is in secret but in a different position
//   uppercase if the letter is in the right position
//   - if the letter is not in the secret word

// evaluate_guess(secret, guess, result) returns whether or not secret is equal 
//   to guess and modifies result chars 
// e.g.
//   evaluate_guess("maybe", "beach", result) => false; result => "-ea--"
//   evaluate_guess("maybe", "mayos", result) => false; result => "MAY--"
// requires: result is sufficiently large [not asserted]
//           strlen(secret) == strlen(guess)
// effects: result will be modified
bool evaluate_guess(const char *secret, const char *guess, char *result);

