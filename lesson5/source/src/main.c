#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dlfcn.h>


int main(int argc, char *argv[]){
	int a, b, opt=0;
	double (*func)(int x, int y);
	char *option;
	void *library_handler = dlopen("/home/oli/lesson2_sort/labnik/lesson5/build/mathlib.so",RTLD_LAZY);

	if (!library_handler){
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
		exit(1);
	}

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

	if (strcmp(option,"mul")==0){
		func = dlsym(library_handler,"multiplication");
		printf("Results: %f\n", (*func)(a,b));
	}
	else if (strcmp(option,"div")==0){
		func = dlsym(library_handler,"divided");
		printf("Results: %f\n", (*func)(a,b));
	}
	else
	{
		fprintf(stderr, "Unknown type of processing: %s\n", option);
		exit(EXIT_FAILURE);
	}

	dlclose(library_handler);
	

	return 0;
}