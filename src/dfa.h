#ifndef DETERMINISTIC_FINITE_AUTOMATA_H
#define DETERMINISTIC_FINITE_AUTOMATA_H

#include <stdbool.h>

/* Structs to represent State, Transition and the automata itself */
typedef struct DETERMINISTIC_FINITE_AUTOMATA DFA;
typedef struct DETERMINISTIC_FINITE_AUTOMATA_STATE DFA_State;
typedef struct DETERMINISTIC_FINITE_AUTOMATA_TRANSITION DFA_Transition;

/* Define an automata transition */
struct DETERMINISTIC_FINITE_AUTOMATA_TRANSITION
{
    DFA_State *origin_state;
    DFA_State *destination_state;
    char trigger_value;     // The value that triggers the transition
};

/* Define an automata state */
struct DETERMINISTIC_FINITE_AUTOMATA_STATE
{
    int state_identifier;   // Integer number to help end user identify the state
    bool accept_state;      // If this state is an accept state or not
    int transitions_count;
    DFA_Transition **transitions;
};

/* Define the automata */
struct DETERMINISTIC_FINITE_AUTOMATA
{
    int states_count;
    DFA_State **states;
    DFA_State *current_state;
    DFA_State *initial_state;
};

/* ====== Functions ====== */
/* Automata state manipulation */
bool init_automata (DFA *automata);
bool update_automata (char ch, DFA *automata);

/* Automata abstraction of state updates */
bool belongs_to_language (char *string, DFA *automata);

/* Alloc abstaction */
DFA_State* create_state (int state_identifier, bool accept_state, DFA *automata);
DFA_Transition* create_transition (char trigger_value, DFA_State *origin_state, DFA_State *destination_state);
DFA* create_automata ();

/* Allow creation of several transitions simply */
bool generate_transitions(char *string, DFA_State *origin_state, DFA_State *destination_state);

/* Dealloc abstraction */
bool free_automata (DFA *automata);

/* ====== DEBUG FUNCTIONS ====== */
void describe_automata (DFA *automata);

#endif  // DETERMINISTIC_FINITE_AUTOMATA_H
