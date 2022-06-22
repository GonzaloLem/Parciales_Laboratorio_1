#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controlador.h"
#include "utn_validaciones.h"
#include "Menu.h"
#include "eServicios.h"

/**
 * @brief Pide memoria dinamica y la retorna
 *
 * @return Puntero eServicio*
 */
eServicio* eServicio_nuevo(void)
{
	return (eServicio*)malloc(sizeof(eServicio));
}

/**
 * @brief crea un servicio con los datos de los parametros que se le pasan
 *
 * @param id int
 * @param descripcion char*
 * @param tipo char*
 * @param precioUnitario float
 * @param cantidad int
 * @param total int
 * @return retorna (NULL) [Si no pudo conseguir espacio en la memoria dinamica] - retorna (*eServicio) si todoOK
 */
eServicio* eServicio_nuevosParametros(int id, char* descripcion, int tipo, float precioUnitario, int cantidad, int total)
{
	eServicio* servicio = NULL;

		servicio = eServicio_nuevo();

			if(servicio != NULL && id >= 0 && descripcion != NULL && tipo >= 0 && precioUnitario >= 0 && cantidad >= 0 && total >= 0)
			{
				eServicio_establecerId(servicio, id);
				eServicio_establecerDescripcion(servicio, descripcion);
				eServicio_establecerTipo(servicio, tipo);
				eServicio_establecerPrecioUnitario(servicio, precioUnitario);
				eServicio_establecerCantidad(servicio, cantidad);
				eServicio_establecerTotal(servicio, total);
			}

	return servicio;
}

/**
 * @brief crea un servicio con los datos (todoss llegan como char) de los parametros que se le pasan
 *
 * @param id char*
 * @param descripcion char*
 * @param tipo char*
 * @param precioUnitario char*
 * @param cantidad char*
 * @param total char*
 * @return retorna (NULL) [Si no pudo conseguir espacio en la memoria dinamica] - retorna (*eServicio) si todoOK
 */
eServicio* eServicio_nuevosParametrosTxt(char* idTxt, char* descripcionTxt, char* tipoTxt, char* precioUnitarioTxt, char* cantidadTxt, char* totalTxt)
{
	eServicio* servicio = NULL;

		servicio = eServicio_nuevo();

			if(servicio != NULL && idTxt != NULL && descripcionTxt != NULL && tipoTxt != NULL && precioUnitarioTxt != NULL && cantidadTxt != NULL && totalTxt != NULL)
			{
				eServicio_establecerIdTxt(servicio, idTxt);
				eServicio_establecerDescripcion(servicio, descripcionTxt);
				eServicio_establecerTipoTxt(servicio, tipoTxt);
				eServicio_establecerPrecioUnitarioTxt(servicio, precioUnitarioTxt);
				eServicio_establecerCantidadTxt(servicio, cantidadTxt);
				eServicio_establecerTotalTxt(servicio, totalTxt);
			}

	return servicio;
}

/**
 * @brief establece un id a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param id int
 * @return retorno (-1) [Si la estructura es NULL o el id es menor a 0] - retorno (0) [TodoOk]
 */
int eServicio_establecerId(eServicio* this, int id)
{
	int retorno = -1;

		if(this != NULL && id >= 0)
		{
			retorno = 0;

			this->id_servicio = id;

		}

	return retorno;
}

/**
 * @brief establece un id pasandole una variable tipo char a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param id char
 * @return retorno (-1) [Si algunos de los punteros es NULL] - retorno (0) [TodoOk]
 */
int eServicio_establecerIdTxt(eServicio* this, char* id)
{
	int retorno = -1;

		if(this != NULL && id != NULL)
		{
			if( !validar_numerosEnteros(id, medirLongitud(id)) )
			{
				retorno = 0;
				this->id_servicio = atoi(id);
			}

		}

	return retorno;
}

