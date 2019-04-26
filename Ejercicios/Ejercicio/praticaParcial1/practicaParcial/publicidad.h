#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct{
    int idPublicidad;
    int isEmpty;
    char cuit[50];
    int dias;
    char archivo[20];
    int idPantalla;
}Publicidad;



/** \brief Inicializa los elementos del array
 * \param arrayPantalla y limiteArray
 * \return 0 todo bien -1 error
 */

int publicidad_init(Publicidad* arrayPublicidad,int limite);


/** \brief Muestra todas las publicidades disponibles
 * \param arrayPublicidades
 * \param limite int cantidad de elementos del array
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicidad_mostrar(Publicidad* arrayPublicidad,int limite);

/** \brief Da de alta una publicidad
 * \param arrayPublicidades
 * \param int indice del array
 * \param limite int cantidad de elementos del array
 * \param id de la pantalla
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int publicidad_alta(Publicidad* arrayPublicidad,int limite,int idPantalla);


/** \brief Busca por id un elemento en el array
 * \param array Publicidad* array de publicidad
 * \param limite int cantidad de elementos del array
 * \param id id de la publicidad a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */

int publicidad_buscarPorId(Publicidad* arrayPublicidad,int limite,int id);

int publicidad_imprimirPublicidadCuit(Publicidad* arrayPublicidad,int limite,Pantalla* arrayPantalla,int limite2,char* cuitVacio);
int publicidad_buscarPublicidadPorIdyCuit(Publicidad* arrayPublicidad,int limite,int idPantalla,char* cuit);
int publicidad_borrarPublicidad(Publicidad* arrayPublicidad,int limite,int indicePublicidad);
int publicidad_modificarIndice(Publicidad* arrayPublicidad,int indicePublicidad,int limite);
int publicidad_mostrarIndices(Publicidad* arrayPublicidad,int limite, Pantalla* arrayPantalla, int limite2);
int publicidad_calcularFacturaciones(Publicidad* arrayPublicidad,int limite,Pantalla* arrayPantalla,int limite2);
#endif // PUBLICIDAD_H_INCLUDED
