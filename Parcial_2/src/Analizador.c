#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "eServicios.h"
#include "utn_validaciones.h"
#include "Controlador.h"
#include "Analizador.h"

/**
 * @brief Pide el nombre de la lista
 *
 * @param ruta char*
 * @param limiteArchivo int limite de caracteres del archivo
 * @return retorna (-1) [Si el puntero llego en NULL - el limite es menor o igual a 0] - retorna (1) [Si no ingresa lo que se le pide] - retorna (0) todoOK
 */
int archivo_pedirArchivo(char* ruta, int limiteArchivo)
{
	int retorno = -1;
	int retornoArchivo;
	int retornoTipo;

	char nombreTexto[limiteArchivo];
	int tipo;

		if(ruta != NULL && limiteArchivo > 0)
		{
			retorno = 1;
			retornoArchivo = pedirArchivo(nombreTexto, limiteArchivo, "ingrese el nombre del texto(Antes del punto): ", "Error. Respete lo que se le pide\n", 2);

			retornoTipo = pedirNumeroEntero(&tipo, "Ingrese el tipo de texto\n1)Archivo de Texto\n2)Archivo Binario\n-Opcion: ", "Error. Ingrese lo que se le pide\n", 1, 2, 3);

				if(retornoArchivo == 0 && retornoTipo == 0)
				{
					retorno = 0;
					switch(tipo)
					{
						case 1:
							strcat(nombreTexto, ".csv");
						break;
					}

					strcpy(ruta, nombreTexto);
				}
				//printf("RUTA: %s\n", ruta);
		}

	return retorno;
}

/**
 * @brief Lee y carga los datos dela archivo en el sistema
 *
 * @param archivo Puntero al archivo
 * @param copiaServicios LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista o el archivo llego en NULL] - retorna (0) todoOk
 */
int archivo_leerServicios(FILE* archivo, LinkedList* pArrayListaServicios)
{
	eServicio* auxilear = NULL;
	eServicio* servicio = NULL;

	int retorno = -1;

	char buffer[6][100];

	char idTxt[100];
	char descripcion[100];
	char tipo[100];
	char precioTxt[100];
	char cantidadTxt[100];
	char totalTxt[100];
	//int id = 0;

		if(archivo != NULL && pArrayListaServicios != NULL)
		{

			retorno = 0;
				fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1), *(buffer+2), *(buffer+3), *(buffer+4), *(buffer+5));
				do{

					if(fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idTxt, descripcion, tipo, precioTxt, cantidadTxt, totalTxt) == 6 )
					{
						auxilear = eServicio_nuevosParametrosTxt(idTxt, descripcion, tipo, precioTxt, cantidadTxt, totalTxt);

							if(auxilear != NULL)
							{
								servicio = auxilear;
								ll_add(pArrayListaServicios, servicio);

									/*if(atoi(idTxt) >= id)
									{
										id = atoi(idTxt);
									}*/
							}
					}

				}while( !feof(archivo) );

		}

	return retorno;
}

/**
 * @brief  Guardar los datos de la lista en el archivo
 *
 * @param pArrayListaServicios LinkedList* Puntero a la lista
 * @param ruta char*
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) todoOk
 */
int archivo_guardarDatos(LinkedList* pArrayListaServicios, char* ruta)
{
	FILE* pArchivo;
	eServicio* servicio;

	int retorno = -1;
	int i;

	int id;
	char descripcion[61];
	int tipo;
	float precio;
	int cantidad;
	int total;

		if(ruta != NULL && pArrayListaServicios != NULL)
		{
			pArchivo = fopen(ruta, "w");
				if(pArchivo != NULL)
				{
					retorno = 0;
					fprintf(pArchivo,"ID,Descripcion,Tipo,Precio Unitario,Cantidad,Total\n");
					for(i=0;i<ll_len(pArrayListaServicios);i++)
					{
						servicio = ll_get(pArrayListaServicios, i);

						eServicio_obtenerId(servicio, &id);
						eServicio_obtenerDescripcion(servicio, descripcion);
						eServicio_obtenerTipo(servicio, &tipo);
						eServicio_obtenerPrecioUnitario(servicio, &precio);
						eServicio_obtenerCantidad(servicio, &cantidad);
						eServicio_obtenerTotal(servicio, &total);

						fprintf(pArchivo,"%d,%s,%d,%.2f,%d,%d\n", id, descripcion, tipo, precio, cantidad, total);
					}
					fclose(pArchivo);

				}
		}

	return retorno;
}

/**
 * @brief Crear un archivo y guarda los servicios del tipo que se le indico
 *
 * @param pArrayListaServicios LinkedList* Puntero a la lista
 * @param ruta char*
 * @return retorno (-1) [Si alguno de los punteros llego en NULL] - retorna (1) [Si no ingresa un tipo valido] - retorna (0) todoOk
 */
int archivo_filtrarLista(LinkedList* pArrayListaServicios, char* ruta)
{
	LinkedList* listaFiltrada = ll_newLinkedList();

	int(*fn)(void*);

	int retorno = -1;
	int retornoTipo;

	int tipo;

		if(pArrayListaServicios != NULL && ruta != NULL)
		{
			retorno = 1;

			retornoTipo = pedirNumeroEntero(&tipo, "Ingrese el tipo por el que va a filtrar\n1)Minorista\n2)Mayorista\n3)Exportar\n-Opcion: ", "Error. Ingrese lo que se le pide", 1, 3,  3);

				if(retornoTipo == 0)
				{
					retorno = 0;
					switch(tipo)
					{
						case 1:
							fn = eServicio_filtrarServiciosTipoUno;
						break;

						case 2:
							fn = eServicio_filtrarServiciosTipoDos;
						break;

						case 3:
							fn = eServicio_filtrarServiciosTipoTres;
						break;
					}
					listaFiltrada = ll_filter(pArrayListaServicios, fn);
					archivo_guardarDatos(listaFiltrada, ruta);
				}
		}

	return retorno;
}

