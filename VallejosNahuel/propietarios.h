typedef struct
{
  int idPropietario;
  char nombre[50];
  char apellido[50];
  char direccion[50];
  char tarjeta[17];
  int estado;
}ePropietario;


void harcodePro(ePropietario[]);
void filtroCadena(char[],char[]);
void filtroCadena123(char[],char[]);
void proInit(ePropietario[],int);
int buscarLibre(ePropietario[],int);
int pro_siguienteId(ePropietario[] ,int);
int pro_buscarPorId(ePropietario[] ,int, int);
void pro_mostrarUno(ePropietario parametro);
void mostrarPropietarios(ePropietario[],int);

int alta_Pro(ePropietario[],int);
int modificacionPro(ePropietario[],int);
//int pro_Baja(ePropietario[],int,eIngreso[],int);

