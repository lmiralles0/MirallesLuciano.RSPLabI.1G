#include "LinkedList.h"
#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

typedef struct
{
    int id;
    char user[120];
    int likes;
    int dislikes;
    int followers;
} ePost;

ePost* datos_new();
ePost* datos_newParametros(char* idStr, char* userStr, char* likesStr, char* dislikesStr, char* followersStr);
int ePost_setId(ePost* newDatos, int id);
int ePost_setUser(ePost* newDatos, char* user);
int ePost_setLikes(ePost* newDatos, int likes);
int ePost_setDislikes(ePost* newDatos, int dislikes);
int ePost_setFollowers(ePost* newDatos, int followers);
void ePost_Print(ePost* datos);
int ePost_Prints(LinkedList* pArray);
int comparePost(void* (datos1), void* (datos2));
void randomLikes(void* elemento);
void randomDislikes(void* elemento);
void randomFollowers(void* elemento);
int filterMejoresPosteos(void* elemento);
int filterPeorPosteos(void* elemento);


#endif // DATOS_H_INCLUDED
