#ifndef LISTDB_LIST_H
#define LISTDB_LIST_H

#include <iostream>

using namespace std;

template<class T> class List {
    private:
        NodeList<T> *head; //es el puntero al nodo cabeza de la lista
        NodeList<T> *tail; //es el puntero al nodo cola de la lista
    public:
        List(void);
        List(NodeList<T> *n);
        void add(T d); //agrega un nodo al final
        void addHead(T d); //agrega un nodo al inicio
        void add(T d, int n); //agrega un nodo en la posicion n
        void dlte(void); //borra el nodo al final
        void dlteHead(void); //borra el nodo al inicio
        void dlte(int n); //borra el nodo en la posicion n
        NodeList<T> *getHead(void); //retorna un puntero al nodo cabeza
        NodeList<T> *getTail(void); //retorna un puntero al nodo cola
        List *rest(void); //retorna una nueva lista igual sin el nodo cabeza
        NodeList<T> *take(int n); //retorna un puntero al nodo en la posicion n
        void swap(int a, int b); //efectua un swap entre la informacion del nodo en la posicion a con el nodo en la posicion b
        int position(T d); //retorna un entero indicando la posicion donde se encuentra el dato d
        void show(void); //muestra todos los elementos de la lista
        int size(void); //retorna un entero que indica la cantidad de nodos de la lista
        bool isEmpty(void); //retorna true si la lista esta vacia
};

#endif