#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define TAM_alfabeto 54
void CifrarCesar(char cadena[TAM],int espacios)
{
    printf("\nCadena introducida :%s",cadena);
    /* ponemos dos alfabetos para que los caracteres del final del abecedario sean faciles de encriptar */
    char alfabeto[TAM_alfabeto] = "abcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyz";
    char cadena_cifrada[TAM];
    /* comprobamos cada caracter de la cadena con los del abecedario, si encuentra una coincidencia, suma la posicion y el espacio, sacando el caracter encriptado */
    for(int f=0;f<TAM;f++)
    {
        for(int i=0;i<28;i++)
        {

            if(alfabeto[i]==cadena[f])
            {
                int z=espacios+i;
                if(z>27)
                {
                    cadena_cifrada[f]=alfabeto[z];
                }
                if(z<=27)
                {
                    cadena_cifrada[f]=alfabeto[z];
                }


            }
            if(cadena[f]==' ')
            {
                cadena_cifrada[f]=cadena[f];
            }
            if(cadena[f]=='\0')
            {
                f=TAM+1;
            }


        }
    }
    printf("\nCadena cifrada :%s",cadena_cifrada);
}
/* igual que el cifrar, pero restando el espacio */
void DesCifrarCesar(char cadena[],int espacios)
{
    printf("\nCadena introducida :%s",cadena);
    char alfabeto[TAM_alfabeto] = "abcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyz";
    char cadena_descifrada[TAM];
    /* comprobamos cada caracter de la cadena con los del abecedario, si encuentra una coincidencia, resta la posicion y el espacio, sacando el caracter desencriptado */
    for(int f=0;f<TAM;f++)
    {
        for(int i=0;i<28;i++)
        {

            if(alfabeto[i]==cadena[f])
            {
                int z=i-espacios;
                if(z>27)
                {
                    cadena_descifrada[f]=alfabeto[z];
                }
                if(z<=27)
                {
                    cadena_descifrada[f]=alfabeto[z];
                }


            }
            if(cadena[f]==' ')
            {
                cadena_descifrada[f]=cadena[f];
            }
            if(cadena[f]=='\0')
            {
                f=TAM+1;
            }


        }
    }
    printf("\nCadena descifrada :%s",cadena_descifrada);
}
void menu(int x)
{
    char cadena[TAM];
     while(x!=2){
	 /* opciones del menu */
        puts("\n1 - Cifrar o descifrar");
        puts("2 - Salir\n");
        printf("Respuesta: ");
        fflush(stdin);
        scanf("%d",&x);
        /* opcion 1 */
        if(x==1)
        {
            puts("Introduzca la cadena");
            fflush(stdin);
            gets(cadena);
            puts("Que quiere hacer:\n1 - Encriptar\n2 - Desencriptar\nRespuesta: ");
            int respuesta=0,espacios=0;
            scanf("%d",&respuesta);
            if(respuesta==1)
            {
                int n_espacios;
                puts("Ha elegido encriptar, cuantos N espacios hacia la derecha del caracter quiere sumar :");
                scanf("%d",&espacios);
                CifrarCesar(cadena,espacios) ;
            }
            if(respuesta==2)
            {
                int n_espacios;
                puts("Ha elegido desencriptar, cuantos N espacios hacia la derecha del caracter quiere restar :");
                scanf("%d",&espacios);
                DesCifrarCesar(cadena,espacios) ;
            }

        }
        /* opcion 2 */
        if(x==2)
        {
            puts("Saliendo del menu.");
        }
        }
}
int main()
{
    int x=0;

    menu(x);
}