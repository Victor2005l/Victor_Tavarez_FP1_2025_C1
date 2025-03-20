#include <stdio.h>
/* Empresa textil.
El programa, al recibir un arreglo tridimensional que contiene informaci�n
sobre las ventas mensuales de tres departamentos en los �ltimos ocho a�os,
genera informaci�n estad�stica valiosa para la empresa. */

const int MES = 12;
const int DEP = 3;
const int A�O = 8;

void Lectura(float [MES][DEP][A�O], int, int, int);
void Funcion1(float [MES][DEP][A�O], int, int, int);
void Funcion2(float [MES][DEP][A�O], int, int, int); /* Prototipos de funciones. */
void Funcion3(float [MES][DEP][A�O], int, int, int);

void main(void)
{
    float PRO[MES][DEP][A�O];
    Lectura(PRO, MES, DEP, A�O);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, A�O);
    Funcion3(PRO, MES, DEP, A�O);
}

void Lectura(float A[][DEP][A�O], int F, int C, int P)
/* La funci�n Lectura se utiliza para leer un arreglo tridimensional de tipo
real de F filas, C columnas y P planos de profundidad. */
{
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
            {
                printf("A�o: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][DEP][A�O], int F, int C, int P)
/* Esta funci�n se utiliza para obtener las ventas totales de la empresa
en el segundo a�o. */
{
    int I, J;
    float SUM = 0.0;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];
    printf("\n\nVentas totales de la empresa en el segundo a�o: %.2f", SUM);
}

void Funcion2(float A[][DEP][A�O], int F, int C, int P)
/* Esta funci�n se utiliza para obtener el departamento que tuvo las mayores
ventas en el �ltimo a�o. Genera adem�s el importe de las ventas. */
{
    int I, J;
    float SUM[DEP] = {0}; // Sumar las ventas por departamento
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM[J] += A[I][J][P - 1];

    // Comparar las ventas y determinar el departamento con mayores ventas
    int maxDep = 0;
    for (int k = 1; k < DEP; k++) {
        if (SUM[k] > SUM[maxDep]) {
            maxDep = k;
        }
    }

    // Imprimir el departamento con mayores ventas
    switch (maxDep) {
        case 0:
            printf("\n\nDepartamento con mayores ventas en el �ltimo a�o: Hilos");
            break;
        case 1:
            printf("\n\nDepartamento con mayores ventas en el �ltimo a�o: Lanas");
            break;
        case 2:
            printf("\n\nDepartamento con mayores ventas en el �ltimo a�o: Licra");
            break;
    }
    printf(" Ventas: %.2f", SUM[maxDep]);
}

void Funcion3(float A[][DEP][A�O], int F, int C, int P)
/* Esta funci�n se utiliza para obtener el departamento, mes y a�o con la mayor
venta. Escribe tambi�n el monto de las ventas. */
{
    int K, I, J, DE, ME, AN;
    float VEN = -1.0;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
                if (A[I][J][K] > VEN)
                {
                    VEN = A[I][J][K];
                    DE = J;
                    ME = I;
                    AN = K;
                }

    // Imprimir el departamento, mes y a�o con la mayor venta
    printf("\n\nDepartamento: ");
    switch (DE) {
        case 0:
            printf("Hilos");
            break;
        case 1:
            printf("Lanas");
            break;
        case 2:
            printf("Licra");
            break;
    }
    printf("\tMes: %d\tA�o: %d", ME + 1, AN + 1);
    printf("\tVentas: %.2f", VEN);
}
