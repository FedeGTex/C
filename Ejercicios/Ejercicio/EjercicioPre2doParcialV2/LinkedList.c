#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
static void* startIter(LinkedList* this);
static void* nextNodeIter(LinkedList* this);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    int size=ll_len(this);
    if(this != NULL && nodeIndex>=0 && nodeIndex < size)
    {
        pNode=this->pFirstNode;
        if(pNode!=NULL)
        {
            for(i=0;i<size;i++)
            {
               if(i==nodeIndex)
               {
                    break;
               }
               else
               {
                    pNode=pNode->pNextNode;
               }
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode=malloc(sizeof(Node));
    Node* pNode;
    int size=ll_len(this);
    pNewNode->pElement=pElement;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=size)
    {
        if(nodeIndex==0)
        {
            pNewNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNewNode;
            this->size++;
            returnAux=0;
        }
        else
        {
            pNode=getNode(this,nodeIndex-1);
            pNewNode->pNextNode=pNode->pNextNode;
            pNode->pNextNode=pNewNode;
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && !addNode(this,this->size,pElement))
    {
        returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this!=NULL && index>=0 && index<=this->size)
    {
        pNode=getNode(this,index);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this!=NULL && index>=0 && index<this->size)
    {
        returnAux=0;
        pNode=getNode(this,index);
        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNode2;
    int size=ll_len(this);
    if(this!=NULL && index>=0 && index<size)
    {
        if(index>0)
        {
            pNode=getNode(this,index);
            pNode2=getNode(this,index-1);
            pNode2->pNextNode=pNode->pNextNode;
            free(pNode);
            this->size--;
            returnAux=0;
        }
        else if(index==0)
        {
            pNode=this->pFirstNode;
            this->pFirstNode=pNode->pNextNode;
            this->size--;
            free(pNode);
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int size;
    int i;
    if(this!=NULL)
    {
        size=ll_len(this);
        returnAux=0;
        for(i=0;i<size;i++)
        {
            ll_remove(this,i);
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_clear(this)==0)
        {
            free(this);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);
    Node* pNode;
    if(this!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pNode=getNode(this,i);
            if(pNode!=NULL && pElement==pNode->pElement)
            {
                returnAux=i;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int size=ll_len(this);
    if(this!=NULL)
    {
        if(size>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int size=ll_len(this);
    if(this!=NULL && index>=0 && index<=size)
    {
        if(addNode(this,index,pElement)==0 && this->size>size)
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int size=ll_len(this);
    void* pElement=ll_get(this,index);
    if(this!=NULL && index>=0 && index<size)
    {
        if(ll_remove(this,index)==0)
        {
            returnAux=pElement;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);
    void* pElementAux;
    if(this!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pElementAux=ll_get(this,i);
            if(pElementAux==pElement)
            {
                returnAux=1;
                break;
            }
        }
        if(i==size)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int size1=ll_len(this);
    int size2=ll_len(this2);
    void* pElement1;
    void* pElement2;
    int cantidadIguales=0;
    if(this!=NULL && this2!=NULL)
    {
        for(i=0;i<size1;i++)
        {
            pElement1=ll_get(this,i);
            pElement2=ll_get(this2,i);
            if(pElement1==pElement2)
            {
                cantidadIguales++;
            }
        }
        if(cantidadIguales==size1 && size1==size2)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    cloneArray=ll_newLinkedList();
    void* pElement;
    int i;
    int size=ll_len(this);
    if(this!=NULL && from>=0 && from<size && to>from && to<=size)
    {
        for(i=from;i<to;i++)
        {
            pElement=ll_get(this,i);
            if(ll_add(cloneArray,pElement)==0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray=NULL;
                break;
            }
        }
    }
    else
    {
        free(cloneArray);
        cloneArray=NULL;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    cloneArray=ll_newLinkedList();
    void* pElement;
    int i;
    int size=ll_len(this);
    if(this!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pElement=ll_get(this,i);
            if(ll_add(cloneArray,pElement)==0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray=NULL;
                break;
            }
        }
    }
    else
    {
        free(cloneArray);
        cloneArray=NULL;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int size=ll_len(this);
    void* thisA;
    void* thisB;
    int flagSwap;
    int returnOrderValue;
    if(this!=NULL && size>0 && pFunc!=NULL && (order==0 || order==1))
    {
        do
        {
            flagSwap=0;
            for(i=0;i<size-1;i++)
            {
                thisA=ll_get(this,i);
                thisB=ll_get(this,i+1);
                if(thisA!=NULL && thisB!=NULL)
                {
                    returnOrderValue=pFunc(thisA,thisB);
                    if((returnOrderValue==-1 && order==0) || (returnOrderValue==1 && order==1))
                    {
                        flagSwap=1;
                        ll_set(this,i,thisB);
                        ll_set(this,i+1,thisA);
                    }
                }
            }
        }while(flagSwap==1);
        returnAux=0;
    }
    return returnAux;

}


/** \brief devuelve el puntero al primer nodo de la lista
 * \param pList LinkedList* Puntero a la lista
 * \return void* Retorna NULL si la lista esta vacia o no existe la lista
 */
static void* startIter(LinkedList* this)
{
    if(this!= NULL)
    {
        this->pNodeIter=this->pFirstNode;
        return this->pNodeIter;
    }
    return NULL;
}
/** \brief devuelve el puntero al prioximo nodo de la lista
 * \param pList LinkedList* Puntero a la lista
 * \return void* Retorna NULL si no hay mas nodos en lista o no existe la lista
 */
static void* nextNodeIter(LinkedList* this)
{
    Node* pNode;
    if(this!=NULL)
    {
        pNode=this->pNodeIter;
        this->pNodeIter=pNode->pNextNode;
        return this->pNodeIter;
    }
    return NULL;
}
/** \brief recorre la lista pasada por parametros y le pasa los elementos a una funcion
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc* puntero a FUNCION
 * \return void
 */
int ll_map(LinkedList* this,int(*pFunc)(void*))
{
    Node* pNode;
    void* pElement;
    int returnAux=-1;
    if(this != NULL && pFunc != NULL)
    {
        returnAux=0;
        startIter(this);
        do
        {
            pNode=nextNodeIter(this);
            if(pNode == NULL)
            {
                break;
            }
            pElement=pNode->pElement;
            if(pFunc(pElement)==0)
            {
                returnAux=0;
            }
        }while(pNode!=NULL);
    }
    return returnAux;
}

/*Achica la lista original segun el criterio
Hago remove del elemento

void* ll_reduce(LinkedList* this,void(*pFunc)(void*))
{
    void* thisA;
    if(this!=NULL && pFunc!=NULL)
    {

        thisA=startIter(this);
        if(thisA!=NULL)
        {
           do{
                if(pFunc(thisA))
                {
                    ll_remove(this,thisA);
                }
                thisA=nextNodeIter(this);
            }while(thisA!=NULL);
        }
    }
    return this;
}
*/

/** \brief recorre la lista pasada por parametros y genera una nueva segun las
            condiciones de la funcion recibida por parametros
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc* puntero a FUNCION
 * \return void* puntero a la nueva lista filtrada
 */
void* ll_filter(LinkedList* this,int(*pFunc)(void*))
{
    Node* pNode;
    LinkedList* pLink=ll_newLinkedList();
    if(this!= NULL && pFunc != NULL && pLink!=NULL)
    {
        pNode=startIter(this);
        if(pNode!=NULL)
        {
            do{
                if(pFunc(pNode->pElement))
                {
                    ll_add(pLink,pNode->pElement);
                }
                pNode=nextNodeIter(this);
            }while(pNode!=NULL);
        }
    }
    return pLink;
}

