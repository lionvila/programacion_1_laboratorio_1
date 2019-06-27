#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListFantasma);
int controller_ListFantasma(LinkedList* pArrayListFantasma);
int controller_sortFantasma(LinkedList* pArrayListFantasma);
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma);

#endif // CONTROLLER_H_INCLUDED
