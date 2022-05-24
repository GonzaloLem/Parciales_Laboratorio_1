#ifndef LISTAR_H_
#define LISTAR_H_

int imprimirLista(eVivienda* vivienda, eTipoVivienda* tipoVivienda, eCensista* censista);
int imprimirArrayLista(eVivienda* vivienda, int limitevivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista);

int asignarCensista(eVivienda* vivienda, int indice, eCensista* censista, int limiteCensista);

#endif /* LISTAR_H_ */
