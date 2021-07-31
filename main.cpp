#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//vectores y funciones

//lectura del vector
void leer_vector(int num[], int tamanio) {
    //los vectores siempre se pasan por referencia
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el elemento # " << (i + 1) << ": ";
        cin >> num[i];
    }
}

//impresión del vector
void imprime_vector(int vector[], int tamanio) {
    cout << endl << endl << "Elemenotos del vector";
    for (int i = 0; i < tamanio; i++) {
        cout << endl << "Elemento #" << (i + 1) << " : " << vector[i];
    }
}

//Realizar la sumatoria de los elemtenos del vector
int sumatoria_vector(int vector[], int tamanio) {
    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += vector[i];
    }
    return suma;
}

//Realizar el promedio de los elementos del vector
double promedio_vector(int vector[], int tamanio) {
    int prom = 0;
    prom = sumatoria_vector(vector, tamanio) / tamanio;
    return prom;
}

//Ejercicios
//1)Función que devuelve el elemento máximo del vector
int maximo_vector(int num[], int tamanio) {
    int max = num[0];

    for (int i = 1; i < tamanio; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

//2)Función que devuelve el elemento mínimo del vector
int minimo_vector(int num[], int tamanio) {
    int min = num[0];

    for (int i = 1; i < tamanio; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

//3)Función que devuelve por referencia el elemento mínimo y máximo del vector
void maximo_minimo_vector(int num[], int tamanio, int &max, int &min) {

    max = maximo_vector(num, tamanio);
    min = minimo_vector(num, tamanio);
}

//4)Función que llene el vector con valores aleatorios
void valores_alatorios(int num[], int tamanio) {

    for (int i = 0; i < tamanio; i++) {
        num[i] = rand();
    }
}


int main() {
    srand(time(NULL));
    const int MAX = 7;
    int num[MAX];

    //llamada a la función para leer el vector
    leer_vector(num, MAX);
    imprime_vector(num, MAX);

//    cout<<endl<<num[6];
    cout << endl << endl << "---SUMATORIA - PROMEDIO DEL VECTOR---";

    int suma = sumatoria_vector(num, MAX);
    cout << endl << "La sumatoria del vector es: " << suma;

    cout << endl << "El promedio del vector es: " << promedio_vector(num, MAX);

    cout << endl << endl << "---MAXIMO - MINIMO DEL VECTOR---";

    cout << endl << "El maximo del vector es: " << maximo_vector(num, MAX);

    cout << endl << "El minimo del vector es: " << minimo_vector(num, MAX);

    cout << endl << endl << "---NUMEROS POR REFERENCIAS---";

    int min_referencia, max_referencia;

    maximo_minimo_vector(num, MAX, max_referencia, min_referencia);

    cout << endl << "El maximo del vector es: " << max_referencia;

    cout << endl << "El minimo del vector es: " << min_referencia;


    cout << endl << endl << "---NUMEROS ALEATORIOS---";

    int num_aleatorios[MAX];
    valores_alatorios(num_aleatorios, MAX);
    imprime_vector(num_aleatorios, MAX);
    return 0;
}