/**
 * @brief obtiene un id de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param id int*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerId(eServicio* this, int* id)
{
	int retorno = -1;

		if(this != NULL && id != NULL)
		{
			retorno = 0;
			(*id) = this->id_servicio;
		}

	return retorno;
}

/**
 * @brief obtiene una id de la entidad eServicio y se la pasa a una variable de tipo char
 *
 * @param this Puntero* eServicio
 * @param id char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerIdTxt(eServicio* this, char* id)
{
	int retorno = -1;

		if(this != NULL && id != NULL)
		{
			retorno = 0;
			sprintf(id, "%d", this->id_servicio);
		}

	return retorno;
}

/**
 * @brief establece una descripcion de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param descripcion char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_establecerDescripcion(eServicio* this, char* descripcion)
{
	int retorno = -1;

		if(this != NULL && descripcion != NULL)
		{
			if( !validarSoloLetras_espacios(descripcion, medirLongitud(descripcion)))
			{
				retorno = 0;
				strncpy(this->descripcion, descripcion, LIMITE_DESCRIPCION);
			}

		}

	return retorno;
}
/**
 * @brief obtiene una descripcion de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param descripcion char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerDescripcion(eServicio* this, char* descripcion)
{
	int retorno = -1;

		if(this != NULL && descripcion != NULL)
		{
			retorno = 0;
			strncpy(descripcion, this->descripcion,LIMITE_DESCRIPCION);
		}

	return retorno;
}

/**
 * @brief establece un tipo de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param tipo int
 * @return retorno (-1)  [Si el puntero es NULL - el tipo es menor a 0]  - retorno (0) [TodoOk]
 */
int eServicio_establecerTipo(eServicio* this, int tipo)
{
	int retorno = -1;

		if(this != NULL && tipo >= 0)
		{
			retorno = 0;
			this->tipo = tipo;
		}

	return retorno;
}
/**
 * @brief obtiene un tipo de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param tipo char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerTipo(eServicio* this, int* tipo)
{
	int retorno = -1;

		if(this != NULL && tipo != NULL)
		{
			retorno = 0;
			(*tipo) = this->tipo;
		}

	return retorno;
}

/**
 * @brief establece un tipo de la entidad eServicio pasandole una variable char
 *
 * @param this Puntero* eServicio
 * @param tipo char*
 * @return retorno (-1)  [Si el puntero es NULL - el tipo es menor a 0]  - retorno (0) [TodoOk]
 */
int eServicio_establecerTipoTxt(eServicio* this, char* tipo)
{
	int retorno = -1;

		if(this != NULL && tipo != NULL)
		{
			if( !validar_numerosEnteros(tipo, medirLongitud(tipo)))
			{
				retorno = 0;
				this->tipo = atoi(tipo);
			}
		}

	return retorno;
}
/**
 * @brief obtiene un tipo de la entidad eServicio y se lo pasa a una variable char
 *
 * @param this Puntero* eServicio
 * @param tipo char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerTipoTxt(eServicio* this, char* tipo)
{
	int retorno = -1;

		if(this != NULL && tipo != NULL)
		{
			retorno = 0;
			sprintf(tipo, "%d", this->tipo);
		}

	return retorno;
}

/**
 * @brief establece el precio unitario de la entidad eServicio
 *
 * @param this	Puntero* eServicio
 * @param precio float
 * @return retorno (-1) [Si la estructura es NULL o el precio es menor a 0] - retorno (0) [TodoOk]
 */
int eServicio_establecerPrecioUnitario(eServicio* this, float precio)
{
	int retorno = -1;

		if(this != NULL && precio >= 0)
		{
				retorno = 0;
				this->precioUnitario = precio;
		}

	return retorno;
}

/**
 * @brief establece el precio unitario de la entidad eServicio pasandole una variable tipo char
 *
 * @param this	Puntero* eServicio
 * @param precio char*
 * @return retorno (-1) [Si la estructura o la variable es NULL] - retorno (0) [TodoOk]
 */
int eServicio_establecerPrecioUnitarioTxt(eServicio* this, char* precio)
{
	int retorno = -1;

		if(this != NULL && precio >= 0)
		{
			if( !validarNumeroDecimal(precio, medirLongitud(precio)))
			{
				retorno = 0;
				this->precioUnitario = atof(precio);
			}

		}

	return retorno;
}

/**
 * @brief	obtiene el precio de la entidad eServicio
 *
 * @param this	Puntero* eServicio
 * @param precio float*
 * @return	 retorno (-1) [Si la estructura o la variable es NULL] - retorno (0) [TodoOk]
 */
