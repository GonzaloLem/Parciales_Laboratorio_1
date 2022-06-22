#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "eServicios.h"
#include "Analizador.h"
#include "Controlador.h"

/**
 * @brief Se encarga de abrir el archivo que le indicaron y agregarlo en el sistema
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] retorna (1) [Si no encontro el archivo]  - retorna (0) si TodoOK
 */
int controlador_leearArchivo(LinkedList* pArrayListaServicios)
{
	FILE* pArchivo;

	int retorno = -1;
	int retornoRuta;

	char ruta[LIMITE_ARCHIVO];

		if(pArrayListaServicios != NULL)
		{
			retorno = 1;

			retornoRuta = archivo_pedirArchivo(ruta, LIMITE_ARCHIVO);
				if(retornoRuta == 0)
				{
					pArchivo = fopen(ruta, "r");
						if(pArchivo != NULL)
						{
							retorno = 0;
							archivo_leerServicios(pArchivo, pArrayListaServicios);
							fclose(pArchivo);
						}
						else
						{
							printf("Error, el archivo no se pudo abrir. Puede que no exista o se ingreso mal el nombre\n");
						}

				}


		}

	return retorno;
}

/**
 * @brief Se encarga de imprimir la lista
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (0) si TodoOK
 */
int controlardor_imprimirLista(LinkedList* pArrayListaServicios)
{
	eServicio* servicio = NULL;

	int retorno = -1;
	int i;

		if(pArrayListaServicios != NULL)
		{
			retorno = 0;

			emparejarDatos(pArrayListaServicios);
			printf("ID    Descripcion                                Tipo                           Precio Unitario         Cantidad             Total\n");
			for(i=0;i<ll_len(pArrayListaServicios);i++)
			{
				servicio = ll_get(pArrayListaServicios, i);
				eServicio_imprimirLista(servicio);
			}

		}

	return retorno;
}

/**
 * @brief Se encarga de asginarle los totales a la lista
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (0) si todoOk
 */
int controlador_asignarTotales(LinkedList* pArraylistaServicios)
{
	int retorno = -1;

		void (*fn)(void* element);

		if(pArraylistaServicios != NULL)
		{
			retorno = 0;

			fn = asignarTotal;
			ll_map(pArraylistaServicios, fn);
		}

	return retorno;
}

/**
 * @brief Se encarga de filtrar la lista por lo que le pidan
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (0) si todoOk
 */
int controlador_filtrar(LinkedList* pArraylistaServicios)
{

	int retorno = -1;
	int retornoRuta;

	char ruta[LIMITE_ARCHIVO];

		if(pArraylistaServicios != NULL)
		{
			retorno = 1;

			printf("Si ingrese el nombre de un archivo ya existente el programa eliminara ese archivo y creara uno nuevo, perdiendo los datos del anterior\n");
			retornoRuta = archivo_pedirArchivo(ruta, LIMITE_ARCHIVO);

				if(retornoRuta == 0)
				{
					archivo_filtrarLista(pArraylistaServicios, ruta);
				}
		}

	return retorno;
}

/**
 * @brief Se encarga de ordenar la lista como le indiquen
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (0) TodoOk
 */
int controlador_ordenarServicios(LinkedList* pArraylistaServicios)
{
	int retorno = -1;

	int (*pFunc)(void* ,void*);

		if(pArraylistaServicios != NULL)
		{
			retorno = 0;

				pFunc = eServicio_ordenarDescripcion;

				ll_sort(pArraylistaServicios, pFunc, 1);
				controlardor_imprimirLista(pArraylistaServicios);
		}

	return retorno;
}

/**
 * @brief Se encarga de guardar los datos de la lista en el archivo
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (1) [Si no se encontro el archivo o no hay nada que guardar] - retorna (0) todoOk
 */
int controlador_guardarServicios(LinkedList* pArraylistaServicios)
{
	int retorno = -1;
	int retornoArchivo;

	char ruta[LIMITE_ARCHIVO];

		if(pArraylistaServicios != NULL)
		{
			retorno = 1;

			printf("Si ingrese el nombre de un archivo ya existente el programa eliminara ese archivo y creara uno nuevo, perdiendo los datos del anterior\n");
			retornoArchivo = archivo_pedirArchivo(ruta, LIMITE_ARCHIVO);
				if(retornoArchivo == 0 && ll_len(pArraylistaServicios) > 0)
				{
					retorno = 0;
					archivo_guardarDatos(pArraylistaServicios, ruta);
				}
				else
				{
					printf("Error. El archivo no se encontro o no hay servicios para guardar\n");
				}

		}

	return retorno;
}

/*
int controlador_reasignarId(LinkedList* auxilearLista, LinkedList* listaServicios)
{
	eServicio* servicio;

	int retorno = -1;

	int i;
	int id = 0;
	int idServicio;

		if(auxilearLista != NULL && listaServicios != NULL)
		{
			for(i=0;i<ll_len(auxilearLista);i++)
			{
				servicio = ll_get(auxilearLista, i);
				eServicio_obtenerId(servicio, &idServicio);

					if(idServicio > id)
					{
						id = idServicio;
					}
			}

			for(i=0;i<ll_len(listaServicios);i++)
			{
				servicio = ll_get(listaServicios, i);
				id++;
				eServicio_establecerId(servicio, id);
				ll_set(listaServicios, i, servicio);
			}

		}

	return retorno;
}*/
/**
 * @brief Da de alta a un servicio
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (-2) [Si el alta retorna un NULL] - retorna (0) si TodoOK
 */
/*
int controlador_altaServicio(LinkedList* pArrayListaServicio)
{
	eServicio* servicio = NULL;

	int retorno = -1;
	int id;

		if(pArrayListaServicio != NULL)
		{
			retorno = -2;
			servicio = eServicio_agregarServicio(pArrayListaServicio);

				if(servicio != NULL)
				{
					retorno  = 0;
					id = eServicio_asignarId(pArrayListaServicio)+1;
					eServicio_establecerId(servicio, id);
					ll_add(pArrayListaServicio, servicio);
				}
		}

	return retorno;
}*/

/**
 * @brief Modifica el servicio que el usuario elija
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (1) [Si no encontro el servicio] - retorna (0) TodoOk
 */
/*
int controlador_modificarServicio(LinkedList* pArrayListaServicios)
{
	eServicio* servicio = NULL;

	int retorno = -1;
	int indice;

		if(pArrayListaServicios != NULL)
		{

			retorno = 1;

			controlardor_imprimirLista(pArrayListaServicios);
			indice = eServicio_pedirId(pArrayListaServicios);

				if(indice >= 0)
				{
					retorno = 0;
					servicio = ll_get(pArrayListaServicios, indice);
					eServicio_modificarServicio(servicio);
					ll_set(pArrayListaServicios, indice, servicio);
				}



		}

	return retorno;
}*/

/**
 * @brief Elimina un servicio
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (1) [Si no encontro el servicio] - retorna (0) todoOk
 */
/*
int controlador_eliminarServicio(LinkedList* pArrayListaServicios)
{
	int retorno = -1;
	int indice;

		if(pArrayListaServicios != NULL)
		{
			retorno = 1;

			controlardor_imprimirLista(pArrayListaServicios);
			indice = eServicio_pedirId(pArrayListaServicios);

				if(indice >= 0)
				{
					retorno = 0;
					ll_remove(pArrayListaServicios, indice);
				}
		}

	return retorno;
}
*/




