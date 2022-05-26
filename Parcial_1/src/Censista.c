#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Vivienda.h"
#include "Censista.h"
#include "utn_Validaciones.h"


/**
 * @brief imprime un censista
 *
 * @param censista Puntero* de eCensista
 * @param limite int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorno (0) si todoOk
 */
int imprimirCensista(eCensista* censista)
{
	int retorno = -1;

		if(censista != NULL)
		{
			retorno = 0;

				printf("%d\t"
						"%s\t"
						"%d\t"
						"%s\n",
						censista->legajoCensista,
						censista->nombre,
						censista->edad,
						censista->telefono );

		}

	return retorno;
}

/**
 * @brief se le pasa un array de eCensista y lo manda a imprimir
 *
 * @param censista puntero* eCensista
 * @param limite int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) si todoOk
 */
int imprimirArrayCensista(eCensista* censista, int limite)
{
	int retorno = -1;
	int i;

		if(censista != NULL && limite > 0)
		{

			retorno = 0;

			printf("ID      Nombre Edad     Telefono\n");
			for(i=0;i<limite;i++)
			{
				imprimirCensista( (censista+i) );
			}
		}

	return retorno;
}

/**
 * @brief verifica si el nombre ingresado coincide con el de algun censista
 *
 * @param censista Puntero* a eCensista
 * @param limite int
 * @param nombre Puntero* char
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (-2) [Si no se encontro el censista] -  retorna [el legajo del censista] si todoOk
 */
int verificarCensista(eCensista* censista, int limite, char* nombre)
{
	int retorno = -1;
	int i;
	int comparacion;

		if(censista != NULL && limite > 0 && nombre != NULL)
		{
			retorno = -2;

			strlwr(nombre);

				for(i=0;i<limite;i++)
				{
					strlwr( (*(censista+i)).nombre);

					comparacion = strcmp( (*(censista+i)).nombre, nombre);

					if(comparacion == 0)
					{
						retorno = (*(censista+i)).legajoCensista;
						break;
					}
				}

		}

	return retorno;
}

/**
 * @brief Busca por un legajo que se le pasa si coincide con alguno de los censista
 *
 * @param legajo int
 * @param censista Puntero* de eCenssita
 * @param limite int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (-2) [Si no se encontro el legajo del Censista] - retorna (La posicion del legajo) si TodoOk
 */
int buscarCensista(int legajo, eCensista* censista, int limite)
{
	int retorno = -1;
	int i;

		if(legajo > 0 && censista != NULL && limite > 0)
		{
			retorno = -2;

				for(i=0;i<limite;i++)
				{
					if(legajo == (*(censista+i)).legajoCensista )
					{
						retorno = i;
						break;
					}
				}

		}

	return retorno;
}

/*
int asignarCensista(int* legajo, eCensista* censista, int limite)
{
	int retorno = -1;
	char buffer[LIMITE_CARACTER];
	int legajoDelCensista;

		if(legajo != NULL && censista != NULL && limite > 0)
		{


		}

	return retorno;
}*/


