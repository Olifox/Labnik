#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#define MAX_LEN 1024

void line_proc (char * fpath, char * opt);
void char_proc (char * fpath, char * opt);

int main(int argc, char ** argv){
	int opt=0;
	char *fpath,*type,*option;

	while((opt=getopt(argc,argv,"f:o:t:"))!=-1){
		switch (opt){
			case 'f':
				fpath = optarg;
				break;
			case 'o':
				option = optarg;
				break;
			case 't':
				type = optarg;
				break;
			default:
				fprintf(stderr, "Unknown arguments. Expected: [-f file path] [-o option] [-t type] \n");
				exit(EXIT_FAILURE);
		}
	}

	if (option==NULL || type==NULL || fpath==NULL)
		printf("Not enough arguments: Expected: [-f file path] [-o option] [-t type]\n");

	if (strcmp(type,"line")==0)
		line_proc(fpath,option);
	else if (strcmp(type,"char")==0)
		char_proc(fpath,option);
	else
	{
		fprintf(stderr, "Unknown type of processing: %s\n", type);
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

void line_proc (char * fpath, char * opt){
	FILE *fp;
	char buffer[MAX_LEN];
	char sep[]="\n";
	char *s;

	if((fp=fopen(fpath, "r"))==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	fread(&buffer, sizeof(char), MAX_LEN, fp);
	if (fclose(fp)){
		printf("Error close file.\n");
		exit(1);
	}

	if((fp=fopen(fpath, "w"))==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	s=strtok(buffer,sep);
	while(s != NULL){
		if (*s==*opt){
			printf("%s\n", s);
			fprintf(fp, "%s\n", s);
		}
		s=strtok(NULL,sep);		
	}
	if (fclose(fp)){
		printf("Error close file.\n");
		exit(1);
	}
}

void char_proc (char * fpath, char * opt){
	FILE *fp;
	char ch;
	char buffer[MAX_LEN];
	int i;

	if((fp=fopen(fpath, "r"))==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	while((ch=fgetc(fp)) != EOF){
		if (ch!=*opt){
			buffer[i]=ch;
			i++;
		}
	}
	if (fclose(fp)){
		printf("Error close file.\n");
		exit(1);
	}

	if((fp=fopen(fpath, "w"))==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	for (int j = 0; j < i; ++j)
		fputc(buffer[j],fp);
	if (fclose(fp)){
		printf("Error close file.\n");
		exit(1);
	}
}