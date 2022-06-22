#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"
#include "Menu.h"

/**
 * @brief imprime las opciones del menu
 *
 */
void imprimir_menuPrincipal()
{
	printf("\n1)Cargar Archivo\n"
			"2)imprimir Lista\n"
			"3)Asignar Totales\n"
			"4)Filtrar por Tipo\n"
			"5)Mostrar servicios\n"
			"6)Guardar servicios\n"
			"7)Salir\n");

	/*printf("\n1)Cargar Archivo\n"
			"2)imprimir Lista\n"
			"3)Asignar Totales\n"
			"4)Filtrar por Tipo\n"
			"5)Mostrar servicios\n"
			"6)Guardar servicios\n"
			"7)Alta Servicio\n"
			"8)Modificar Servicio\n"
			"9)Baja servicio\n"
			"10)Salir\n");*/
}

void imprimir_menuModificar()
{
	printf("\n1)Modifcar descripcion\n"
			"2)Modificar Tipo\n"
			"3)Modificar precio\n"
			"4)Modificar Cantidad\n"
			"5)Salir\n");
}

/**
 * @brief pide una opcion y valida que este entre las opciones del menu
 *
 * @param minimo int opcion minima
 * @param maximo int opcion maxima
 * @return retorna (-1) [Si se pasa del minimo y el maximo] - retorna (La opcion elegida) si todoOk
 */
int menu_validarOpcion(int minimo, int maximo)
{
	int opcion = -1;

		if(minimo >= 0 && maximo < 20)
		{
			pedirNumeroEntero(&opcion, "-Opcion: ", "Error. Ingrese una opcion valida\n", minimo, maximo,  1);
		}


	return opcion;
}

int menu_verificarGuardado(int bandera)
{
	int retorno = -1;
	int retornoOpcion;

	int opcion;

		if(bandera >= 0)
		{
			retorno = 7;
			if(bandera == 0)
			{
				printf("No se guardo ningun dato. ¿Esta seguro que quiere salir?\n"
						"1) regresar\n"
						"2) salir\n");

				retornoOpcion = pedirNumeroEntero(&opcion, "-opcion: ", "Error. Ingrese lo que se le pide\n", 1, 2,  2);

					if(retornoOpcion == 0)
					{
						switch(opcion)
						{
							case 1:
								retorno = 0;
							break;

							case 2:
								retorno = 7;
							break;
						}
					}
			}
		}
	return retorno;
}

