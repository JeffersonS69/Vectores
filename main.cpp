#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include <string.h>

using namespace std;
//vectores y funciones

//lectura del vector
void leer_vector(double num[], int tamanio) {
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
double sumatoria_vector(int vector[], int tamanio) {
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
double maximo_vector(int num[], int tamanio) {
    int max = num[0];

    for (int i = 1; i < tamanio; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

//2)Función que devuelve el elemento mínimo del vector
double minimo_vector(int num[], int tamanio) {
    double min = num[0];

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
        num[i] = rand() % 50 - 1;
    }
}

//Diseñe la función que realice el intercambio
void intercambio(int &num1, int &num2) {
    int aux;
    aux = num1;
    num1 = num2;
    num2 = aux;

}
//Ordernar el vector

void ordenar_secuencial(int vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] > vector[j]) {
                intercambio(vector[i], vector[j]);
            }
        }
    }
}

//1)Diseñe la función que busque un número entero en el vector.
//La función debe devolver verdadero si el elemento existe en el vector,
//o falso en caso contrario.

//bool verdadero_falso_vector(double vector[],double tamanio){
//    int aux;
//
//    for (int i = 0; i < tamanio; i++) {
//        aux=vector[i];
//            if ((vector[i] - aux) > 0) {
//                aux= false;
//            } else{
//                aux= true;
//                break;
//            }
//        }
//    return aux;
//}

bool elemento_vector(int num[], int tamanio, int elemento) {
    for (int i = 0; i < tamanio; i++) {
        if (num[i] == elemento)
            return true;
    }
    return false;
}

//2)Diseñe la función que busque un número entero en el vector.
//La función debe devolver la posición donde el elemento fue encontrado.
//Devuelve -1 si no existe.

//int posicion_vector(double vector[],double tamanio){
//    int aux = 0;
//    for (int i = 0; i < tamanio; i++) {
//        int valor = vector[i];
//        if ((vector[i] - valor) > 0) {
//            aux = -1;
//        } else {
//            aux = i+1;
//            break;
//        }
//    }
//    return aux;
//}
int buscar_posicion(int num[], int tamanio, int elemento) {
    for (int i = 0; i < tamanio; i++) {
        if (num[i] == elemento)
            return i;
    }
    return -1;
}
//3)Diseñe la función que devuelva la cantidad de veces que
//existe un entero en el vector
//vector [10,45,6,10,8,10]. El elemetno 10 existe 3 veces
//El elemento 1 existe 0 veces

int cantidad_vector(int num[], int tamanio, int elemento) {
    int acum = 0;
    for (int i = 0; i < tamanio; i++) {
        if (num[i] == elemento)
            acum = acum + 1;
    }
    return acum;
}
//4)Diseñe la función que ordene el vector de manera descendente

void ordenar_descendente(int vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] < vector[j]) {
                double aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double) (a->QuadPart - b->QuadPart) / (double) freq.QuadPart;
}

//1. Diseñe la función que imprima el vector de nombres

void nombres_vectores(string nombres[], int tamanio) {
    for (int k = 0; k < tamanio; k++) {
        cout << endl << nombres[k];
    }
}

//2. Diseñe la función que ordene descendentemente el vector de nombres

void nombres_descendente(string vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i].compare(vector[j]) < 0) {
                string aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

int main() {
    LARGE_INTEGER t_ini, t_fin;
    double secs;
    srand(time(NULL));
    const int MAX = 50;
    int num[MAX];
    //llamada a la función para leer el vector
    valores_alatorios(num, MAX);
    num[2] = 15;
    cout << endl << endl << "---VECTOR ORIGINAL---";
    imprime_vector(num, MAX);

    cout << endl << endl << "---VECTOR ORDENADO---";
    //captura tiempo inicial del proceso
    QueryPerformanceCounter(&t_ini);
    ordenar_secuencial(num, MAX);
    imprime_vector(num, MAX);
    //captura el tiempo después de concluir el proceso
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "\nORDENACION SECUENCIAL: Tiempo EJECUCION en ms: " << (secs * 1000.0);


////    cout<<endl<<num[6];
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


    cout << endl << endl << "---NUMERO ENTERO DEL VECTOR---";


    int x = 15;

    int resultado = elemento_vector(num, MAX, x);
    if (resultado) {
        cout << endl << "El elemento " << x << "Si existe..." << endl;
    } else {
        cout << endl << "Es elemento " << x << "no existe..." << endl;
    }

    cout << endl << endl << "---POSICION DEL VECTOR---";


    double posicion = buscar_posicion(num, MAX, x);
    if (posicion == -1) {
        cout << endl << "No existe el elemento " << x << " en el vector" << endl;
    } else {
        cout << endl << "El elemento " << x << " existe en la posicion" << endl;
    }

    cout << endl << endl << "---NUMEROS REPETIDOS---";

    cout << endl << "El elemento " << x << " existe: " << cantidad_vector(num_aleatorios, MAX, x);

    cout << endl << endl << "---VECTOR ORDENADO DESCENDENTE---";
    ordenar_descendente(num, MAX);
    imprime_vector(num, MAX);

//    vector de string(nombres de personas)
    cout << endl << endl << "---ARRAY---";

    int tam = 6;
    string nombres[tam] = {"Juan", "Antonio", "Carlos", "Martha", "Pedro", "Amalia"};
    cout << endl << endl << "---Sin Ordenar---";

    nombres_vectores(nombres, tam);
    nombres_descendente(nombres, tam);
    cout << endl << endl << "---Ordenados---";

    nombres_vectores(nombres, tam);


    return 0;
}
