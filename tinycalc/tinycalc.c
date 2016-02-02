
#include "tinycalc.h"
#include <stdio.h>
#include <ctype.h>


int check_command(char op) {
	op = (isalpha(op)) ? tolower(op) : op;
	switch (op) {
	case 'm' :
		return TC_COMMAND_OK;
	case 'q':
		return TC_COMMAND_OK;
	case '+':
		return TC_COMMAND_OK;
	case '-':
		return TC_COMMAND_OK;
	case '*':
		return TC_COMMAND_OK;
	case '/' :
		return TC_COMMAND_OK;
	case '^' :
		return TC_COMMAND_OK;		
	default:
		return TC_COMMAND_INVALID;
	}
}

int read_command(char *op, double *num) {
	scanf("%c  %lf", op, num);
	return (*op == ('q' | 'Q')) ? TC_COMMAND_QUIT : TC_COMMAND_OK;
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
	if (f_operator == '+') {
		*p_result += f_operand;
	} else if (f_operator == '-') {
		*p_result -= f_operand;
	} else if (f_operator == '*') {
		*p_result *= f_operand;
	} else if (f_operator == '/') {
		*p_result = f_operand;
	} else if (f_operator == '^') {
		int i; int result = 1;
		for (i = 0; i < *p_result; i++) {
			result *= f_operand;
		}
		*p_result = result;
	}
}

double mem_read(tc_memory_t mem, int v) {
	return mem.vals[v];
}

void mem_save(tc_memory_t *mem, double v) {
	int i;
	if ((*mem).most_recent < TC_MEM_SZ) {
		(*mem).vals[TC_MEM_SZ - 1 - (*mem).most_recent] = v;
		(*mem).most_recent++;
	} else {
		for (i = 4; i >= 1; i--) {
			(*mem).vals[i] = (*mem).vals[i - 1];
		}
		(*mem).vals[0] = v;
	}

}
