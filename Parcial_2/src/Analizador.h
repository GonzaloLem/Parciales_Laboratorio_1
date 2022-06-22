#ifndef ANALIZADOR_H_
#define ANALIZADOR_H_

int archivo_pedirArchivo(char* ruta, int limiteArchivo);

int archivo_leerServicios(FILE* archivo, LinkedList* pArrayListaServicios);
int archivo_guardarDatos(LinkedList* pArrayListaServicios, char* ruta);
int archivo_filtrarLista(LinkedList* pArrayListaServicios, char* ruta);


#endif /* ANALIZADOR_H_ */
