#include <stdio.h>

/* Escuela.
El programa, al recibir como dato un archivo de acceso directo que contiene
informaci�n de los alumnos de una escuela, genera informaci�n estad�stica
importante. */

/* Declaraci�n de la estructura matcal. */
typedef struct
{
    char materia[20];
    int calificacion;
} matcal;

/* Declaraci�n de la estructura alumno. */
typedef struct
{
    int matricula;
    char nombre[20];
    matcal cal[5];  /* Observa que un campo de esta estructura es a su vez estructura. */
} alumno;

void F1(FILE *);
void F2(FILE *);  /* Prototipos de funciones. */
float F3(FILE *);

void main(void)
{
    float pro;
    FILE *ap;

    ap = fopen("esc.dat", "rb"); /* Usar 'rb' para apertura en modo binario de lectura. */

    if (ap != NULL)
    {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f", pro);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }

    fclose(ap);
}

void F1(FILE *ap)
/* La funci�n escribe la matr�cula y el promedio general de cada alumno. */
{
    alumno alu;
    int j;
    float sum, pro;
    printf("\nMATR�CULA y PROMEDIOS");

    fread(&alu, sizeof(alumno), 1, ap); /* Lee el primer alumno */

    while (!feof(ap))  /* Lee hasta el final del archivo */
    {
        printf("\nMatr�cula: %d", alu.matricula);

        sum = 0.0;
        for (j = 0; j < 5; j++)  /* Calcula el promedio del alumno */
        {
            sum += alu.cal[j].calificacion;
        }

        pro = sum / 5;
        printf("\tPromedio: %f", pro);

        fread(&alu, sizeof(alumno), 1, ap); /* Lee el siguiente alumno */
    }
}

void F2(FILE *ap)
/* La funci�n escribe la matr�cula de los alumnos cuya calificaci�n en la
tercera materia es mayor a 9. */
{
    alumno alu;
    int j;

    rewind(ap); /* Regresa al inicio del archivo */

    printf("\n\nALUMNOS CON CALIFICACI�N > 9 EN MATERIA 3");

    fread(&alu, sizeof(alumno), 1, ap); /* Lee el primer alumno */

    while (!feof(ap))  /* Lee hasta el final del archivo */
    {
        if (alu.cal[2].calificacion > 9)  /* Revisa la calificaci�n de la tercera materia */
        {
            printf("\nMatr�cula del alumno: %d", alu.matricula);
        }

        fread(&alu, sizeof(alumno), 1, ap); /* Lee el siguiente alumno */
    }
}

float F3(FILE *ap)
/* Esta funci�n obtiene el promedio general de la materia 4. */
{
    alumno alu;
    int i = 0;
    float sum = 0, pro;

    rewind(ap); /* Regresa al inicio del archivo */

    fread(&alu, sizeof(alumno), 1, ap); /* Lee el primer alumno */

    while (!feof(ap))  /* Lee hasta el final del archivo */
    {
        i++;  /* Cuenta cu�ntos alumnos hay */
        sum += alu.cal[3].calificacion;  /* Suma las calificaciones de la materia 4 */

        fread(&alu, sizeof(alumno), 1, ap); /* Lee el siguiente alumno */
    }

    if (i > 0)  /* Evita divisi�n por cero */
    {
        pro = sum / i;  /* Calcula el promedio de la materia 4 */
    }
    else
    {
        pro = 0;  /* Si no hay alumnos, el promedio es 0 */
    }

    return pro;
}