int eServicio_obtenerPrecioUnitario(eServicio* this, float* precio)
{
	int retorno = -1;

		if(this != NULL && precio != NULL)
		{
			retorno = 0;
			(*precio) = this->precioUnitario;
		}

	return retorno;
}

/**
 * @brief	obtiene el precio de la entidad eServicio y se lo pasa a una variable tipo char
 *
 * @param this	Puntero* eServicio
 * @param precio char*
 * @return retorno (-1) [Si la estructura o la variable es NULL] - retorno (0) [TodoOk]
 */
int eServicio_obtenerPrecioUnitarioTxt(eServicio* this, char* precio)
{
	int retorno = -1;

		if(this != NULL && precio != NULL)
		{
			retorno = 0;
			sprintf(precio, "%f", this->precioUnitario);
		}

	return retorno;
}

/**
 * @brief establece una cantidad a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param cantidad int
 * @return retorno (-1) [Si la estructura es NULL o la cantidad es menor a 0] - retorno (0) [TodoOk]
 */
int eServicio_establecerCantidad(eServicio* this, int cantidad)
{
	int retorno = -1;

		if(this != NULL && cantidad >= 0)
		{
			retorno = 0;

			this->cantidad = cantidad;

		}

	return retorno;
}

/**
 * @brief establece una cantidad pasandole una variable tipo char a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param cantidad char
 * @return retorno (-1) [Si algunos de los punteros es NULL] - retorno (0) [TodoOk]
 */
int eServicio_establecerCantidadTxt(eServicio* this, char* cantidad)
{
	int retorno = -1;

		if(this != NULL && cantidad != NULL)
		{
			if( !validar_numerosEnteros(cantidad, medirLongitud(cantidad)) )
			{
				retorno = 0;
				this->cantidad = atoi(cantidad);
			}

		}

	return retorno;
}

/**
 * @brief obtiene una cantidad de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param cantidad int*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerCantidad(eServicio* this, int* cantidad)
{
	int retorno = -1;

		if(this != NULL && cantidad != NULL)
		{
			retorno = 0;
			(*cantidad) = this->cantidad;
		}

	return retorno;
}

/**
 * @brief obtiene una cantidad de la entidad eServicio y se la pasa a una variable de tipo char
 *
 * @param this Puntero* eServicio
 * @param cantidad char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerCantidadTxt(eServicio* this, char* cantidad)
{
	int retorno = -1;

		if(this != NULL && cantidad != NULL)
		{
			retorno = 0;
			sprintf(cantidad, "%d", this->cantidad);
		}

	return retorno;
}

/**
 * @brief establece un total a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param total int
 * @return retorno (-1) [Si la estructura es NULL o el total es menor a 0] - retorno (0) [TodoOk]
 */
int eServicio_establecerTotal(eServicio* this, int total)
{
	int retorno = -1;

		if(this != NULL && total >= 0)
		{
			retorno = 0;

			this->total = total;

		}

	return retorno;
}

/**
 * @brief establece un total pasandole una variable tipo char a la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param total char
 * @return retorno (-1) [Si algunos de los punteros es NULL] - retorno (0) [TodoOk]
 */
int eServicio_establecerTotalTxt(eServicio* this, char* total)
{
	int retorno = -1;

		if(this != NULL && total != NULL)
		{
			if( !validar_numerosEnteros(total, medirLongitud(total)) )
			{
				retorno = 0;
				this->total = atoi(total);
			}

		}

	return retorno;
}

/**
 * @brief obtiene un total de la entidad eServicio
 *
 * @param this Puntero* eServicio
 * @param total int*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerTotal(eServicio* this, int* total)
{
	int retorno = -1;

		if(this != NULL && total != NULL)
		{
			retorno = 0;
			(*total) = this->total;
		}

	return retorno;
}

/**
 * @brief obtiene un total de la entidad eServicio y se la pasa a una variable de tipo char
 *
 * @param this Puntero* eServicio
 * @param total char*
 * @return retorno (-1)  [Si algunos de los punteros es NULL]  - retorno (0) [TodoOk]
 */
int eServicio_obtenerTotalTxt(eServicio* this, char* total)
{
	int retorno = -1;

		if(this != NULL && total != NULL)
		{
			retorno = 0;
			sprintf(total, "%d", this->total);
		}

	return retorno;
}

