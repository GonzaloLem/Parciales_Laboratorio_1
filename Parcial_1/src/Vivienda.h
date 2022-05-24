
#define LIMITE_ALFANUMERICO 25
#define LIMITE_CARACTER 51
#define LIMITE_DESCRIPCION 51

typedef struct{

	int idTipoVivienda;
	char descripcion[LIMITE_DESCRIPCION];

}eTipoVivienda;

typedef struct{

	int legajoCensista;
	char nombre[LIMITE_CARACTER];
	int edad;
	char telefono[LIMITE_CARACTER];

}eCensista;

typedef struct{

	int idVivienda;
	char calle[LIMITE_ALFANUMERICO];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int isEmpty;

	int idTipoVivienda;
	int legajoCensista;

}eVivienda;

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

typedef int(*funcionOrdenar)(eVivienda*, int);

int iniciarIsEmpty(eVivienda* vivienda, int limite);
int buscarLibre(eVivienda* vivienda, int limiteVivienda);
int buscarViviendaCargada(eVivienda* vivienda, int limiteVivienda);
int asignarId(int* id , int** contador);


int verificarVivienda(eTipoVivienda* tipoVivienda, int limiteVivienda, int opcionVivienda, int* guardarId);
int imprimirCensista(eCensista* censista, int limite);
int verificarCensista(eCensista* censista, int limite, char* nombre);
int altaVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista, int* contador);

int buscarTipoVivienda(int idTipoVivienda, eTipoVivienda* tipoVivienda, int limite);
int buscarCensista(int legajo, eCensista* censista, int limite);

int buscarId(eVivienda* vivienda, int limite, int id);
int modificarDatoVivienda(eVivienda* vivienda, int indice, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, int opcion);

int darDeBaja(eVivienda* vivienda, int indice);

int imprimirVivienda(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista);
int vivienda_ordenarCalle(eVivienda* vivienda, int limiteVivienda);
int ordenarViviendas(eVivienda* vivienda, int limiteVivienda, eTipoVivienda* tipoVivienda, int limiteTipoVivienda, eCensista* censista, int limiteCensista, funcionOrdenar ordenarPorCalle);

#endif /* VIVIENDA_H_ */
