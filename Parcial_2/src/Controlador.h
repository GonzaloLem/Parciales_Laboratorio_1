#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#define LIMITE_ARCHIVO 50

int controlador_leearArchivo(LinkedList* pArrayListaServicios);
int controlardor_imprimirLista(LinkedList* pArrayListaServicios);
int controlador_asignarTotales(LinkedList* pArraylistaServicios);
int controlador_filtrar(LinkedList* pArraylistaServicios);
int controlador_ordenarServicios(LinkedList* pArraylistaServicios);
int controlador_guardarServicios(LinkedList* pArraylistaServicios);

/*
int controlador_altaServicio(LinkedList* pArrayListaServicios);
int controlador_modificarServicio(LinkedList* pArrayListaServicios);
int controlador_eliminarServicio(LinkedList* pArrayListaServicios);

int controlador_reasignarId(LinkedList* auxilearLista, LinkedList* listaServicios);
*/

#endif /* CONTROLADOR_H_ */
