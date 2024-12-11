#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
void registrarLibros(struct Libro Libros [], int i, int n)
{
    int len;
 
    //Ingreso ID Libro
    printf("Ingrese el id del libro %d: ", i+1);
    scanf("%d", &Libros[i].ID);
    getchar();
 
    //Ingreso titulo del libro
    printf("Ingrese el titulo del libro %d: ", i+1);
    fflush(stdin);
    fgets(Libros[i].titulo, 100, stdin);
    len = strlen(Libros[i].titulo)-1;
    Libros[i].titulo[len]='\0';
 
    //Ingreso nombre del usuario
    printf("Ingrese el Autor del libro %d: ", i+1);
    fflush(stdin);
    fgets(Libros[i].Autor, 50, stdin);
    len = strlen(Libros[i].Autor)-1;
    Libros[i].Autor[len]='\0';
 
    //Ingreso del año del libro
    printf("Ingrese el anio del libro %d: ", i+1);
    scanf("%d", &Libros[i].anioPublicacion);
    getchar();
 
    strcpy(Libros[i].estado, "Disponible");
}
 
void mostrarLibros(struct Libro Libros[], int n)
{
 
    //Menu de lo que va a poder ver el usuario
 
    printf("ID\t\t|Titulo\t\t\t|Autor\t\t\t|Anio\t\t|Estado\n");
 
    //Menu con las iteraciones
    for (int i = 0; i < n; i++)
    {
        if (Libros[i].ID != 0)
        {
            printf("%d\t\t|%s\t|%s\t\t|%d\t\t|%s\n", Libros[i].ID,
                                                     Libros[i].titulo,
                                                     Libros[i].Autor,
                                                     Libros[i].anioPublicacion,
                                                     Libros[i].estado);
        }
       
    }
}
 
void buscarlibroID(struct Libro Libros[], int id, int n)
{
    int banderaID = 0;
    printf("ID ingresado\t|Busqueda\n");
    for (int i = 0; i < n; i++)
    {
        if (Libros[i].ID == id)
        {
            printf("%d\t\t|Existe\n",id);
            banderaID = 1;
            printf("ID encontrado: Titulo : %s, Autor : %s, Anio : %d, Estado : %s\n", Libros[i].titulo,
                                                                                       Libros[i].Autor,
                                                                                       Libros[i].anioPublicacion,
                                                                                       Libros[i].estado);
        }
        if (banderaID == 0)
        {
            printf("%d\t\tNo existe\n",id);
        }
    }
}
 
void buscarTituloLibro(struct Libro Libros[], char titulo[], int n) {
    int banderaTitulo = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(Libros[i].titulo, titulo) == 0) {
            banderaTitulo = 1;
            printf("Libro encontrado: ID : %d, Titulo : %s, Autor : %s, Anio : %d, Estado : %s\n",
                                                                                        Libros[i].ID,
                                                                                        Libros[i].titulo,
                                                                                        Libros[i].Autor,
                                                                                        Libros[i].anioPublicacion,
                                                                                        Libros[i].estado);
        }
    }
    if (banderaTitulo == 0) {
        printf("No se encontro un libro con el titulo \"%s\".\n", titulo);
    }
}
 
void eliminarLibro(struct Libro Libros[], int id, int n){
 
    int posicionEliminar = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (Libros[i].ID == id)
        {
            posicionEliminar = 1;
            Libros[i].ID = 0;
            Libros[i].titulo[0] = '\0';  
            Libros[i].Autor[0] = '\0';  
            Libros[i].anioPublicacion = 0;
            Libros[i].estado[0] = '\0';
            printf("El Libro con el ID %d eliminado.\n", id);
        }
    }
    if (posicionEliminar == 0)
    {
        printf("Libro no encontrado con el ID %d\n", id);
    }
}
 
void cambiarEstado(struct Libro Libros[], int id, int n) {
 
    int banderaEstado = 0;
    int cambiarEstado;
    for (int i = 0; i < n; i++) {
 
        if (Libros[i].ID == id) {
           
            banderaEstado = 1;
 
            printf("Estado actual: %s\n", Libros[i].estado);
           
            printf("1. Disponible\n2. Prestado\n");
 
            printf("Ingrese la opcion de estado a la cual quiere cambiar del libro con ID %d: ", id);
            scanf("%d", &cambiarEstado);
            switch (cambiarEstado)
            {
            case 1:
                strcpy(Libros[i].estado, "Disponible");
                printf("El estado del libro ha cambiado a Disponible.\n");
                break;
            case 2:
                strcpy(Libros[i].estado, "Prestado");
                printf("El estado del libro ha cambiado a Prestado.\n");
                break;
            default:
                printf("Opcio no valida. El estado del libro no ha cambiado.\n");
                break;
            }
           
        }
    }
    if (banderaEstado == 0) {
        printf("Libro no encontrado con el ID %d, nose actualizo nada\n", id);
    }
}