#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_validaciones.h"

/**
 * @brief mide la longitud de la cadena que se le pasa y la retorna
 *
 * @param cadena Puntero* char
 * @return Retorna (-1) [Si el puntero llego en NULL] - Retorna (La longitud de la cadena) si todoOk
 */
int medirLongitud(char* cadena)
{
	int retorno = -1;

		if(cadena != NULL)
		{
			retorno = strlen(cadena);
		}

	return retorno;
}

/**
 * @brief valida que cadena no pase el limte de caracters
 *
 * @param cadena char*
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si la cadena supera el limete] -retorna (0) si todoOk
 */
int validarLongitud(char* cadena, int limite, int minimo)
{
	int retorno = -1;
	int longitud;

		if(cadena != NULL && limite > 0)
		{

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
 * @brief  valida que la cadena que se le pase sean numeros enteros
 *
 * @param buffer char*
 * @param longitud int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (0) si todoOk
 */
int validar_numerosEnteros(char* buffer, int longitud)
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
 * @brief Valida que la cadena sean solo letras y espacios
 *
 * @param cadena char*
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si hay un caracter que no es una letra] - retorna (0) si todoOk
 */
int validarSoloLetras_espacios(char* cadena, int limite)
{
	int retorno = -1;
	int i;

		if(cadena != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				if( *(cadena+i) != 32 && *(cadena+i) != 45 && ( *(cadena+i) < 65 || *(cadena+i) > 90) && ( *(cadena+i) < 97 || *(cadena+i) > 122))
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief Valida que sea correcta la cadena ingresada
 *
 * @param cadena char*
 * @param limite int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si hay un caracter que no es una letra] - retorna (0) si todoOk
 */
int validar_letrasEspaciosNumeros(char* cadena, int limite)
{
	int retorno = -1;
	int i;

		if(cadena != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				if( *(cadena+i) != 32 && *(cadena+i) != 45 && *(cadena+i) != 45 && ( *(cadena+i) < 65 || *(cadena+i) > 90) && ( *(cadena+i) < 97 || *(cadena+i) > 122) && ((*(cadena+i)) < 48 || (*(cadena+i)) > 57) )
				{
					retorno = 1;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief  valida que la cadena que se le pase sean numeros decimales
 *
 * @param buffer char*
 * @param longitud int
 * @return retorna (-1) [Si los punteros llegaron en NULL - la longitud es 0 o menor] - retorna (0) si todoOk
 */
int validarNumeroDecimal(char* buffer, int longitud)
{
	int retorno = -1;
	int i;
	int contador = 0;

		if(buffer != NULL && longitud > 0)
		{
			retorno = 0;

				for(i=0;i<longitud;i++)
				{
					if((*(buffer+i)) == 46)
					{
						contador++;
					}

					if( (contador > 1) || (( (*(buffer+i)) != 46 ) && ( (*(buffer+i)) < 48 || (*(buffer+i)) > 57)) )
					{
						retorno = 1;
						break;
					}



				}

		}

	return retorno;
}

/**
 * @brief  pide un numero que sea entero, tiene un minimo y un maximo valor a ingresar y le da x intentos de ingresarla bien
 *
 * @param numero Puntero* int
 * @param mensaje char*
 * @param mensajeError char*
 * @param min int
 * @param max int
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos)
{
	int retorno = -1;
	char buffer[4096];
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

					retornoNumero = validar_numerosEnteros(buffer, medirLongitud(buffer));

					numeroConvertido = atoi(buffer);

						if(retornoNumero == 0 && numeroConvertido >= min && numeroConvertido <= max)
						{
							retorno = 0;
							*numero = numeroConvertido;
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
 * @brief Le pide al usuario que ingrese una descripcion y le da x intentos para ingresarla bien
 *
 * @param cadena char
 * @param limite int
 * @param mensaje char
 * @param mensajeError char
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL - el limite es 0 o menor y los intentos son 0 o menor] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirDescripcion(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos)
{
	int retorno = -1;
	int retornoLetras;
	int retornolongitud;
	char buffer[4096];

		if(cadena != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0)
		{
			while(intentos >= 0)
			{
					retorno = 1;

					intentos--;

					printf("%s", mensaje);
						fflush(stdin);
						gets(buffer);

						retornolongitud = validarLongitud(buffer, limite, 3);
						retornoLetras = validarSoloLetras_espacios(buffer, medirLongitud(buffer));

						if(retornoLetras == 0 && retornolongitud == 0)
						{
							retorno = 0;
							strncpy(cadena, buffer, limite);
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
 * @brief pide un precio y valida que sea correcto, le da x cantidad de intentos al usuario de ingresarlo bien
 *
 * @param alfaNumerico char*
 * @param limite int
 * @param mensaje char*
 * @param mensajeError char*
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL - si el limite o los intentos son 0 o menor] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirPrecio(float* precio, char* mensaje, char*mensajeError, int minimo, int maximo,int intentos)
{
	int retorno = -1;
	char buffer[4096];
	int reportarLetrasNumeros;

		if(precio != NULL && mensaje != NULL && intentos > 0 && minimo >= 0 && maximo <= 1000000000)
		{
			retorno = 1;

				while(intentos >= 0)
				{
					intentos--;

					printf("%s", mensaje);
					fflush(stdin);
					gets(buffer);

					reportarLetrasNumeros = validarNumeroDecimal(buffer, medirLongitud(buffer));

						if(reportarLetrasNumeros == 0 && atof(buffer) >= minimo && atof(buffer) <= maximo )
						{
							(*precio) = atof(buffer);
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
 * @brief Le pide al usuario que ingrese el nombre de un texto y le da x intentos para ingresarla bien
 *
 * @param cadena char
 * @param limite int
 * @param mensaje char
 * @param mensajeError char
 * @param intentos int
 * @return retorna (-1) [Si los punteros llegaron en NULL - el limite o los intentos son 0 o menor] - retorna (1) [Si no respeta lo que se le pide] - retorna (0) si todoOk
 */
int pedirArchivo(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos)
{
	int retorno = -1;
	int retornoLetras;
	int retornolongitud;
	char buffer[4096];

		if(cadena != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0)
		{
			while(intentos >= 0)
			{
					retorno = 1;

					intentos--;

					printf("%s", mensaje);
						fflush(stdin);
						gets(buffer);

						retornolongitud = validarLongitud(buffer, limite, 3);
						retornoLetras = validar_letrasEspaciosNumeros(buffer, medirLongitud(buffer));

						if(retornoLetras == 0 && retornolongitud == 0)
						{
							retorno = 0;
							strncpy(cadena, buffer, limite);
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







