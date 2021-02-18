#include <stdio.h>
#include "Netflix.h"

void menu(netf *head, char *argv[], int *si){
	netf *in = NULL;
	netf *help;
	netf *help2;
	int n;
	in = head;
	do{
		
		printf(
		"\n          NN      N\n"
		"          N N     N\n"
		"          N  N    N\n"
		"          N   N   N\n"
		"          N    N  N\n"
		"          N     N N\n"
		"          N      NN\n"
		"\n           Netflix\n\n"
		" 1. Добавить сериал\n"
		" 2. Удалить сериал\n"
		" 3. Все сериалы\n"
		" 4. Найти сериал\n"
		" 5. Редактировать сериал\n"
		" 6. Выход\n\n > ");
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 1:
				in = new_s(in, si);
			break;
			case 2:
				help = in;
				help2 = in;
				if(help == NULL){
					printf("Пока сериалов здесь нет\n");
					break;
				}
				printf("Введите название сериала: ");
				help = find(file_insert(), help);
				if(help == NULL){
					printf("Пока сериалов здесь нет\n");
					break;
				}
				if(help == in)
					in = deletes(help);
				else{
					while(1){
						if(help2->next == help)
							break;
						else help2 = help2->next;
					}
					help2->next = deletes(help);
				}
			break;
			case 3:
				help = in;
				if(help == NULL){
					printf("Пока сериалов здесь нет\n");
					break;
				}
				printf("Вот актуальная информация по всем сериалам в базе:\n");
				while(help != NULL){
					printf("Название: %sДата выхода: %sРежиссёр: %sОценка: %1.1f Количество сезонов: %d\n\n",
					help->name,help->date,help->director,help->rank,help->s_number);
					help = help->next;
				}
			break;
			case 4:
				help = in;
				if(help == NULL){
					printf("Таких сериалов здесь нет\n");
					break;
				}
				printf("Введите название сериала:" );
				help = find(file_insert(), help);
				if(help == NULL){
					printf("Таких сериалов здесь нет\n");
					break;
				}
				printf("Название: %sДата выхода: %sРежиссёр: %sОценка: %1.1f Количество сезонов: %d\n\n",
					help->name,help->date,help->director,help->rank,help->s_number);
					help = help->next;

			break;
			case 5:
				help = in;
				if(help == NULL){
					printf("Таких сериалов здесь нет\n");
					break;
				}
				printf("Введите название сериала: ");
				help = find(file_insert(), help);
				if(help == NULL){
					printf("Таких сериалов здесь нет\n");
					break;
				}
				edit(help);
			break;
			case 6:
				write(in, argv, si);
				printf("\nВыход\n\n");
			break;
			default:
				printf("Команды с таким номером не существует\n ");
			break;
		}
	}
	while(n != 6);
}
