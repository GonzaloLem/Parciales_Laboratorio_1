#ifndef LISTAR_H_
#define LISTAR_H_

int imprimirLista(eVivienda* vivienda, eTipoVivienda* tipoVivienda, eCensista* censista);
int imprimirArrayLista(eVivienda* vivienda, int limitevivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista);

int asignarCensista(eVivienda* vivienda, int indice, eCensista* censista, int limiteCensista);

int listar_buscarCensista(int legajoCensista, eVivienda* vivienda, int limite, eTipoVivienda* tipoVivienda, int limiteTipoVivienda);
int imprimirArrayCensistaVivienda(eCensista* censista, int limiteCensista, eVivienda* vivienda, int limitevivienda, eTipoVivienda* tipoVivienda, int limiteTipovivienda);

int mejorCensista(eCensista* censista, int limiteCensista,eVivienda*  vivienda, int limiteVivienda);

#endif /* LISTAR_H_ */
