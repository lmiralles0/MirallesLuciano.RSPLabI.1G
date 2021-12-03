#ifndef GET_ENTRADA_H_INCLUDED
#define GET_ENTRADA_H_INCLUDED

int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos);
int get_EntradaTexto(char* pArrays, int longitud, char* mensaje, char* mensajeError,int intentos);
int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError, float maximo, float minimo, int intentos);

#endif // GET_ENTRADA_H_INCLUDED
