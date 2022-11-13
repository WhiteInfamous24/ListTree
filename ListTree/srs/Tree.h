#ifndef TREEDB_TREE_H
#define TREEDB_TREE_H

#include <iostream>

using namespace std;

template<class T> class Tree {
    private:
        int max_childrens; //cantidad de hijos que puede tener un nodo
        NodeTree<T> *root; //puntero al nodo raiz
    public:
        Tree(void);
        Tree(int n);
        Tree(NodeTree<T> *r, int n);
        void add(T d, NodeTree<T> *f);
        void addBalanced(T d); //añade un nuevo nodo llenando por nivel
        void dlte(int n);
        void dlteBalanced(void); //elimina el ultimo nodo quitando por nivel
        NodeTree<T> *getRoot(void); //retorna un puntero a la raiz
        NodeTree<T> *take(int n); //retorna un puntero al nodo en la posicion n
        int size(void); //retorna la cantidad de nodos del arbol
        void swapChildrenFather(NodeTree<T> *n); //efectua un swap entre la informacion del nodo n y su nodo padre
        void show(void); //muestra todos los elementos del arbol en forma de lista
        List<NodeTree<T> *> *toList(void); //retorna todos los elementos del arbol en forma de lista
};

#endif
