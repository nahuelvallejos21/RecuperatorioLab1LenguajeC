typedef struct
{
  char patente[30];
  int marca;
  int idAutomovil;
  int idPropietario;
  int estado;
  float estadia;
  float recaudacion;
}eIngreso;
typedef struct
{
  int marca;
  float precio;
}eEgreso;

int buscarLibreEst(eIngreso[],int);
int est_siguienteId(eIngreso[] ,int);
void estacionamientoInic(eIngreso[],int);
void harcodeEST(eIngreso[]);
void ingresoAuto(eIngreso [],int,ePropietario[],int);
int devolverHorasEstadia();
void estadiaAuto(eIngreso[],int,ePropietario[],int);
void mostrarAutos(eIngreso[],int,ePropietario[],int);
void recaudacionEst(eIngreso[],int);
void recaudacionMarca(eIngreso[],int);
void autosPro(ePropietario[],int,eIngreso[],int);
int pro_Baja(ePropietario[],int,eIngreso[],int);
void propietariosAudi(ePropietario[],int,eIngreso[],int);
void ordenarAutos(ePropietario[],int,eIngreso[],int);
