
#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

int medirLongitud(char* cadena, int* longitud);
int contadorDeId(int* contadorId);

int validarLongitud(char* cadena, int limite);
int validarSololetrasNumeros(char* cadena, int limite);
int pedirNumeroAlfanumerico(char* alfaNumerico, int len, char* mensaje, char*mensajeError, int intentos);

int validarSoloNumerosEnteros(char* buffer, int longitud);
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos);

int validarSoloLetras(char* cadena, int limite);
int pedirNombreOapellido(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos);

#endif /* UTN_VALIDACIONES_H_ */
