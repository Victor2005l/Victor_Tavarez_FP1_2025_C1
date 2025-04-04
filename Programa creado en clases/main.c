#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100


    int a[ARRAY_SIZE];
    time_t seed;
    int i;
    int ganador[3];

   int numerosloto(int argc, char * argv)
    {
        seed = 0;
        srand(time(&seed));

        for (i = 0; i<= ARRAY_SIZE-1; i++)

        {
            a[i] = rand()%100;
        }
         for (i = 0; i<= ARRAY_SIZE-1; i++)
         {
             printf("Numeros a[%d]: %d\n", i, a[i]);
         }
         return 0;

   }

void ganadores()
{
    int i;
    srand(time(NULL));
    for (i = 0; i<3; i++)
    {
       ganador[i] = rand()%100;
    }
    printf("\n Numeros ganadores: %d %d %d\n", ganador[0], ganador[1], ganador[2]);
}

void jugador()
{
    char nombre[20];
    int num;
    int id;
    float cantidaddine;
    float premio = 0;

    printf("\nIngrese el nombre: ");
    scanf("%s", nombre);
    printf("\nIngrese el numero jugado: ");
    scanf("%d", &num);
    printf("\nIngrese la cantidad de dinero apostado: ");
    scanf("%f", &cantidaddine);
    printf("\nID: ");
    scanf("%d", &id);
    if (num == ganador[0])
        premio = cantidaddine * 100;
    else if (num == ganador[1])
        premio = cantidaddine * 50;
    else if (num == ganador[2])
        premio = cantidaddine * 10;

     if (premio > 0)
        printf("\nHaz ganado %.3f\n", premio);
     else
        ("\nPerdiste tu dinero: ");



}
void numerosganadores()
{
    printf("\nLos ganadores son: %d %d y %d\n", ganador[0], ganador[1], ganador[2]);

}

void main(void)

{
    int opcion;
    do
    {
        printf("\n1- jugador \t 2-numeros \t 0 - salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
           jugador();
           break;
        case 2:
           ganadores();
            break;
        case 0:
            printf("\nAdios");
            break;
        default:
            printf("\neso no iba");

        }
    }
    while (opcion != 0);
}