/**
 * @brief dependiendo del tipo le asigna a la variable tipoTxt un nombre
 *
 * @param servicio eServicio* Puntero al servicio
 * @param tipo int
 * @param tipotxt char*
 * @return retorna (-1) [Si los punteros llegaron en NULL - el tipo se pasa de los limites] - retorna (0) todoOk
 */
int eServicio_agregarTipo(eServicio* servicio, int tipo, char* tipotxt)
{
	int retorno = -1;

		if(tipo > 0 && tipo < 4)
		{
			retorno = 0;
			switch(tipo)
			{
				case 1:
					strcpy(tipotxt, "1)Minorista");
				break;

				case 2:
					strcpy(tipotxt, "2)Mayorista");
				break;

				case 3:
					strcpy(tipotxt, "3)Exportar");
				break;
			}
		}

	return retorno;
}

/**
 * @brief Se encarga de imprimir el servicio que le pasaron
 *
 * @param servicio eServicio* puntero al servicio
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOK
 */
int eServicio_imprimirLista(eServicio* servicio)
{

	int retorno = -1;

	int id;
	char descripcion[LIMITE_DESCRIPCION];
	int tipo;
	char tipoTxt[26];
	float precio;
	int cantidad;
	int total;

		if(servicio != NULL)
		{
			retorno = 0;

			eServicio_obtenerId(servicio, &id);
			eServicio_obtenerDescripcion(servicio, descripcion);
			eServicio_obtenerTipo(servicio, &tipo);
			eServicio_obtenerPrecioUnitario(servicio, &precio);
			eServicio_obtenerCantidad(servicio, &cantidad);
			eServicio_obtenerTotal(servicio, &total);
			eServicio_agregarTipo(servicio, tipo, tipoTxt);

			printf("%d    "
					"%s                 "
					"%s                             "
					"%.2f               "
					"%d                   "
					"%d\n",
					id,
					descripcion,
					tipoTxt,
					precio,
					cantidad,
					total);


		}

	return retorno;
}

/**
 * @brief Le asigna un total al elemento que le llega
 *
 * @param element void* puntero a element
 */
void asignarTotal(void* element)
{
	float precioUnitario;
	int cantidad;
	int total;

		if(element != NULL)
		{
			eServicio_obtenerPrecioUnitario(element, &precioUnitario);
			eServicio_obtenerCantidad(element, &cantidad);

			total = precioUnitario * cantidad;

			eServicio_establecerTotal(element, total);
		}
}

/**
 * @brief Filtra el elemento que se le pase
 *
 * @param elemento void* puntero a elemento
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int eServicio_filtrarServiciosTipoUno(void* elemento)
{
	int retorno = -1;

	int tipo;

		if(elemento != NULL)
		{
			retorno = 0;

			eServicio_obtenerTipo(elemento, &tipo);
				if(tipo == 1)
				{
					retorno = 1;
				}

		}

	return retorno;
}

/**
 * @brief Filtra el elemento que se le pase
 *
 * @param elemento void* puntero a elemento
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int eServicio_filtrarServiciosTipoDos(void* elemento)
{
	int retorno = -1;

	int tipo;

		if(elemento != NULL)
		{
			retorno = 0;

			eServicio_obtenerTipo(elemento, &tipo);
				if(tipo == 2)
				{
					retorno = 1;
				}

		}

	return retorno;
}

/**
 * @brief Filtra el elemento que se le pase
 *
 * @param elemento void* puntero a elemento
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOk
 */
int eServicio_filtrarServiciosTipoTres(void* elemento)
{
	int retorno = -1;

	int tipo;

		if(elemento != NULL)
		{
			retorno = 0;

			eServicio_obtenerTipo(elemento, &tipo);
				if(tipo == 3)
				{
					retorno = 1;
				}

		}

	return retorno;
}


/**
 * @brief Compara los dos elementos que se le pasan por parametro
 *
 * @param servicioUno	void* puntero a ServicioUno
 * @param servicioDos	void* puntero a ServicioDos
 * @return retorna (-2) [Si alguno de los punteros llego en NULL] - retorna (-1) [Si la comparacion esta bien] - retorna (1) [Si hay que cambiar]
 */
