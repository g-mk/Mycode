#include<stdio.h>
#include"java.h"
int main(){
	int* binstream = verifier("codearray.txt");
	binary_class bin_class = binary_formatter(binstream);
	load_link(bin_class);
	print_binclass(bin_class);
}
