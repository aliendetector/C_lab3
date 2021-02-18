#include "Netflix.h"
	
int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Ошибка: слишком мало аргументов\n");
		return 0;
	}
	netf *head;
	int *si = 0;
	head = readfile(head, argv, si);
	menu(head, argv, si);
return 0;
}
