#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"

/** \brief Crea un espacio de memoria con espacio para un Venta.
 *
 * \param void
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Venta* venta_new(void)
{
	return (Venta*) malloc(sizeof(Venta));
}

/** \brief Crea un espacio de memoria con espacio para un Venta y lo crea mediante
 *         los parametros pasados.
 *
 * \param char* id (del Venta a crear).
 * \param char* nombre (del Venta a crear).
 * \param char* numeroInt trabajadas (del Venta a crear).
 * \param char* numeroIntDos (del Venta a crear).
 * \param char* numeroFloatStr (del Venta a crear).
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Venta* venta_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* apellidoStr,
                                 char* numeroIntStr,
                                 char* numeroIntDosStr,
                                 char* numeroFloatStr)
{
	Venta* retorno=NULL;
	Venta* pAuxVenta;

	if(idStr!=NULL &&
	   nombreStr!=NULL &&
	   apellidoStr!=NULL &&
	   numeroIntStr!=NULL &&
	   numeroIntDosStr!=NULL &&
	   numeroFloatStr!=NULL)
	{
		pAuxVenta=venta_new();
		if(pAuxVenta!=NULL)
		{
			if(	!venta_setIdStr(pAuxVenta,idStr) &&
				!venta_setNombre(pAuxVenta,nombreStr) &&
                !venta_setApellido(pAuxVenta,apellidoStr) &&
				!venta_setNumeroIntStr(pAuxVenta,numeroIntStr) &&
				!venta_setNumeroIntDosStr(pAuxVenta,numeroIntDosStr) &&
                !venta_setNumeroFloatStr(pAuxVenta,numeroFloatStr))
			{
				retorno=pAuxVenta;
			}
			else
			{
				venta_delete(pAuxVenta);
			}
		}
	}
	return retorno;
}

/** \brief Libera el espacio en memoria ocupado por un Venta(Delete).
 *
 * \param void
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
void venta_delete(Venta* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Set del id en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int id del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setId(Venta* this,int id)
{
	int retorno = -1;
    if(this != NULL && isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* id del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getId(Venta* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del nombre en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* nombre del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNombre(Venta* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* nombre del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNombre(Venta* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del apellido en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* apellido del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setApellido(Venta* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && isValidName(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el apeliido de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* apellido del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getApellido(Venta* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de numeroInt trabajadas en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int numeroInt trabajadas del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroInt(Venta* this,int numeroInt)
{
	int retorno = -1;
    if(this != NULL && isValidInt(numeroInt,1000000,0))
    {
        this->numeroInt=numeroInt;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene numeroInt trabajadas de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* numeroInt del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroInt(Venta* this,int* numeroInt)
{
	int retorno = -1;
    if(this != NULL && numeroInt != NULL)
    {
        *numeroInt = this->numeroInt;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set de numeroFloat trabajadas en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param float numeroFloat trabajadas del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroFloat(Venta* this,float numeroFloat)
{
	int retorno = -1;
    if(this != NULL && isValidFloat(numeroFloat,1000000,0))
    {
        this->numeroFloat=numeroFloat;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene numeroFloat trabajadas de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param float* numeroFloat del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroFloat(Venta* this,float* numeroFloat)
{
	int retorno = -1;
    if(this != NULL && numeroFloat != NULL)
    {
        *numeroFloat = this->numeroFloat;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del numeroIntDos en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int numeroIntDos del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroIntDos(Venta* this,int numeroIntDos)
{
	int retorno = -1;
    if(this != NULL && isValidInt(numeroIntDos,1000000,0))
    {
        this->numeroIntDos=numeroIntDos;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el numeroIntDos de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* numeroIntDos del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroIntDos(Venta* this,int* numeroIntDos)
{
	int retorno = -1;
    if(this != NULL && numeroIntDos != NULL)
    {
        *numeroIntDos = this->numeroIntDos;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del id en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* id del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setIdStr(Venta* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        retorno = venta_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* id del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getIdStr(Venta* this, char* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && id != NULL)
    {
        venta_getId(this,&bufferInt);
        sprintf(id,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de numeroInt trabajadas en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroInt del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroIntStr(Venta* this, char* numeroInt)
{
    int retorno = -1;
    if(this != NULL && numeroInt!=NULL)
    {
        retorno = venta_setNumeroInt(this,atoi(numeroInt));
    }
    return retorno;
}

/** \brief Obtiene numeroInt trabajadas en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroInt del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroIntStr(Venta* this, char* numeroInt)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && numeroInt != NULL)
    {
        venta_getNumeroInt(this,&bufferInt);
        sprintf(numeroInt,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
/** \brief Set de numeroFloat trabajadas en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroFloat del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroFloatStr(Venta* this, char* numeroFloat)
{
    int retorno = -1;
    if(this != NULL && isValidFloatNumber(numeroFloat))
    {
        retorno = venta_setNumeroFloat(this,atof(numeroFloat));
    }
    return retorno;
}

/** \brief Obtiene numeroFloat trabajadas en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroFloat del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroFloatStr(Venta* this, char* numeroFloat)
{
    int retorno = -1;
    float bufferFloat;
    if(this != NULL && numeroFloat != NULL)
    {
        venta_getNumeroFloat(this,&bufferFloat);
        sprintf(numeroFloat,"%f",bufferFloat);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del numeroIntDos en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroIntDos del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setNumeroIntDosStr(Venta* this, char* numeroIntDos)
{
    int retorno = -1;
    if(this != NULL && numeroIntDos!=NULL)
    {
        retorno = venta_setNumeroIntDos(this,atoi(numeroIntDos));
    }
    return retorno;
}

/** \brief Obtiene el numeroIntDos en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* numeroIntDos del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getNumeroIntDosStr(Venta* this, char* numeroIntDos)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && numeroIntDos != NULL)
    {
        venta_getNumeroIntDos(this,&bufferInt);
        sprintf(numeroIntDos,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id maximo de un Venta en una LinkedList.
 *
 * \param LinkedList* pArray .
 * \return int max retorna el id mas grande.
 *
 */
int venta_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Venta* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			venta_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

/** \brief Obtiene el indice de un Venta mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Venta
 * \param int* indice del Venta buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int venta_getEmpById(LinkedList* pArray,int id,int* indice)
{
	int i;
	Venta* pAuxEmp;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxEmp=ll_get(pArray,i);
			if(!venta_getId(pAuxEmp,&bufferId))
            {
                if(id==bufferId)
                {
                    *indice=i;
                    retorno=0;
                    break;
                }
            }
		}
	}
	return retorno;
}

/** \brief Compara por nombre dos Venta.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
int venta_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	venta_getNombre((Venta*)this1,bufferA);
	venta_getNombre((Venta*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}

int venta_calcularNumeroIntDos(Venta* this)
{
	int retorno=-1;
	int bufferNumeroInt;

	if(this!=NULL)
	{
		venta_getNumeroInt(this,&bufferNumeroInt);
		if(bufferNumeroInt<=120)
		{
			venta_setNumeroIntDos(this,bufferNumeroInt*180);
		}
		else if(bufferNumeroInt>120 && bufferNumeroInt<=160)
		{
			venta_setNumeroIntDos(this,bufferNumeroInt*240);
		}
		else if(bufferNumeroInt>160 && bufferNumeroInt<240)
		{
			venta_setNumeroIntDos(this,bufferNumeroInt*350);
		}
	}
	return retorno;
}

//int fun(int indice,int (*pFun) (void*,void*),float peso)

