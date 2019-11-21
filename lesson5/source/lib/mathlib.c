#include <stdio.h>
#include <stdlib.h>

double multiplication(int a, int b){
	return a*b;
}

double divided(int a, int b){
	if (b==0){
		printf("Cannot be divided by zero.\n");
		exit(EXIT_FAILURE);
	}
	return a/b;
}