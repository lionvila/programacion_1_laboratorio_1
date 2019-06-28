#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
	char salto[512];
	int retorno=-1;

	char bufferId[128];
    char bufferFecha[128];
    char bufferCuit[128];
    char bufferTipo[128];
    char bufferCantidad[128];
    char bufferPrecio[128];
    Venta* pAux;

    if(pFile!=NULL)
    {
		fscanf(pFile,"%[^\n]\n",salto);



		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                    bufferFecha,
                                                                    bufferTipo,
                                                                    bufferCantidad,
                                                                    bufferPrecio,
                                                                    bufferCuit);

            pAux=venta_newParametros(bufferId,
                                        bufferFecha,
                                        bufferCuit,
                                        bufferTipo,
                                        bufferCantidad,
                                        bufferPrecio);
            if(pAux!=NULL)
            {
				ll_add(pArrayListVenta,pAux);
				retorno=0;
            }
		}
	}
    return retorno;
}
