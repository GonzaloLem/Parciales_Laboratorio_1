#define LIMITE_ALFANUMERICO 25
#define LIMITE_CARACTER 51
#define LIMITE_DESCRIPCION 51

typedef struct{

	int idTipoVivienda;
	char descripcion[LIMITE_DESCRIPCION];

}eTipoVivienda;

typedef struct{

	int idVivienda;
	char calle[LIMITE_ALFANUMERICO];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int isEmpty;

	//int idTipoVivienda;
	int legajoCensista;

}eVivienda;

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

typedef int(*funcionOrdenar)(eVivienda*, int);

int iniciarIsEmpty(eVivienda* vivienda, int limite);
int buscarLibre(eVivienda* vivienda, int limiteVivienda);
int buscarViviendaCargada(eVivienda* vivienda, int limiteVivienda);
int asignarId(int* id , int* contador);

int verificarVivienda(eTipoVivienda* tipoVivienda, int limiteVivienda, int opcionVivienda, int* guardarId);
int altaVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda);

int buscarTipoVivienda(int idTipoVivienda, eTipoVivienda* tipoVivienda, int limite);

int buscarId(eVivienda* vivienda, int limite, int id);
int modificarDatoVivienda(eVivienda* vivienda, int indice, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, int opcion);

int darDeBaja(eVivienda* vivienda, int indice);

int imprimirVivienda(eVivienda* vivienda, eTipoVivienda* tipoVivienda);
int imprimirArrayVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda);
int vivienda_ordenarCalle(eVivienda* vivienda, int limiteVivienda);
int ordenarViviendas(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, funcionOrdenar ordenarVivienda);

int forzarAltaVivienda(eVivienda* vivienda, int indice, int* id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);
#endif /* VIVIENDA_H_ */
