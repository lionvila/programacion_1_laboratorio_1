#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"
#include "parser.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los fantasmas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int parser_FantasmaFromText(FILE* pFile , LinkedList* pArrayListFantasma)
{
	char salto[512];
	int retorno=-1;

	char bufferId[128];
    char bufferNombre[128];
    char bufferApellido[128];
    char bufferNumeroInt[128];
    char bufferNumeroIntDos[128];
    char bufferNumeroFloat[128];
    Fantasma* pAux;

    if(pFile!=NULL)
    {
		fscanf(pFile,"%[^\n]\n",salto);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                    bufferNombre,
                                                                    bufferApellido,
                                                                    bufferNumeroInt,
                                                                    bufferNumeroIntDos,
                                                                    bufferNumeroFloat);
            pAux=fantasma_newParametros(bufferId,
                                        bufferNombre,
                                        bufferApellido,
                                        bufferNumeroInt,
                                        bufferNumeroIntDos,
                                        bufferNumeroFloat);
            if(pAux!=NULL)
            {
				ll_add(pArrayListFantasma,pAux);
				retorno=0;
            }
		}
	}
    return retorno;
}
