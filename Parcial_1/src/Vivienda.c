#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "Validaciones.h"

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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si TodoOk
 */
int asignarId(int* id , int** contador)
{
	int retorno = -1;

		if(id != NULL && contador != NULL)
		{

			retorno = 0;

			(**contador)++;

			(*id) = (**contador);

		}

	return retorno;
}

/**
 * @brief imprime los datos de la estructura eCensista
 *
 * @param censista Puntero* de eCensista
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorno (0) si todoOk
 */
int imprimirCensista(eCensista* censista, int limite)
{
	int retorno = -1;
	int i;

		if(censista != NULL && limite > 0)
		{

			retorno = 0;
			printf("Legajo Nombre  Edad    Telefono\n");
			for(i=0;i<limite;i++)
			{
				printf("%d\t"
						"%s\t"
						"%d\t"
						"%s\n",
						(censista+i)->legajoCensista,
						(censista+i)->nombre,
						(censista+i)->edad,
						(censista+i)->telefono );
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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (-2) [Si no se encontro el censista] -  retorna [el legajo del censista] si todoOk
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
					strlwr((censista+i)->nombre);

					comparacion = strcmp( (censista+i)->nombre, nombre);

					if(comparacion == 0)
					{
						retorno = (censista+i)->legajoCensista;
						break;
					}
				}

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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si los datos no se cargaron] - retorna (0) si todoOk
 */
int altaVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista, int* contador)
{
	int retorno = -1;
	int retornoCalle;
	int retornoPersonas;
	int retornoHabitaciones;
	int retornoVivienda;
	int retornoVerificarVivienda;

	int opcionVivienda;
	int indice;
	int legajoDelCensista;
	char buffer[LIMITE_CARACTER];

	eVivienda aux;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0)
		{
			retorno = 1;


			retornoCalle = pedirNumeroAlfanumerico(aux.calle, LIMITE_ALFANUMERICO, "Ingrese la calle: ", "Error. Ingrese bien los datos.\n", 2);
			retornoPersonas = pedirNumeroEntero(&aux.cantidadPersonas, "Ingrese la cantidad de Personas: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);
			retornoHabitaciones = pedirNumeroEntero(&aux.cantidadHabitaciones, "Ingrese la cantidad de Habitaciones: ", "Error. ingrese lo que se le pide.\n", 1, 1000, 2);
			retornoVivienda = pedirNumeroEntero(&opcionVivienda, "Ingrese el tipo de vivienda\n1)Casa\n2)Departamento\n3)Casilla\n4)Rancho\n-Opcion: ", "Error. ingrese lo que se le pide.\n", 1, 4, 2);
			retornoVerificarVivienda = verificarVivienda(tipoVivienda, limiteTipoVivienda, opcionVivienda, &aux.tipoVivienda);

			imprimirCensista(censista, limiteCensista);
			pedirNombreOapellido(buffer, LIMITE_CARACTER, "Ingrese el nombre del Censista: ", "Error. Ingrese bien los datos.\n", 2);
			legajoDelCensista = verificarCensista(censista, limiteCensista, buffer);


				if(retornoCalle == 0 && retornoPersonas == 0 && retornoHabitaciones == 0 && retornoVivienda == 0 && retornoVerificarVivienda == 0 && legajoDelCensista != -1 && legajoDelCensista != -2)
				{
					indice = buscarLibre(vivienda, limiteVivienda);
					asignarId(&aux.idVivienda, &contador);

						if(indice != -1 && indice != -2)
						{
							retorno = 0;

							aux.isEmpty = 0;
							aux.legajoCensista = legajoDelCensista;
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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (-2) [Si no se encontro el ID] - retorna (la posicion de la ID) si todoOk
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
 * @brief Busca por un legajo que se le pasa si coincide con alguno de los censista
 *
 * @param legajo int
 * @param censista Puntero* de eCenssita
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (-2) [Si no se encontro el legajo del Censista] - retorna (La posicion del legajo) si TodoOk
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
					if(legajo == (censista+i)->legajoCensista )
					{
						retorno = i;
						break;
					}
				}

		}

	return retorno;
}

/**
 * @brief	imprime la estructura de eVivienda
 *
 * @param vivienda Puntero* de eVivvienda
 * @param limiteVivienda int
 * @param tipoVivienda Puntero* de eTipoVivienda
 * @param limiteTipoVivienda int
 * @param censista Puntero* de eCensista
 * @param limiteCensista int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int imprimirVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista)
{
	int retorno = -1;
	int i;
	int indice;
	int indiceCensista;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0 && censista != NULL && limiteCensista > 0)
		{
			retorno = 0;
				printf("ID\tCalle\t\t\t    Personas\t  Habitaciones\tVivienda   Censista\n");
				for(i=0;i<limiteVivienda;i++)
				{
					if( (vivienda+i)->isEmpty == 0 )
					{
						indice = buscarTipoVivienda( (vivienda+i)->tipoVivienda, tipoVivienda, limiteTipoVivienda );
						indiceCensista = buscarCensista( (vivienda+i)->legajoCensista, censista, limiteCensista );
						printf("%d\t"
								"%s\t\t\t"
								"%d\t\t"
								"%d\t"
								"%s\t   "
								"%s\n",
						(vivienda+i)->idVivienda,
						(vivienda+i)->calle,
						(vivienda+i)->cantidadPersonas,
						(vivienda+i)->cantidadHabitaciones,
						(tipoVivienda+indice)->descripcion,
						(censista+indiceCensista)->nombre );
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
 * @return retorna -1 [Si los punteros llegaron en NULL] - retorna (-2) [Si no se encontro el ID] - retorna (La posicion del ID) si todoOk
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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no se pudo guardar el dato modificado] - retorna (0) si todoOK
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
 * @brief Ordena el arrat de manera ascedente por calle o en caso de igualdad por Cantidad de Personas
 *
 * @param vivienda Puntero* eVivienda
 * @param limiteVivienda int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no se pudo ordenar] - retorna (0) si todoOK
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
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int ordenarViviendas(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista, funcionOrdenar ordenar)
{
	int retorno = -1;

		if(vivienda != NULL && limiteVivienda > 0 && tipoVivienda != NULL && limiteTipoVivienda > 0 && censista != NULL && limiteCensista > 0 )
		{
			retorno = 0;

			ordenar(vivienda, limiteVivienda);
	 	 	imprimirVivienda(vivienda, limiteVivienda, tipoVivienda, limiteTipoVivienda, censista, limiteCensista);

		}

	return retorno;
}

