#include <stdio.h>
#include <ctype.h>

void main (void)
{
    char a;
    int letras[30] = {0};
    int dentropala = 0;
    int palabras = 0;
    int i;
    FILE *texto;

   if (( texto = fopen("Habitos.txt", "r")) != NULL)
   {
       while((a = fgetc(texto)) != EOF)
       {
           if (isalpha(a))
           {
               a = tolower(a);
               letras[ a - 'a']++;
           }
           if (isspace(a) || ispunct(a))
           {
               dentropala = 0;


           }
           else if (!dentropala)
           {
               dentropala = 1;
               palabras++;
           }

       }
       fclose(texto);
       printf("Total de palabras: %d\n", palabras);
       printf("Frecuencia de letras:\n");
        for (int i = 0; i < 26; i++)
   {
        printf("%c: %d\n", 'a' + i, letras[i]);
   }




}
else
    printf("\nEl texto no esta disponible :(");


}
