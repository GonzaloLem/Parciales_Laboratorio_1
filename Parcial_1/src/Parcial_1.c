#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Vivienda.h"
#include "Validaciones.h"

#define CANTIDAD_CENSISTA 3
#define CANTIDAD_VIVIENDA 2000
#define CANTIDAD_TIPO_VIVIENDA 4

int main(void) {

	setbuf(stdout, NULL);

	eCensista censista[CANTIDAD_CENSISTA] = { {100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"} };
	eTipoVivienda tipoVivienda[CANTIDAD_TIPO_VIVIENDA] = { {200, "Casa"}, {201, "Departamento"}, {202, "Casilla"}, {203, "Rancho"} };
	eVivienda vivienda[CANTIDAD_VIVIENDA];

	funcionOrdenar ordenarPorCalle;

	int opcionMenuPrincipal;
	int opcionMenuSecundario;
	int contador = 20000;
	int id;
	int indiceModificar;
	int indiceBaja;
	int bandera = 1;

	int retornoIdModificar;
	int retornoIdBaja;

	ordenarPorCalle = vivienda_ordenarCalle;

		iniciarIsEmpty(vivienda, CANTIDAD_VIVIENDA);

		do{

			 imprimirMenu();
			 validarOpcion(&opcionMenuPrincipal);
			 bandera = buscarViviendaCargada(vivienda, CANTIDAD_VIVIENDA);
			 	 switch(opcionMenuPrincipal)
			 	 {
			 	 	 case 1:
			 	 		 altaVivienda(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, censista, CANTIDAD_CENSISTA, &contador);
			 	 	 break;

			 	 	 case 2:
			 	 		 if(bandera == 0)
			 	 		 {
			 	 			imprimirVivienda(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, censista, CANTIDAD_CENSISTA);
			 	 			retornoIdModificar = pedirNumeroEntero(&id, "Ingrese el ID de la Vivienda: ", "Error. ingrese lo que se le pide.\n", 20000, 22000, 2);

								if(retornoIdModificar == 0)
								{
									indiceModificar = buscarId(vivienda, CANTIDAD_VIVIENDA, id);

										if(indiceModificar != -1 && indiceModificar != -2)
										{
											do{

												 imprimirMenuSecundario();
												 validarOpcion(&opcionMenuSecundario);

												 	 switch(opcionMenuSecundario)
												 	 {
												 	 	 case 1:
												 	 		 modificarDatoVivienda(vivienda, indiceModificar, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, 1);
												 	     break;

												 	 	 case 2:
												 	 		modificarDatoVivienda(vivienda, indiceModificar, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, 2);
												 	 	 break;

												 	 	 case 3:
												 	 		modificarDatoVivienda(vivienda, indiceModificar, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, 3);
												 	 	 break;

												 	 	 case 4:
												 	 		modificarDatoVivienda(vivienda, indiceModificar, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, 4);
												 	 	 break;
												 	 }

											}while(opcionMenuSecundario != 5);

										}

								}
			 	 		 }
			 	     break;

			 	 	 case 3:
			 	 		 if(bandera == 0)
			 	 		 {
			 	 			imprimirVivienda(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, censista, CANTIDAD_CENSISTA);
							retornoIdBaja = pedirNumeroEntero(&id, "Ingrese el ID de la Vivienda: ", "Error. ingrese lo que se le pide.\n", 20000, 22000, 2);

								if(retornoIdBaja == 0)
								{
									indiceBaja = buscarId(vivienda, CANTIDAD_VIVIENDA, id);

										if(indiceBaja != -1 && indiceBaja != -2)
										{
											darDeBaja(vivienda, indiceBaja);
										}
								}
			 	 		 }
			 	 	 break;

			 	 	 case 4:
			 	 		 if(bandera == 0)
			 	 		 {
			 	 			ordenarViviendas(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_VIVIENDA, censista, CANTIDAD_CENSISTA, ordenarPorCalle);
			 	 		 }

			 	 	break;

			 	 	case 5:
			 	 		imprimirCensista(censista, CANTIDAD_CENSISTA);
			 	 	break;

			 	 	 case 6:
			 	 		 printf("Cerrando programa\n");
			 	 		 system("PAUSE");
			 	  	 break;
			 	 }


		}while(opcionMenuPrincipal != 6);


	return EXIT_SUCCESS;
}
