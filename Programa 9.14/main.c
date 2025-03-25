#include <stdio.h>
#include <ctype.h>
/* Letras min�sculas y may�sculas.
El programa, al recibir como dato un archivo formado por cadenas de caracteres,
determina el n�mero de letras min�sculas y may�sculas que hay en el archivo. */

void minymay(FILE *); /* Prototipo de funci�n. */
/* Observa que esta funci�n va a recibir un archivo como par�metro. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("arc5.txt", "r")) != NULL) /* Cambi� las comillas estilizadas por comillas est�ndar. */
    {
        minymay(ar);
        /* Se llama a la funci�n minymay. Se pasa el archivo ar como par�metro. */
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void minymay(FILE *arc)
/* Esta funci�n cuenta el n�mero de min�sculas y may�sculas que hay en el archivo arc. */
{
    int min = 0, may = 0;
    char p;

    while ((p = fgetc(arc)) != EOF) /* Se utiliza la funci�n fgetc() para leer caracteres del archivo. */
    {
        if (islower(p)) /* Verifica si el car�cter es una letra min�scula. */
            min++;
        else if (isupper(p)) /* Verifica si el car�cter es una letra may�scula. */
            may++;
    }

    printf("\nN�mero de min�sculas: %d\n", min);
    printf("N�mero de may�sculas: %d\n", may);
}
