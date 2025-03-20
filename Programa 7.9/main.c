#include <stdio.h>
/* Cuenta caracteres.
El programa, al recibir como datos una cadena de caracteres y un caracter,
cuenta cu�ntas veces se encuentra el caracter en la cadena. */

int cuenta(char *, char); /* Prototipo de funci�n. */

void main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);  // Usamos fgets para evitar desbordamientos.
    cad[strcspn(cad, "\n")] = 0;  // Eliminar el salto de l�nea que fgets agrega.

    printf("\nIngrese el caracter: ");
    car = getchar();  // Lectura de un solo caracter.

    res = cuenta(cad, car);

    printf("\n\n%c se encuentra %d veces en la cadena %s", car, res, cad);
}

int cuenta(char *cad, char car)
{
    int i = 0, r = 0;
    while (cad[i] != '\0')  // Iteramos sobre la cadena hasta el fin (car�cter nulo).
    {
        if (cad[i] == car)  // Comparamos si el car�cter actual es igual al buscado.
            r++;  // Si hay coincidencia, aumentamos el contador.
        i++;  // Avanzamos al siguiente car�cter.
    }
    return r;  // Retornamos el n�mero de veces que el car�cter aparece.
}
