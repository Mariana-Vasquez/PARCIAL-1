#include <iostream>

using namespace std;

//Declaracion de las funciones

/*Creamos las funciones Creacion y Destruccion matriz para tener mayor control sobre la reserva del espacio de la memoria y su liberacion
esto nos permite poder inicializarla y destruirla para diferentes zonas del codigo endonde se pueda requerir*/

int** CreacionMatriz(int filas, int columnas); //--> crea una matriz 8x8 simulando los leds
void DestruccionMatriz(int** matriz, int filas); //--> libera el espacio de la memoria dinamica reservada para la matriz
void Imagen(); //--> le permite al usuario elegir el patron a mostrar
void PruebaDeEncendido(int **matriz, int filas, int columnas); //--> enciende los leds para mostrar que su funcionamiento sea correcto
void Espera();

int main()
{
    // Declaramos las dimensiones de la matriz 8x8 que simulara nuestra matriz de leds
    int filas = 8;
    int columnas = 8;

    // PRUEBA DE ENCENDIDO/APAGADO DE LEDS

    int **Matriz = CreacionMatriz(filas, columnas);

    PruebaDeEncendido(Matriz, filas, columnas);

    DestruccionMatriz(Matriz, filas);


    // IMAGENES


    return 0;
}



//Estructuras de las funciones

int** CreacionMatriz(int filas, int columnas){

    // Creamos un puntero doble para almacenar la matriz y acceder a las posiciones
    // Reservamos el espacio en memoria dinamica para poder acceder mas facil y directamente a las posiciones de la matriz
    int **matriz = new int*[filas];

    // Asignamos posiciones de memoria para cada fila de la matriz
    for(int i = 0; i < filas; i++)
        matriz[i] = new int[columnas]; // -> denuevo con memoria dinamica

    // Llenamos la matriz con 0 para simular los leds apagados
    int contador = 0;
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {    matriz[i][j] = contador;}
    }

/*
    //Imprimir la matriz (ETAPA PRUEBA)
    for(int i = 0; i < filas; i++)
    {   for(int j = 0; j < columnas; j++)
        {    cout<< matriz[i][j] << " ";}

        cout<<endl;
    }

*/

    return matriz;
}

void DestruccionMatriz(int** matriz, int filas){
    //Liberacion de la memoria dinamica asignada a la matriz -> evitar fugas de memoria y el ocupamiento innecesario de la memoria
    for(int i = 0; i < filas; i++)
    {    delete[] matriz[i];}
    delete[] matriz;
}

void Imagen(){

    int opcion; //-> No la inicializo de una vez por que necesito que se tome un valor ingresado por el usuario antes de ingresar al while

    cout<<"Bienvenido señor usuario, por favor ingrese el numero del patron que quiere ver en la matriz: "<<endl;
    cout<<"1. Sin esquinas. "<<endl;
    cout<<"2. Diagonales. "<<endl;
    cout<<"3. Serpientes. "<<endl;
    cout<<"4. Flecha. "<<endl;
    cout<<"5. Todos. "<<endl;

    cin>>opcion;

    while(opcion != 0){

        switch (opcion) {

        case 0:
            cout<< "Gracias por ingresar a nuestro programa, vuelva pronto."<<endl;
            break;

        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        default:
            cout<<"Se ingreso una opcion invalida, intentelo nuevamente." << endl;
            break;

        } // del switch
    } // del while
} //de la funcion

void Espera(){

    _sleep(1000);       // --> Crea un retrazo o pausa momentanea en el tiempo por una cantidad de milisegundos especifica
    //system("cls");
}

void PruebaDeEncendido(int **matriz, int filas, int columnas){

    //matriz con leds apagados
    CreacionMatriz(filas, columnas);

    int **Matriz = matriz;

   // Queremos cambiar uno a uno los 0s por 1s para simular los encendidos de los leds
   // Accederemos a estas posiciones de esta matriz por medio de un puntero

    for(int i = 0; i < filas ; i++) // -> necesitamos que el for pase por todas las posiciones de la matriz 8 x 8 = 64 posiciones
        for(int j = 0; j < columnas ; j++)
        {
            Matriz[i][j] = 1;
        }

    // Imprimimos la matriz a medida que se van cambiando los leds
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout<< matriz[i][j] << " ";
        }
        cout<<endl;
    }

    DestruccionMatriz(matriz, filas);
}
