#include <stdio.h>
/* Cuenta caracteres.
El programa, al recibir como dato un archivo de texto y un car�cter, cuenta
el n�mero de veces que se encuentra el car�cter en el archivo. */

int cuenta(char car); /* Prototipo de funci�n. */

void main(void)
{
    int res;
    char car;

    printf("\nIngrese el car�cter que se va a buscar en el archivo: ");
    car = getchar(); /* Obtiene el car�cter ingresado por el usuario. */

    res = cuenta(car);

    if (res != -1)
        printf("\n\nEl car�cter '%c' se encuentra en el archivo %d veces.\n", car, res);
    else
        printf("\nNo se pudo abrir el archivo.\n");
}

int cuenta(char car)
/* Esta funci�n determina cu�ntas veces se encuentra el car�cter en el archivo. */
{
    int res, con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r"); /* Abre el archivo en modo lectura. */


    if (ar != NULL)
    {
        while ((p = getc(ar)) != EOF)
        {
            if (p == car)
                con++;
        }
        fclose(ar);
        res = con;
    }
    else
    {
        res = -1;
    }

    return res;
}
