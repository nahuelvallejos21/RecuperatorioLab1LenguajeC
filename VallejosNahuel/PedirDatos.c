
#include "stdio.h"
#include "PedirDatos.h"

//CARACTER
char pedirCaracter(char mensaje[],int min,int max)
{
  char caracter;
  printf("Ingrese %s",mensaje);
  caracter = getche();
  caracter = validarCaracter(caracter,min,max,mensaje);

  return caracter;

}
char validarCaracter(char dato,int min,int max,char mensaje[])
{
  while(dato<min || dato>max)
  {
    printf("\nError!...Reingrese %s",mensaje);
    dato = getche();
  }

  return dato;

}
char pedirSoloCaracter(char mensaje[])
{
  char caracter;
  printf("%s",mensaje);
  caracter = getche();

  return caracter;
}
//ENTERO
int pedirEntero(char mensaje[], int min,int max)
{
  int numero;
  printf("Ingrese %s",mensaje);
  scanf("%d",&numero);

  numero = validarEntero(numero,min,max,mensaje);

  return numero;
}
int validarEntero(int dato,int min,int max,char mensaje[])
{
  while(dato <min || dato>max)
  {
      printf("Error!: Reingrese %s",mensaje);
      scanf("%d",&dato);
  }

  return dato;

}
int pedirSoloEntero(char mensaje[])
{
   int numero;
   printf("%s",mensaje);
   scanf("%d",&numero);

   return numero;
}

//FLOTANTES
float pedirFlotante(char mensaje[],float min,float max)
{
   float numero;
   printf("Ingrese %s",mensaje);
   scanf("%f",&numero);

   numero = validarFlotante(numero,min,max,mensaje);

   return numero;
}
float validarFlotante(float dato,float min,float max,char mensaje[])
{
  while(dato <min || dato>max)
  {
    printf("Error!...Reingrese %s",mensaje);
    scanf("%f",&dato);

  }

  return dato;
}
float pedirSoloFloat(char mensaje[])
{
  float dato;
  printf("%s",mensaje);
  scanf("%f",&dato);

  return dato;
}
void pedirString(char cadena[],char msj[])
{
  char aux[100];
  printf("%s",msj);
  fflush(stdin);
  gets(aux);

  strcpy(cadena,aux);
}
int validarStringABC(char cadena[])
{
  int retorno;
  int i =0;
  int contador = 0;

  while(cadena[i])
  {
    if(isalpha(cadena[i]))
    {
      contador++;
    }

    i++;
  }
  if(contador == strlen(cadena))
  {
    retorno = 1;
  }
  else
  {
    retorno = 0;
  }

 return retorno;
}
int validarString123(char cadena[])
{
  int retorno;
  int i =0;
  int contador = 0;

  while(cadena[i])
  {
    if(!isalpha(cadena[i]))
    {
      contador++;
    }

    i++;
  }
  if(contador == strlen(cadena))
  {
    retorno = 1;
  }
  else
  {
    retorno = 0;
  }

 return retorno;













}
