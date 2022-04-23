#include "NodeList.h"

#include <iostream>

using namespace std;

template<class T> NodeList<T>::NodeList(void) {
    next = NULL;
    previous = NULL;
}

template<class T> NodeList<T>::NodeList(T d) {
    data = d;
    next = NULL;
    previous = NULL;
}

template<class T> NodeList<T>::NodeList(T d, NodeList<T> *n, NodeList<T> *p) {
    data = d;
    next = n;
    previous = p;
}

template<class T> void NodeList<T>::setData(T d) {
    data = d;
}

template<class T> void NodeList<T>::setNext(void) {
    next = NULL;
}

template<class T> void NodeList<T>::setNext(NodeList<T> *n) {
    next = n;
}

template<class T> void NodeList<T>::setPrevious(void) {
    previous = NULL;
}

template<class T> void NodeList<T>::setPrevious(NodeList<T> *p) {
    previous = p;
}

template<class T> T NodeList<T>::getData(void) {
    return data;
}

template<class T> NodeList<T> *NodeList<T>::getNext(void) {
    return next;
}

template<class T> NodeList<T> *NodeList<T>::getPrevious(void) {
    return previous;
}

template<class T> bool NodeList<T>::hasNext(void) {
    return next != NULL;
}

template<class T> bool NodeList<T>::hasPrevious(void) {
    return previous != NULL;
}