int eServicio_ordenarDescripcion(void* servicioUno,void* servicioDos)
{
	int retorno = -2;

	int comparacion;
	char descUno[61];
	char descDos[61];

		if(servicioUno != NULL && servicioDos != NULL)
		{
			retorno = -1;

			eServicio_obtenerDescripcion(servicioUno, descUno);
			eServicio_obtenerDescripcion(servicioDos, descDos);

				comparacion = strcmp(descUno, descDos);

					if(comparacion > 0)
					{
						retorno = 1;
					}
		}

	return retorno;
}

int emparejarDatos(LinkedList* pArrayListaServicios)
{
	eServicio* servicio;

	int retorno = -1;

	int i;
	int len = 0;
	char descripcion[61];

		if(pArrayListaServicios != NULL)
		{
			for(i=0;i<ll_len(pArrayListaServicios);i++)
			{
				servicio = ll_get(pArrayListaServicios, i);
				eServicio_obtenerDescripcion(servicio, descripcion);

				medirLongitud(descripcion);
				if(strlen(descripcion) > len)
				{
					len = strlen(descripcion);
				}
			}

			for(i=0;i<ll_len(pArrayListaServicios);i++)
			{
				servicio = ll_get(pArrayListaServicios, i);
				eServicio_obtenerDescripcion(servicio, descripcion);
					while(strlen(descripcion) < len)
					{
						strcat(descripcion, " ");
					}
					eServicio_establecerDescripcion(servicio, descripcion);
					ll_set(pArrayListaServicios, i, servicio);

			}
		}

	return retorno;
}


/**
 * @brief Le asigna un id al sevicio creado
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL] - retorna (0) todoOk
 */
/*
int eServicio_asignarId(LinkedList* pArrayListaServicio)
{
	eServicio* servicio;

	int retorno = -1;
	int i;
	int limite;
	int idServicio;
	int id = 0;

		if(pArrayListaServicio != NULL)
		{
			limite = ll_len(pArrayListaServicio);

			if(limite > 0)
			{
				for(i=0;i<limite;i++)
				{
					servicio = ll_get(pArrayListaServicio, i);

					eServicio_obtenerId(servicio, &idServicio);

					if(idServicio > id)
					{
						id = idServicio;
					}
				}
			}
			retorno = id;
		}

	return retorno;
}*/

/**
 * @brief Reasigna las id de la lista
 *
 * @param pArrayListaServicio LinkedList* Puntero a la lista
 * @return retorna (-1) [Si la lista llego en NULL o el id es 0 o menor] - retorna (0) todoOk
 */
/*
int eServicio_reAsignarId(LinkedList* pArrayListaServicio, int id)
{
	eServicio* servicio;

	int retorno = -1;
	int i;

		if(pArrayListaServicio != NULL && id > 0)
		{
			retorno  = 0;

				for(i=0;i< ll_len(pArrayListaServicio);i++)
				{
					servicio = ll_get(pArrayListaServicio, i);
					id++;
					eServicio_establecerId(servicio, id);
				}
		}

	return retorno;
}*/

/**
 * @brief Crea un servicio y lo retorna
 *
 * @return retorna (NULL) [No respeta lo que se le pide] - retorna (el servicio) todoOk
 */
/*
eServicio* eServicio_agregarServicio()
{

	eServicio* servicio = NULL;
	eServicio* pEspacio = NULL;
	eServicio aux;

	int retornoDesripcion;
	int retornoTipo;
	int retornoPrecio;
	int retornoCantidad;
	int total = 0;

		retornoDesripcion =  pedirDescripcion(aux.descripcion , LIMITE_DESCRIPCION, "Ingrese la descripcion del servicio: ", "Error. Ingrese lo que se le pide\n", 2);
		retornoTipo = pedirNumeroEntero(&aux.tipo, "Ingrese el tipo\n1)Minorista\n2)Mayorista\n3)Exportar\n-Opcion: ", "Error. Ingrese lo que se le pide\n", 1, 3,  2);
		retornoPrecio =  pedirPrecio(&aux.precioUnitario, "Ingrese el precio: ", "Error. Ingrese lo que se le pide\n", 0, 100000,2);
		retornoCantidad = pedirNumeroEntero(&aux.cantidad, "Ingrese la cantidad: ", "Error. Ingrese lo que se le pide\n", 0, 10000,  2);
		//pedirNumeroEntero(&aux.total, "Ingrese el total: ", "Error. Ingrese lo que se le pide\n", 0, 10000,  2);

			if(retornoDesripcion == 0 && retornoTipo == 0 && retornoPrecio == 0 && retornoCantidad == 0)
			{
				pEspacio = eServicio_nuevosParametros(aux.id_servicio, aux.descripcion, aux.tipo, aux.precioUnitario, aux.cantidad, total);

					if(pEspacio != NULL)
					{
						servicio = pEspacio;
					}
			}


	return servicio;
}*/

