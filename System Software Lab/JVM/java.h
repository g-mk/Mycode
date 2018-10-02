#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char mnemonic[10];
	int opcode;
	int operands;
	int length;
}token;
typedef struct{
	int index;
	int value;

}const_pool;
typedef struct{
	int index;
	double value;
}local_var;
typedef struct{
	int top;
	double * value;
}stack_frame;
typedef struct{
	int pc;
	char method_name[10];
	int* binstream;
}method_table;
typedef struct{
	int magic_number;
	float version;
	int Const_size;
	int access_flag;
	char class_name[25];
	char super_class[25];
	int attrib_count;
	stack_frame* stack_ptr;
	int stack_depth;
	int method_count;
	const_pool* const_ptr;
	local_var* local_ptr;
	method_table methods[10];
}binary_class;

token* getToken(char* name);

stack_frame* initialize(int size);
void push(stack_frame *stack, double value);
double pop(stack_frame* stack);

char* readline(FILE* file);
int word_count(char* line);

int* verifier(char* fileName);
binary_class binary_formatter(int* binstream);
void load_link(binary_class binClass);
void print_binclass(binary_class binClass);
