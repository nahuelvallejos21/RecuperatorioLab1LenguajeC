#include <stdio.h>
#include <stdlib.h>
#include "propietarios.h"
#include "estacionamiento.h"
#define PRO 10
#define AUT 20
int main()
{
    char seguir='s';
    int opcion=0;
    int retorno;
    ePropietario lista[PRO];
    eIngreso lista2[AUT];


    proInit(lista,PRO);
    estacionamientoInic(lista2,AUT);
    harcodePro(lista);
    harcodeEST(lista2);

    while(seguir=='s')
    {
        printf("1- Agregar propietario\n");
        printf("2- Modificar propietario\n");
        printf("3- Baja del propietario\n");
        printf("4- Listar propietarios\n");
        printf("5- Listar autos estacionados\n");
        printf("6- Estacionar automovil\n");
        printf("7- Ticket de la estadia del automovil del propietario\n");
        printf("8- Recaudacion del EST\n");
        printf("9- Recaudacion por marca\n");
        printf("10-Autos del propietario\n");
        printf("11-Propietarios con autos estacionados marca Audi\n");
        printf("12-Lista de autos ordenados por patente\n");
        printf("13- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
           case 1:
                retorno = alta_Pro(lista,PRO);
                if(retorno == 0)
                {
                  printf("Usuario cargado correctamente....\n");
                }
                else
                {
                  printf("No hay espacio para cargar mas usuarios....\n");
                }
                break;
            case 2:
                retorno = modificacionPro(lista,PRO);
                if(retorno == 0)
                {
                  printf("Cambios aplicados correctamente\n");
                }
                if(retorno ==1)
                {
                  printf("\nAccion cancelada por el usuario\n");
                }
                if(retorno==-1)
                {
                 printf("ID Incorrecta....\n");
                }
                break;
            case 3:
                retorno = pro_Baja(lista,PRO,lista2,AUT);
                if(retorno == 1)
                {
                  printf("\nUsuario dado de baja\n");
                }
                if(retorno==0)
                {
                  printf("\nAccion cancelada\n");
                }
                if(retorno == -1)
                {
                  printf("ID incorrecta.....\n");
                }
                break;
            case 4:
                mostrarPropietarios(lista,PRO);
                break;
            case 5:
                mostrarAutos(lista2,AUT,lista,PRO);
                break;
            case 6:
                ingresoAuto(lista2,AUT,lista,PRO);
                break;
            case 7:
                estadiaAuto(lista2,AUT,lista,PRO);
                break;
            case 8:
                recaudacionEst(lista2,AUT);
                break;
            case 9:
                recaudacionMarca(lista2,AUT);
                break;
            case 10:
                autosPro(lista,PRO,lista2,AUT);
                break;
            case 11:
                propietariosAudi(lista,PRO,lista2,AUT);
                break;
            case 12:
                ordenarAutos(lista,PRO,lista2,AUT);
                break;
            case 13:
                seguir = 'n';
                break;
        }
    }






    return 0;
}
