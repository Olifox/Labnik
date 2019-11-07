#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

struct student{
	char * last_name;
	char * group;
	int list_number;
	int grant;
};
typedef struct student students;

void read_students(students *st);
int cmp(const void *p1, const void *p2);
void print_student(students **st, int count);

int main(int argc, char **argv){
	int count=0;

	printf("Enter the number of students\n");
	scanf("%d",&count);
	if (count<1){
		fprintf(stderr, "Incorrect value entered\n");
		exit(EXIT_FAILURE);
	}
	students** st = (students**)malloc(sizeof(students*)*count);

	for (int i=0; i<count; i++){
		st[i] = (students*) malloc (sizeof(students));
		read_students(st[i]);
	}
	qsort(st, count, sizeof(students*), cmp);
	print_student(st, count);
	free(st);
	return 0;
}

void read_students(students *st){
	char buffer[MAX_LEN];

	printf("Enter last name: ");
	scanf("%s", buffer);
	st->last_name = (char*)malloc(sizeof(char)*strlen(buffer));
	strcpy(st->last_name, buffer);
	printf("Enter group: ");
	scanf("%s", buffer);
	st->group = (char*)malloc(sizeof(char)*strlen(buffer));
	strcpy(st->group, buffer);
	printf("Enter list number: ");
	scanf("%d", &st->list_number);
	printf("Enter grant: ");
	scanf("%d", &st->grant);
}

int cmp(const void *p1, const void *p2){
	students * st1 = *(students**)p1;
	students * st2 = *(students**)p2;
	return st1->list_number - st2->list_number;
}

void print_student(students **st, int count){
	for (int i = 0; i < count; ++i)
	{
		printf("List number: %d\n", st[i]->list_number);
		printf("Last name: %s\n", st[i]->last_name);
		printf("Group: %s\n", st[i]->group);
		printf("Grant: %d\n", st[i]->grant);
	}
}