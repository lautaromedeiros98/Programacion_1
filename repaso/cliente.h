typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int edad;
    int idCliente;
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newForzado(char* nombre,char* apellido,int edad);
void cliente_delete(Cliente* this);

//setters
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setEdad(Cliente* this,int edad);
//setters

//getters
int cliente_getApellido(Cliente* this,char* apellido);
int cliente_getNombre(Cliente* this,char* nombre);
int cliente_getId(Cliente* this,int* id);
int cliente_getEdad(Cliente* this,int* edad);

int cliente_alta(Cliente* punteroArrayC[], int* cantidadArrayC);
int cliente_mostrar(Cliente* punteroArrayC[],int cantidad);
