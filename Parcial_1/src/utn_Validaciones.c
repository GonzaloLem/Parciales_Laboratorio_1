#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_Validaciones.h"

#define LIMITE_BUFFER 4096

/**
 * @brief mide la longitud de la cadena que se le pasa y la devuelve
 *
 * @param cadena char
 * @param longitud Puntero* int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int medirLongitud(char* cadena, int* longitud)
{
	int retorno = -1;

		if(cadena != NULL && longitud > 0)
		{
			retorno = 0;

			(*longitud) = strlen(cadena);

		}

	return retorno;
}

/**
 * @brief se le pasa un puntero int, lo suma y devuelve el valor sumado
 *
 * @param contadorId Puntero* int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int contadorDeId(int* contadorId)
{
	int retorno = -1;

		if(contadorId != NULL)
		{
			retorno = 0;

			(*contadorId)++;
		}

	return retorno;
}

/**
 * @brief  valida que la cadena que se le pase sean numeros enteros
 *
 * @param buffer char
 * @param longitud int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int validarSoloNumerosEnteros(char* buffer, int longitud)
{
	int retorno = -1;
	int i;

		if(buffer != NULL && longitud > 0)
		{
			retorno = 0;

				for(i=0;i<longitud;i++)
				{
					if((*(buffer+i)) < 48 || (*(buffer+i)) > 57)
					{
						retorno = 1;
						break;
					}
				}

		}

	return retorno;
}

/**
 * @brief valida que cadena no pase el limte de caracters
 *
 * @param cadena char
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si la cadena supera el limete] -retorna (0) si todoOk
 */
int validarLongitud(char* cadena, int limite, int minimo)
{
	int retorno = -1;
	int longitud;

		if(cadena != NULL && limite > 0)
		{
			retorno = 0;

				longitud = strlen(cadena);

				if(longitud < limite && longitud >= minimo)
				{
					retorno = 0;
				}
				else
				{
					retorno = 1;
				}

		}

	return retorno;
}

/**
 * @brief Valida que la cadena sean solo letras
 *
 * @param cadena char
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si hay un caracter que no es una letra] - retorna (0) si todoOk
 */
int validarSoloLetras(char* cadena, int limite)
{
	int retorno = -1;
	int i;

		if(cadena != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				if(( (*(cadena+i)) < 65 || (*(cadena+i)) > 90) && ( (*(cadena+i)) < 97 || (*(cadena+i)) > 122))
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief valida que la cadena sean solo letras y numeros
 *
 * @param cadena char
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si la cadena tiene un caracter que no es una letra o numero] - retorna (0) si todoOk
 */
int validarSololetrasNumeros(char* cadena, int limite)
{
	int retorno = -1;
	int i;

		if(cadena != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				if(( ( (*(cadena+i)) < 48 || (*(cadena+i)) > 57) && ( (*(cadena+i)) < 65 || (*(cadena+i)) > 90)) && ( (*(cadena+i)) < 97 || (*(cadena+i)) > 122) && (*(cadena+i)) != 32)
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief pide un alfanumerico y le da x intentos de ingresarla bien
 *
 * @param alfaNumerico char
 * @param limite int
 * @param mensaje char
 * @param mensajeError char
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirNumeroAlfanumerico(char* alfaNumerico, int limite, char* mensaje, char*mensajeError, int intentos)
{
	int retorno = -1;
	char buffer[LIMITE_BUFFER];
	int reportarLongitud;
	int reportarLetrasNumeros;
	int longitud;

		if(alfaNumerico != NULL && limite > 0 && mensaje != NULL && intentos > 0)
		{
			retorno = 1;

				while(intentos >= 0)
				{
					intentos--;

					printf("%s", mensaje);
						fflush(stdin);
						gets(buffer);

						printf("\n");

					medirLongitud(buffer, &longitud);

					reportarLongitud = validarLongitud(buffer, limite, 3);
					reportarLetrasNumeros = validarSololetrasNumeros(buffer, longitud);

						if(reportarLongitud == 0 && reportarLetrasNumeros == 0 )
						{
							strcpy(alfaNumerico, buffer);
							retorno = 0;
							break;
						}
						else
						{
							printf("%s", mensajeError);
						}
				}


		}

	return retorno;
}

/**
 * @brief  pide un numero que sea entero, tiene un minimo y un maximo valor a ingresar y le da x intentos de ingresarla bien
 *
 * @param numero Puntero* int
 * @param mensaje char
 * @param mensajeError char
 * @param min int
 * @param max int
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos)
{
	int retorno = -1;
	char buffer[4096];
	int longitud;
	int retornoNumero;
	int numeroConvertido;

		if(min >= 0 && max < 1000000 && mensaje != NULL && mensajeError != NULL && intentos > 0)
		{
				while(intentos >= 0)
				{
					retorno = 1;

					intentos--;


					printf("%s", mensaje);
					fflush(stdin);
					gets(buffer);
					printf("\n");

					medirLongitud(buffer, &longitud);

					retornoNumero = validarSoloNumerosEnteros(buffer, longitud);

					numeroConvertido = atoi(buffer);

						if(retornoNumero == 0 && numeroConvertido >= min && numeroConvertido <= max)
						{
							retorno = 0;
							*numero = numeroConvertido;
							break;
						}
						else
						{
							printf("%s\n", mensajeError);
						}
				}

		}

	return retorno;
}

/**
 * @brief Le pide al usuario que ingrese un nombre o Apellido, tiene un limite de caracters a ingresar y le da x intentos de ingresarla bien
 *
 * @param cadena char
 * @param limite int
 * @param mensaje char
 * @param mensajeError char
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirNombreOapellido(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos)
{
	int retorno = -1;
	int retornoLetras;
	int retornolongitud;
	char buffer[4096];
	int longitud;

		if(cadena != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0)
		{
			while(intentos >= 0)
				{
					retorno = 1;

					intentos--;


					printf("%s", mensaje);
						fflush(stdin);
						gets(buffer);
					printf("\n");

						medirLongitud(buffer, &longitud);

						retornolongitud = validarLongitud(buffer, limite, 3);
						retornoLetras = validarSoloLetras(buffer, longitud);

						if(retornoLetras == 0 && retornolongitud == 0)
						{
							retorno = 0;
							strncpy(cadena, buffer, limite);
							break;
						}
						else
						{
							printf("%s\n", mensajeError);
						}
			}

		}

	return retorno;
}




