#include <stdio.h>
#include <stdlib.h>
#define SALIR 0
#define SUMAR 1
#define RESTAR 2
#define MULTIPLICAR 3
#define DIVIDIR 4
#define ERR_OK 0
#define ERR_DbZ 1

void inNumeros(float *num1, float *num2);
int sum(float n1, float n2, float *r);
int resta(float n1, float n2, float *r);
int divi(float num, float denom, float *r);
int mul(float n1, float n2, float *r);
int main()

{
    float num1, num2, resul = 0.0;
    int menu = - 1;
    int cod_err = ERR_OK;
    do
    {
        printf("\n1 - Suma\n2 - Resta\n3 - Multiplicacion\n4 - Division\n0 - salir\n");
        scanf("%d", &menu);
        if (menu == SUMAR)
        {
            inNumeros(&num1, &num2);
            cod_err = sum(num1,num2, &resul);
            printf ("\nLas suma de %.2f mas %.2f es = %.2f", num1, num2, resul);
        }else if(menu == RESTAR)
        {
             inNumeros(&num1, &num2);
             cod_err = resta(num1,num2, &resul);
             printf ("\nLa resta de %.2f memos %.2f es = %.2f", num1, num2, resul);
        }else if (menu == DIVIDIR)
        {
            inNumeros(&num1, &num2);
            cod_err = divi(num1, num2, &resul);

             if (cod_err == ERR_OK)
             {
                 printf ("\nLa division de  %.2f entre %.2f es = %.2f", num1, num2, resul);
             }
             else
             {
                 if (cod_err == ERR_DbZ)
                 {
                     printf("\nError al dividir entre 0");
                 }
                  else
                 {
                     printf("\nError general");
                 }
             }

        }
        else if (menu == MULTIPLICAR)
        {
            inNumeros(&num1, &num2);
            cod_err = mul(num1,num2, &resul);
            printf ("\nLa multiplicacion de %.2f por %.2f es = %f", num1, num2, resul);

        }
        else
        {
            printf("\nValor de menu no valido");
        }

    }while(menu != SALIR);

    printf("\nFin");
    return 0;
}
void inNumeros(float *num1, float *num2)
{
    float temp;

    printf("\nIngresa numero 1: ");
    scanf("%f", &temp);
    *num1 = temp;

    printf("\nIngresa numero 2: ");
    scanf("%f", &temp);
    *num2 = temp;

}
int sum(float n1, float n2, float *r)
{
    *r = n1 + n2;
    return n1 + n2;
}
int resta(float n1, float n2, float *r)
{
    *r = n1 - n2;
    return n1 - n2;
}
int divi(float num, float denom, float *r)
{
   if(denom == 0)
   {
       return ERR_DbZ;
   }
   else
   {
       *r = num/denom;
       return ERR_OK;
   }
}
int mul(float n1, float n2, float *r)
{
    *r = n1 * n2;
    return n1 * n2;
}
