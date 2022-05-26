#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "Censista.h"
#include "utn_Validaciones.h"
#include  "Listar.h"

#define LIMITE_CARACTER_LISTAR 51

/**
 * @brief Recibe como parametro una vivienda, su tipo, el censista asignado y la imprime
 *
 * @param vivienda Puntero* vivienda
 * @param tipoVivienda Puntero* eTipoVivienda
 * @param censista Puntero* eCensista
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int imprimirLista(eVivienda* vivienda, eTipoVivienda* tipoVivienda, eCensista* censista)
{
	int retorno = -1;

		if(vivienda != NULL && tipoVivienda != NULL && censista != NULL)
		{
			retorno = 0;

			printf("%d  "
					"\t%s"
					"      \t%d"
					" \t%d"
					"           %s"
					"           %s\n",
			vivienda->idVivienda,
			vivienda->calle,
			vivienda->cantidadPersonas,
			vivienda->cantidadHabitaciones,
			tipoVivienda->descripcion,
			censista->nombre );
		}

	return retorno;
}

/**
 * @brief Recibe un array de vivienda y los manda a imprimir
 *
 * @param vivienda	Puntero* vivienda
 * @param limiteVivienda int
 * @param tipoVivienda Puntero* eTipoVivienda
 * @param limiteTipoVivienda int
 * @param censista Puntero* eCensista
 * @param limiteCensista int
 * @return retorna (-1) [Si los punteros llegaron en NULL]  - retorna (0) si todoOk
 */
int imprimirArrayLista(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista)
{
	int retorno = -1;
	int i;
	int indiceTipo;
	int indiceCensista;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0 &&censista != NULL && limiteCensista > 0)
		{
			retorno = 0;

				printf("ID    Calle                   Personas Habitaciones Vivienda         Censista\n");
				for(i=0;i<limiteVivienda;i++)
				{
					if( (*(vivienda+i)).isEmpty == 0 )
					{

						indiceTipo = buscarTipoVivienda( (*(vivienda+i)).tipoVivienda, tipoVivienda, limiteTipoVivienda );
						indiceCensista = buscarCensista( (*(vivienda+i)).legajoCensista , censista, limiteCensista);

						imprimirLista( (vivienda+i), (tipoVivienda+indiceTipo), (censista+indiceCensista) );
					}
				}
		}


	return retorno;
}

/**
 * @brief se encarga de pedirle el nombre del censista y de asignarle el legajo a la estrucutra eVivienda
 *
 * @param vivienda Puntero* eVivienda
 * @param indice int posisicion que se le asignara
 * @param censista Puntero* eCensista
 * @param limiteCensista int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no se ingreso lo que se le pidio] - retorna (0) si todoOk
 */
int asignarCensista(eVivienda* vivienda, int indice, eCensista* censista, int limiteCensista)
{
	int retorno = -1;
	int retornoNombre;
	char buffer[LIMITE_CARACTER_LISTAR];
	int legajoDelCensista;

		if(vivienda != NULL && indice >= 0 && censista != NULL && limiteCensista > 0)
		{
			retorno = 1;

			retornoNombre = pedirNombreOapellido(buffer, LIMITE_CARACTER_LISTAR, "Ingrese el nombre del Cesista: ", "\nError. ingrese bien los datos", 2);

				if(retornoNombre == 0)
				{
					legajoDelCensista = verificarCensista(censista, limiteCensista, buffer);
					if(legajoDelCensista != -1 && legajoDelCensista != -2)
					{
						retorno = 0;

						(*(vivienda+indice)).legajoCensista = legajoDelCensista;
					}

				}


		}

	return retorno;
}

int listar_buscarCensista(int legajoCensista, eVivienda* vivienda, int limite, eTipoVivienda* tipoVivienda, int limiteTipoVivienda)
{
	int retorno = -1;
	int i;
	int indiceTipo;

		if(legajoCensista >= 0 && vivienda != NULL && limite > 0)
		{
			for(i=0;i<limite;i++)
			{
				if(legajoCensista == (*(vivienda+i)).legajoCensista && (*(vivienda+i)).isEmpty == 0 )
				{
					indiceTipo = buscarTipoVivienda( (*(vivienda+i)).tipoVivienda, tipoVivienda, limiteTipoVivienda );
					imprimirVivienda( (vivienda+i) , (tipoVivienda+indiceTipo));
				}
			}
		}

	return retorno;
}

/**
 * @brief imprime las viviendas censadas por un censista
 *
 * @param censista Puntero* eCensista
 * @param limiteCensista int
 * @param vivienda Puntero* eVivienda
 * @param limitevivienda int
 * @param tipoVivienda Puntero* eTipoVivienda
 * @param limiteTipovivienda int
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) todoOk
 */
int imprimirArrayCensistaVivienda(eCensista* censista, int limiteCensista, eVivienda* vivienda, int limitevivienda, eTipoVivienda* tipoVivienda, int limiteTipovivienda)
{
	int retorno = -1;
	int i;

		if(censista != NULL && limiteCensista > 0 && vivienda != NULL && limitevivienda > 0 && tipoVivienda > 0 && limiteTipovivienda > 0)
		{
			retorno = 0;

				for(i=0;i<limiteCensista;i++)
				{
					imprimirCensista( (censista+i) );

					listar_buscarCensista( (*(censista+i)).legajoCensista, vivienda, limitevivienda, tipoVivienda, limiteTipovivienda );


				}

		}

	return retorno;
}

/*
int comprarLegajos(int legajoCensista, eCensista* censista, int limite)
{
	int retorno = -1;
	int i;

		if(legajoCensista >= 0 && censista != NULL && limite > 0)
		{
			retorno = -2;

			for(i=0;i<limite;i++)
			{
				if(legajoCensista == (*(censista+i)).legajoCensista )
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}*/

int mejorCensista(eCensista* censista, int limiteCensista,eVivienda*  vivienda, int limiteVivienda)
{
	int retorno = -1;
	int i;
	int censis;
	int contadorAna = 0;
	int contadorJuan = 0;
	int contadorSol = 0;

		if(censista != NULL && limiteCensista > 0 && vivienda != NULL && limiteVivienda > 0)
		{
			retorno = 0;

				for(i=0;i<limiteVivienda;i++)
				{
					if( (*(vivienda+i)).isEmpty == 0 )
					{
						censis = buscarCensista( (*(vivienda+i)).legajoCensista , censista, limiteCensista);
							switch(censis)
							{
								case 0:
									contadorAna++;
								break;

								case 1:
									contadorJuan++;
								break;

								case 2:
									contadorSol++;
								break;
							}

					}
				}

				if(contadorAna > contadorJuan && contadorAna > contadorSol)
				{
					printf("La censista ana es la que mas censos realizo\n");
				}
				else
				{
					if(contadorJuan > contadorAna && contadorJuan > contadorSol)
					{
						printf("El censista Juan es el que mas censos realizo\n");
					}
					else
					{
						if(contadorSol > contadorAna && contadorSol > contadorJuan)
						{
							printf("La censista Sol es el que mas censos realizo\n");
						}
					}
				}



		}

	return retorno;
}
