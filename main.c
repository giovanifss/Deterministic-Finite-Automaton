#include <stdio.h>
#include <stdbool.h>
#include "dfa.h"

enum Identifiers {
  INITIAL_STATE,
  ZERO_STATE,
  ONE_STATE,
  ACCEPT_STATE
};

int main (int argc, char *argv[])
{
  DFA *automata = create_automata();

  DFA_State *initial_state = create_state(INITIAL_STATE, false, automata);
  DFA_State *zero_state = create_state(ZERO_STATE, false, automata);
  DFA_State *one_state = create_state(ONE_STATE, false, automata);
  DFA_State *accept_state = create_state(ACCEPT_STATE, true, automata);

  generate_transitions("a-", initial_state, initial_state);
  generate_transitions("0", initial_state, zero_state);
  generate_transitions("1", initial_state, one_state);
  generate_transitions("0", one_state, zero_state);
  generate_transitions("1", zero_state, one_state);
  generate_transitions("+", zero_state, accept_state);
  generate_transitions("%", one_state, accept_state);

  automata->initial_state = initial_state;

  /* Imaginary language tests */
  char *string1 = "a-aaaa--0101%"; // Valid
  printf("Checking if the string '%s' pertences to language... ", string1);
  if (belongs_to_language(string1, automata)) {
    printf("Yes!!!\n");
  } else {
    printf("No!!!\n");
  }

  char *string2 = "100101011"; // Invalid
  printf("Checking if the string '%s' pertences to language... ", string2);
  if (belongs_to_language(string2, automata)) {
    printf("Yes!!!\n");
  } else {
    printf("No!!!\n");
  }

  return 0;
}
