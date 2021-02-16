// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#pragma once

#include <stdio.h>
//#define STUDENT_FILE "studentbin"
#define NOT_DELETED 1
#define DELETED 0
#define TAM 100

char *fileName;
FILE *fileStudent; // Ponteiro do ficheiro Student
int numStudent; // variavel que vai guardar o numero que usuario a de digitar
int keepOn; // variavel que vai o valor da condicao do loop 

//Estrutura Estudante
typedef struct{
	int numberStudent;
	char firstName[TAM];
	char lastName[TAM];
	int age;
	char gender;
	char group[100];
	char course[100];
	int year_Course;
	int state;
}STUDENT; 

//Declaracao das funcoes que gerem o estudante

void registers(char *fileName); //funcao cadastrar

void show(); // funcao mostrar

void consult(char *fileName); // funcao consultar

void list(char *fileName); // funcao listar

void listRemove(char *fileName); // funcao para listar os removidos 

void update(char *fileName); // funcao alterar(update)

void delet(char *fileName); // funcao excluir(delete)

//int files(); //verificacao de ficheiro
 
