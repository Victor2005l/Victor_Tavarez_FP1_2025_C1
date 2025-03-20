#include <stdio.h>
#include <ctype.h> // Biblioteca para el manejo de caracteres

int main(void)
{
    char p1;

    // An�lisis para verificar si el car�cter ingresado es un d�gito
    printf("\nIngrese un car�cter para analizar si este es un d�gito: ");
    p1 = getchar();
    if (isdigit(p1)) // Verifica si p1 es un d�gito
        printf("%c es un d�gito\n", p1);
    else
        printf("%c no es un d�gito\n", p1);

    // Limpieza del b�fer de entrada
    while (getchar() != '\n');

    // An�lisis para verificar si el car�cter ingresado es una letra
    printf("\nIngrese un car�cter para examinar si este es una letra: ");
    p1 = getchar();
    if (isalpha(p1)) // Verifica si p1 es una letra
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);

    // Limpieza del b�fer de entrada
    while (getchar() != '\n');

    // An�lisis para verificar si el car�cter ingresado es una letra min�scula
    printf("\nIngrese un car�cter para examinar si este es una letra min�scula: ");
    p1 = getchar();
    if (isalpha(p1)) {
        if (islower(p1)) // Verifica si p1 es una letra min�scula
            printf("%c es una letra min�scula\n", p1);
        else
            printf("%c no es una letra min�scula\n", p1);
    } else {
        printf("%c no es una letra\n", p1);
    }

    // Limpieza del b�fer de entrada
    while (getchar() != '\n');

    // Conversi�n de una letra may�scula a min�scula
    printf("\nIngrese una letra para convertirla de may�scula a min�scula: ");
    p1 = getchar();
    if (isalpha(p1)) {
        if (isupper(p1)) // Verifica si p1 es una letra may�scula
            printf("%c fue convertida de may�scula a min�scula\n", tolower(p1));
        else
            printf("%c es una letra min�scula\n", p1);
    } else {
        printf("%c no es una letra\n", p1);
    }

    return 0; // Retorna 0 para indicar que el programa termin� correctamente
}
