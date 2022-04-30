#include <stdio.h>
#include <stdlib.h>
#include "../../../pila.h"
#include <string.h>
#include <time.h>

///PROTOTIPADO EJERCICIOS:

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();

///PROTOTIPADO FUNCIONES:

int cargarArreglo(int arr[], int dimension);
int cargarRandom(int arr[], int dimension);
int cargarArregloChar(char arr[], int dimension);
void cargarArregloStr(char arr[]);
void mostrarArreglo(int arr[], int validos);
void mostrarArregloStr(char arr[]);
void mostrarArregloChar(char arr[], int validos);
int sumaElementos(int arr[], int validos);
void pasarArrPila(int arr[], Pila *pilaPasar, int validos);
int letra(char arr[]);
void invertirArreglo(char arrOrg[], char *destino);
int buscarElemento(char arr[], char caracter);
int insertarElemOrd(char arr[], int validos, char dato);
int capicua(char arreglo[], int validos);
void ordenarSeleccion(char arr[], int validos);

///FUNCION MAIN:

int main(){
    ejercicio11();
}

///CUERPO DE FUNCIONES:

int cargarArreglo(int arr[], int dimension){
    char s;
    int validos=0;
    int i=0;

    do{

        puts("\nIngrese un numero\n");
        scanf("%d", &arr[i]);
        i++;
        validos++;

        puts("\nDesea ingresar otro numero? s/n\n");
        fflush(stdin);
        scanf("%c", &s);

    }while((i<dimension) && (s=='s'));

    return validos;
}

void cargarArregloStr(char arr[]){

    printf("\nIngrese una cadena de caracteres: \n\n");
    fflush(stdin);
    gets(arr);

}

void mostrarArregloStr(char arr[]){

    printf("\nLa cadena de caracteres es:\n\n%s\n", arr);

}

void mostrarArreglo(int arr[], int validos){

    int i=0;
    puts("\nContenido del arreglo:\n");

    for(i=0; i<validos; i++){
        printf("| %d |", arr[i]);
    }
}

int sumaElementos(int arr[], int validos){
    int suma=0;

    for(int i=0; i<validos; i++){
        suma=suma+arr[i];
    }

    return suma;
}

void pasarArrPila(int arr[], Pila *pilaPasar, int validos){

    int i=0;

    for(i=0; i<validos; i++){
        apilar(pilaPasar, arr[i]);
    }
}

int cargarRandom(int arr[], int dimension){
    int validos=0;
    srand(time(NULL));

    while(validos<dimension){
        arr[validos]=rand()%101;
        validos++;
    }

    return validos;
}

