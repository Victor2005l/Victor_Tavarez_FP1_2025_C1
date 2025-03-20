#include <stdio.h>
#include <string.h>

/* Uniones.
El programa muestra la manera como se declara una uni�n, as� como la forma de
acceso a los campos de las variables de tipo uni�n tanto para asignaci�n
de valores como para lectura y escritura. */

union datos {
    /* Declaraci�n de una uni�n. */
    char celular[15];
    char correo[20];
};

typedef struct {
    /* Declaraci�n de una estructura utilizando typedef. */
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
    /* Observa que uno de los campos de la estructura alumno es una uni�n. */
} alumno;

void Lectura(alumno *a); /* Prototipo de funci�n. */

void main(void) {
    alumno a1 = {120, "Mar�a", "Contabilidad", 8.9, "5-158-40-50"}, a2, a3;
    /* Observa que s�lo el primer componente de una uni�n puede recibir valores por
    medio de este tipo de asignaciones. */

    /* Para que puedas observar las diferentes formas en que los campos de las
    variables de tipo estructura alumno reciben valores, ingresamos los valores
    de los campos de tres formas diferentes. Los campos de a1 reciben valores
    directamente, los campos de a2 se leen en el programa principal, y los campos
    de a3 reciben valores a trav�s de una funci�n. */

    printf("Alumno 2\n");
    printf("Ingrese la matr�cula: ");
    scanf("%d", &a2.matricula);
    getchar(); /* Limpiar el buffer de entrada */
    printf("Ingrese el nombre: ");
    fgets(a2.nombre, sizeof(a2.nombre), stdin);
    a2.nombre[strcspn(a2.nombre, "\n")] = '\0'; /* Eliminar el salto de l�nea al final del nombre */

    printf("Ingrese la carrera: ");
    fgets(a2.carrera, sizeof(a2.carrera), stdin);
    a2.carrera[strcspn(a2.carrera, "\n")] = '\0';

    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese el correo electr�nico: ");
    fgets(a2.personales.correo, sizeof(a2.personales.correo), stdin);
    a2.personales.correo[strcspn(a2.personales.correo, "\n")] = '\0';

    /* Observa que en la variable a2 de tipo estructura alumno el segundo campo de la
    uni�n recibe un valor. */

    printf("Alumno 3\n");
    Lectura(&a3); /* Se llama a una funci�n para leer los campos de la variable a3. */

    /* Impresi�n de resultados. */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular); /* Observa que escribe el valor del tel�fono celular asignado. */
    /* Observa que si tratamos de imprimir el campo correo, escribe basura. */

    strcpy(a1.personales.correo, "hgimenez@hotmail.com");
    /* Se ingresa ahora un valor al segundo campo de la uni�n de la variable a1. */
    puts(a1.personales.celular); /* Ahora escribe basura en el campo del tel�fono celular. */
    puts(a1.personales.correo);  /* Escribe el contenido del campo (hgimenez@hotmail.com). */

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular); /* Escribe basura. */
    puts(a2.personales.correo); /* Escribe el contenido del segundo campo. */

    printf("Ingrese el tel�fono celular del alumno 2: ");
    fgets(a2.personales.celular, sizeof(a2.personales.celular), stdin);
    a2.personales.celular[strcspn(a2.personales.celular, "\n")] = '\0'; /* Eliminar salto de l�nea */
    puts(a2.personales.celular); /* Escribe el tel�fono celular ingresado. */
    puts(a2.personales.correo); /* Ahora escribe basura. */

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo); /* Escribe basura. */
}

void Lectura(alumno *a) {
    /* La funci�n Lectura se utiliza para leer los campos de una variable de tipo
    estructura alumno. */
    printf("\nIngrese la matr�cula: ");
    scanf("%d", &a->matricula);
    getchar(); /* Limpiar el buffer de entrada */
    printf("Ingrese el nombre: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0'; /* Eliminar el salto de l�nea */

    printf("Ingrese la carrera: ");
    fgets(a->carrera, sizeof(a->carrera), stdin);
    a->carrera[strcspn(a->carrera, "\n")] = '\0';

    printf("Ingrese el promedio: ");
    scanf("%f", &a->promedio);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese el tel�fono celular: ");
    fgets(a->personales.celular, sizeof(a->personales.celular), stdin);
    a->personales.celular[strcspn(a->personales.celular, "\n")] = '\0';
}
