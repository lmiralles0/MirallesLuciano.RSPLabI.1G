#include "LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);


#endif // CONTROLLER_H_INCLUDED
