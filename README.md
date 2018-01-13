# Deterministic Finite Automaton
An abstract deterministic finite automaton implementation in C. Created to help parsing and lexical analysis in a compiler
implementation.

## Usage
To use the DFA, first you need to create the automata through the ```create_automata()``` function. Then you can create states and
add transitions through ```create_state(int id, bool is_accept_state?, DFA automata)``` and ```create_transition(char trigger,
DFA_State origin, DFA_State destination)``` respectively.  

You can also create multiples transitions through the ```generate_transitions(string, DFA_State origin, DFA_State destination)```.
This function will go through all characters in the string and generate a transition for each one.

## Examples
Lets consider a imaginary language that accepts ```a``` and ```-``` at the beginning of the word, then after ```1``` or ```0```
only accepts one`s and zero`s. Also, to accept the phrase, it must terminate with either ```+``` if it was in the zero state or
```%``` if it was in the one state. To clarify, the language`s automata is described in the following image:

![Imaginary Language Automata](https://github.com/giovanifss/Deterministic-Finite-Automaton/blob/master/imaginary-language.png)

The following code create and describes this automata:
```
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
```
