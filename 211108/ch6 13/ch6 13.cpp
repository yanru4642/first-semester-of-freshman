#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef enum { start, build_num, number, build_id, identifier, stop }state;


state transition(state current_state, char transition_char);

int main(void) {
	char transition_char;
	state current_state;


	current_state = start;
	do {
		if (current_state == identifier) {
			printf(" - Identifier\n");
			current_state = start;
		}
		else if (current_state == number) {
			printf(" - Number\n");
			current_state = start;
		}
		else if (current_state == stop) {

		}
		scanf("%c", &transition_char);
		if (transition_char != ' ') {
			printf("%c", transition_char);
		}
		current_state = transition(current_state, transition_char);
	} while (current_state != stop);

	system("pause");
	return(0);
}

state transition(state current_state, char transition_char) {

	if (isdigit(transition_char)) {
		while (isdigit(transition_char) || transition_char == '-' || transition_char == '+' || transition_char == '.') {
			current_state = build_num;
			scanf("%c", &transition_char);
			if (transition_char == '\n') {
				printf(" - Number\n");
				current_state = stop;
				return current_state;
				break;
			}
			printf("%c", transition_char);
		}
		current_state = number;
		return current_state;
	}

	else if (isalpha(transition_char)) {
		while (transition_char != ' ') {
			current_state = build_id;
			scanf("%c", &transition_char);
			if (transition_char == '\n') {
				printf(" - Identifier\n");
				current_state = stop;
				return current_state;
				break;
			}
			printf("%c", transition_char);
		}
		current_state = identifier;
		return current_state;
	}
}