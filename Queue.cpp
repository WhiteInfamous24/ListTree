#include "Queue.h"

#include <iostream>

using namespace std;

template<class T> Queue<T>::Queue(void) {
    List<T>();
}

template<class T> void Queue<T>::queue(T d) { //encola un elemento en la cola
    this->add(d);
}

template<class T> void Queue<T>::unqueue(void) { //desencola un elemento de la cola
    this->dlteHead();
}

template<class T> NodeList<T> *Queue<T>::queueTake(void) { //retorna un puntero al nodo proximo a salir
    return this->getHead();
}

template<class T> bool Queue<T>::queueIsEmpty(void) { //retorna true si la cola esta vacia
    return this->isEmpty();
}

template<class T> int Queue<T>::queueSize(void) { //retorna la cantidad de nodos de la cola
    return this->size();
}

template<class T> void Queue<T>::queueShow() { //muestra todos los elementos de la cola
    return this->show();
}