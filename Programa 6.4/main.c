#include <stdio.h>
/* Sim�trico.
El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
si el mismo es sim�trico. */

const int MAX = 100;

void Lectura(int [][MAX], int); /* Prototipos de funciones. */
int Simetrico(int [][MAX], int);

void main(void)
{
    int MAT[MAX][MAX], N, RES;
    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &N);
    }
    while (N > MAX || N < 1); /* Se verifica que el tama�o del arreglo sea v�lido. */

    Lectura(MAT, N);  // Llamada a la funci�n para leer la matriz
    RES = Simetrico(MAT, N); // Llamada a la funci�n que determina si es sim�trico

    if (RES)
        printf("\nEl arreglo bidimensional es sim�trico");
    else
        printf("\nEl arreglo bidimensional no es sim�trico");
}

void Lectura(int A[][MAX], int T)
/* La funci�n Lectura se utiliza para leer un arreglo bidimensional cuadrado de
tipo entero de T filas y T columnas. */
{
    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++)
        {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T)
/* La funci�n Sim�trico se utiliza para determinar si el arreglo bidimensional
cuadrado es sim�trico. Si es sim�trico regresa 1, en caso contrario, 0. */
{
    int I, J, F = 1;
    for (I = 0; I < T && F; I++)
    {
        for (J = 0; J < I; J++) // Solo compara la parte triangular inferior
        {
            if (A[I][J] != A[J][I]) // Si alg�n valor no es igual, no es sim�trica
            {
                F = 0;
                break;
            }
        }
    }
    return F;
}
