#define TC_COMMAND_QUIT 0
#define TC_COMMAND_OK 1
#define TC_COMMAND_INVALID 0

#include <tinycalc.h>
#include <stdio.h>


int check_command(char op) {
  if (tolower(op) != 'm') || (tolower(op) != 'q') || (op != '+') || (op != '-') || (op != '*') || (op != '/') || (op != '^'){
  	return TC_COMMAND_INVALID;
  } else{
  	return TC_COMMAND_OK;
  }
}

int read_command(char *op, double *num){
  if (check_command(op) == 1){

  }
  return 0;
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
}

double mem_read(tc_memory_t mem, int v) {
  return 0;
}

void mem_save(tc_memory_t *mem, double v) {
}
