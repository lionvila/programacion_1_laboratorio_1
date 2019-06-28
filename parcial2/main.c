#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"

int main()
{
    int aux;
    LinkedList* listaVentas=ll_newLinkedList();
    controller_loadFromText("data.csv",listaVentas);
    aux=controller_qtyPolaroid(listaVentas);
    printf("QTY polaroid:%d",aux);
    controller_saveAsText("informes.txt",listaVentas);
    return 0;
}
