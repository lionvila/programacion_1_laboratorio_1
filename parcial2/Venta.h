#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id;
    char fecha[128];
    char cuit[128];
    int tipo;
    int cantidad;
    float precio;
}Venta;

Venta* venta_new(void);
Venta* venta_newParametros(char* idStr,
                                 char* fechaStr,
                                 char* cuitStr,
                                 char* tipoStr,
                                 char* cantidadStr,
                                 char* precioStr);

void venta_delete(Venta* this);

int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);
int venta_setIdStr(Venta* this, char* id);
int venta_getIdStr(Venta* this, char* id);

int venta_setFecha(Venta* this,char* fecha);
int venta_getFecha(Venta* this,char* fecha);

int venta_setCuit(Venta* this,char* cuit);
int venta_getCuit(Venta* this,char* cuit);

int venta_setTipo(Venta* this,int tipo);
int venta_getTipo(Venta* this,int* tipo);
int venta_setTipoStr(Venta* this, char* tipo);
int venta_getTipoStr(Venta* this, char* tipo);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);
int venta_setCantidadStr(Venta* this, char* cantidad);
int venta_getCantidadStr(Venta* this, char* cantidad);

int venta_setPrecio(Venta* this,float precio);
int venta_getPrecio(Venta* this,float* precio);
int venta_setPrecioStr(Venta* this, char* precio);
int venta_getPrecioStr(Venta* this, char* precio);

int venta_setEstado(Venta* this,int estado);
int venta_getEstado(Venta* this,int* estado);

int venta_getIdMax(LinkedList* pArray);

int venta_getEmpById(LinkedList* pArray,int id,int* indice);

int venta_compararPorFecha(void* this1,void* this2);
int venta_calcularCantidad(Venta* this);

int esMayorA(Venta* pVenta);
int esMayorB(Venta* pVenta);
int esPolaroid(Venta* pVenta);


#endif // VENTA_H_INCLUDED
