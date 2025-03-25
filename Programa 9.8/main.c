#include <stdio.h>
/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */

typedef struct /* Declaraci�n de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *); /* Prototipo de funci�n. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "wb")) != NULL) /* Apertura del archivo en modo binario de escritura. */
    {
        escribe(ar); /* Llama a la funci�n para escribir en el archivo. */
        fclose(ar);  /* Cierra el archivo despu�s de escribir. */
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void escribe(FILE *ap)
/* Esta funci�n sirve para leer los datos de los alumnos utilizando una
estructura tipo alumno, que se almacenar� posteriormente en un archivo. */
{
    alumno alu;
    int i = 0, r;

    printf("\n�Desea ingresar informaci�n sobre alumnos? (S�-1 No-0): ");
    scanf("%d", &r);

    while (r)
    {
        i++;
        printf("Matr�cula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        fflush(stdin); /* Limpia el buffer de entrada. */
        gets(alu.nombre); /* Lee el nombre del alumno. */

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        /* Observa que la funci�n fwrite tiene cuatro argumentos:
           - La variable tipo estructura que se desea almacenar.
           - El tama�o de esa variable en t�rminos de bytes.
           - El n�mero de variables que se escribir�n en el archivo.
           - El apuntador al inicio del archivo. */

        printf("\n�Desea ingresar informaci�n sobre m�s alumnos? (S�-1 No-0): ");
        scanf("%d", &r);
    }
}
