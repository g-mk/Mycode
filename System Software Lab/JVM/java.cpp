#include"java.h"

stack_frame* initialize(int size){
	stack_frame *stack = (stack_frame*)malloc(sizeof(stack_frame));
	stack->value = (double*)malloc(size*sizeof(double));
	stack->top = 0;
	return stack;
}

void push(stack_frame* stack, double value){
	stack->value[stack->top++] = value;
}
double pop(stack_frame *stack){
	return stack->value[--stack->top];
}

int word_count(char* line){
	int i = 0;
	int count = 1;
	while (i < strlen(line)){
		if (isblank(line[i])){
			count++;
		}
		i++;
	}
	return count;
}

char* readline(FILE* file){
	char * line = (char*)malloc(25 * sizeof(char));
	fscanf(file, "%[^\n]s", line);
	fgetc(file);
	return line;
}

token * getToken(char* mnemonic){
	FILE* file = fopen("opcode.txt", "r");
	char* line;
	token * tokens=(token*)malloc(sizeof(token));
	while (!feof(file)){
		line = readline(file);
		if (word_count(line) ==4){
			sscanf(line, "%s %X %d %d", tokens->mnemonic, &tokens->opcode, &tokens->operands, &tokens->length);
			if (strcmp(tokens->mnemonic, mnemonic) == 0){
				return tokens;
			}
		}
	}
	return NULL;
}
binary_class binary_formatter(int* binstream){
	FILE* file = fopen("inter.txt", "r");
	char* line = readline(file);
	char keyword[10], name[10], arguments[25];
	binary_class bin_class;
	sscanf(line, "%s %s %s", keyword, name, arguments);
	if (strcmp(keyword, "Method")==0){
		strcpy(bin_class.methods[0].method_name, name);
	}
	bin_class.access_flag = 1;
	bin_class.magic_number = 33;
	bin_class.version = 1.0;
	strcpy(bin_class.super_class, "OBJECT");
	strcpy(bin_class.class_name, "Sum");
	bin_class.methods[0].pc = 0;
	bin_class.stack_depth = 0;
	bin_class.stack_ptr =initialize(10);
	bin_class.local_ptr = (local_var*)malloc(10*sizeof(local_var));
	bin_class.Const_size=2;
	bin_class.attrib_count=13;
	bin_class.method_count=1;
	bin_class.const_ptr = (const_pool*)malloc(10*sizeof(const_pool));
	bin_class.methods[0].binstream = binstream;
	printf("\nEnter the Double Constant: ");
    scanf("%lf",&bin_class.local_ptr[1].value);
    printf("\nEnter the Double Constant: ");
    scanf("%lf",&bin_class.local_ptr[2].value);

	return bin_class;
}
void print_binclass(binary_class binClass){
    char * line;
    printf("\n**********************BINARY CLASS************************\n");
	printf("\nMagic Number:%d", binClass.magic_number);
	printf("\nVersion:%f", binClass.version);
	printf("\nConstant Size:%d",binClass.Const_size);
	printf("\nAccess Flag:%d", binClass.access_flag);
	printf("\nThis Class Name:%s", binClass.class_name);
	printf("\nSuper Class Name:%s", binClass.super_class);
	printf("\nStack Depth:%d", binClass.stack_depth);
	printf("\nMethod Count:%d", binClass.method_count);
	printf("\nMethod Name:%s", binClass.methods[0].method_name);
	printf("\nMethods:\n");
	/*FILE *fp = fopen("inter.txt","r");
	line = readline(fp);
	while(!feof(fp))
    {

        line = readline(fp);
        printf("%s\n",line);
    }*/

	printf("\nAttribute Count:%d",binClass.attrib_count);
	printf("\n*********************************************************\n\n");
}
void load_link(binary_class bin_class){
	double operand1, operand2;
	int i = 0;
	do{
		switch (bin_class.methods[0].binstream[i]){
		case 0x27:
		    //scanf("%X%X",&bin_class.local_ptr[1].value,&bin_class.local_ptr[2].value);
			push(bin_class.stack_ptr, bin_class.local_ptr[1].value);
			break;
		case 0x29:
			push(bin_class.stack_ptr, bin_class.local_ptr[2].value);
			break;
		case 0x63:
			operand1 = pop(bin_class.stack_ptr);
		    operand2 = pop(bin_class.stack_ptr);
			push(bin_class.stack_ptr, operand1 + operand2);
			break;
		case 0xAF:
			double result = pop(bin_class.stack_ptr);
			printf("\nReturned:%lf", result);
			break;

		}
		i++;
	} while (bin_class.methods[0].binstream[i-1] != 0xAF);
}

int* verifier(char* fileName){
	FILE* file = fopen(fileName, "r");
	FILE* interFile = fopen("inter.txt", "w");
	int lc=0;
	int i = 0;
	char mnemonic[25];
	int* binstream;
	char* line;
	token* tokens;
	binstream= (int*)malloc(10 * sizeof(int));
	char operand1[25], operand2[25];
	line = readline(file);
	fprintf(interFile, "%s\n", line);
	while (!feof(file)){
		line = readline(file);
		int countWord = word_count(line);
		int operands = countWord - 1;
		if (countWord == 1){
			sscanf(line, "%s", mnemonic);
			tokens = getToken(mnemonic);
			binstream[i] = tokens->opcode;
			if (tokens != NULL){
				if (operands == tokens->operands){
					fprintf(interFile, "%d %s\n", lc,mnemonic);
					lc += tokens->length;
				}
				else{
					printf("\nInvalid Number of operands for %s", mnemonic);
				}
			}
			else{
				printf("\nUnknown command %s", mnemonic);
			}
		}
		else if (countWord == 2){
			sscanf(line, "%s %s", mnemonic, operand1);
			tokens= getToken(mnemonic);
			if (tokens != NULL){
				if (operands == tokens->operands){
					fprintf(interFile, "%d %s %s\n", lc, mnemonic, operand1);
					lc += tokens->length;
				}
				else{
					printf("\nInvalid Number of operands for %s", mnemonic);
				}
			}
			else{
				printf("\nUnknown command %s", mnemonic);
			}
		}
		else if (word_count(line) == 3){
			sscanf(line, "%s %s %s", mnemonic, operand1, operand2);
			tokens = getToken(mnemonic);
			if (tokens != NULL){
				if (operands == tokens->operands){
					fprintf(interFile, "%d %s %s %s\n", lc, mnemonic, operand1, operand2);
					lc += tokens->length;
				}
				else{
					printf("\nInvalid Number of operands for %s", mnemonic);
				}
			}
			else{
				printf("\nUnknown command %s", mnemonic);
			}
		}
		i++;
	}
	fclose(file);
	fclose(interFile);
	return binstream;

}
