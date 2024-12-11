#include <stdio.h>
#include "funciones.h"
#include <string.h>
 
int main (int argc, char *argv[])
{
 
    //Variables
    struct Libro libros[20];
    int opc;
    int i=0;
    do{
        printf("\n--- Menu Principal ---\n");
        printf("1. Registrar Libro\n2. Mostrar Libros\n3. Buscar Libro por ID\n4. Buscar libro por titulo\n5. Eliminar Libro\n6. Cambiar Estado\n7. Salir\n");
        printf("Ingrese la opcion que quiere escoger: ");
        scanf("%d", &opc);
        getchar(); //sirve para que no error borrando el caracter que queda del scanf
        switch (opc)
        {
        case 1:
            registrarLibros(libros,i);
            i++;
            break;
        case 2:
            mostrarLibros(libros,i);
            break;
        case 3:
            int id;
            printf("Ingrese el id del libro a buscar: ");
            scanf("%d", &id);
            buscarlibroID(libros,id,i);
            break;
        case 4:
            char titulo[100];
            int len;
            printf("Ingrese el titulo del libro a buscar: ");
            fflush(stdin);
            fgets(titulo,100,stdin);
            len = strlen(titulo)-1;
            titulo[len]='\0';
            buscarTituloLibro(libros,titulo,i);
            break;
        case 5:
            printf("Ingrese el id del Libro que quiere eliminar: ");
            scanf("%d",&id);
            eliminarLibro(libros, id, i);
            break;
        case 6:
            printf("Ingrese el ID del libro que quiere cambiar el estado: ");
            scanf("%d", &id);
            cambiarEstado(libros, id, i);
        case 7:
            printf("Salir\n");
            break;
        default:
            printf("Opcion invalida. Intente de nuevo\n");
            break;
        }
    }while(opc != 7);
 
    return 0;
}