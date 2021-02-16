// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
//#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "utilitarian.h"
#define YES 1
#define NOT 0



STUDENT student;
int answer;
int cont;
int any = -1;



//funcao responsavel para cadastrar estudantes.
void registers(char *fileName){
	do{
		fileStudent = fopen(fileName,"a+b");
		system("cls");
		
		student.state = NOT_DELETED;
		student.numberStudent = newStudentNumber(fileStudent,fileName,sizeof(STUDENT));
		printf("\t\t ============================================= \n");
		printf("\t\t ===========> Register Student <============== \n");
		printf("\t\t ============================================= \n");
		//cleanBuffer();
		setbuf(stdin,NULL);
		printf("Enter the student's last name: ");
		//gets(student.lastName);
		scanf("%s",student.lastName);
		setbuf(stdin,NULL);
		printf("Enter the student's first name: ");
		//gets(student.firstName);
		scanf("%s",student.firstName);
		setbuf(stdin,NULL);
		printf("Enter the age of the student: ");
		scanf("%d",&student.age);
		setbuf(stdin,NULL);
		printf("Enter the gender of the student M - Male and F - Female: ");
		scanf("%c",&student.gender);
		setbuf(stdin,NULL);
		printf("Enter student course: ");
		//gets(student.course);
		scanf("%s",student.course);
		setbuf(stdin,NULL);	
		printf("Enter student group :");
		//gets(student.group);
		scanf("%s",student.group);
		setbuf(stdin,NULL);
		printf("What year is the student in: ");
		scanf("%d",&student.year_Course);
		setbuf(stdin,NULL);
		if(fileStudent == NULL)
			printf("\nERROR: OPENING THE FILE");
		else
			fwrite(&student, sizeof(STUDENT), 1, fileStudent);
		
		if(ferror(fileStudent))
			printf("\nRecording Error");
		else
			printf("\n Student successfully registered! \n");
		printf("\nDo you want to register more students? YES(1) / NO(0):");
		scanf("%d",&keepOn);
		fclose(fileStudent);
	}while(keepOn == YES);
}

//Funcao responsavel por mostrar os estudantes
void show(){
	printf("\nStudent number: %d",student.numberStudent);
	printf("\nName of the student: %s %s",student.firstName,student.lastName);
	printf("\nAge: %d",student.age);
	printf("\nGender: %c",student.gender);
	printf("\nCourse: %s",student.course);
	printf("\nGroup: %s",student.group);
	printf("\nYear: %d",student.year_Course);
	printf("\n");
}

//Funcao para consultar um estudante
void consult(char *fileName){
	//Abertura do ficheiro
	fileStudent = fopen(fileName,"r+b");
	
	//loop para consultar enquanto pretende consultar
	do{
		system("cls");
		printf("\t\t ============================================= \n");
		printf("\t\t ===========> Consult Student <=============== \n");
		printf("\t\t ============================================= \n");
		printf("Student number you want to consult: ");
		scanf("%d",&numStudent);
		
		//funcao para colocar o ponteiro no inicio do ficheiro
		rewind(fileStudent);
		
		//loop para percorrer todo ficheiro, apartir da posicao 0 ate o final
		do{
			//leitura do arquivo para obtermos os numeros cadastrados
			fread(&student, sizeof(STUDENT), 1, fileStudent);
			
			//Comaparando o numero de pesquisa com o numero armazenado
			if(numStudent == student.numberStudent && student.state == NOT_DELETED){
				printf("\t\t ============================================= \n");
				printf("\t\t =============> Student Data <================ \n");
				printf("\t\t ============================================= \n");
				show();
			}
			//else
			//	printf("\n\nstudent not found\n");
		}while(feof(fileStudent) == 0 && numStudent != student.numberStudent);
		
		if(numStudent != student.numberStudent || student.state == DELETED){ printf("\nstudent not found");}
		printf("\n\nConsult another Student (YES(1) / NO(0)): ");
		scanf("%d",&cont);
	}while(cont == YES);
	fclose(fileStudent);
}

//Funcao para listar os estudantes
void list(char *fileName){
	fileStudent = fopen(fileName,"r+b");
	system("cls");
	printf("\t\t ===================================================== \n");
	printf("\t\t =============> General Listing <===================== \n");
	printf("\t\t =============> Data of all Students <================ \n");
	printf("\t\t ===================================================== \n");
	
	rewind(fileStudent);
	
	do{
		fread(&student, sizeof(STUDENT), 1, fileStudent);
		if(feof(fileStudent) == 0 && student.state == NOT_DELETED)
			show();
	}while(feof(fileStudent)==0);
	fclose(fileStudent);
}

