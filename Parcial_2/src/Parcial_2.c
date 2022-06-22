#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Menu.h"
#include "eServicios.h"
#include "utn_validaciones.h"
#include "Controlador.h"
#include "Analizador.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaServicios = ll_newLinkedList();
	LinkedList* auxilearLista = ll_newLinkedList();

	int opcion;

	int retornoLeer;
	int retornoGuardar;

	int banderaGuardar = 0;

		if(listaServicios != NULL)
		{
			do{

				imprimir_menuPrincipal();
				opcion = menu_validarOpcion(1, 11);

					switch(opcion)
					{
						case 1:
							retornoLeer = controlador_leearArchivo(auxilearLista);
								if(retornoLeer == 0)
								{
									listaServicios = ll_clone(auxilearLista);
									ll_clear(auxilearLista);
								}
						break;

						case 2:
							if( !ll_isEmpty(listaServicios) )
							{
								controlardor_imprimirLista(listaServicios);
							}
							else
							{
								printf("No hay servicios para imprimir\n");
							}

						break;

						case 3:
							if(!ll_isEmpty(listaServicios))
							{
								controlador_asignarTotales(listaServicios);
							}
							else
							{
								printf("No hay servicios para asignar totales\n");
							}
						break;

						case 4:
							if(!ll_isEmpty(listaServicios))
							{
								controlador_filtrar(listaServicios);
							}
							else
							{
								printf("No hay servicios para filtrar\n");
							}

						break;

						case 5:
							if(!ll_isEmpty(listaServicios))
							{
								controlador_ordenarServicios(listaServicios);
							}
							else
							{
								printf("No hay servicios para ordenar\n");
							}

						break;

						case 6:
							if(!ll_isEmpty(listaServicios))
							{
								retornoGuardar = controlador_guardarServicios(listaServicios);

									if(retornoGuardar == 0)
									{
										banderaGuardar = 1;
									}
							}
							else
							{
								printf("No hay servicios para guardar \n");
							}
						break;

						case 7:
							if(!ll_isEmpty(listaServicios))
							{
								opcion = menu_verificarGuardado(banderaGuardar);
							}
						break;

					}

			}while(opcion != 7);
		}

	return EXIT_SUCCESS;
}
