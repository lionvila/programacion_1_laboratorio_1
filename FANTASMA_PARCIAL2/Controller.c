#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Fantasma.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los fantasmas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListFantasma)
{
    FILE* pFile;
    int retorno=-1;
    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_FantasmaFromText(pFile,pArrayListFantasma);
			retorno=0;
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Listar fantasmas
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_ListFantasma(LinkedList* pArrayListFantasma)
{
	int bufferId;
    char bufferNombre[4096];
    char buffeApellido[4096];
    int bufferNumeroInt;
    int bufferNumeroIntDos;
    float bufferNumeroFloat;

    int i;
    int len;
    int retorno=-1;
    Fantasma* pAux;
    len=ll_len(pArrayListFantasma);
    printf("len ll:%d",len);
    for(i=0;i<len;i++)
    {
        if(pArrayListFantasma!=NULL)
		{
			pAux=ll_get(pArrayListFantasma,i);
		}
		if(	!fantasma_getId(pAux,&bufferId) &&
			!fantasma_getNombre(pAux,bufferNombre) &&
            !fantasma_getApellido(pAux,buffeApellido) &&
			!fantasma_getNumeroInt(pAux,&bufferNumeroInt) &&
			!fantasma_getNumeroIntDos(pAux,&bufferNumeroIntDos) &&
            !fantasma_getNumeroFloat(pAux,&bufferNumeroFloat))
		{
			printf("\nID:%d\nNombre:%s\nApellido:%s\nNumeroInt:%d\nNumeroIntDos:%d\nNumeroFloat:%f\n",  bufferId,
                                                                                                        bufferNombre,
                                                                                                        buffeApellido,
                                                                                                        bufferNumeroInt,
                                                                                                        bufferNumeroIntDos,
                                                                                                        bufferNumeroFloat);
			retorno=0;
		}
    }
    return retorno;
}

/** \brief Ordenar fantasmas
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_sortFantasma(LinkedList* pArrayListFantasma)
{
    int retorno=-1;
    if(pArrayListFantasma!=NULL)
    {
        ll_sort(pArrayListFantasma,fantasma_compararPorNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los fantasmas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFantasma LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListFantasma)
{
    char bufferId[128];
    char bufferNombre[128];
    char bufferNumeroInt[128];
    char bufferNumeroIntDos[128];
    int retorno=-1;
    int i;

	Fantasma* pAux=NULL;
	FILE* pFile=NULL;

    if(path!=NULL && pArrayListFantasma!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayListFantasma);i++)
            {
                pAux=ll_get(pArrayListFantasma,i);
                if(	pAux !=NULL &&
                    !fantasma_getIdStr(pAux,bufferId) &&
                    !fantasma_getNombre(pAux,bufferNombre) &&
                    !fantasma_getNumeroIntStr(pAux,bufferNumeroInt) &&
                    !fantasma_getNumeroIntDosStr(pAux,bufferNumeroIntDos))
                {
                    fprintf(pFile,"%s,%s,%s,%s\n",  bufferId,
                                                    bufferNombre,
                                                    bufferNumeroInt,
                                                    bufferNumeroIntDos);
                    retorno=0;
                }
            }
		}
    }
    fclose(pFile);
    return retorno;
}
