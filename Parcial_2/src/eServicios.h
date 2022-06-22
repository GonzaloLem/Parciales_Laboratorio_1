#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

#define LIMITE_DESCRIPCION 61

typedef struct{

	int id_servicio;
	char descripcion[LIMITE_DESCRIPCION];
	int tipo;
	float precioUnitario;
	int cantidad;
	int total;

}eServicio;

eServicio* eServicio_nuevo(void);
eServicio* eServicio_nuevosParametros(int id, char* descripcion, int tipo, float precioUnitario, int cantidad, int total);
eServicio* eServicio_nuevosParametrosTxt(char* idTxt, char* descripcionTxt, char* tipoTxt, char* precioUnitarioTxt, char* cantidadTxt, char* totalTxt);

int eServicio_establecerId(eServicio* this, int id);
int eServicio_establecerIdTxt(eServicio* this, char* id);
int eServicio_obtenerId(eServicio* this, int* id);
int eServicio_obtenerIdTxt(eServicio* this, char* id);

int eServicio_establecerDescripcion(eServicio* this, char* descripcion);
int eServicio_obtenerDescripcion(eServicio* this, char* descripcion);

int eServicio_establecerTipo(eServicio* this, int tipo);
int eServicio_obtenerTipo(eServicio* this, int* tipo);
int eServicio_establecerTipoTxt(eServicio* this, char* tipo);
int eServicio_obtenerTipoTxt(eServicio* this, char* tipo);

int eServicio_establecerPrecioUnitario(eServicio* this, float precio);
int eServicio_establecerPrecioUnitarioTxt(eServicio* this, char* precio);
int eServicio_obtenerPrecioUnitario(eServicio* this, float* precio);
int eServicio_obtenerPrecioUnitarioTxt(eServicio* this, char* precio);

int eServicio_establecerCantidad(eServicio* this, int cantidad);
int eServicio_establecerCantidadTxt(eServicio* this, char* cantidad);
int eServicio_obtenerCantidad(eServicio* this, int* cantidad);
int eServicio_obtenerCantidadTxt(eServicio* this, char* cantidad);

int eServicio_establecerTotal(eServicio* this, int total);
int eServicio_establecerTotalTxt(eServicio* this, char* total);
int eServicio_obtenerTotal(eServicio* this, int* total);
int eServicio_obtenerTotalTxt(eServicio* this, char* total);

int eServicio_agregarTipo(eServicio* servicio, int tipo, char* tipotxt);
int eServicio_imprimirLista(eServicio* servicio);

void asignarTotal(void* element);
int eServicio_filtrarServiciosTipoUno(void* elemento);
int eServicio_filtrarServiciosTipoDos(void* elemento);
int eServicio_filtrarServiciosTipoTres(void* elemento);
int eServicio_ordenarDescripcion(void* servicioUno,void* servicioDos);

int emparejarDatos(LinkedList* pArrayListaServicios);

/*
int eServicio_reAsignarId(LinkedList* pArrayListaServicio, int id);
int eServicio_asignarId(LinkedList* pArrayListaServicio);
eServicio* eServicio_agregarServicio();

int eServicio_buscarId(LinkedList* pArrayListaServicios, int id);
int eServicio_pedirId(LinkedList* pArrayListaServicios);
int eServicio_modificarServicio(eServicio* servicio);*/



#endif /* ESERVICIOS_H_ */
