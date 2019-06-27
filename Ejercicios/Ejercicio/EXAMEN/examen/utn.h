/** \brief Pide al usuario el ingreso de un entero lo valida y lo guarda en una variable
            por paramatro
 * \param int* pEdad puntero donde guardar lo obtenido
 * \param int reintentos cantidad de reintentos
 * \param char* msg Mensaje a mostrar al usuario
 * \param char* msgError Mensaje de error
 * \param int max numero max permitido
 * \param int min numero min permitido
 * \return 0 todo bien -1 error
 */
int utn_getEntero(int*pEdad,int reintentos,char* msg,char*msgError,int max,int min);

/** \brief Imprime un array
 * \param int* pArray puntero a la primera posicion del array
 * \param int limite len array
 * \return 0 todo bien -1 error
 */
int utn_mostrarArray(int * pArray,int limite);

/** \brief Calcula el nuemero maximo de un array
 * \param int* pArray puntero a la primera posicion del array
 * \param int len tamaño del array
 * \param int* max variable a guardar el resultado
 * \return 0 todo bien -1 error
 */
int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo);

/** \brief Inicia un array poniendo un valor
 * \param int* pArray puntero a la primera posicion del array
 * \param int limite len array
 * \param int valor valor a colocar
 * \return 0 todo bien -1 error
 */
int utn_initArray(int * pArray,int limite,int valor);

/** \brief carga un array con numeros aleatorios
 * \param int* pArray puntero a la primera posicion del array
 * \param int len tamaño del array
 * \param int min numero minimo
 * \param int max numero maximo
 * \return 0 todo bien -1 error
 */
int utn_cargaNumeroAleatoriosEnArrays(int* pArray,int len,int min, int max);

/** Calcula el promedio de un array de enteros:
@parametros
pArray: puntero al array
limite: numero de indices del array
promedio: puntero a la variable donde cargar el resultado
valorOmision: numero el cual me indique que el indice esta vacio,para omitir su suma
return: retorna -1 si el array esta cargado solo de valores de omision, 0 is ok
*/
int utn_promedioArray(int*pArray,int limite,float *promedio,int valorOmision);

/** Ordenar array de mayor a menor o de mayor a menor
@parametros
pArray: puntero al array
limite: limite del array
flagMaxMin: colocar 1 para ordenar de menor a mayor o 0 de mayor a menor
*/
int utn_ordenarArray(int *pArray,int limite,int flagMaxMin);

/** \brief Pide al usuario el ingreso de un flotante lo valida y lo guarda en una variable
            por paramatro
 * \param int* pFloat puntero donde guardar lo obtenido
 * \param int reintentos cantidad de reintentos
 * \param char* msg Mensaje a mostrar al usuario
 * \param char* msgError Mensaje de error
 * \param int max numero max permitido
 * \param int min numero min permitido
 * \return 0 todo bien -1 error
 */
int utn_getFloat(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);

/** \brief Pide al usuario el ingreso de un nombre o apellido lo valida y lo guarda en una variable
            por paramatro
 * \param char* pBuffer puntero donde guardar lo obtenido
 * \param int limite tamaño max de caracteres
 * \param int reintentos cantidad de reintentos
 * \param char* msg Mensaje a mostrar al usuario
 * \param char* msgError Mensaje de error
 * \return 0 todo bien -1 error
 */
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/** \brief Ordena un array por insercion
 * \param int* pArray puntero a la primera posicion del array
 * \param int limite len del array
 * \return 0 todo bien -1 error
 */
int ordenarInsertion(int* pArray,int limite);

/** \brief Pide al usuario cadena de caracteres y lo guarda en una variable
 * \param int* pBuffer variable para guardar el ingreso
 * \param int limite tamaño max de caracteres
 * \return 0 todo bien -1 error
 */
int getString(char* pBuffer,int limite);

/** \brief Pide al usuario cadena de caracteres y lo guarda en una variable
 * \param int* pBuffer variable para guardar el ingreso
 * \param char* msg Mensaje a mostrar al usuario
 * \param int limite tamaño max de caracteres
 * \return 0 todo bien -1 error
 */
int utn_getLetrasYNumeros(char* pBuffer,int limite,char* msj);

/** \brief Pide al usuario el ingreso de un email lo valida y lo guarda en una variable
            por paramatro
 * \param char* pBuffer puntero donde guardar lo obtenido
 * \param int limite tamaño max de caracteres
 * \param int reintentos cantidad de reintentos
 * \param char* msg Mensaje a mostrar al usuario
 * \param char* msgError Mensaje de error
 * \return 0 todo bien -1 error
 */
int utn_getEmial(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/** \brief Pide al usuario el ingreso de un cuit lo valida y lo guarda en una variable
            por paramatro
 * \param char* pBuffer puntero donde guardar lo obtenido
 * \param int limite tamaño max de caracteres
 * \param int reintentos cantidad de reintentos
 * \param char* msg Mensaje a mostrar al usuario
 * \param char* msgError Mensaje de error
 * \return 0 todo bien -1 error
 */
int utn_getCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/** \brief Pide al usuario un flotante y lo guarda en una variable
 * \param int* pBuffer variable para guardar el ingreso
 * \return 0 todo bien -1 error
 */
int getFloat(float*pBuffer);

/** \brief Pide al usuario el ingreso por teclado y lo guarda en una variable
 * \param int limite tamaño max de caracteres
 * \return 0 todo bien -1 error
 */
int getString(char* bufferString,int limite);

/** \brief Valida un flotante de una cadena de caracteres
 * \param char* pBuffer cadena a validar
 * \return 0 todo bien -1 error
 */
int isFloat(char* pBuffer);

/** \brief Pide al usuario un entero y lo guarda en una variable
 * \param int* pBuffer variable para guardar el ingreso
 * \return 0 todo bien -1 error
 */
int getInt(int*pBuffer);

/** \brief Valida un entero de una cadena de caracteres
 * \param char* pBuffer cadena a validar
 * \return 0 todo bien -1 error
 */
int isInt(char *pBuffer);

/** \brief Valida un nombre o apellido de una cadena de caracteres
 * \param char* pBuffer cadena a validar
 * \return 0 todo bien -1 error
 */
int isLetras(char*pBuffer);

/** \brief Valida un email de una cadena de caracteres
 * \param char* pBuffer cadena a validar
 * \return 0 todo bien -1 error
 */
int isEmail(char* pBuffer);

/** \brief Valida un cuit de una cadena de caracteres
 * \param char* pBuffer cadena a validar
 * \return 0 todo bien -1 error
 */
int isCuit(char* pBuffer);
