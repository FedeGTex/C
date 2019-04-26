#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
}Pantalla;


/** \brief Inicializa los elementos del array
 * \param arrayPantalla y limiteArray
 * \return 0 todo bien -1 error
 */
int pantalla_init(Pantalla* arrayPantalla,int limite);

/** \brief Muestra todas las pantallas disponibles
 * \param arrayPantallas
 * \param limite int cantidad de elementos del array
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
 int pantalla_mostrar(Pantalla* arrayPantalla,int limite);


 /** \brief Carga una pantalla
 * \param arrayPantallas
 * \param limite int cantidad de elementos del array
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
 int pantalla_alta(Pantalla* arrayPantalla,int limite);

 /** \brief Busca por id un elemento en el array
 * \param array Pantalla* array de pantalla
 * \param limite int cantidad de elementos del array
 * \param id id de la pantalla a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */

 int pantalla_buscarPorId(Pantalla* arrayPantalla,int limite,int id);

 /** \brief Modificacion de una pantalla
 * \param array Pantalla* array de pantallas
 * \param limite int cantidad de elementos del array
 * \param id id de la pantalla a modificar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 */
 int pantalla_modificar(Pantalla* arrayPantalla,int limite,int id);

 /** \brief Baja de una pantalla
 * \param array Pantalla* array de pantallas
 * \param limite int cantidad de elementos del array
 * \param id id de la pantalla a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 */
 int pantalla_baja(Pantalla* arrayPantalla,int limite,int id);

 /** \brief Da de alta pantallas sin necesidad del ingreso del usuario
 * \param array Pantallas* array de pantalla
 * \param limite int cantidad de elementos del array
 * \param char* nombre
 * \param char* direccion
 * \param int tipo
 * \param float precio
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */

 int pantalla_altaForzada(Pantalla* arrayPantalla,int limite,char* nombre,char* direccion,float precio,int tipo);


 /** \brief Muestra un indice de pantalla
 * \param arrayPantallas
 * \param limite int cantidad de elementos del array
 * \param indice
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
 int pantalla_mostrarUnIndice(Pantalla* arrayPantalla,int limite,int indice);

#endif // PANTALLA_H_INCLUDED
