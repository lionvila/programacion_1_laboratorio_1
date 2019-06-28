#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int numeroInt;
    int numeroIntDos;
    float numeroFloat;
}Venta;

Venta* venta_new(void);
Venta* venta_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* apellidoStr,
                                 char* numeroIntStr,
                                 char* numeroIntDosStr,
                                 char* numeroFloatStr);

void venta_delete(Venta* this);

int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);
int venta_setIdStr(Venta* this, char* id);
int venta_getIdStr(Venta* this, char* id);

int venta_setNombre(Venta* this,char* nombre);
int venta_getNombre(Venta* this,char* nombre);

int venta_setApellido(Venta* this,char* apellido);
int venta_getApellido(Venta* this,char* apellido);

int venta_setNumeroInt(Venta* this,int numeroInt);
int venta_getNumeroInt(Venta* this,int* numeroInt);
int venta_setNumeroIntStr(Venta* this, char* numeroInt);
int venta_getNumeroIntStr(Venta* this, char* numeroInt);

int venta_setNumeroIntDos(Venta* this,int numeroIntDos);
int venta_getNumeroIntDos(Venta* this,int* numeroIntDos);
int venta_setNumeroIntDosStr(Venta* this, char* numeroIntDos);
int venta_getNumeroIntDosStr(Venta* this, char* numeroIntDos);

int venta_setNumeroFloat(Venta* this,float numeroFloat);
int venta_getNumeroFloat(Venta* this,float* numeroFloat);
int venta_setNumeroFloatStr(Venta* this, char* numeroFloat);
int venta_getNumeroFloatStr(Venta* this, char* numeroFloat);

int venta_setEstado(Venta* this,int estado);
int venta_getEstado(Venta* this,int* estado);

int venta_getIdMax(LinkedList* pArray);

int venta_getEmpById(LinkedList* pArray,int id,int* indice);

int venta_compararPorNombre(void* this1,void* this2);
int venta_calcularNumeroIntDos(Venta* this);


#endif // VENTA_H_INCLUDED
