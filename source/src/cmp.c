#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmp.h>

int count = 0;

int cmpinc_strlen(const void *p1, const void *p2){
	count++;
	return strlen(*(char * const*)p1)-strlen(*(char * const*)p2);
}

int cmpdec_strlen(const void *p1, const void *p2){
	count++;
	return strlen(*(char * const*)p2)-strlen(*(char * const*)p1);
}

int cmpinc_alphabet(const void *p1, const void *p2){
	count++;
	return strcmp(*(char* const*)p1,*(char* const*)p2);
}

int cmpdec_alphabet(const void *p1, const void *p2){
	count++;
	return strcmp(*(char* const*)p2,*(char* const*)p1);
}

int cmpinc_cntlet(const void *p1, const void *p2){
	count++;
	int a=0,b=0;

	a=word_count(p1);
	b=word_count(p2);
	return a-b;
}

int cmpdec_cntlet(const void *p1, const void *p2){
	count++;
	char *p=NULL;
	int a=0,b=0;

	a=word_count(p1);
	b=word_count(p2);
	return b-a;
}

int cmpinc_cntnum(const void *p1, const void *p2){
	count++;
	int a=0,b=0;
	a=num_count(p1);
	b=num_count(p2);
	return a-b;
}

int cmpdec_cntnum(const void *p1, const void *p2){
	count++;
	int a=0,b=0;
	a=num_count(p1);
	b=num_count(p2);
	return b-a;
}

int cmpinc_wlngth(const void *p1, const void *p2){
	count++;
	int a=0,b=0;
	a=word_length(p1);
	b=word_length(p2);
	return a-b;
}

int cmpdec_wlngth(const void *p1, const void *p2){
	count++;
	int a=0,b=0;
	a=word_length(p1);
	b=word_length(p2);
	
	return b-a;
}

int callcount(){
	return count;
}

int word_length(const void *param){
	char **mas=break_string(param);
	return strlen(mas[0]);
}

int numcount(char ** mas,int cnt){
	int numcnt=0;
	char **line=NULL;
	for (int i = 0; i < cnt; ++i)
	{
		line = break_string(&mas[i]);
		for (int j = 0; j < word_count(&mas[i]); ++j)
		{
			if(isnum(line[j]))
				numcnt++;
		}
	}
	return numcnt;
}

int word_count(const void *param){
	char *s;
	char *p=(char *)malloc(sizeof(char)*strlen(param));
	strcpy(p,*(char* const*)param);
	int wcount=0;
	char sep[]=" ";
	s=strtok(p,sep);
	while (s!=NULL){		
		s=strtok(NULL,sep);
		wcount++;	
	}
	free(s);
	return wcount;
}

int num_count(const void *param){
	char **mas=NULL;
	int ncount=0;

	mas=break_string(param);
	for (int i=0;i<word_count(param);i++){
		if (isnum(mas[i]))
			ncount++;
	}
	return ncount;
}

char ** break_string(const void *param){
	char *s;
	char **mas;
	char sep[]=" ";
	char *p=(char *)malloc(sizeof(char)*strlen(param));
	int i=0;

	i=word_count(param);
	strcpy(p,*(char* const*)param);
	mas =(char**)malloc(sizeof(char*)*i);
	s=strtok(p,sep);
	mas[0]=(char*)malloc(sizeof(char)*strlen(s));
	strcpy(mas[0], s);
	for (int j=1;j<i;j++){
		s=strtok(NULL,sep);	
		mas[j]=(char*)malloc(sizeof(char)*strlen(s));
		strcpy(mas[j],s);
	}
	return mas;
}

int isnum(char *s){
	for (int j=0; j<strlen(s); j++){
		if (((int)s[j]<48) || ((int)s[j]>57)){
			return 0;
		}
	}
	return 1;
}