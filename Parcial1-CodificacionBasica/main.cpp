#include <iostream>

using namespace std;



// Declaramos las dimensiones de la matriz 8x8 que simulara nuestra matriz de leds
int filas = 8;
int columnas = 8;
int tiempo = 0;


//Declaracion de las funciones

/*Creamos las funciones Creacion y Destruccion matriz para tener mayor control sobre la reserva del espacio de la memoria y su liberacion
esto nos permite poder inicializarla y destruirla para diferentes zonas del codigo endonde se pueda requerir*/

int** CreacionMatriz(int filas, int columnas); //--> Crea una matriz 8x8 simulando los leds
void DestruccionMatriz(int** matriz, int filas); //--> Libera el espacio de la memoria dinamica reservada para la matriz
void ImprimirMatriz(int **matriz, int filas, int columnas); //--> Imprime las matrices que simulan las salidas de los leds
void Patrones(int **matriz); //--> Le permite al usuario elegir el patron a mostrar
void Verificacion(int **matriz, int filas, int columnas, int tiempo); //--> Enciende los leds para mostrar que su funcionamiento sea correcto
void Espera(int tiempo); //--> Crea un delay de tiempo para mostrar un patron en la maeriz o en algun proceso, tambien limpia pantalla
void Publick(int **Matriz, int filas, int columnas, int tiempo);  //--> Es el menu esencial de nuestro programa
void Imagen(int **matriz, int filas, int columnas, int tiempo);  //--> Le permite al usuario ingresar la matriz que quiere ver  en la matriz de leds


//Funcion de invocacion auxiliar
int main()
{
    int **Matriz = CreacionMatriz(filas, columnas);
    Publick(Matriz, filas, columnas, tiempo);
    DestruccionMatriz(Matriz, filas);
    return 0;
}


//Cuerpo de las funciones

void Publick(int **Matriz, int filas,int columnas, int tiempo)
{
    int opcion = 1;
    while(opcion !=0){

        cout<<"Bienvenido sr. usuario, por favor ingrese el numero de la opcion que quiere ver en la matriz: "<<endl;
        cout<<"0. Salir. "<<endl;
        cout<<"1. Prueba de encendido. "<<endl;
        cout<<"2. Imagen prueba. "<<endl;
        cout<<"3. Patrones por defecto. "<<endl;
        cout<<"Opcion elegida: ";
        cin >> opcion;

        system("cls");

        switch (opcion) {
        case 0:
        {
            cout<< "Gracias por ingresar a nuestro programa, vuelva pronto."<<endl;
            break;
        }

        //PRUEBA DE ENECENDIDO/APAGADO DE LEDS
        case 1:
        {
            cout<<"Cuanto tiempo quiere que el patron se muestre en pantalla? "<<endl;
            cout<<"RECUERDE para un segundo el tiempo ingresado sera de 1000 "<<endl;
            cin>>tiempo;

            Verificacion(Matriz, filas, columnas, tiempo);
            Espera(tiempo);
            break;
        }

        //PATRON INGRESADO POR EL USUARIO
        case 2:
        {
            Imagen(Matriz, filas, columnas, tiempo);
            break;
        }

        //PATRONES PREDETERMINADOS
        case 3:
        {
            Patrones(Matriz);
            break;
        }

        default:
            cout<<"La opcion ingresada no es validad, intentelo nuevamente."<<endl;
            break;
        }

    }
}

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