int cargarArregloChar(char arr[], int dimension){
    char continuar='s';
    int validos=0, i=0;

    for(i=0; i<dimension && continuar=='s'||continuar=='S'; i++){
        printf("\nIngrese un caracter: \n\n");
        fflush(stdin);
        scanf("%c", &arr[i]);
        validos++;

        puts("\n\nDesea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    return validos;
}

void mostrarArregloChar(char arr[], int validos){
    int i=0;
    puts("\nContenido del arreglo:\n\n");

    for(i=0; i<validos; i++){
        printf("| %c |", arr[i]);
    }
}

int buscarElemento(char arr[], char caracter){

    int i=0, flag=0;

    while(i<strlen(arr) && flag==0){
        if(caracter!=arr[i]){
            i++;
        }else{
            flag=1;
        }
    }

    return flag;
}

int insertarElemOrd(char arr[], int validos, char dato){
    int ult = validos-1;

    while((ult>0) && (dato<arr[ult])){
        arr[ult+1]=arr[ult];
        ult--;
    }
    arr[ult+1]=dato;

    return validos+1;
}

void ordenarInsercion(char arr[], int validos){
    char aux;
    int i,j;

    for(i=0; i<validos; i++){
        j=i;
        aux=arr[i];

        while((j>0) && (aux<arr[j-1])){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=aux;
    }
}

void ordenarSeleccion(char arr[], int validos){
    int i, j, posicionMenor;
    char aux;

    for(i=0; i<validos-1; i++){
        posicionMenor=i;
        for(j=i+1; j<validos; j++){
            if(arr[j]<arr[posicionMenor]){
                posicionMenor=j;
            }
        }
        aux=arr[i];
        arr[i]=arr[posicionMenor];
        arr[posicionMenor]=aux;
    }
}

void invertirArreglo(char arrOrg[], char *destino){

    *destino=strrev(arrOrg);
}

int capicua(char arreglo[], int validos){
    char aux1=arreglo[0];
    char aux2=arreglo[validos-1];
    int flag=0;

    if((aux1==aux2)){
        puts("\nEl arreglo es capicua\n");
        flag=1;
    }else{
        puts("\nEl arreglo no es capicua\n");
    }

    return flag;
}

///CUERPO DE EJERCICIOS:

void ejercicio1(){
    int arreglo1[10], validos=0;

    validos=cargarArreglo(arreglo1, 10);

    mostrarArreglo(arreglo1, validos);
}

void ejercicio2(){
    int arreglo2[10];
    int validos=0;

    validos=cargarArreglo(arreglo2, 10);

    mostrarArreglo(arreglo2, validos);
    printf("\nLa cantidad de validos es de: %d\n", validos);
}

void ejercicio3(){
    int arreglo3[10];
    int validos=0, suma=0;

    validos=cargarArreglo(arreglo3, 10);
    mostrarArreglo(arreglo3, validos);

    suma=sumaElementos(arreglo3, validos);
    printf("\nLa suma total de los elementos es: %d\n", suma);
}

void ejercicio4(){
    int arreglo4[10];
    int validos=0;
    Pila pila;
    inicpila(&pila);

    validos=cargarArreglo(arreglo4, 10);
    mostrarArreglo(arreglo4, validos);

    pasarArrPila(arreglo4, &pila, validos);
    mostrar(&pila);
}

void ejercicio5(){
    int arreglo5[100];
    int validos=0;

    validos=cargarRandom(arreglo5, 100);
    mostrarArreglo(arreglo5, validos);
}

void ejercicio6(){
    char arreglo6[5];
    int validos=0, flag=0;
    char letra;

    validos=cargarArregloChar(arreglo6, 5);

    printf("\nIngrese el elemento buscado: \n");
    fflush(stdin);
    scanf("%c", &letra);

    flag=buscarElemento(arreglo6, letra);
    if(flag==1){
        printf("\nElemento encontrado\n");
    }else{
        printf("\nElemento no encontrado\n");
    }
}

void ejercicio7(){
    char arreglo7[5];
    char dato;
    int validos=0;

    validos=cargarArregloChar(arreglo7, 5);
    mostrarArregloChar(arreglo7, validos);

    ordenarInsercion(arreglo7, validos);
    mostrarArregloChar(arreglo7, validos);

    puts("\nIngrese un caracter\n\n");
    fflush(stdin);
    scanf("%c", &dato);

    validos=insertarElemOrd(arreglo7, validos, dato);
    mostrarArregloChar(arreglo7, validos);
}

void ejercicio8(){
    char arreglo8[10];
    int validos=0;

    validos=cargarArregloChar(arreglo8, 10);
    mostrarArregloChar(arreglo8, validos);

    ordenarInsercion(arreglo8, validos);
    mostrarArregloChar(arreglo8, validos);

    printf("\nEl mayor elemento es:\t%c\n", arreglo8[validos-1]);
}

void ejercicio9(){
    char arreglo9[10];
    int validos=0, flag=0;

    validos=cargarArregloChar(arreglo9, 10);
    mostrarArregloChar(arreglo9, validos);

    flag=capicua(arreglo9, validos);
    /*if(flag==1){
        printf("\nEl arreglo es capicua\n");
    }else{
        printf("\nElemento no encontrado\n");
    }*/
}

void ejercicio10(){
    char arreglo10[5];
    char invertido;

    cargarArregloStr(arreglo10);
    mostrarArregloStr(arreglo10);

    invertirArreglo(arreglo10, &invertido);
    printf("\n%s\n", &invertido);
}

void ejercicio11(){
    system("cls");
    char arreglo11[10];
    char arreglo11Bis[10];

    puts("\t******ORDENAMIENTO POR SELECCION******\n\n");

    int validos=cargarArregloChar(arreglo11, 10);
    mostrarArregloChar(arreglo11, validos);

    puts("\n\nOrdenado:");

    ordenarSeleccion(arreglo11, validos);

    puts("\n");

    mostrarArregloChar(arreglo11, validos);

    puts("\n");
    system("pause");
    system("cls");

    puts("\t******ORDENAMIENTO POR INSERCION******\n\n");

    int validosBis=cargarArregloChar(arreglo11Bis, 10);
    mostrarArregloChar(arreglo11Bis, validosBis);

    puts("\n\nOrdenado:");

    ordenarInsercion(arreglo11Bis, validosBis);

    puts("\n");

    mostrarArregloChar(arreglo11Bis, validosBis);
    puts("\n\n");
}

void ejercicio12(){

}

void ejercicio13(){

}
