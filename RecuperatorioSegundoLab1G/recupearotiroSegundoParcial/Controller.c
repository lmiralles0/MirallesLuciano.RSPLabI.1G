#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "parser.h"
#include "datos.h"


int controller_loadFromText(char* path , LinkedList* pArray)
{
	int retorno = 1;
	FILE* f = fopen(path, "r");
	if(f != NULL)
	{
		if(parser_FromText(f, pArray) == 0)
		{
			retorno = 0;
		}
		fclose(f);
	}
	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArray)
{
	int retorno = 1;
	FILE* f = fopen(path, "w");
	int tam = ll_len(pArray);
	ePost* aux = NULL;
	int cant;
	if(f != NULL && pArray != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = (ePost*)ll_get(pArray, i);
			cant = fprintf(f, "%d,%s,%d,%d,%d\n",aux->id, aux->user, aux->likes, aux->dislikes, aux->followers);
			if(cant < 5)
			{
				break;
			}
		}
		retorno = 0;

	}
	fclose(f);
    return retorno;

}
