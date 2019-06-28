#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Venta.h"

int controller_loadFromText(char* path , LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_sortVenta(LinkedList* pArrayListVenta);
int controller_saveAsText(char* path , LinkedList* pArrayListVenta);
int controller_fotosReveladasTotales(LinkedList* listaVenta);
int controller_qtyVentasMayorB(LinkedList* listaVentas);
int controller_qtyVentasMayorA(LinkedList* listaVentas);
int controller_qtyPolaroid(LinkedList* listaVenta);


#endif // CONTROLLER_H_INCLUDED