void Patrones(int **Matriz){

    system("cls");

    int opcion1;
    cout<<"Bienvenido sr. usuario, por favor ingrese el numero del patron que quiere ver en la matriz: "<<endl;
    cout<<"1. Diamante sin puntas. "<<endl;
    cout<<"2. Diagonales. "<<endl;
    cout<<"3. Serpientes. "<<endl;
    cout<<"4. Flecha. "<<endl;
    cout<<"5. Todos. "<<endl;
    cout<<"Opcion elegida: ";
    cin>>opcion1;

    system("cls");

    cout<<"Ingrese la cantidad de tiempo que quiere que el patron se muestre: ";
    cin>>tiempo;

    system("cls");

    switch (opcion1) {

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
        Espera(tiempo);
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
        Espera(tiempo);

        break;
    }

    case 3:
    {
        /*
         * Este patron general cada dos fulas un patron diferente
         * para las filas 0, 1, 4, 5 genera el siguiente patron
         * 1 1 0 1 1 0 1 1
         *
         * para las filas 2, 3, 6, 7 genera el siguiente patron
         * 0 1 1 0 1 1 0 1
         *
         * por lo que la la matriz deberia quedar asi
         *
         *  1 1 0 1 1 0 1 1
         *  1 1 0 1 1 0 1 1
         *  0 1 1 0 1 1 0 1
         *  0 1 1 0 1 1 0 1
         *  1 1 0 1 1 0 1 1
         *  1 1 0 1 1 0 1 1
         *  0 1 1 0 1 1 0 1
         *  0 1 1 0 1 1 0 1
         *
        */

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
            {
                if(i == 0 or i == 1 or i == 4 or i == 5)
                {
                    if(j != 2 and j != 5)
                    {Matriz[i][j]= 1;}

                    else
                        Matriz[i][j] = 0;
                }

                else
                {
                    if(j != 0 and j != 3 and j != 6)
                    {Matriz[i][j]= 1;}

                    else
                        Matriz[i][j] = 0;

                }
            }
        }

        ImprimirMatriz(Matriz, filas, columnas);
        cout<<endl;
        Espera(tiempo);
        break;
    }

    case 4:
    {
        /*
         * Esta es una > de grosor 4, pero sin la punta ya que la ultima columna (8) no se toca
         * por simetria con el eje x podemos hacer primero la parte de arriba y luego reflejarlo para que de la for ma de >
        */

        // Rellenar la parte superior del patrón de ">"
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < i + 4; j++) {
                Matriz[i][j] = 1;
            }
        }

        int contador = 0; //--> pequeño problema para establecer las condiciones del for :D, asi que lo arreglamos con un contador para que solo imprima cuatro 1s

        // Rellenar la parte inferior del patrón de ">"
        for (int i = 4; i < filas; i++) {
            for (int j = 7 - i; j <= 7; j++) {
                if(contador != 4)
                {   Matriz[i][j] = 1;
                    contador++;}
            }
            contador = 0;
        }

        ImprimirMatriz(Matriz, filas, columnas);
        cout<<endl;
        Espera(tiempo);
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
} //de la funcion

void Espera(int tiempo){

    _sleep(tiempo);       // --> Crea un retrazo o pausa momentanea en el tiempo por una cantidad de milisegundos especifica
    system("cls");
}

void Verificacion(int **matriz, int filas, int columnas, int tiempo){

    int secuencias = 1;
    int contador = 0;

    cout<<"Ingrese la cantidad de secuencias que quiere realizar: ";
    cin>>secuencias;

    system("cls");

   // Queremos cambiar uno a uno los 0s por 1s para simular los encendidos de los leds
   // Accederemos a estas posiciones de esta matriz por medio de un puntero
    while(contador != secuencias)
    {
        cout<<endl;
        for(int i = 0; i < filas ; i++) // -> necesitamos que el for pase por todas las posiciones de la matriz 8 x 8 = 64 posiciones
        {    for(int j = 0; j < columnas ; j++)
            {
                matriz[i][j] = 1;
                // Imprimimos la matriz a medida que se van cambiando los leds
                for (int k = 0; k < filas; k++)
                {
                    for(int m = 0; m < columnas; m++)
                    {cout<< matriz[k][m] << " ";}
                    cout<<endl;
                }
                cout<<endl;
            }
        }

        Espera(tiempo);

        // Apagamos los leds
        for(int i = 0; i < filas; i++)
        {   for(int j = 0; j < columnas; j++)
            { matriz[i][j] = 0;}
        }

        ImprimirMatriz(matriz, filas, columnas);

        Espera(tiempo);
        contador++;
    }
}

void Imagen(int **matriz, int filas, int columnas, int tiempo){
    cout<<"Ingrese el numero para la posicion correspondiente dentro de la matriz"<<endl;
    cout<<"1: led encendido ; 0: led apagado"<<endl;

    for(int i = 0; i < filas ; i++)
        for(int j = 0; j < columnas; j++)
        {    cout<<"para la posicion: ("<<i<<","<<j<<"): "<<endl;
            cin>> matriz[i][j];
        }

    system("cls");

    cout<<"Ingrese la cantidad de tiempo que quiere que el patron se muestre: ";
    cin>>tiempo;

    system("cls");

    ImprimirMatriz(matriz, filas, columnas);

    Espera(tiempo);

    // Apagamos los leds
    for(int i = 0; i < filas; i++)
    {   for(int j = 0; j < columnas; j++)
        { matriz[i][j] = 0;}
    }

    ImprimirMatriz(matriz, filas, columnas);

    Espera(tiempo);
}
