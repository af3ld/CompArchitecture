#include <stdio.h>
#include "tinycalc.h"
#include <ctype.h>
#include <stdlib.h>



int main(void) {
	char op; double num;
	double res = 0.0;
	int go = 1;
	tc_memory_t mem; mem.most_recent = 0;

	printf("\nWelcome to TinyCalc!\n\n Enter an operation <+, - , *, /, ^>");
	printf(" followed by operand\n\n Enter 'q' or 'Q' to quit.\n\n");
	printf(" Enter 'm' or 'M' followed by location (0-4) to load a previous\n");
	printf(" result from memory.");

	mem_save(&mem, 0);
	while (go) {
		printf("\n>");
		if (read_command(&op, &num) == 0) {
			go = 0;
		} else if (check_command(op)) {
			if (tolower(op) == 'm') {
				printf("%lf", mem_read(mem, num));
			} else {
				execute_calculation(op, num, &res);
				printf("%.2lf", res);
			}
		}
	}

	return (0);
}




