#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

int medirLongitud(char* cadena);
int validarLongitud(char* cadena, int limite, int minimo);

int validar_numerosEnteros(char* buffer, int longitud);
int pedirNumeroEntero(int* numero, char* mensaje, char* mensajeError, int min, int max,  int intentos);

int validarSoloLetras_espacios(char* cadena, int limite);
int pedirDescripcion(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos);

int validarNumeroDecimal(char* buffer, int longitud);
int pedirPrecio(float* precio, char* mensaje, char*mensajeError, int minimo, int maximo,int intentos);

int validar_letrasEspaciosNumeros(char* cadena, int limite);
int pedirArchivo(char* cadena, int limite, char* mensaje, char* mensajeError, int intentos);



#endif /* UTN_VALIDACIONES_H_ */
