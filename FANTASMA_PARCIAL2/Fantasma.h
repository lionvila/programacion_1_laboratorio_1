#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int numeroInt;
    int numeroIntDos;
    float numeroFloat;
}Fantasma;

Fantasma* fantasma_new(void);
Fantasma* fantasma_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* apellidoStr,
                                 char* numeroIntStr,
                                 char* numeroIntDosStr,
                                 char* numeroFloatStr);

void fantasma_delete(Fantasma* this);

int fantasma_setId(Fantasma* this,int id);
int fantasma_getId(Fantasma* this,int* id);
int fantasma_setIdStr(Fantasma* this, char* id);
int fantasma_getIdStr(Fantasma* this, char* id);

int fantasma_setNombre(Fantasma* this,char* nombre);
int fantasma_getNombre(Fantasma* this,char* nombre);

int fantasma_setApellido(Fantasma* this,char* apellido);
int fantasma_getApellido(Fantasma* this,char* apellido);

int fantasma_setNumeroInt(Fantasma* this,int numeroInt);
int fantasma_getNumeroInt(Fantasma* this,int* numeroInt);
int fantasma_setNumeroIntStr(Fantasma* this, char* numeroInt);
int fantasma_getNumeroIntStr(Fantasma* this, char* numeroInt);

int fantasma_setNumeroIntDos(Fantasma* this,int numeroIntDos);
int fantasma_getNumeroIntDos(Fantasma* this,int* numeroIntDos);
int fantasma_setNumeroIntDosStr(Fantasma* this, char* numeroIntDos);
int fantasma_getNumeroIntDosStr(Fantasma* this, char* numeroIntDos);

int fantasma_setNumeroFloat(Fantasma* this,float numeroFloat);
int fantasma_getNumeroFloat(Fantasma* this,float* numeroFloat);
int fantasma_setNumeroFloatStr(Fantasma* this, char* numeroFloat);
int fantasma_getNumeroFloatStr(Fantasma* this, char* numeroFloat);

int fantasma_setEstado(Fantasma* this,int estado);
int fantasma_getEstado(Fantasma* this,int* estado);

int fantasma_getIdMax(LinkedList* pArray);

int fantasma_getEmpById(LinkedList* pArray,int id,int* indice);

int fantasma_compararPorNombre(void* this1,void* this2);
int fantasma_calcularNumeroIntDos(Fantasma* this);


#endif // FANTASMA_H_INCLUDED
