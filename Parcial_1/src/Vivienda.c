#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "utn_Validaciones.h"

#define LIMITE_BUFFER 4096

/**
* @brief Inicializa el isEmpty de la estructura eVivienda en 1
 *
 * @param vivienda *Puntero a eVivienda
 * @param limite int
 * @return retorno (-1) [si la estructura vivienda llego en NULL] - retorno (0) TodoOk
 */
int iniciarIsEmpty(eVivienda* vivienda, int limite)
{
	int retorno = -1;
	int i;

		if(vivienda != NULL && limite > 0)
		{
			retorno = 0;

				for(i=0;i<limite;i++)
				{
					(vivienda+i)->isEmpty = 1;
				}

		}

	return retorno;
}

/**
* @brief Busca si hay un lugar vacio (que el isEmpty este en 1) para asignar una vivienda
 *
 * @param vivienda *Puntero a eVivienda
 * @param limiteVivienda int
 * @return retorna (-1) [Si la estructura vivienda llego en NULL] - retorna (-2) [Si no hay mas lugar para asignar] - retorno (0) si TodoOk
 */
int buscarLibre(eVivienda* vivienda, int limiteVivienda)
{
	int retorno = -1;
	int i;

		if(vivienda != NULL && limiteVivienda > 0)
		{
			retorno = -2;

			for(i=0;i<limiteVivienda;i++)
			{
				if( (vivienda+i)->isEmpty == 1 )
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief Se encarga de saber si se hay datos de viviendas cargados
 *
 * @param vivienda *Puntero de eVivienda
 * @param limiteVivienda int
 * @return retorno (-1) [Si la estructura eVivienda llego en NULL] - retorna (-2) [Si no hay ninguna vivienda cargada] -  retorna (0) TodoOk
 */
int buscarViviendaCargada(eVivienda* vivienda, int limiteVivienda)
{
	int retorno = -1;
	int i;

		if(vivienda != NULL && limiteVivienda > 0)
		{
			retorno = -2;

			for(i=0;i<limiteVivienda;i++)
			{
				if( (vivienda+i)->isEmpty == 0 )
				{
					retorno = 0;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief verificar si la vivienda ingresada existe y le guarda la ID del tipo de vivienda
 *
 * @param tipoVivienda Puntero* de la estructura eVivienda
 * @param limiteVivienda int
 * @param opcionVivienda int
 * @param guardarId Puntero* int guarda el id del tipo de vivienda
 * @return retorno (-1) [Si la estructura eTipoVivienda llego en NULL] - retorna (1) [Si la opcion no coincide con ningun dato cargado] - retorna (0) todoOk
 */
int verificarVivienda(eTipoVivienda* tipoVivienda, int limiteVivienda, int opcionVivienda, int* guardarId)
{
	int retorno = -1;
	int i;
	int nuevoLimite;

		if(tipoVivienda != NULL && limiteVivienda > 0 && opcionVivienda > 0 && guardarId != NULL)
		{
			retorno = 1;

				nuevoLimite = limiteVivienda+1;

				for(i=0;i<nuevoLimite;i++)
				{
					if(opcionVivienda == i)
					{
						retorno = 0;
						(*guardarId) = (tipoVivienda+i-1)->idTipoVivienda;
						break;
					}
				}

		}

	return retorno;
}

/**
 * @brief Se encarga de asignar ID y de sumarlo
 *
 * @param id Punterp* int
 * @param contador Puntero del puntero tipo int
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) si TodoOk
 */
int asignarId(int* id , int* contador)
{
	int retorno = -1;

		if(id != NULL && contador != NULL)
		{

			retorno = 0;

			(*contador)++;

			(*id) = (*contador);

		}

	return retorno;
}





/**
 * @brief Da de alta a una vivienda
 *
 * @param vivienda Puntero* de eVivienda
 * @param limiteVivienda int
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @param limiteTipoVivienda int
 * @param censista Puntero* de eCensista
 * @param limiteCensista int
 * @param contador Puntero* int id de la vivienda
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (1) [Si los datos no se cargaron] - retorna (0) si todoOk
 */
int altaVivienda(eVivienda* vivienda, int indice, eTipoVivienda* tipoVivienda, int limiteTipoVivienda)
{
	int retorno = -1;
	int retornoCalle;
	int retornoPersonas;
	int retornoHabitaciones;
	int retornoVivienda;
	int retornoVerificarVivienda;

	int opcionVivienda;

	eVivienda aux;

		if(vivienda != NULL && indice >= 0 && tipoVivienda != NULL && limiteTipoVivienda > 0)
		{
			retorno = 1;


			retornoCalle = pedirNumeroAlfanumerico(aux.calle, LIMITE_ALFANUMERICO, "Ingrese la calle: ", "Error. Ingrese bien los datos.\n", 2);
			retornoPersonas = pedirNumeroEntero(&aux.cantidadPersonas, "Ingrese la cantidad de Personas: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);
			retornoHabitaciones = pedirNumeroEntero(&aux.cantidadHabitaciones, "Ingrese la cantidad de Habitaciones: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);
			retornoVivienda = pedirNumeroEntero(&opcionVivienda, "Ingrese el tipo de vivienda\n1)Casa\n2)Departamento\n3)Casilla\n4)Rancho\n-Opcion: ", "Error. ingrese lo que se le pide.\n", 1, 4, 2);
			retornoVerificarVivienda = verificarVivienda(tipoVivienda, limiteTipoVivienda, opcionVivienda, &aux.tipoVivienda);

				if(retornoCalle == 0 && retornoPersonas == 0 && retornoHabitaciones == 0 && retornoVivienda == 0 && retornoVerificarVivienda == 0 /*&& legajoDelCensista != -1 && legajoDelCensista != -2*/)
				{
						if(indice != -1 && indice != -2)
						{
							retorno = 0;

							(*(vivienda+indice)) = aux;
						}
				}





		}

	return retorno;
}

/**
 * @brief busca si el ID ingresado coincide con algun ID del tipo de vivienda
 *
 * @param idTipoVivienda int
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @param limite int
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (-2) [Si no se encontro el ID] - retorna (la posicion de la ID) si todoOk
 */
int buscarTipoVivienda(int idTipoVivienda, eTipoVivienda* tipoVivienda, int limite)
{
	int retorno = -1;
	int i;

		if(idTipoVivienda > 0 && tipoVivienda != NULL && limite > 0)
		{
			retorno = -2;

				for(i=0;i<limite;i++)
				{
					if(idTipoVivienda == (tipoVivienda+i)->idTipoVivienda )
					{
						retorno = i;
						break;
					}
				}
		}

	return retorno;
}



/**
 * @brief imprime una vivienda que se le pase
 *
 * @param vivienda Puntero* de eVivienda
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) si todoOk
 */
int imprimirVivienda(eVivienda* vivienda, eTipoVivienda* tipoVivienda)
{
	int retorno = -1;

		if(vivienda != NULL && tipoVivienda != NULL )
		{
			retorno = 0;

			printf("%d  "
					"\t%s"
					"      \t%d"
					" \t%d"
					"           %s\n",
			(vivienda)->idVivienda,
			(vivienda)->calle,
			(vivienda)->cantidadPersonas,
			(vivienda)->cantidadHabitaciones,
			(tipoVivienda)->descripcion );

		}

	return retorno;
}

/**
 * @brief Recibe un array de eVivienda y lo manda a imprimir
 *
 * @param vivienda Puntero* eVivienda
 * @param limiteVivienda int
 * @param tipoVivienda Puntero* eTipoVivienda
 * @param limiteTipoVivienda int
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) si todoOk
 */
int imprimirArrayVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda)
{
	int retorno = -1;
	int i;
	int indiceTipo;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0)
		{
			retorno = 0;
			printf("ID    Calle                   Personas Habitaciones Vivienda\n");
				for(i=0;i<limiteVivienda;i++)
				{
					if( (*(vivienda+i)).isEmpty == 0 )
					{
						indiceTipo = buscarTipoVivienda( (vivienda+i)->tipoVivienda, tipoVivienda, limiteTipoVivienda );

						imprimirVivienda( (vivienda+i), (tipoVivienda+indiceTipo));
					}
				}
		}

	return retorno;
}

/**
 * @brief busca el ID ingresado por el usuario
 *
 * @param vivienda Puntero* de eVivienda
 * @param limite int
 * @param id int valor ingresado por el usuario
 * @return retorna -1 [Si alguno de los punteros llego en NULL] - retorna (-2) [Si no se encontro el ID] - retorna (La posicion del ID) si todoOk
 */
int buscarId(eVivienda* vivienda, int limite, int id)
{
	int retorno = -1;
	int i;

		if(vivienda != NULL && limite > 0 && id > 0)
		{
			retorno = -2;

			for(i=0;i<limite;i++)
			{
				if(id == (vivienda+i)->idVivienda && (vivienda+i)->isEmpty == 0 )
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief Modifica uno de los valores de eVivienda que el usuario quiera
 *
 * @param vivienda Puntero* de eVivienda
 * @param indice int posicion a modificar
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @param limiteTipoVivienda int
 * @param opcion int
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (1) [Si no se pudo guardar el dato modificado] - retorna (0) si todoOK
 */
int modificarDatoVivienda(eVivienda* vivienda, int indice, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, int opcion)
{
	int retorno = -1;
	int opcionVivienda;

	int retornoCalle;
	int retornoPersonas;
	int retornoHabitaciones;
	int retornoVivienda;
	int retornoVerificarVivienda;

	eVivienda aux;

		if(vivienda != NULL && tipoVivienda != NULL && limiteTipoVivienda > 0 && indice >= 0 && opcion > 0)
		{
			retorno = 1;

				switch(opcion)
				{
					case 1:
						retornoCalle = pedirNumeroAlfanumerico(aux.calle, LIMITE_ALFANUMERICO, "Ingrese la calle: ", "Error. Ingrese bien los datos.\n", 2);

							if(retornoCalle == 0)
							{
								retorno = 0;
								strcpy( (vivienda+indice)->calle,aux.calle );
							}

					break;

					case 2:
						retornoPersonas = pedirNumeroEntero(&aux.cantidadPersonas, "Ingrese la cantidad de Personas: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);

							if(retornoPersonas == 0)
							{
								retorno = 0;
								(vivienda+indice)->cantidadPersonas = aux.cantidadPersonas;
							}
					break;

					case 3:
						retornoHabitaciones = pedirNumeroEntero(&aux.cantidadHabitaciones, "Ingrese la cantidad de Habitaciones: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);

							if(retornoHabitaciones == 0)
							{
								retorno = 0;
								(vivienda+indice)->cantidadHabitaciones = aux.cantidadHabitaciones;
							}
					break;

					case 4:
						retornoVivienda = pedirNumeroEntero(&opcionVivienda, "Ingrese el tipo de vivienda\n1)Casa\n2)Departamento\n3)Casilla\n4)Rancho\n-Opcion: ", "Error. ingrese lo que se le pide.\n", 1, 4, 2);
						retornoVerificarVivienda = verificarVivienda(tipoVivienda, limiteTipoVivienda, opcionVivienda, &aux.tipoVivienda);

							if(retornoVivienda == 0 && retornoVerificarVivienda == 0)
							{
								retorno = 0;
								(vivienda+indice)->tipoVivienda = aux.tipoVivienda;
							}
					break;
				}
		}

	return retorno;
}

/**
 * @brief Da de baja a una vivienda
 *
 * @param vivienda Puntero* de eVivienda
 * @param indice int posicion a dar de baja
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) Si todoOk
 */
int darDeBaja(eVivienda* vivienda, int indice)
{
	int retorno = -1;

		if(vivienda != NULL && indice >= 0)
		{
			retorno = 0;

			(vivienda+indice)->isEmpty = 1;
		}

	return retorno;
}

/**
 * @brief Ordena el array de manera ascedente por calle o en caso de igualdad por Cantidad de Personas
 *
 * @param vivienda Puntero* eVivienda
 * @param limiteVivienda int
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (1) [Si no se pudo ordenar] - retorna (0) si todoOK
 */
int vivienda_ordenarCalle(eVivienda* vivienda, int limiteVivienda)
{
	int retorno = -1;
	int i;
	int swap;
	int comparacion;
	int nuevoLimite;

	eVivienda aux;

	if(vivienda != NULL && limiteVivienda > 0)
	{
		retorno = 1;

		nuevoLimite = limiteVivienda-1;

			do{
	 			swap = 0;
	 	 		for(i=0;i<nuevoLimite;i++)
	 	 		{
	 	 			comparacion = strcmp( (vivienda+i)->calle, (vivienda+i+1)->calle);

	 	 			if( (vivienda+i)->isEmpty == 0)
	 	 			{
	 	 				if(comparacion > 0)
	 	 				{
	 	 					swap = 1;

	 	 					aux = (*(vivienda+i));
	 	 					(*(vivienda+i)) = (*(vivienda+i+1));
	 	 					(*(vivienda+i+1)) = aux;
	 	 				}
	 	 				else
	 	 				{
	 	 					if(comparacion == 0)
	 	 					{
	 	 						if( (vivienda+i)->cantidadPersonas > (vivienda+i+1)->cantidadPersonas )
	 	 						{
	 	 	 	 					swap = 1;

	 	 		 	 					aux = (*(vivienda+i));
	 	 		 	 					(*(vivienda+i)) = (*(vivienda+i+1));
	 	 		 	 					(*(vivienda+i+1)) = aux;
	 	 						}
	 	 					}

	 	 				}
	 	 			}
	 	 		}

			}while(swap);


	}

	return retorno;
}

/**
 * @brief Ordena y imprime la estructura eVivienda llamando a la funcion (funcionOrdenar) para que lo ordene
 *
 * @param vivienda Puntero* de eVivienda
 * @param limiteVivienda int
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @param limiteTipoVivienda int
 * @param censista Puntero* de eCensista
 * @param limiteCensista int
 * @param ordenar funcion (funcionOrdenar)
 * @return retorna (-1) [Si alguno de los punteros llego en NULL] - retorna (0) si todoOk
 */
int ordenarViviendas(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, funcionOrdenar ordenarVivienda)
{
	int retorno = -1;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0)
		{
			retorno = 0;

			ordenarVivienda(vivienda, limiteVivienda);
			imprimirArrayVivienda(vivienda, limiteVivienda, tipoVivienda, limiteTipoVivienda);

		}

	return retorno;
}

/**
 * @brief Hace un alta Forzosa de una vivienda
 *
 * @param vivienda Puntero* eVivienda
 * @param indice int posicion que se le asigna
 * @param id Puntero* int
 * @param calle char
 * @param cantidadPersonas int
 * @param cantidadHabitaciones int
 * @param tipoVivienda int
 * @param legajoCensista int
 * @return retorna (-1) [Si algunos de los punteros llego en NULL] - retorna (0) si todoOk
 */
int forzarAltaVivienda(eVivienda* vivienda, int indice, int* id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista)
{
	int retorno = -1;


		if(vivienda != NULL && indice >= 0)
		{
			retorno = 0;


				strcpy((vivienda+indice)->calle, calle);
				(vivienda+indice)->cantidadPersonas = cantidadPersonas;
				(vivienda+indice)->cantidadHabitaciones = cantidadHabitaciones;
				(vivienda+indice)->tipoVivienda = tipoVivienda;
				(vivienda+indice)->legajoCensista = legajoCensista;

				(*id)++;
				(vivienda+indice)->idVivienda = *id;
				(vivienda+indice)->isEmpty = 0;



		}

	return retorno;
}



