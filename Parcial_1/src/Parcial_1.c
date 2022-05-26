/*
 * Nombre: Gonzalo
 * Apellido: Lemiña
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "Vivienda.h"
#include "Censista.h"
#include "utn_Validaciones.h"
#include  "Listar.h"

#define CANTIDAD_CENSISTA 3
#define CANTIDAD_VIVIENDA 2000
#define CANTIDAD_TIPO_VIVIENDA 4

int main(void) {

	setbuf(stdout, NULL);

	eCensista censista[CANTIDAD_CENSISTA] = { {100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-54678"}, {102, "Sol", 47, "5902-37487"} };
	eTipoVivienda tipoVivienda[CANTIDAD_TIPO_VIVIENDA] = { {200, "Casa"}, {201, "Departamento"}, {202, "Casilla"}, {203, "Rancho"} };
	eVivienda vivienda[CANTIDAD_VIVIENDA];

	funcionOrdenar ordenarVivienda;

	int opcionMenuPrincipal;
	int opcionMenuSecundario;
	int contador = 20000;
	int idDeVivienda;
	int id;
	int indice;
	int indiceModificar;
	int indiceBaja;
	int bandera = 1;

	int retornoAlta;
	int retornoCensista;
	int retornoIdModificar;
	int retornoIdBaja;

	ordenarVivienda = vivienda_ordenarCalle;

		iniciarIsEmpty(vivienda, CANTIDAD_VIVIENDA);

		//funcion para forzar datos
		forzarAltaVivienda(vivienda, 0, &contador, "Piedra buena 341", 4, 2, 202, 102);
		forzarAltaVivienda(vivienda, 1, &contador, "Libres del sur 17", 8, 3, 200, 101);
		forzarAltaVivienda(vivienda, 2, &contador, "9 de Febrero 265", 2, 111, 200, 102);
		forzarAltaVivienda(vivienda, 3, &contador, "Acevedo 112", 88, 55, 201, 102);
		forzarAltaVivienda(vivienda, 4, &contador, "Zapiola 832", 9, 2, 203, 100);

		do{

			 imprimirMenu();
			 validarOpcion(&opcionMenuPrincipal);
			 bandera = buscarViviendaCargada(vivienda, CANTIDAD_VIVIENDA);
			 	 switch(opcionMenuPrincipal)
			 	 {
			 	 	 case 1:
		 	 		 	indice = buscarLibre(vivienda, CANTIDAD_VIVIENDA);
			 	 		retornoAlta = altaVivienda(vivienda, indice, tipoVivienda, CANTIDAD_TIPO_VIVIENDA);

			 	 		 	 if(retornoAlta == 0)
			 	 		 	 {
			 	 		 		imprimirArrayCensista(censista,CANTIDAD_CENSISTA);
			 	 		 		retornoCensista = asignarCensista( vivienda, indice, censista, CANTIDAD_CENSISTA);
			 	 		 			if(retornoCensista == 0)
			 	 		 			{
			 	 						asignarId(&idDeVivienda , &contador);

			 	 						(*(vivienda+indice)).idVivienda = idDeVivienda;
					 	 		 		(*(vivienda+indice)).isEmpty = 0;
			 	 		 			}
					 	 		 	 else
					 	 		 	 {
					 	 		 		 printf("ERROR en el Censista. Los datos no fueron cargados correctamente\n");
					 	 		 	 }
			 	 		 	 }
			 	 		 	 else
			 	 		 	 {
			 	 		 		 printf("ERROR en el Alta. Los datos no fueron cargados correctamente\n");
			 	 		 	 }
			 	 	 break;

			 	 	 case 2:
			 	 		 if(bandera == 0)
			 	 		 {
			 	 			imprimirArrayVivienda(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA);
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
			 	 			imprimirArrayVivienda(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA);
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
			 	 			ordenarViviendas(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA, ordenarVivienda);
			 	 			imprimirArrayLista(vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_VIVIENDA, censista, CANTIDAD_CENSISTA);
			 	 		 }

			 	 	break;

			 	 	case 5:
			 	 		imprimirArrayCensista(censista,CANTIDAD_CENSISTA);
			 	 	break;

			 	 	case 6:
			 	 		imprimirArrayCensistaVivienda(censista, CANTIDAD_CENSISTA, vivienda, CANTIDAD_VIVIENDA, tipoVivienda, CANTIDAD_TIPO_VIVIENDA);
			 	 	break;

			 	 	case 7:
			 	 		mejorCensista(censista, CANTIDAD_CENSISTA, vivienda, CANTIDAD_VIVIENDA);
			 	 	break;
			 	 	 case 8:
			 	 		 printf("Cerrando programa\n");
			 	 		 system("PAUSE");
			 	  	 break;
			 	 }


		}while(opcionMenuPrincipal != 8);


	return EXIT_SUCCESS;
}
