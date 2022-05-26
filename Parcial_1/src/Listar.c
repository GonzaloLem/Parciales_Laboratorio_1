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
					"             %s\n",
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

