#include <stdio.h>
#include <string.h>
#include "PedirDatos.h"
#include "propietarios.h"
#include "estacionamiento.h"
#define ESTACIONADO 0
#define NOESTA -1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int buscarLibreEst(eIngreso automovil[],int tam)
{
  int retorno = -1;
  int i;

  for(i=0;i<tam;i++)
  {
    if(automovil[i].estado == NOESTA && automovil[i].estadia == 0)
    {
      retorno = i;
      break;
    }
  }
  return retorno;
}
void estacionamientoInic(eIngreso automovil[],int tam)
{
   int i;
   for(i=0;i<tam;i++)
   {
     automovil[i].idAutomovil = 0;
     automovil[i].estado = NOESTA;
     automovil[i].estadia = 0;
   }
}
int est_siguienteId(eIngreso automovil[],int tam)
{
    int retorno = 0;
    int i;
    for(i=0; i<tam; i++)
    {
      if(automovil[i].estado == ESTACIONADO)
      {
        if(automovil[i].idAutomovil>retorno)
        {
          retorno=automovil[i].idAutomovil;
        }

      }
   }
  return retorno+1;
}
void harcodeEST(eIngreso automovil[])
{

    int i;
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    for(i=0;i<10;i++)
    {
      automovil[i].idAutomovil = id[i];
      automovil[i].idPropietario = propietario[i];
      strcpy(automovil[i].patente,patente[i]);
      automovil[i].marca = marca[i];
      automovil[i].estado = ESTACIONADO;
    }

}
void mostrarAutos(eIngreso automovil[],int tam,ePropietario lista[],int tam2)
{
  int i,j;
  for(i=0;i<tam;i++)
  {
    for(j=0;j<tam2;j++)
    {
      if(automovil[i].idPropietario==lista[j].idPropietario && lista[j].estado==1 && automovil[i].estado==ESTACIONADO)
      {
        if(automovil[i].marca == ALPHA_ROMEO)
        {
          printf("%d\t%s\t%s\t%s\t%s\n",automovil[i].idAutomovil,"Alpha Romeo",automovil[i].patente,lista[j].nombre,lista[j].apellido);
        }
        if(automovil[i].marca == FERRARI)
        {
          printf("%d\t%s\t%s\t%s\t%s\n",automovil[i].idAutomovil,"Ferrari",automovil[i].patente,lista[j].nombre,lista[j].apellido);
        }
        if(automovil[i].marca == AUDI)
        {
          printf("%d\t%s\t%s\t%s\t%s\n",automovil[i].idAutomovil,"Audi",automovil[i].patente,lista[j].nombre,lista[j].apellido);
        }
        if(automovil[i].marca == OTROS)
        {
          printf("%d\t%s\t%s\t%s\t%s\n",automovil[i].idAutomovil,"Otros",automovil[i].patente,lista[j].nombre,lista[j].apellido);
        }
      }
    }
  }
}
int pro_Baja(ePropietario lista[],int tam,eIngreso automovil[],int tam2)
{
  int retorno = -1;
  int aux2;
  int i;
  int j;
  char rta;
  int time;
  int total = 0;
  int flag = 0;

  mostrarPropietarios(lista,tam);
  aux2 = pedirSoloEntero("Ingrese la id a eliminar: ");
  for(i=0;i<tam;i++)
  {
    if(lista[i].idPropietario == aux2 && lista[i].estado == 1)
    {

      rta = pedirSoloCaracter("Desea elimnar el usuario? s/n ");
      rta = tolower(rta);
      if(rta == 's')
      {

        time = devolverHorasEstadia();
        for(j=0;j<tam2;j++)
        {
          if(lista[i].idPropietario == automovil[j].idPropietario && automovil[j].estado == ESTACIONADO)
          {
            if(automovil[j].marca == ALPHA_ROMEO)
            {
              automovil[j].estadia = 150*time;
              total = total+automovil[j].estadia;
              automovil[j].estado = NOESTA;
            }
            if(automovil[j].marca == FERRARI)
            {
              automovil[j].estadia = 175*time;
              total = total+automovil[j].estadia;
              automovil[j].estado = NOESTA;
            }
            if(automovil[j].marca == AUDI)
            {
              automovil[j].estadia = 200*time;
              total = total+automovil[j].estadia;
              automovil[j].estado = NOESTA;
            }
            if(automovil[j].marca == OTROS)
            {
              automovil[j].estadia = 250*time;
              total = total+automovil[j].estadia;
              automovil[j].estado = NOESTA;
            }
          }
          flag = 1;
        }
        if(flag==1)
        {
          printf("\nEl importe a pagar es: %d\n",total);
        }
        else
        {
          printf("Este propietario no tiene autos estacionados\n");
        }

        lista[i].estado = 0;
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
}
void ingresoAuto(eIngreso automovil[],int tam,ePropietario lista[],int tam2)
{
  int index;
  int encontro;
  int aux;
  mostrarPropietarios(lista,tam2);
  printf("MARCAS\n");
  printf("1. Alpha romeo\n");
  printf("2. Ferrari\n");
  printf("3. Audi\n");
  printf("4. Otros\n");
  aux = pedirSoloEntero("Ingrese ID del propietario que desea estacionar auto: ");
  encontro = pro_buscarPorId(lista,tam2,aux);

  if(encontro!=-1)
  {
    index = buscarLibreEst(automovil,tam);
    if(index!=-1)
    {
      automovil[index].idPropietario = lista[encontro].idPropietario;
      automovil[index].idAutomovil = est_siguienteId(automovil,tam);
      automovil[index].marca = pedirEntero("la ID de la marca: ",1,4);
      pedirString(automovil[index].patente,"Ingrese patente: ");
      automovil[index].estado = ESTACIONADO;
      printf("Auto estacionado.........\n");

    }
    else
    {
      printf("No hay espacio para mas autos......\n");
    }
  }
  else
  {
    printf("ID inexistente......\n");
  }

}
int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
void estadiaAuto(eIngreso automovil[],int tam,ePropietario lista[],int tam2)
{

   int encontro;
   int aux;
   int time;
   int i;
   int flag =0;


   mostrarPropietarios(lista,tam2);
   aux = pedirSoloEntero("Ingrese el ID del propietario para el ticket: ");
   encontro = pro_buscarPorId(lista,tam2,aux);

   if(encontro!=-1)
   {

    time = devolverHorasEstadia();
    for(i=0;i<tam;i++)
    {
      if(automovil[i].idPropietario == lista[encontro].idPropietario && automovil[i].estado== ESTACIONADO)
      {
        if(automovil[i].marca == ALPHA_ROMEO)
        {
          automovil[i].estadia = 150*time;
          printf("*********************************************\n");
          printf("TICKET\n");
          printf("Propietario: %s %s\n",lista[encontro].nombre,lista[encontro].apellido);
          printf("Patente: %s\n",automovil[i].patente);
          printf("Marca: %s\n","Alpha Romeo");
          printf("Total estadia: %.2f\n",automovil[i].estadia);
          printf("*********************************************\n");
          automovil[i].estado = NOESTA;
        }
        if(automovil[i].marca == FERRARI)
        {
          automovil[i].estadia = 175*time;
          printf("*********************************************\n");
          printf("TICKET\n");
          printf("Propietario: %s %s\n",lista[encontro].nombre,lista[encontro].apellido);
          printf("Patente: %s\n",automovil[i].patente);
          printf("Marca: %s\n","Ferrari");
          printf("Total estadia: %.2f\n",automovil[i].estadia);
          printf("*********************************************\n");
          automovil[i].estado = NOESTA;
        }
        if(automovil[i].marca == AUDI)
        {
          automovil[i].estadia = 200*time;
          printf("*********************************************\n");
          printf("TICKET\n");
          printf("Propietario: %s %s\n",lista[encontro].nombre,lista[encontro].apellido);
          printf("Patente: %s\n",automovil[i].patente);
          printf("Marca: %s\n","Audi");
          printf("Total estadia: %.2f\n",automovil[i].estadia);
          printf("*********************************************\n");
          automovil[i].estado = NOESTA;
        }
        if(automovil[i].marca == OTROS)
        {
          automovil[i].estadia = 250*time;
          printf("*********************************************\n");
          printf("TICKET\n");
          printf("Propietario: %s %s\n",lista[encontro].nombre,lista[encontro].apellido);
          printf("Patente: %s\n",automovil[i].patente);
          printf("Marca: %s\n","Otros");
          printf("Total estadia: %.2f\n",automovil[i].estadia);
          printf("*********************************************\n");
          automovil[i].estado = NOESTA;
        }
        flag = 1;
      }
    }
    if(flag == 0)
    {
      printf("Este usuario no tiene ningun auto estacionado\n");
    }
   }
   else
   {
    printf("ID inexistente\n");
   }
}
void recaudacionEst(eIngreso automovil[],int tam)
{
  int i;
  float total = 0;
  int flag = 0;

  for(i=0;i<tam;i++)
  {
    if(automovil[i].estado == NOESTA && automovil[i].estadia >0)
    {
      //printf("Estadia: %.2f\n",automovil[i].estadia);
      total = total + automovil[i].estadia;
      flag = 1;
    }
  }
  if(flag == 1)
  {
    printf("La recaudacion total del estacionamiento es: %.2f\n",total);
  }
  else
  {
    printf("No hay autos que hayan cumplido la estadia en el EST\n");
  }
}
void recaudacionMarca(eIngreso automovil[],int tam)
{
  float audiT =0;
  float alphaT=0;
  float ferrariT=0;
  float otrosT=0;
  int i;
  int flag=0;

  for(i=0;i<tam;i++)
  {
    if(automovil[i].estadia >0)
    {
      if(automovil[i].marca == ALPHA_ROMEO)
      {
        alphaT = alphaT + automovil[i].estadia;
      }
      if(automovil[i].marca == FERRARI)
      {
        ferrariT = ferrariT + automovil[i].estadia;
      }
      if(automovil[i].marca == AUDI)
      {
        audiT = audiT + automovil[i].estadia;
      }
      if(automovil[i].marca == OTROS)
      {
        otrosT = otrosT + automovil[i].estadia;
      }

    flag = 1;

   }
  }
  if(flag==1)
  {
    printf("Recaudacion total (ALPHA ROMEO): %.2f\n",alphaT);
    printf("Recaudacion total (FERRARI): %.2f\n",ferrariT);
    printf("Recaudacion total (AUDI): %.2f\n",audiT);
    printf("Recaudacion total (OTROS): %.2f\n",otrosT);
  }
  else
  {
   printf("No hay autos que hayan cumplido la estadia en el EST\n");
  }
}
void autosPro(ePropietario cliente[],int tam,eIngreso automovil[],int tam2)
{
  int aux;
  int encontro;
  int i;
  int flag = 0;
  mostrarPropietarios(cliente,tam);
  aux = pedirSoloEntero("Ingrese la ID del propietario: ");
  encontro = pro_buscarPorId(cliente,tam,aux);

  if(encontro!= -1)
  {
    printf("PROPIETARIO: %s %s\n",cliente[encontro].nombre,cliente[encontro].apellido);
    for(i=0;i<tam2;i++)
    {
      if(automovil[i].idPropietario == cliente[encontro].idPropietario)
      {
        if(automovil[i].marca == ALPHA_ROMEO)
        {
          printf("%s\t%s\n",automovil[i].patente,"Alpha Romeo");
        }
        if(automovil[i].marca == FERRARI)
        {
          printf("%s\t%s\n",automovil[i].patente,"Ferrari");
        }
        if(automovil[i].marca == AUDI)
        {
          printf("%s\t%s\n",automovil[i].patente,"Audi");
        }
        if(automovil[i].marca == OTROS)
        {
          printf("%s\t%s\n",automovil[i].patente,"Otros");
        }
        flag = 1;
      }
    }
    if(flag==0)
    {
      printf("Este propietario no tiene ningun auto estacionado\n");
    }
  }
  else
  {
    printf("ID inexistente\n");
  }
}
void propietariosAudi(ePropietario cliente[],int tam,eIngreso automovil[],int tam2)
{
 int i,j;
 int max = 0;
 int flag = 0;
 printf("PROPIETARIOS CON AUTOS MARCA AUDI\n");
 for(i=0;i<tam;i++)
 {
   for(j=0;j<tam2;j++)
   {
     if(automovil[j].estado==ESTACIONADO)
     {
       if(cliente[i].idPropietario == automovil[j].idPropietario && automovil[j].marca == AUDI)
       {
          if(max!= automovil[j].idPropietario)
          {
            max = automovil[j].idPropietario;
            pro_mostrarUno(cliente[i]);
            flag = 1;
          }
       }
     }
    }
 }
 if(flag==0)
 {
  printf("No hay propietarios con autos Audi\n");
 }
}
void ordenarAutos(ePropietario cliente[],int tam,eIngreso automovil[],int tam2)
{
   int i,j,k;
   eIngreso aux;

   for(i=0;i<tam;i++)
   {
     for(j=0;j<tam2-1;j++)
     {
       for(k=j+1;k<tam2;k++)
       {
         if(automovil[j].idPropietario == cliente[i].idPropietario && stricmp(automovil[j].patente,automovil[k].patente)>0)
         {
           aux = automovil[j];
           automovil[j] = automovil[k];
           automovil[k] = aux;
         }
       }
     }
   }

   printf("*********** ORDENADOS POR PATENTES **********\n");
   mostrarAutos(automovil,tam2,cliente,tam);
}
