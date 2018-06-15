#ifndef DESTINATARIO_H_INCLUDED
#define DESTINATARIO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char email[140];
}Destinatario;

Destinatario* destinatario_new();
void destinatario_delete();
Destinatario* destinatario_newParametros(char* nombre, char* email);

int destinatario_setNombre(Destinatario* this,char* nombre);
int destinatario_getNombre(Destinatario* this,char* nombre);

int destinatario_setEmail(Destinatario* this,char* email);
int destinatario_getEmail(Destinatario* this,char* email);

#endif // DESTINATARIO_H_INCLUDED
