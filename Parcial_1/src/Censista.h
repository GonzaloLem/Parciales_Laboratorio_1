#define LIMITE_CARACTER 51

typedef struct{

	int legajoCensista;
	char nombre[LIMITE_CARACTER];
	int edad;
	char telefono[LIMITE_CARACTER];

}eCensista;

#ifndef CENSISTA_H_
#define CENSISTA_H_

int imprimirCensista(eCensista* censista);
int imprimirArrayCensista(eCensista* censista, int limite);

int verificarCensista(eCensista* censista, int limite, char* nombre);
int buscarCensista(int legajo, eCensista* censista, int limite);

//int asignarCensista(int* legajo, eCensista* censista, int limite);


#endif /* CENSISTA_H_ */
