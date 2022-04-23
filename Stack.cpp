#include "Stack.h"

#include <iostream>

using namespace std;

template<class T> Stack<T>::Stack(void) {
    List<T>();
}

template<class T> void Stack<T>::stack(T d) { //apila un elemento en la pila
    this->add(d);
}

template<class T> void Stack<T>::unstack(void) { //desapila un elemento de la pila
    this->dlte();
}

template<class T> NodeList<T> *Stack<T>::stackTake(void) { //retorna un puntero al nodo proximo a salir
    return this->getTail();
}

template<class T> bool Stack<T>::stackIsEmpty(void) { //retorna true si la pila esta vacia
    return this->isEmpty();
}

template<class T> int Stack<T>::stackSize(void) { //retorna la cantidad de nodos de la pila
    return this->size();
}

template<class T> void Stack<T>::stackShow(void) { //muestra todos los elementos de la pila
    return this->show();
}
