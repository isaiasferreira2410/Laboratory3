// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#include <stdio.h>
#include <stdlib.h>
#include "systempresentation.h"
#include "menu.h"


void systemPresentation(){
	printf("\t\t =========================================================================== \n");
	printf("\t\t =======================> Republic of Russia <============================== \n");
	printf("\t\t |=> University: Nizhny Novgorod State Technical University R.E. Alekseeva | \n");
	printf("\t\t |=> Faculty: Institute Of Radioelectronics and Information Technology     | \n");
	printf("\t\t |=> Project: Laboratory Work Nº3                                          | \n");
	printf("\t\t =========================================================================== \n");
	printf("\t\t |================> STUDENT MANAGEMENT SYSTEM               <==============| \n");
	printf("\t\t |=> Presentation of the System                                            | \n");
	printf("\t\t |=> Ojective: This project aims to create a database                      | \n");
	printf("\t\t |             for management students for different institutions          | \n");
	printf("\t\t |             The system has functionalities that allowed                 | \n");
	printf("\t\t |             to manege  information related to students.                 | \n");
	printf("\t\t =========================================================================== \n");
	printf("\t\t |================> Advisor: Chernov                        <==============| \n");
	printf("\t\t |================> Author : Isaias Antonio Ferreira        <==============| \n");
	printf("\t\t =========================================================================== \n");
	printf("\t\t |=> ENTER = 1                       |=> EXIT = 0                          | \n");
	printf("\t\t =========================================================================== \n");
	printf("\t\t |=> Do you want to enter the System: ");
	scanf("%d",&agree);
	if(agree == 1){
		system("cls");
		mainMenu();
	}else
		system("exit");
}
