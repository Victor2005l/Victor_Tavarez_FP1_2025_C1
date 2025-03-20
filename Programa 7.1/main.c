#include <stdio.h> // Biblioteca para funciones de entrada y salida

int main(void)
{
    char p1, p2, p3 = '$'; // Declaraci�n e inicializaci�n de variables

    printf("\nIngrese un caracter: ");
    p1 = getchar(); // Se utiliza la funci�n getchar para leer un car�cter.
    putchar(p1);    // Se utiliza la funci�n putchar para escribir el car�cter.
    printf("\n");

    // Eliminar caracteres sobrantes en el b�fer de entrada
    while (getchar() != '\n'); // Alternativa est�ndar para limpiar el b�fer

    printf("\nEl caracter p3 es: ");
    putchar(p3); // Escribir el car�cter almacenado en p3.
    printf("\n");

    printf("\nIngrese otro caracter: ");
    scanf(" %c", &p2); // Leer otro car�cter con scanf
    printf("%c\n", p2); // Escribir el car�cter le�do

    return 0; // Retornar 0 al sistema operativo
}
