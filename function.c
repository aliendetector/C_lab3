#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Netflix.h"


netf *deletes(netf *head){
    	netf *dop;
    	dop = head->next;
    	free(head->name);
    	free(head->date);
	free(head->director);
    	free(head);
	return dop;
}


char *file_insert(){
	char buffer[128];
	char *a;
	fgets(buffer, 128, stdin);
	a = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(a, buffer);
	return a;
}


netf *find(char *str, netf *head){
    while(head != NULL){
        if(!strcmp(head->name, str))
        	break;
        else head = head->next;
    }
    return head;
}


netf *new_s(netf *head, int *si){
	/*for (int i = 0; i < *si; i = i + 1){
		fscanf(f, "%s\n", head[i].name);
		fscanf(f, "%s\n", head[i].date);
		fscanf(f, "%s\n", head[i].director);
		fscanf(f, "%f\n", head[i].rank);
		fscanf(f, "%d\n", head[i].s_number);*/
	int i = *si;
	netf *smo = (netf*)malloc(sizeof(netf));
	/*printf("Введите название сериала\n");
	fscanf(f, "%s\n", head[i].name);
	printf("Введите дату выхода:\n");
	fscanf(f, "%s\n", head[i].date);
	printf("Введите фамилию режиссёра\n");
	fscanf(f, "%s\n", head[i].director);
	printf("Введите оценку:\n");
	fscanf(f, "%f\n", head[i].rank);
	printf("Введите количество сезонов:\n");
	fscanf(f, "%d\n", head[i].s_number)*/
	printf("Введите название сериала\n");
	smo[i].name = file_insert();
	printf("Введите дату выхода:\n");
	&smo[i].date = file_insert();
	printf("Введите фамилию режиссёра\n");
	&smo[i].director = file_insert();
	printf("Введите оценку:\n");
	scanf("%f",&smo[i].rank);
        getchar();
	printf("Введите количество сезонов:\n");
	scanf("%d",&smo[i].s_number);
	smo[i].next = head;
	return netf;
}


void edit(netf *head){
	int y;
    	do{
	        printf(
	        "\n Что вы хотите отредактировать?\n"
		" 1. Название\n"
		" 2. Дату выхода\n"
		" 3. Режиссёра\n"
		" 4. Оценку\n"
		" 5. Количество сезонов\n"
		" 6. Выйти из режима редактирования\n\n >");
		scanf("%d",&y);
		getchar();
        	switch(y){
			case 1:
				free(head->name);
				printf("Введите новое название: ");
				head->name = file_insert();
			break;
			case 2:
				free(head->date);
				printf("Введите новую дату выхода: ");
				head->date = file_insert();
			break;
			case 3:
				free(head->director);
				printf("Введите режиссёра: ");
				head->director = file_insert();
			break;
			case 4:
				printf("Введите новую оценку: ");
				scanf("%f",&head->rank);
			break;
			case 5:
				printf("Введите новое количество сезонов: ");
				scanf("%d",&head->s_number);
			break;
			case 6:
			break;
			default:
				printf("Команды с таким номером не существует!\n");
			break;
	        }
    	}
	while(y != 6);
}


netf *readfile(netf* head, char *argv[], int *si){
	FILE *f;
	if((f = fopen(argv[1],"r")) == NULL){
		printf("Возникла ошибка\n");
		return head;
	}
	netf n;
	while(!feof(f)){
		fscanf(f, "%s\n", n.name);
		fscanf(f, "%s\n", n.date);
		fscanf(f, "%s\n", n.director);
		fscanf(f, "%f\n", &n.rank);
		fscanf(f, "%d\n", &n.s_number);
		*si = *si + 1;
	}
	*si = *si - 1;
	fseek(f, 0, SEEK_SET);
	head = (netf *)malloc(*si * sizeof(netf));
	for (int i = 0; i < *si; i = i + 1){
		fscanf(f, "%s\n", head->name);
		fscanf(f, "%s\n", head->date);
		fscanf(f, "%s\n", head->director);
		fscanf(f, "%f\n", &head->rank);
		fscanf(f, "%d\n", &head->s_number);
	}
	fclose(f);
	return head;
}


void write(netf *head, char *argv[], int *si){
	FILE *f;
	if ((f = fopen(argv[1],"w")) == NULL){
		return;
		printf("Возникла ошибка записи");
	}
	for (int i = 0; i < *si; i = i + 1){
		fprintf(f, "%s\n", head[i].name);
		fprintf(f, "%s\n", head[i].date);
		fprintf(f, "%s\n", head[i].director);
		fprintf(f, "%f\n", head[i].rank);
		fprintf(f, "%d\n", head[i].s_number);
	}
	fclose(f);
	return;
}

