#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <mathlib.h>

int main(int argc, char *argv[]){
	int a, b, opt=0;
	double c = 0;
	char *option;

	while((opt=getopt(argc,argv,"a:b:o:"))!=-1){
		switch (opt){
			case 'a':
				a = atoi(optarg);
				break;
			case 'b':
				b = atoi(optarg);
				break;
			case 'o':
				option = optarg;
				break;
			default:
				fprintf(stderr, "Unknown arguments. Expected: [-f paramA] [-o paramB] [-t type operation] \n");
				exit(EXIT_FAILURE);
		}
	}

	if (strcmp(option,"mul")==0)
		c=multiplication(a,b);
	else if (strcmp(option,"div")==0)
		c=divided(a,b);
	else
	{
		fprintf(stderr, "Unknown type of processing: %s\n", option);
		exit(EXIT_FAILURE);
	}

	printf("Results: %f\n", c);

	return 0;
}