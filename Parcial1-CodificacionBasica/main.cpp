#include <iostream>

using namespace std;

int main()
{
    // Declaramos las dimensiones de la matriz 8x8 que simulara nuestra matriz de leds
    int filas = 8;
    int columnas = 8;


    // Creamos un puntero doble para almacenar la matriz y acceder a las posiciones
    // Reservamos el espacio en memoria dinamica para poder acceder mas facil y directamente a las posiciones de la matriz
    int **matriz = new int*[filas];


    // Asignamos posiciones de memoria para cada fila d ela matriz
    for(int i = 0; i < filas; i++)
        matriz[i] = new int[columnas]; // -> denuevo con memoria dinamica


    // Llenamos la matriz con 0 para simular los leds apagados
    int contador = 0;
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {    matriz[i][j] = contador;}
    }

    //Imprimir la matriz (ETAPA PRUEBA)
    for(int i = 0; i < filas; i++)
    {   for(int j = 0; j < columnas; j++)
        {    cout<< matriz[i][j] << " ";}

        cout<<endl;
    }

    //Liberacion de la memoria dinamica asignada a la matriz -> evitar fugas de memoria y el ocupamiento innecesario de la memoria
    for(int i = 0; i < filas; i++)
    {    delete[] matriz[i];}
    delete[] matriz;

    return 0;
}
