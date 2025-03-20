#include <stdio.h>
#include <ctype.h>

/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por n�meros y
letras. */

void interpreta(char *); /* Prototipo de funci�n. */

void main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);  // Aunque gets() es inseguro, lo mantengo como en tu c�digo.
    interpreta(cad);
}

void interpreta(char *cadena)
/* Esta funci�n se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')  // Cambio de 'cad' por 'cadena' para coincidir con el nombre del par�metro
    {
        if (isalpha(cadena[i]))  // Verifica si el caracter es una letra
        {
            k = cadena[i - 1] - 48;
            /* En la variable entera k se almacena el valor del n�mero �convertido
            en caracter� que nos interesa, menos 48 que corresponde al ASCII
            del d�gito 0. */
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
