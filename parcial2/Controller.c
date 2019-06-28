#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVenta)
{
    FILE* pFile;
    int retorno=-1;
    if(path!=NULL && pArrayListVenta!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_VentaFromText(pFile,pArrayListVenta);
			retorno=0;
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_ListVenta(LinkedList* pArrayListVenta)
{
	int bufferId;
    char bufferFecha[4096];
    char buffeCuit[4096];
    int bufferTipo;
    int bufferCantidad;
    float bufferPrecio;

    int i;
    int len;
    int retorno=-1;
    Venta* pAux;
    len=ll_len(pArrayListVenta);
    for(i=0;i<len;i++)
    {
        if(pArrayListVenta!=NULL)
		{
			pAux=ll_get(pArrayListVenta,i);
		}
		if(	!venta_getId(pAux,&bufferId) &&
			!venta_getFecha(pAux,bufferFecha) &&
            !venta_getCuit(pAux,buffeCuit) &&
			!venta_getTipo(pAux,&bufferTipo) &&
			!venta_getCantidad(pAux,&bufferCantidad) &&
            !venta_getPrecio(pAux,&bufferPrecio))
		{
			printf("\nID:%d\nFecha:%s\nCuit:%s\nTipo:%d\nCantidad:%d\nPrecio:%f\n", bufferId,
                                                                                    bufferFecha,
                                                                                    buffeCuit,
                                                                                    bufferTipo,
                                                                                    bufferCantidad,
                                                                                    bufferPrecio);
			retorno=0;
		}
    }
    printf("len ll:%d",len);
    return retorno;
}

/** \brief Ordenar ventas
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_sortVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    if(pArrayListVenta!=NULL)
    {
        ll_sort(pArrayListVenta,venta_compararPorFecha,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los ventas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVenta)
{
    int fotosTotal;
    int ventasMayorA;
    int ventasMayorB;
    int qtyPolaroid;
    int retorno=-1;
    int i;

	FILE* pFile=NULL;

    if(path!=NULL && pArrayListVenta!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			fotosTotal=controller_fotosReveladasTotales(pArrayListVenta);
			ventasMayorA=controller_qtyVentasMayorA(pArrayListVenta);
			ventasMayorB=controller_qtyVentasMayorB(pArrayListVenta);
			qtyPolaroid=controller_qtyPolaroid(pArrayListVenta);

			fprintf(pFile,"******\nInforme de Ventas\n******");
			fprintf(pFile,"\nCantidad de fotos reveladas totales:%d",fotosTotal);
			fprintf(pFile,"\nCantidad de ventas mayores a $150:%d",ventasMayorA);
			fprintf(pFile,"\nCantidad de ventas mayores a $300:%d",ventasMayorB);
			fprintf(pFile,"\nCantidad de fotos polaroid reveladas:%d",qtyPolaroid);
			retorno=0;
		}
    }
    fclose(pFile);
    return retorno;
}

int controller_fotosReveladasTotales(LinkedList* listaVenta)
{
    int i;
    Venta* pVenta;
    int cantidad;
    int total=0;
    if(listaVenta!=NULL)
    {
        for(i=0;i<ll_len(listaVenta);i++)
        {
            pVenta=ll_get(listaVenta,i);
            if(pVenta!=NULL)
            {
                venta_getCantidad(pVenta,&cantidad);
                total=cantidad+total;
            }
        }
    }
    return total;
}

int controller_qtyVentasMayorA(LinkedList* listaVentas)
{
    int cantidad;
    if( listaVentas!=NULL)
    {
        cantidad=ll_count(listaVentas,esMayorA);
    }
    return cantidad;
}

int controller_qtyVentasMayorB(LinkedList* listaVentas)
{
    int cantidad;
    if( listaVentas!=NULL)
    {
        cantidad=ll_count(listaVentas,esMayorB);
    }
    return cantidad;
}

int controller_qtyPolaroid(LinkedList* listaVenta)
{
    int i;
    Venta* pVenta;
    int cantidad;
    int tipo;
    int total=0;
    if(listaVenta!=NULL)
    {
        total=ll_count(listaVenta,esPolaroid);
    }
    return total;
}