/**
 * @brief Busca si hay una id del servicio con la id que se le pasa por parametro
 *
 * @param pArrayListaServicios Puntero a LinkedList* pArrayServicios
 * @param id int
 * @return retorna (-1) [Si el puntero llego en NULL o el id es menor a 0] - retorna (-2) [Si no se encontro le ID] - retorna (la posicion del servicio) si todoOk
 */
/*
int eServicio_buscarId(LinkedList* pArrayListaServicios, int id)
{
	eServicio* servicio;
	int retorno = -1;
	int i;
	int idServicio;

		if(pArrayListaServicios != NULL && id >= 0)
		{
			retorno = -2;
			for(i=0;i<ll_len(pArrayListaServicios);i++)
			{
				servicio = ll_get(pArrayListaServicios, i);
				eServicio_obtenerId(servicio, &idServicio);

				if(id == idServicio)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}*/

/**
 * @brief Pide un ID y lo busca
 *
 * @param pArrayListaServicios Puntero a LinkedList* pArrayServicios
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (-2) [Si no ingresa lo que se le pide] - retorna (La posicion del servicio) si todoOk
 */
/*
int eServicio_pedirId(LinkedList* pArrayListaServicios)
{
	int retorno = -1;
	int retornoId;

	int id;

		if(pArrayListaServicios != NULL)
		{
			retorno = -2;

			retornoId = pedirNumeroEntero(&id, "Ingrese el ID del servicio: ", "Error. ingrese un id valido\n", 1, 10000,  2);

				if(retornoId == 0)
				{
					retorno = eServicio_buscarId(pArrayListaServicios, id);
				}

		}

	return retorno;
}*/


/**
 * @brief Modifica los datos del servicio que se le paso por parametro
 *
 * @param servicio Puntero eServicio*
 * @return retorna (-1) [Si el puntero llego en NULL] - retorna (0) todoOK
 */
/*
int eServicio_modificarServicio(eServicio* servicio)
{
	eServicio aux;

	int retorno = -1;
	int retornoDesripcion;
	int retornoTipo;
	int retornoPrecio;
	int retornoCantidad;

	int opcion;

		if(servicio != NULL)
		{
			retorno = 0;

				do{
					imprimir_menuModificar();
					opcion = menu_validarOpcion(1, 5);

						switch(opcion)
						{
							case 1:
								retornoDesripcion =  pedirDescripcion(aux.descripcion , LIMITE_DESCRIPCION, "Ingrese la descripcion del servicio: ", "Error. Ingrese lo que se le pide\n", 2);
									if(retornoDesripcion == 0)
									{
										eServicio_establecerDescripcion(servicio, aux.descripcion);
									}
							break;

							case 2:
								retornoTipo = pedirNumeroEntero(&aux.tipo, "Ingrese el tipo\n1)Minorista\n2)Mayorista\n3)Exportar\n-Opcion: ", "Error. Ingrese lo que se le pide\n", 1, 3,  2);
									if(retornoTipo == 0)
									{
										eServicio_establecerTipo(servicio, aux.tipo);
									}
							break;

							case 3:
								retornoPrecio =  pedirPrecio(&aux.precioUnitario, "Ingrese el precio: ", "Error. Ingrese lo que se le pide\n", 0, 100000,2);
									if(retornoPrecio == 0)
									{
										eServicio_establecerPrecioUnitario(servicio, aux.precioUnitario);
									}
							break;

							case 4:
								retornoCantidad = pedirNumeroEntero(&aux.cantidad, "Ingrese la cantidad: ", "Error. Ingrese lo que se le pide\n", 0, 10000,  2);
									if(retornoCantidad == 0)
									{
										eServicio_establecerCantidad(servicio, aux.cantidad);
									}
							break;
						}

				}while(opcion != 5);

		}

	return retorno;
}*/





