#include <stdio.h>
#include "tinycalc.h"
#include <stdlib.h>



void print_array(double *a, int size){
	int i;
	for (i = 0; i < size; i++){
		printf("%lf\n", a[i]);
	}
}

int main(void) {
	char op; double num;
	double res = 0.0;
	int go = 1;
	tc_memory_t mem; mem.most_recent = 0;

	printf("\nWelcome to TinyCalc!\n\n Enter an operation <+, - , *, /, ^>");
	printf(" followed by operand\n\n Enter 'q' or 'Q' to quit.\n\n");
	printf(" Enter 'm' or 'M' followed by location (0-4) to load a previous\n");
	printf(" result from memory.\n");

	while (go) {
		printf("\n>");
		if (read_command(&op, &num)) {
			if (check_command(op)) {
				if (op == 'm' || op == 'M') {
					printf("%lf\n", mem_read(mem, num));
				} else {
					execute_calculation(op, num, &res);
					mem_save(&mem, res);
					printf("%lf\n", res);
					// print_array(mem.vals, mem.most_recent);
				}
			}
		} else {
			go = 0;
		}
	}
	return (0);
}




