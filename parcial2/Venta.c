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
 * \param char* fecha (del Venta a crear).
 * \param char* tipo trabajadas (del Venta a crear).
 * \param char* cantidad (del Venta a crear).
 * \param char* precioStr (del Venta a crear).
 * \return Venta* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Venta* venta_newParametros(  char* idStr,
                             char* fechaStr,
                             char* cuitStr,
                             char* tipoStr,
                             char* cantidadStr,
                             char* precioStr)
{
	Venta* retorno=NULL;
	Venta* pAuxVenta;

	if(idStr!=NULL &&
	   fechaStr!=NULL &&
	   cuitStr!=NULL &&
	   tipoStr!=NULL &&
	   cantidadStr!=NULL &&
	   precioStr!=NULL)
	{

		pAuxVenta=venta_new();
		if(pAuxVenta!=NULL)
		{

			if(	!venta_setIdStr(pAuxVenta,idStr) &&
				!venta_setFecha(pAuxVenta,fechaStr) &&
                !venta_setCuit(pAuxVenta,cuitStr) &&
				!venta_setTipoStr(pAuxVenta,tipoStr) &&
				!venta_setCantidadStr(pAuxVenta,cantidadStr) &&
                !venta_setPrecioStr(pAuxVenta,precioStr))
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

/** \brief Set del fecha en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* fecha del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setFecha(Venta* this,char* fecha)
{
	int retorno = -1;
    if(this != NULL && isValidFecha(fecha))
    {
        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el fecha de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* fecha del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getFecha(Venta* this,char* fecha)
{
	int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        strncpy(fecha,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del cuit en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cuit del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCuit(Venta* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && isValidCUIT(cuit))
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}
/** \brief Obtiene el apeliido de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cuit del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCuit(Venta* this,char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strncpy(cuit,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de tipo trabajadas en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int tipo trabajadas del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setTipo(Venta* this,int tipo)
{
	int retorno = -1;
    if(this != NULL && isValidInt(tipo,1000000,0))
    {
        this->tipo=tipo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene tipo trabajadas de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* tipo del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getTipo(Venta* this,int* tipo)
{
	int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        *tipo = this->tipo;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set de precio trabajadas en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param float precio trabajadas del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setPrecio(Venta* this,float precio)
{
	int retorno = -1;
    if(this != NULL && isValidFloat(precio,1000000,0))
    {
        this->precio=precio;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene precio trabajadas de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param float* precio del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getPrecio(Venta* this,float* precio)
{
	int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}
/** \brief Set del cantidad en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int cantidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCantidad(Venta* this,int cantidad)
{
	int retorno = -1;
    if(this != NULL && isValidInt(cantidad,1000000,0))
    {
        this->cantidad=cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el cantidad de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param int* cantidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCantidad(Venta* this,int* cantidad)
{
	int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
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

/** \brief Set de tipo trabajadas en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* tipo del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setTipoStr(Venta* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo!=NULL)
    {
        if(strcmp(tipo,"4R_10x15")==0)
        {
            retorno = venta_setTipo(this,0);
        }
        if(strcmp(tipo,"5R_13x18")==0)
        {
            retorno = venta_setTipo(this,1);
        }
        if(strcmp(tipo,"6R_15x20")==0)
        {
            retorno = venta_setTipo(this,2);
        }
        if(strcmp(tipo,"8R_20x25")==0)
        {
            retorno = venta_setTipo(this,3);
        }
        if(strcmp(tipo,"POLAROID_11x9")==0)
        {
            retorno = venta_setTipo(this,4);
        }
        if(strcmp(tipo,"POLAROID_10x10")==0)
        {
            retorno = venta_setTipo(this,5);
        }
    }
    return retorno;
}

/** \brief Obtiene tipo trabajadas en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* tipo del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getTipoStr(Venta* this, char* tipo)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && tipo != NULL)
    {
        venta_getTipo(this,&bufferInt);
        sprintf(tipo,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
/** \brief Set de precio trabajadas en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* precio del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setPrecioStr(Venta* this, char* precio)
{
    int retorno = -1;
    if(this != NULL && precio!=NULL)
    {
        retorno = venta_setPrecio(this,atof(precio));
    }
    return retorno;
}

/** \brief Obtiene precio trabajadas en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* precio del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getPrecioStr(Venta* this, char* precio)
{
    int retorno = -1;
    float bufferFloat;
    if(this != NULL && precio != NULL)
    {
        venta_getPrecio(this,&bufferFloat);
        sprintf(precio,"%f",bufferFloat);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del cantidad en string en un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cantidad del Venta
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int venta_setCantidadStr(Venta* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad!=NULL)
    {
        retorno = venta_setCantidad(this,atoi(cantidad));
    }
    return retorno;
}

/** \brief Obtiene el cantidad en string de un Venta.
 *
 * \param Venta* Puntero del Venta
 * \param char* cantidad del Venta
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int venta_getCantidadStr(Venta* this, char* cantidad)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && cantidad != NULL)
    {
        venta_getCantidad(this,&bufferInt);
        sprintf(cantidad,"%d",bufferInt);
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

/** \brief Compara por fecha dos Venta.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
int venta_compararPorFecha(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	venta_getFecha((Venta*)this1,bufferA);
	venta_getFecha((Venta*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}


int esMayorA(Venta* pVenta)
{
    int cantidad;
    float precio;
    float total;
    if(pVenta!=NULL)
    {
        venta_getCantidad(pVenta,&cantidad);
        venta_getPrecio(pVenta,&precio);
        total=precio*cantidad;
        if(total>150)
        {
            return 1;
        }
    }
    return 0;
}

int esMayorB(Venta* pVenta)
{
    int cantidad;
    float precio;
    float total;
    if(pVenta!=NULL)
    {
        venta_getCantidad(pVenta,&cantidad);
        venta_getPrecio(pVenta,&precio);
        total=precio*cantidad;
        if(total>300)
        {
            return 1;
        }
    }
    return 0;
}
int esPolaroid(Venta* pVenta)
{
    int tipo;
    if(pVenta!=NULL)
    {
        venta_getTipo(pVenta,&tipo);
        if( tipo==4 ||
            tipo==5)
        {
            return 1;
        }
    }
    return 0;
}
//int fun(int indice,int (*pFun) (void*,void*),float peso)


