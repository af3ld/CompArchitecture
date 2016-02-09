
#include "tinycalc.h"
#include <stdio.h>

int check_command(char op) {
	switch (op) {
	case 'm' :
		return TC_COMMAND_OK;
	case 'q':
		return TC_COMMAND_OK;
	case 'M' :
		return TC_COMMAND_OK;
	case 'Q':
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
	// scanf(" %c %lf", op, num);
	scanf(" %c", op);
	if (*op == 'q' || *op == 'Q') {
		return TC_COMMAND_QUIT;
	} else {
		scanf(" %lf", num);
		return TC_COMMAND_OK;
	}
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
	int i; double result = 1.0;
	if (f_operator == '+') {
		*p_result += f_operand;
	} else if (f_operator == '-') {
		*p_result -= f_operand;
	} else if (f_operator == '*') {
		*p_result *= f_operand;
	} else if (f_operator == '/') {
		*p_result /= f_operand;
	} else if (f_operator == '^') {
		if (f_operand == 0.0) {
			*p_result = 1;
		} else if (f_operand > 0) {
			for (i = 0; i < f_operand; i++) {
				result *= *p_result;
			}
			*p_result = result;
		} else {
			for (i = 0; i < -f_operand; i++) {
				result *= *p_result;
			}
			*p_result = 1 / result;
		}
	}
}


//TODO: fix float exponents

double mem_read(tc_memory_t mem, int v) {
	return (v >= TC_MEM_SZ || v < 0) ? mem.vals[0] : mem.vals[v];
}

void mem_save(tc_memory_t *mem, double v) {
	int i;
	for (i = mem->most_recent; i >= 1; i--) {
		mem->vals[i] = mem->vals[i - 1];
	}
	mem->vals[0] = v;
	mem->most_recent++;
}
