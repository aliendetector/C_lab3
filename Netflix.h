#include <stdio.h>
typedef struct netf{
	char name[80];
	char date[80];
	char director[80];
	float rank;
	int s_number;
	struct netf *next;
}netf;
netf *deletes(netf *head);
netf *new_s(netf *head, int *si);
netf *find(char *str, netf *head);
//char *read2 (FILE *f,char *a);
//netf *read (FILE *f, char *a);
void edit(netf *head);
char *file_insert();
//void write(FILE *f, char *a, netf *head);
void menu(netf *head, char *argv[], int *si);
void screen();
netf *readfile(netf* head, char *argv[], int *si);
void write(netf *head, char *argv[], int *si);
