#include <stdio.h>
#include <string.h>

/* Declaraci�n de la estructura domicilio */
typedef struct {
    char cal[20];     /* Calle */
    int num;          /* N�mero */
    char col[20];     /* Colonia */
    char cp[5];       /* C�digo Postal */
    char ciu[20];     /* Ciudad */
} domicilio;

/* Declaraci�n de la estructura paciente */
typedef struct {
    char nom[50];     /* Nombre y apellido */
    int edad;         /* Edad */
    char sexo;        /* Sexo ('F' para femenino, 'M' para masculino) */
    int con;          /* Condici�n (1..5) */
    domicilio dom;    /* Estructura domicilio */
    char tel[15];     /* Tel�fono */
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100]; /* Arreglo para almacenar los pacientes */
    int TAM;

    do {
        printf("Ingrese el n�mero de pacientes (1 a 50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1); /* Verifica que el tama�o del arreglo sea v�lido */

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

/* Funci�n para leer la informaci�n de los pacientes */
void Lectura(paciente A[], int T) {
    int I;

    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d\n", I + 1);
        getchar();  /* Limpiar el buffer de entrada de scanf */

        printf("Nombre: ");
        fgets(A[I].nom, 50, stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = 0;  /* Eliminar el salto de l�nea */

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);

        printf("Condici�n (1..5): ");
        scanf("%d", &A[I].con);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("\tCalle: ");
        fgets(A[I].dom.cal, 20, stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = 0;

        printf("\tN�mero: ");
        scanf("%d", &A[I].dom.num);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("\tColonia: ");
        fgets(A[I].dom.col, 20, stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = 0;

        printf("\tC�digo Postal: ");
        fgets(A[I].dom.cp, 5, stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = 0;

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, 20, stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = 0;

        printf("\tTel�fono: ");
        fgets(A[I].tel, 15, stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = 0;
    }
}

/* Funci�n para calcular el porcentaje de hombres y mujeres */
void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0, TOT;

    for (I = 0; I < T; I++) {
        if (A[I].sexo == 'F') FEM++;
        else if (A[I].sexo == 'M') MAS++;
    }

    TOT = FEM + MAS;

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%\n", (float)FEM / TOT * 100);
}

/* Funci�n para contar los pacientes por condici�n */
void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }

    printf("\nN�mero de pacientes en condici�n 1: %d", C1);
    printf("\nN�mero de pacientes en condici�n 2: %d", C2);
    printf("\nN�mero de pacientes en condici�n 3: %d", C3);
    printf("\nN�mero de pacientes en condici�n 4: %d", C4);
    printf("\nN�mero de pacientes en condici�n 5: %d\n", C5);
}

/* Funci�n para mostrar pacientes con condici�n m�xima de gravedad */
void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad (Condici�n 5):\n");

    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("Nombre: %s\tTel�fono: %s\n", A[I].nom, A[I].tel);
        }
    }
}
