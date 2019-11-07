#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmp.h>
#define MAX_LEN 1024

char** read_mas(int count);
void mas_print(int count, char **mas);
char * print_num(const void *line, int pos);
int wordlnght(char **mas, int count, int (*f) (int, int));
int max(int a, int b);
int min(int a, int b);

int main(int argc, char *argv[]){
	int count=0;
	char **mas=NULL;
	int typesort = 0;

	scanf("%d",&typesort);
	scanf("%d",&count);
	if (count<2){
		fprintf(stderr, "Usage:%s <string>...\n", mas[0]);
		exit(EXIT_FAILURE);
	}
	mas = read_mas(count);
	switch (typesort){
		case 1: 
			qsort(&mas[0],count,sizeof(char*),cmpinc_strlen);
			printf("Number of permuntations: %d\n", callcount());
			printf("Shorter string length: %d\n", (int) strlen(mas[0]));
			break;
		case 2: 
			qsort(&mas[0],count,sizeof(char*),cmpdec_strlen);
			printf("Number of permuntations: %d\n", callcount());
			printf("Longest string length: %d\n", (int) strlen(mas[0]));
			break;
		case 3: 
			qsort(&mas[0],count,sizeof(char*),cmpinc_alphabet);
			printf("Number of permuntations: %d\n", callcount());
			printf("First letter of the first line: %c\n", mas[0][0]);
			break;
		case 4: 
			qsort(&mas[0],count,sizeof(char*),cmpdec_alphabet);
			printf("Number of permuntations: %d\n", callcount());
			printf("First line length: %d\n", (int) strlen(mas[0]));
			break;
		case 5: 
			qsort(&mas[0],count,sizeof(char*),cmpinc_cntlet);
			printf("Number of permuntations: %d\n", callcount());
			printf("First letter of the last line: %c\n", mas[count-1][0]);
			break;
		case 6: 
			qsort(&mas[0],count,sizeof(char*),cmpdec_cntlet);
			printf("Number of permuntations: %d\n", callcount());
			printf("Max number of words: %d\n", word_count(&mas[0]));
			break;
		case 7: 
			qsort(&mas[0],count,sizeof(char*),cmpinc_cntnum);
			printf("Count of numbers: %d\n", numcount(mas,count));
			printf("%d number of the %d line: %s\n",2,count, print_num(&mas[count-1],2));
			break;
		case 8: 
			qsort(&mas[0],count,sizeof(char*),cmpdec_cntnum);
			printf("Number of permuntations: %d\n", callcount());
			printf("Count of numbers: %d\n", numcount(mas,count));
			break;
		case 9: 
			qsort(&mas[0],count,sizeof(char*),cmpinc_wlngth);
			printf("Max word length: %d\n", wordlnght(mas,count,max));
			printf("Count of numbers: %d\n", callcount());
			break;
		case 10: 
			qsort(&mas[0],count,sizeof(char*),cmpdec_wlngth);
			printf("Min word length: %d\n", wordlnght(mas,count,min));
			printf("Count of numbers in first line: %d\n", word_count(&mas[0]));
			break;
		default: 
			fprintf(stderr, "Usage:%s <string>...\n", mas[0]);
			exit(EXIT_FAILURE);
	}
	mas_print(count, mas);
	free (mas);
	exit(EXIT_SUCCESS);
}

char ** read_mas(int count){
	char buffer[MAX_LEN];
	char **mas;
	mas =(char**)malloc(sizeof(char*)*count);
	for (int i=0;i<count;i++){
		scanf("\n%[^\n]", buffer);
		mas[i]=(char*)malloc(sizeof(char)*strlen(buffer));
		strcpy(mas[i], buffer);
	}
	return mas;
}

void mas_print (int count, char **mas){
	for (int j=0;j<count;j++){
		puts(mas[j]);
	}
}

char * print_num(const void  *line, int pos){
	char **l=NULL;
	int j=0;

	l=break_string(line);
	for (int i=0;i<word_count(line);i++){
		if (isnum(l[i])){
			j++;
			if (j==pos)
				return l[i];
		}
	}
}

int wordlnght(char **mas, int count, int (*f) (int, int)){
	char **l=NULL;
	int value=0;

	l = break_string(&mas[0]);
	value = strlen(l[0]);
	for (int i = 0; i < count; ++i)
	{
		l = break_string(&mas[i]);
		for (int j = 0; j < word_count(&mas[i]); ++j)
		{
			if(!isnum(l[j]) && (*f)(value,strlen(l[j])))
				value=strlen(l[j]);
		}
	}
	return value;
}

int max(int a, int b){
	return a < b ? 1 : 0;
}

int min(int a, int b){
	return a > b ? 1 : 0;
}