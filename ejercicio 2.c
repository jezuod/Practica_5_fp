#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_CLAVE 10
#define TAM_NOMBRE 20
#define TAM_DESCRIPCION 80
#define TAM_MODELO 80
#define TAM_PROVEEDOR 40
#define TAM_IDENTIFICADOR 20
#define TAM_FECHA 15
/* estructuras iniciales */
struct categoria {
		char clave[TAM_CLAVE]; /* clave primaria */
		char nombre[TAM_NOMBRE];
		char descripcion[TAM_DESCRIPCION];
		int num_piezas;
		int flag;
};
struct pieza {
		char identificador[TAM_IDENTIFICADOR]; /* clave primaria compuesta por la categoria y un numero */
		char modelo[TAM_MODELO];
		char proveedor[TAM_PROVEEDOR];
		char descripcion[TAM_DESCRIPCION];
		char fecha[TAM_FECHA];
		int num_unidades;
		int flag;
};
struct etiqueta_pieza{
		char clave_categoria[TAM_CLAVE]; /* clave primaria y foranea de categoria */
		char id[TAM_CLAVE]; /* clave primaria y foranea de pieza */
		int flag;
};
struct categoria crear_categoria(char clave[TAM_CLAVE],char nombre[TAM_NOMBRE],char descripcion[TAM_DESCRIPCION])
{
	struct categoria cat;
	stpcpy(cat.clave,clave);
	stpcpy(cat.nombre,nombre);
	stpcpy(cat.descripcion,nombre);
	cat.num_piezas=0;
	/* para filtrar la basura*/
	cat.flag=1;
	return cat;
};
void imprimir_categorias(struct categoria cat)
{
	/* controlamos la basura de la memoria */
	if(cat.flag==1)
    {
       int i;
    printf("\nClave: %s\n",cat.clave);
    printf("Nombre: %s\n",cat.nombre);
    printf("Descripcion: %s\n",cat.descripcion);
    printf("Numero piezas: %d\n",cat.num_piezas);
    }
};
void imprimir_piezas(struct pieza p)
{
	/* controlamos la basura de la memoria */
if(p.flag==1)
    {
       int i;
    printf("\identificador: %s\n",p.identificador);
    printf("modelo: %s\n",p.modelo);
    printf("proveedor: %s\n",p.proveedor);
    printf("descripcion: %s\n",p.descripcion);
	printf("fecha: %s\n",p.fecha);
		printf("num_unidades: %d\n",p.num_unidades);
    }

};
struct pieza crear_pieza(char identificador[TAM_IDENTIFICADOR],char modelo[TAM_MODELO],char proveedor[TAM_PROVEEDOR],char descripcion[TAM_DESCRIPCION],char fecha[TAM_FECHA],int num_unidades)
{
	struct pieza p;
	stpcpy(p.identificador,identificador);
	stpcpy(p.modelo,modelo);
	stpcpy(p.proveedor,proveedor);
	stpcpy(p.descripcion,descripcion);
	stpcpy(p.fecha,fecha);
	p.num_unidades=num_unidades;
	p.flag=1;
	return p;
};
struct etiqueta_pieza crear_etiqueta(char clave_categoria[TAM_CLAVE],char id[TAM_CLAVE])
{
	struct etiqueta_pieza e;
	strcpy(e.clave_categoria,clave_categoria);
	strcpy(e.id,id);
	return e;
};
int main ()
{
	struct categoria categorias[20];
	struct pieza piezas[20];
	struct etiqueta_pieza etiquetas[400];
	int conta_categorias=5,conta_piezas=0,conta_etiquetas=0;
	categorias[0]=crear_categoria("N","Neumaticos","Categoria de los neumaticos");
	categorias[1]=crear_categoria("E","Material electrico","Material que usa electricidad");
	categorias[2]=crear_categoria("M","Motor","Objetos motorizados");
	categorias[3]=crear_categoria("C","Carroceria","Carcasa de un objeto");
	categorias[4]=crear_categoria("A","Accesorios","Complementos y accesorios");
	int respuesta=0;
	char temp_clave[TAM_CLAVE],temp_nombre[TAM_NOMBRE],temp_descripcion[TAM_DESCRIPCION];
	char temp_modelo[TAM_MODELO];
	char temp_proveedor[TAM_PROVEEDOR];
	char temp_fecha[TAM_FECHA];
	int temp_num_unidades;
	int indentificador_piezas_conta=1;
	while (respuesta!=6)
	{
		puts("\n1 Dar de alta una nueve categoria");
		puts("2 Dar de baja una categoria");
		puts("3 Dar de alta una pieza");
		puts("4 Dar de baja una pieza");
		puts("5 Mostrar informacion del sistema\n");

		scanf("%d",&respuesta);
		/* añadir categoria */
		if(respuesta==1)
		{
			/* cogemos los parametros */
			puts("/****** ALTA DE UNA NUEVA CATEGORÍA EN EL SISTEMA *******/\nIntroduzca la siguiente información:");
			fflush(stdin);
			printf("Clave: ");gets(temp_clave);
			fflush(stdin);
			printf("Nombre: ");gets(temp_nombre);
			fflush(stdin);
			printf("Descripcion: ");gets(temp_descripcion);
			printf("Stock General de la categoria: 0\n");
			/* el array que contiene las categorias recibe una nueva categoria */
			categorias[conta_categorias]=crear_categoria(temp_clave,temp_nombre,temp_descripcion);
			++conta_categorias;

		}
		/* baja categoria */
		if(respuesta==2)
		{
			char baja_categoria[5];
			printf("/****** BAJA DE UNA CATEGORÍA *******/\nIntroduzca la clave de la categoría que desea eliminar: ");
			int comprobante=0;
			/* debemos comprobar que la categoria existe */
			while(comprobante==0)
			{
                fflush(stdin);
				gets(temp_clave);
				for(int i=0;i<=20;i++)
				{
					/* comparamos las clave para comprobar que existe */
					if(strcmp(categorias[i].clave,temp_clave)==0)
					{
						/* todos los valores a cero se consideraria borrar?¿ */
						categorias[i].clave[0] = '\0';
						categorias[i].clave[0] = '\0';
						categorias[i].nombre[0] = '\0';
						categorias[i].nombre[0] = '\0';
						categorias[i].num_piezas = 0;
						categorias[i].flag =0;
						/* sale del bucle, al comprobar que existe la categoria */
						comprobante=1;
					}
				}
			}


		}
		/* alta pieza */
		if(respuesta==3)
		{
			puts("/****** NUEVA PIEZA *******/\n");
			puts("Introduzca la siguiente información:");
			int comprobante=0;
			/* debemos comprobar que la categoria existe */
			while(comprobante==0)
			{
                fflush(stdin);
				printf("Clave de la categoria: ");gets(temp_clave);
				for(int i=0;i<=20;i++)
				{
					if(strcmp(categorias[i].clave,temp_clave)==0)
					{
						comprobante=1;
					}
				}
			}

			/* indenticador para las piezas que sera un contador que habra que pasar a tipo string y luego concatenarlo con un guión y la letra de la categoria que pertenece*/
			char contador[20];    //creamos una cadena vacía para guardar el numero
		    sprintf(contador, "%d", indentificador_piezas_conta);   //convertimos el numero en cadena de caracteres con la funcion sprintf
			++indentificador_piezas_conta;
			/* ahora debemos concatenar */
			char guion[] = "-";
			char clave[TAM_CLAVE];

			strcat(temp_clave, guion);
			strcat(temp_clave, contador);
			fflush(stdin);
			printf("Modelo: ");gets(temp_modelo);
			fflush(stdin);
			printf("Marca: ");gets(temp_proveedor);
			fflush(stdin);
			printf("Descripcion: ");gets(temp_descripcion);
			fflush(stdin);
			printf("Fecha de alta: ");gets(temp_fecha);
			fflush(stdin);
			printf("Stock: ");scanf("%d",&temp_num_unidades);
			piezas[conta_piezas]=crear_pieza(temp_clave,temp_modelo,temp_proveedor,temp_descripcion,temp_fecha,temp_num_unidades);
			++conta_piezas;
			puts("La pieza ha sido dada de alta con exito");
			printf("El identificador asignado es %s\n",temp_clave);


			++conta_etiquetas;
		}
		/* baja pieza */
		if(respuesta==4)
		{
			puts("/****** ELIMINAR UNIDAD *******/\n");
			printf("Introduzca el identificador: ");
				/* NO SE LOCALIZA LA PIEZA */

				/* unidades<=2 */

				/* unidades==0 */
		}
		/* mostrar informacion del sistema */
		if(respuesta==5)
		{
			puts("/****** LISTADO DE PIEZAS *******/\n");
			for(int i=0;i<=2;i++)
			{
				imprimir_categorias(categorias[i]);

			}
			for(int i=0;i<=200;i++)
			{
				imprimir_piezas(piezas[i]);

			}

		}
	}
}
