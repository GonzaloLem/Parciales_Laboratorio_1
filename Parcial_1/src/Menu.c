#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Validaciones.h"

void imprimirMenu()
{
	printf("\n1)Alta Vivienda\n"
			"2)Modificar Vivienda\n"
			"3)Baja Vivienda\n"
			"4)Listar Viviendas\n"
			"5)Listar Cencista\n"
			"6)Salir\n"
			"-Opcion: ");
}

void imprimirMenuSecundario()
{
	printf("\n1)Modificar Calle\n"
			"2)Modificar la cantidad de Personas\n"
			"3)Modificar la cantidad de Habitaciones\n"
			"4)Modificar el tipo de Vivienda\n"
			"5)Salir\n"
			"-Opcion: ");
}

int validarOpcion(int* opcion)
{
	int retorno = -1;
	char buffer[4096];
	int longitud;
	int retornoSoloNumeros;

		if(opcion > 0)
		{
			retorno = 1;

				fflush(stdin);
				gets(buffer);


				medirLongitud(buffer, &longitud);
				retornoSoloNumeros = validarSoloNumerosEnteros(buffer, longitud);

					if(retornoSoloNumeros == 0)
					{
						(*opcion) = atoi(buffer);
					}
					else
					{
						printf("Solo se pueden ingresar numeros\n");

						(*opcion) = 0;
					}


		}

	return retorno;
}