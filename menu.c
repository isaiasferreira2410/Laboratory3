// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "student.h"
#define EXIT

void mainMenu(){
	int choose;
	a:
	system("cls");
	printf("\t\t =================================================== \n");
	printf("\t\t =============> Student Management <================ \n");
	printf("\t\t =============> Main Menu          <================ \n");
	printf("\t\t =================================================== \n");
	printf("\t\t |            * Student Data *                     | \n");
	printf("\t\t | 1) Register                                     | \n");
	printf("\t\t | 2) Consult                                      | \n");
	printf("\t\t | 3) List of                                      | \n");
	printf("\t\t | 4) Update                                       | \n");
	printf("\t\t | 5) Remove                                       | \n");
	printf("\t\t | 6) List removed students                        | \n");
	printf("\t\t =================================================== \n");
	printf("\t\t | 0) GET OUT(EXIT)                                | \n");
	printf("\t\t =================================================== \n");
	printf("\t\t | Choose an option : ");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			registers("studentbin");
			goto a;
			break;
		case 2:
			consult("studentbin");
			goto a;
			break;
		case 3:
			list("studentbin");
			system("pause");
			goto a;
			break;
		case 4:
			update("studentbin");
			goto a;
			break;
		case 5:
			delet("studentbin");
			goto a;
			break;
		case 6:
			listRemove("studentbin");
			system("Pause");
			goto a;
			break;
		case 0:
			exit(0); break;
		default:
			printf("\t\t Invalid Option!!!"); break; 
	}
}
