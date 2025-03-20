#include <stdio.h>
#include <string.h> // Para usar funciones como strcpy

void main(void) {
    char *cad0;
    cad0 = "Argentina"; /* La declaraci�n y la asignaci�n son correctas. */
    puts(cad0);          // Imprime "Argentina"
    cad0 = "Brasil";     /* Correcto. Modifica el puntero a otra cadena literal. */
    puts(cad0);          // Imprime "Brasil"

    char cad1[20];       // Arreglo con espacio reservado
    printf("\nIngrese una cadena de caracteres (m�x. 19 caracteres): ");
    fgets(cad1, sizeof(cad1), stdin); // Uso seguro para leer una cadena
    cad1[strcspn(cad1, "\n")] = '\0'; // Elimina el salto de l�nea
    puts(cad1);          // Imprime la cadena ingresada

    char cad2[20] = "M�xico"; /* Correcto. Se inicializa con una cadena. */
    puts(cad2);          // Imprime "M�xico"

    printf("\nIngrese otra cadena (m�x. 19 caracteres): ");
    fgets(cad2, sizeof(cad2), stdin); // Lee una nueva cadena
    cad2[strcspn(cad2, "\n")] = '\0'; // Elimina el salto de l�nea
    puts(cad2);          // Imprime la nueva cadena ingresada

    // Esta l�nea ten�a un error: ahora usa strcpy para copiar la cadena completa.
    strcpy(cad2, "Guatemala"); /* Correcto. Copia la cadena en el arreglo. */
    puts(cad2);          // Imprime "Guatemala"
}
