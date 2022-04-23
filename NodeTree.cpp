#include "NodeTree.h"

#include <iostream>

using namespace std;

template<class T> NodeTree<T>::NodeTree(void) {
    father = NULL;
    childrens = new List<NodeTree<T> *>();
}

template<class T> NodeTree<T>::NodeTree(T d) {
    data = d;
    father = NULL;
    childrens = new List<NodeTree<T> *>();
}

template<class T> NodeTree<T>::NodeTree(T d, NodeTree<T> *f) {
    data = d;
    father = f;
    childrens = new List<NodeTree<T> *>();
}

template<class T> void NodeTree<T>::setData(T d) {
    data = d;
}

template<class T> void NodeTree<T>::setFather(void) {
    father = NULL;
}

template<class T> void NodeTree<T>::setFather(NodeTree<T> *f) {
    father = f;
}

template<class T> T NodeTree<T>::getData(void) {
    return data;
}

template<class T> NodeTree<T> *NodeTree<T>::getFather(void) {
    return father;
}

template<class T> List<NodeTree<T> *> *NodeTree<T>::getChildrens(void) {
    return childrens;
}

template<class T> int NodeTree<T>::level(void) {
    if(father == NULL)
        return 0;
    else
        return 1+this->getFather()->level();
}

template<class T> bool NodeTree<T>::hasFather(void) {
    return father != NULL;
}

template<class T> bool NodeTree<T>::hasChildrens(void) {
    return !childrens->isEmpty();
}