// Funcao para listar os estudantes removidos
void listRemove(char *fileName){
	fileStudent = fopen(fileName,"r+b");
	system("cls");
	printf("\t\t ===================================================== \n");
	printf("\t\t =============> General Listing <===================== \n");
	printf("\t\t =============> Students Removed <==================== \n");
	printf("\t\t ===================================================== \n");
	
	rewind(fileStudent);
	
	do{
		fread(&student, sizeof(STUDENT), 1, fileStudent);
		if(feof(fileStudent) == 0 && student.state == DELETED)
			show();
	}while(feof(fileStudent)==0);
	fclose(fileStudent);
}

//Funcao para actualizar a informacao de um estudante
void update(char *fileName){
	do{
		fileStudent = fopen(fileName,"r+b");
		system("cls");
		if(fileStudent == NULL)
			printf("\nERROR: OPENING THE FILE");
		else{
			printf("Enter the number of the student who wants to update the information: ");
			scanf("%d",&numStudent);
			fseek(fileStudent,(numStudent - 1) * sizeof(STUDENT),SEEK_SET);
			fread(&student, sizeof(STUDENT), 1, fileStudent);
			if(numStudent == student.numberStudent && student.state == NOT_DELETED){
				show();
				printf("Do you want to update the information shown above?YES(1) / NO(0): ");
				scanf("%d",&answer);
				if(answer == YES){
					setbuf(stdin,NULL);
					printf("Enter the student's last name: ");
					//gets(student.lastName);
					scanf("%s",student.lastName);
					setbuf(stdin,NULL);
					printf("Enter the student's first name: ");
					//gets(student.firstName);
					scanf("%s",student.firstName);
					setbuf(stdin,NULL);
					printf("Enter the age of the student: ");
					scanf("%d",&student.age);
					setbuf(stdin,NULL);
					printf("Enter student course: ");
					//gets(student.course);
					scanf("%s",student.course);
					setbuf(stdin,NULL);	
					printf("Enter student group :");
					//gets(student.group);
					scanf("%s",student.group);
					setbuf(stdin,NULL);
					printf("What year is the student in: ");
					scanf("%d",&student.year_Course);
					setbuf(stdin,NULL);
					fseek(fileStudent, (any * sizeof(STUDENT)), SEEK_CUR);
					fwrite(&student, sizeof(STUDENT), 1, fileStudent);
					if(ferror(fileStudent))
						printf("\nRecording Error!!!");
					else
						printf("\nStudent information updated successfully!");	
				}
			}else{
					printf("\nInvalid student number!!!\n");
					printf("Press </Enter> to continue ...");
					//getch();
					system("pause");
				}
		}
		printf("\n\nWant to update another student's information? YES(1) / NO(0): ");
		scanf("%d",&keepOn);
		fclose(fileStudent);
	}while(keepOn == YES);
}

//Funcao para excluir um estudante da base de dados
void delet(char *fileName){
	do{
		fileStudent = fopen(fileName,"r+b");
		system("cls");
		if(fileStudent == NULL)
			printf("\nERROR: OPENING THE FILE");
		else{
			printf("Enter the number of the student you wish to remove from the list: ");
			scanf("%d",&numStudent);
			fseek(fileStudent, (numStudent - 1)  * sizeof(STUDENT), SEEK_SET);
			fread(&student, sizeof(STUDENT), 1, fileStudent);
			if(numStudent == student.numberStudent && student.state == NOT_DELETED){
				show();
				printf("Do you want to delete the data shown above? YES(1) / NO(0): ");
				scanf("%d",&answer);
				if(answer == YES){
					student.state = DELETED;
					fseek(fileStudent, (any * sizeof(STUDENT)), SEEK_CUR);
					fwrite(&student, sizeof(STUDENT), 1, fileStudent);
					if(ferror(fileStudent))
						printf("\n Error while removing!!!");
					else
						printf("\nSuccessfully removed!!");
				}
			}else{
					printf("\nInvalid student number!!!\n");
					printf("Press </Enter> to continue ...");
					//getch();
					system("pause");
			}
		}
		printf("\nYou want to remove another student? YES(1) / NO(0): ");
		scanf("%d",&keepOn);
		fclose(fileStudent);
	}while(keepOn == YES);
}
