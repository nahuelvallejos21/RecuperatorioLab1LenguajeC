
#include <stdio.h>
#include <string.h>
#include "propietarios.h"
#include "PedirDatos.h"
#include "estacionamiento.h"
#define OCUPADO 1
#define LIBRE 0


void filtroCadena(char cadena[],char msj[])
{
  char aux[50];
  int aux2;

  printf("%s",msj);
  fflush(stdin);
  gets(aux);

  aux2 = validarStringABC(aux);
  while(aux2!=1)
  {
   printf("ERROR, el string tiene que ser alfabetico...reingrese:");
   fflush(stdin);
   gets(aux);
   aux2 = validarStringABC(aux);
  }
  strcpy(cadena,aux);
}
void filtroCadena123(char cadena[], char msj[])
{
  char aux[50];
  int aux2;
  printf("%s",msj);
  fflush(stdin);
  gets(aux);
  aux2 = validarString123(aux);
  while(aux2!=1)
  {
    printf("ERROR, el string tiene que ser numerico....reingrese: ");
    fflush(stdin);
    gets(aux);
    aux2 = validarString123(aux);
  }

  strcpy(cadena,aux);
}
void proInit(ePropietario lista[],int tam)
{
   int i;
   for(i=0;i<tam;i++)
   {
     lista[i].idPropietario = 0;
     lista[i].estado = LIBRE;
   }
}

int buscarLibre(ePropietario lista[], int tam)
{
  int retorno = -1;
  int i;

  for(i=0;i<tam;i++)
  {
    if(lista[i].estado == LIBRE)
    {
      retorno = i;
      break;
    }
  }

 return retorno;
}
int pro_siguienteId(ePropietario lista[],int tam)
{
    int retorno = 0;
    int i;
    for(i=0; i<tam; i++)
    {
      if(lista[i].estado == OCUPADO)
      {
        if(lista[i].idPropietario>retorno)
        {
          retorno=lista[i].idPropietario;
        }

      }
     }
   return retorno+1;
}
int pro_buscarPorId(ePropietario lista[] ,int tam, int id)
{
    int retorno = -1;
    int i;
    for(i=0;i<tam;i++)
    {
       if(lista[i].estado == OCUPADO && lista[i].idPropietario == id)
       {
                retorno = i;
                break;
       }
        }

    return retorno;
}
void harcodePro(ePropietario lista[])
{
    int i;
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char apellido[][20]= {"Fernandez","Villareal","Zapata","Hernandez"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"Mitre","Urquiza","Belgrano","Alsina"};

    for(i=0;i<4;i++)
    {
      lista[i].idPropietario = id[i];
      strcpy(lista[i].nombre,nombre[i]);
      strcpy(lista[i].apellido,apellido[i]);
      strcpy(lista[i].tarjeta,tarjeta[i]);
      strcpy(lista[i].direccion,direccion[i]);
      lista[i].estado = OCUPADO;
    }

}
int alta_Pro(ePropietario lista[],int tam)
{
  int index;
  int retorno = -1;

  index = buscarLibre(lista,tam);
  if(index!=-1)
  {
    lista[index].idPropietario = pro_siguienteId(lista,tam);
    filtroCadena(lista[index].nombre,"Ingrese nombre: ");
    filtroCadena(lista[index].apellido,"Ingrese apellido: ");
    pedirString(lista[index].direccion,"Ingrese direccion :");
    filtroCadena123(lista[index].tarjeta,"Ingrese su tarjeta de credito: ");
    lista[index].estado = OCUPADO;
    retorno = 0;
  }

  return retorno;
}

void pro_mostrarUno(ePropietario parametro)
{

     printf("%d\t%s\t%s\t%s\t%s\n",parametro.idPropietario,parametro.nombre,parametro.apellido,parametro.direccion,parametro.tarjeta);

}
void mostrarPropietarios(ePropietario lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
      if(lista[i].estado==OCUPADO)
      {

        pro_mostrarUno(lista[i]);
      }
    }
}
int modificacionPro(ePropietario lista[],int tam)
{
  int aux;
  char rta;
  int i;
  int retorno = -1;



  mostrarPropietarios(lista,tam);
  aux = pedirSoloEntero("Ingrese el id que desea modificar: ");

  for(i=0;i<tam;i++)
  {
    if(aux ==  lista[i].idPropietario&& lista[i].estado == OCUPADO)
    {

      rta = pedirSoloCaracter("Desea modificar la tarjeta de credito de esa ID? s/n ");
      rta = tolower(rta);
      if(rta == 's')
      {
        filtroCadena123(lista[i].tarjeta,"Ingrese su nueva tarjeta de credito: ");
        retorno = 0;
      }
      else
      {
        retorno = 1;
      }
      break;
    }
  }
  return retorno;
}
/*int pro_Baja(ePropietario lista[],int tam,eIngreso automovil[],int tam2)
{
  int retorno = -1;
  int aux2;
  int i;
  int j;
  char rta;

  mostrarPropietarios(lista,tam);
  aux2 = pedirSoloEntero("Ingrese la id a eliminar: ");
  for(i=0;i<tam;i++)
  {
    if(lista[i].idPropietario == aux2 && lista[i].estado == OCUPADO)
    {

      rta = pedirSoloCaracter("Desea elimnar el usuario? s/n ");
      rta = tolower(rta);
      if(rta == 's')
      {

        for(j=0;j<tam2;j++)
        {
          if(lista[i].idPropietario == automovil[j].idPropietario)
          {
            automovil[j].estado = NOESTA;
          }
        }

        lista[i].estado = LIBRE;
        retorno = 1;
      }
      else
      {
        retorno = 0;
      }
     break;
    }
  }
  return retorno;
}*/

