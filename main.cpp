#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//vectores y funciones

//lectura del vector
void leer_vector(double num[], double tamanio) {
    //los vectores siempre se pasan por referencia
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el elemento # " << (i + 1) << ": ";
        cin >> num[i];
    }
}

//impresión del vector
void imprime_vector(double vector[], double tamanio) {
    cout << endl << endl << "Elemenotos del vector";
    for (int i = 0; i < tamanio; i++) {
        cout << endl << "Elemento #" << (i + 1) << " : " << vector[i];
    }
}

//Realizar la sumatoria de los elemtenos del vector
double sumatoria_vector(double vector[], double tamanio) {
    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += vector[i];
    }
    return suma;
}

//Realizar el promedio de los elementos del vector
double promedio_vector(double vector[], double tamanio) {
    int prom = 0;
    prom = sumatoria_vector(vector, tamanio) / tamanio;
    return prom;
}

//Ejercicios
//1)Función que devuelve el elemento máximo del vector
double maximo_vector(double num[], double tamanio) {
    int max = num[0];

    for (int i = 1; i < tamanio; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

//2)Función que devuelve el elemento mínimo del vector
double minimo_vector(double num[], double tamanio) {
    double min = num[0];

    for (int i = 1; i < tamanio; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

//3)Función que devuelve por referencia el elemento mínimo y máximo del vector
void maximo_minimo_vector(double num[], double tamanio, double &max, double &min) {

    max = maximo_vector(num, tamanio);
    min = minimo_vector(num, tamanio);
}

//4)Función que llene el vector con valores aleatorios
void valores_alatorios(double num[], double tamanio) {

    for (int i = 0; i < tamanio; i++) {
        num[i] = rand();
    }
}

//Ordernar el vector

void ordenar_secuencial(double vector[], double tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] > vector[j]) {
                double aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

//1)Diseñe la función que busque un número entero en el vector.
//La función debe devolver verdadero si el elemento existe en el vector,
//o falso en caso contrario.

bool verdadero_falso_vector(double vector[],double tamanio){
    int aux;

    for (int i = 0; i < tamanio; i++) {
        aux=vector[i];
            if ((vector[i] - aux) > 0) {
                aux= false;
            } else{
                aux= true;
                break;
            }
        }
    return aux;
}

//2)Diseñe la función que busque un número entero en el vector.
//La función debe devolver la posición donde el elemento fue encontrado.
//Devuelve -1 si no existe.

int posicion_vector(double vector[],double tamanio){
    int aux = 0;
    for (int i = 0; i < tamanio; i++) {
        int valor = vector[i];
        if ((vector[i] - valor) > 0) {
            aux = -1;
        } else {
            aux = i+1;
            break;
        }
    }
    return aux;
}

int main() {
    srand(time(NULL));
    const int MAX = 3;
    double num[MAX];

    //llamada a la función para leer el vector
    leer_vector(num, MAX);
    cout << endl << endl << "---VECTOR ORIGINAL---";
    imprime_vector(num, MAX);

    cout << endl << endl << "---VECTOR ORDENADO---";
    ordenar_secuencial(num, MAX);
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

    double min_referencia, max_referencia;

    maximo_minimo_vector(num, MAX, max_referencia, min_referencia);

    cout << endl << "El maximo del vector es: " << max_referencia;

    cout << endl << "El minimo del vector es: " << min_referencia;


    cout << endl << endl << "---NUMEROS ALEATORIOS---";

    double num_aleatorios[MAX];
    valores_alatorios(num_aleatorios, MAX);
    imprime_vector(num_aleatorios, MAX);


    cout << endl << endl << "---NUMERO ENTERO DEL VECTOR---";

    double resultado= verdadero_falso_vector(num, MAX);
    if(resultado){
        cout<<endl<<"Es verdadero --- Contiene numeros enteros"<<endl;
    }else{
        cout<<endl<<"Es falso --- No contiene numeros enteros"<<endl;
    }

    cout << endl << endl << "---POSICION DEL VECTOR---";

    //La posicion cambia debido al orden de los numeros que aplica otra función --> ordenar_secuencial.

    double posicion= posicion_vector(num, MAX);
    if(posicion>0){
        cout<<endl<<"Se encontro en la posicion: "<<posicion<<endl;
    }else{
        cout<<endl<<"No, se encontro ninguna posicion: "<<posicion<<endl;
    }



    return 0;
}
