struct Libro
{
    int ID;  
    char titulo [100];
    char Autor [50];
    int anioPublicacion;
    char estado [20];
};
 
void registrarLibros(struct Libro Libros[], int i);
void mostrarLibros(struct Libro Libros[], int n);
void buscarlibroID(struct Libro Libros[], int id, int n);
void buscarTituloLibro(struct Libro Libros[], char titulo[], int n);
void eliminarLibro(struct Libro Libros[], int id, int n);
void cambiarEstado(struct Libro Libros[], int id, int n);