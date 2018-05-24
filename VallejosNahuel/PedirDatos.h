
//CARACTER
/** \brief Pide un caracter y lo valida
 *
 * \param char[] Mensaje a mostrar
 * \param int El min del intervalo
 * \param int  El max del intervalo
 * \return char  Caracter validado
 *
 */
char pedirCaracter(char[],int,int);
/** \brief Valida un caracter
 *
 * \param char Dato a ser validado
 * \param int  El min del intervalo
 * \param int  El max del intervalo
 * \param char[] Mensaje a mostrar
 * \return char Caracter validado
 *
 */
char validarCaracter(char,int,int,char[]);
/** \brief Pide un caracter
 *
 * \param char[] Mensaje a mostrar
 * \return char  Retorna el caracter ingresado
 *
 */
char pedirSoloCaracter(char[]);

//ENTEROS
/** \brief Pide un entero y lo valida
 *
 * \param char[] Mensaje a mostrar
 * \param int Min del intervalo
 * \param int Max del intervalo
 * \return int Entero validado
 *
 */
int pedirEntero(char[],int,int);
/** \brief Valida un entero
 *
 * \param int Dato a validar
 * \param int Min del intervalo
 * \param int Max del intervalo
 * \param char[] Mensaje a mostrar
 * \return int Entero validado
 *
 */
int validarEntero(int,int,int,char[]);
/** \brief Pide solo un entero
 *
 * \param char[] Mensaje a mostrar
 * \return int Retorna un entero
 *
 */
int pedirSoloEntero(char[]);

//FLOTANTES
/** \brief Pide y valida un flotante
 *
 * \param char[] Mensaje a mostrar
 * \param float  Min del intervalo
 * \param float  Max del intervalo
 * \return float Flotante validado
 *
 */
float pedirFlotante(char[],float,float);
/** \brief Valida un dato flotante
 *
 * \param float Dato a validar
 * \param float Min del intervalo
 * \param float Max del intervalo
 * \param char[] Mensaje a mostrar
 * \return float Flotante validado
 *
 */
float validarFlotante(float,float,float,char[]);
/** \brief Pide un flotante
 *
 * \param char[] Mensaje a mostrar
 * \return float Retorna un flotante
 *
 */
float pedirSoloFloat(char[]);
/** \brief Pide una cadena
 *
 * \param char[] String al que se le quiere asignar el valor
 * \param char[] Mensaje a mostrar
 * \return void  No retorna nada
 *
 */
void pedirString(char[],char[]);
/** \brief Verifica si la cadena es alfabetica
 *
 * \param char[] String a validar
 * \return int Retorna 1 si es alfabetico, retorna 0 si no lo es
 *
 */
int validarStringABC(char[]);
int validarString123(char[]);
