#include <iostream>

using namespace std;

// Declaramos las dimensiones de la matriz 8x8 que simulara nuestra matriz de leds
int filas = 8;
int columnas = 8;

//Declaracion de las funciones

/*Creamos las funciones Creacion y Destruccion matriz para tener mayor control sobre la reserva del espacio de la memoria y su liberacion
esto nos permite poder inicializarla y destruirla para diferentes zonas del codigo endonde se pueda requerir*/

int** CreacionMatriz(int filas, int columnas); //--> crea una matriz 8x8 simulando los leds
void DestruccionMatriz(int** matriz, int filas); //--> libera el espacio de la memoria dinamica reservada para la matriz
void ImprimirMatriz(int **matriz, int filas, int columnas); //--> imprime las matrices que simulan las salidas de los leds
void Imagen(int **matriz); //--> le permite al usuario elegir el patron a mostrar
void PruebaDeEncendido(int **matriz, int filas, int columnas); //--> enciende los leds para mostrar que su funcionamiento sea correcto
void Espera();

int main()
{

    // PRUEBA DE ENCENDIDO/APAGADO DE LEDS

    int **Matriz = CreacionMatriz(filas, columnas);
    PruebaDeEncendido(Matriz, filas, columnas);

    Espera();

    // IMAGENES

    Imagen(Matriz);

    DestruccionMatriz(Matriz, filas);

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

    return matriz;
}

void DestruccionMatriz(int** matriz, int filas){
    //Liberacion de la memoria dinamica asignada a la matriz -> evitar fugas de memoria y el ocupamiento innecesario de la memoria
    for(int i = 0; i < filas; i++)
    {    delete[] matriz[i];}
    delete[] matriz;
}

void ImprimirMatriz(int **matriz, int filas, int columnas){
    for (int k = 0; k < filas; k++)
    {
        for(int m = 0; m < columnas; m++)
            {cout<< matriz[k][m] << " ";}
        cout<<endl;
    }
}

void Imagen(int **Matriz){

    int opcion = 1; //-> No la inicializo de una vez por que necesito que se tome un valor ingresado por el usuario antes de ingresar al while

    while(opcion != 0){
    cout<<"Bienvenido sr. usuario, por favor ingrese el numero del patron que quiere ver en la matriz: "<<endl;
    cout<<"1. Diamante sin puntas. "<<endl;
    cout<<"2. Diagonales. "<<endl;
    cout<<"3. Serpientes. "<<endl;
    cout<<"4. Flecha. "<<endl;
    cout<<"5. Todos. "<<endl;
    cout<<"Opcion elegida: ";

    cin>>opcion;

    Espera();

        switch (opcion) {

        case 0:
        {
            cout<< "Gracias por ingresar a nuestro programa, vuelva pronto."<<endl;
            break;
        }

        case 1:
        {
            /*
             * Analicemos el problema
             *
             * Necesitamos crear un diamante sin las puntas; emepezando con los leds 3 y 4 de la primera fila que son los centrales de la matriz
             * cosa muy parecida que ya habiamos hecho en la practica introductoria del labaoratorio
             *
             * Ya tenemos la matriz llena de 0s ahora solo hay que remplazar los 0s por los 1s para dibujar la matriz
            */

            for(int i = 0; i < filas/2; i++) //--> Solo hacemos la mitad superior ya que esta es simetrica respecto a el eje x
            {
                //Contorno del diamante
                Matriz[i][3 - i] = 1;
                Matriz[i][4 + i] = 1;

                //Relleno
                for(int j = 3 - i + 1; j < 4 + i; j++)
                {
                    Matriz[i][j]= 1;
                    Matriz[filas - i - 1][j]= 1;
                }
            }

            //Reflecion del patron para la reflexion para el eje x
            for(int i = filas / 2; i < filas; i++)
            {
                for(int j = 0; j < columnas; j++)
                    Matriz[i][j] = Matriz [filas - i - 1][j];
            }

            ImprimirMatriz(Matriz, filas, columnas);
            cout<<endl;
            Espera();
            break;
        }

        case 2:
        {

            // Cambiamos los 0s de las diagonales por 1s
            for(int i = 0 ; i < filas; i++)
            {
                Matriz[i][i] = 1; //-> el primer digito de la matriz que tambien es el primero de la diagonal
                Matriz[i][columnas - i - 1] = 1; //-> El ultimo digito de la primera fila de la matriz y el primer digito de la diagonal secundaria

                /*
                 * A medida que va corriendo el for, el valor de i va ir aumentando y cambiando la posicion de la matriz
                 * i = 0
                 *
                 * nos da la diagonal la posicion (0,0) en la diagonal principal
                 * nos da la diagonal la posicion (0,7) en la diagonal secundaria
                 *
                 * i = 1
                 *
                 * nos da la diagonal la posicion (1,1) en la diagonal principal
                 * nos da la diagonal la posicion (1,6) en la diagonal secundaria
                 *
                 * Asi ira cambiando para recorrer toda la matriz
                 *
                 * i = 7
                 *
                 * nos da la diagonal la posicion (7,7) en la diagonal principal
                 * nos da la diagonal la posicion (7,0) en la diagonal secundaria
                 *
                */
            }

            ImprimirMatriz(Matriz, filas, columnas);
            cout<<endl;
            Espera();

            break;
        }

        case 3:
        {
            break;
        }

        case 4:
        {
            break;
        }

        case 5:
        {
            break;
        }

        default:
        {
            cout<<"Se ingreso una opcion invalida, intentelo nuevamente." << endl;
            break;
        }

        } // del switch
    } // del while
} //de la funcion

void Espera(){

    _sleep(5000);       // --> Crea un retrazo o pausa momentanea en el tiempo por una cantidad de milisegundos especifica
    system("cls");
}

void PruebaDeEncendido(int **matriz, int filas, int columnas){

   // Queremos cambiar uno a uno los 0s por 1s para simular los encendidos de los leds
   // Accederemos a estas posiciones de esta matriz por medio de un puntero

    for(int i = 0; i < filas ; i++) // -> necesitamos que el for pase por todas las posiciones de la matriz 8 x 8 = 64 posiciones
    {    for(int j = 0; j < columnas ; j++)
        {
            matriz[i][j] = 1;
            // Imprimimos la matriz a medida que se van cambiando los leds
            for (int k = 0; k < filas; k++)
            {
                for(int m = 0; m < columnas; m++)
                {
                    cout<< matriz[k][m] << " ";
                    //Espera();
                }
                cout<<endl;
            }

            cout<<endl;
        }
    }

    // Apagamos los leds
    for(int i = 0; i < filas; i++)
    {   for(int j = 0; j < columnas; j++)
        { matriz[i][j] = 0;}
    }

    ImprimirMatriz(matriz, filas, columnas);
}
