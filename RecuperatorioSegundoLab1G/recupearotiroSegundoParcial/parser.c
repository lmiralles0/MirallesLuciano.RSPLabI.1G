#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "LinkedList.h"


int parser_FromText(FILE* pFile , LinkedList* pArray)
{
	int retorno = 1;
	int cant;
	ePost* aux = NULL;
	char buffer[5][130];
	if(pFile != NULL && pArray != NULL)
	{
		fscanf(pFile,"%s", buffer[0]);//lectura fantasma
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			if(cant < 5)
			{
				break;
			}
			aux = datos_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			ll_add(pArray, (ePost*)aux);
		}while(!(feof(pFile)));
		retorno = 0;
	}
	return retorno;
}
