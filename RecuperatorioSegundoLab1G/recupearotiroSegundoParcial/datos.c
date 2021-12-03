#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include <time.h>


ePost* datos_new()
{
    ePost* newDatos = (ePost*) malloc(sizeof(ePost));
	if(newDatos != NULL)
	{
		newDatos->id = 0;
		newDatos->likes = 0;
		newDatos->dislikes = 0;
		newDatos->followers = 0;
		strcpy(newDatos->user, "  ");
	}
	return newDatos;
}


ePost* datos_newParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr)
{
    ePost* newDatos = datos_new();
	if(idStr != NULL && userStr != NULL && likesStr!= NULL && dislikesStr != NULL && followersStr != NULL)
	{
		if(!(ePost_setId(newDatos, atoi(idStr)) && ePost_setUser(newDatos, userStr) &&
			ePost_setLikes(newDatos, atoi(likesStr)) && ePost_setDislikes(newDatos, atoi(dislikesStr)) &&
            ePost_setFollowers(newDatos, atoi(followersStr))))
		{
			free(newDatos);
			newDatos = NULL;
		}

	}
	return newDatos;
}


int ePost_setId(ePost* newDatos, int id)
{
    int retorno = 0;
	if(newDatos != NULL && id >= 0)
	{
		newDatos->id = id;
		retorno = 1;
	}
	return retorno;
}


int ePost_setUser(ePost* newDatos, char* user)
{
    int retorno = 0;
	if(newDatos != NULL && user != NULL)
	{
		strcpy(newDatos->user, user);
		retorno = 1;
	}
	return retorno;
}


int ePost_setLikes(ePost* newDatos, int likes)
{
    int retorno = 0;
	if(newDatos != NULL && likes >= 0)
	{
		newDatos->likes = likes;
		retorno = 1;
	}
	return retorno;
}


int ePost_setDislikes(ePost* newDatos, int dislikes)
{
    int retorno = 0;
	if(newDatos != NULL && dislikes >= 0)
	{
		newDatos->dislikes= dislikes;
		retorno = 1;
	}
	return retorno;
}


int ePost_setFollowers(ePost* newDatos, int followers)
{
    int retorno = 0;
	if(newDatos != NULL && followers >= 0)
	{
		newDatos->followers = followers;
		retorno = 1;
	}
	return retorno;
}


void ePost_Print(ePost* datos)
{
    printf("%3d        %20s       %4d               %4d                   %5d\n", datos->id, datos->user, datos->likes, datos->dislikes, datos->followers);
}


int ePost_Prints(LinkedList* pArray)
{
    int retorno = 1;
	int tam = ll_len(pArray);
	if(pArray != NULL && tam > 0)
	{
	    printf("****************************************************************************************\n");
	    printf("*ID                 USER           LIKES              DISLIKES             FOLLOWERS   *\n");
	    printf("****************************************************************************************\n");
		for(int i = 0; i < tam; i++)
		{
			ePost_Print((ePost*) ll_get(pArray, i));
		}
		retorno = 0;
	}
	return retorno;
}


int comparePost(void* (datos1), void* (datos2))
{
    if((((ePost*)datos1)->followers > ((ePost*)datos2)->followers))
	{
		return 1;
	}
	if((((ePost*)datos1)->followers < ((ePost*)datos2)->followers))
	{
		return -1;
	}
	return 0;
}


void randomLikes(void* elemento)
{
    ePost* aux = NULL;
    int likes;
    int max = 5000;
    int min = 500;
    if(elemento != NULL)
    {
        aux = (ePost*) elemento;
        likes = rand() % (max - min + 1) + min;
        ePost_setLikes(aux, likes);
    }
}

void randomDislikes(void* elemento)
{
    ePost* aux = NULL;
    int disLikes;
    int max = 3500;
    int min = 300;
    if(elemento != NULL)
    {
        aux = (ePost*) elemento;
        disLikes = rand() % (max - min + 1) + min;
        ePost_setDislikes(aux, disLikes);
    }
}


void randomFollowers(void* elemento)
{
    ePost* aux = NULL;
    int followers;
    int max = 10000;
    int min = 20000;
    if(elemento != NULL)
    {
        aux = (ePost*) elemento;
        followers = rand() % (max - min + 1) + min;
        ePost_setFollowers(aux, followers);
    }
}


int filterMejoresPosteos(void* elemento)
{
    int retorno = 0;
    ePost* aux = NULL;
    if(elemento != NULL)
    {
        aux = (ePost*)elemento;
        if(aux->likes >= 3000)
        {
            retorno = 1;
        }
    }
    return retorno;
}


int filterPeorPosteos(void* elemento)
{
    int retorno = 0;
    ePost* aux = NULL;
    if(elemento != NULL)
    {
        aux = (ePost*) elemento;
        if(aux->dislikes > aux->likes)
        {
            retorno = 1;
        }
    }
    return retorno;
}
