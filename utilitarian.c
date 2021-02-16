// Author : ISAIAS FERREIRA
// Course : Applied Mathematics and Informatics
// Group  : 20-PM-2
#include <stdio.h>
#include "utilitarian.h"

// funcao responsavel por limpar o buffer.
/*void cleanBuffer()
{
    int clean;
    while ((clean = fgetc(stdin)) != '\n' && clean != EOF);
}*/

int newStudentNumber(FILE *file, char *nameFile,int sizeRegistry){
	long sizeFile;
	if ((file = fopen(nameFile, "rb")) == NULL)
		return 1;
		
	//indo para o fim do ficheiro(file)
	fseek(file, 0, SEEK_END);
	
	//Pegando o tamanho do ficheiro
	sizeFile = ftell(file);
	
	fclose(file);
	
	//retornando o proximo numeroStudent;
	return(sizeFile/sizeRegistry) + 1;	
}
