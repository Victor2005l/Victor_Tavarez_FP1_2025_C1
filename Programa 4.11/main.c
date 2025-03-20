#include <stdio.h>
#include <stdlib.h>

/* Mayor divisor.
El programa, al recibir como dato un numero entero positivo, calcula su mayor divisor. */

int mad(int); /* Prototipo de funci�n. */

int main(void)
{
    int NUM, RES;

    printf("Ingresa el numero: ");
    scanf("%d", &NUM);
    RES = mad(NUM);
    printf("El mayor divisor de %d es: %d\n", NUM, RES);

}

int mad(int N1)  /* Esta funci�n calcula el mayor divisor del n�mero N1. */
{
    int I = N1 / 2; /* I se inicializa con el maximo valor posible que puede ser divisor de N1. */

    while (N1 % I)

        /* El ciclo se mantiene activo mientras (N1 % I) sea distinto de cero.
        Cuando el resultado sea 0, se detiene, ya que se habr� encontrado el mayor divisor de N1. */
        I--;


    return I;
}
