#include "NodeTree.h"

#include <iostream>

using namespace std;

template<class T> Tree<T>::Tree(void) {
    max_childrens = 0;
    root = NULL;
}

template<class T> Tree<T>::Tree(int n) {
    max_childrens = n;
    root = NULL;
}

template<class T> Tree<T>::Tree(NodeTree<T> *r, int n) {
    max_childrens = n;
    root = r;
}

template<class T> void Tree<T>::add(T d, NodeTree<T> *f) {
    if(f != NULL)
        NodeTree<T> *nw = new NodeTree<T>(d, f);
    else {
        NodeTree<T> *nw = new NodeTree<T>(d);
        root = nw;
    }
}

template<class T> void Tree<T>::addBalanced(T d) {
    if(root != NULL) {
        
        //IMPLEMENT

    }
    else
        this->add(d, NULL);
}

template<class T> void Tree<T>::dlte(int n) {

    //IMPLEMENT

}

template<class T> void Tree<T>::dlteBalanced(void) {
    if(root != NULL) {
        
        //IMPLEMENT

    }
}

template<class T> NodeTree<T> *Tree<T>::getRoot(void) {
    return root;
}

template<class T> NodeTree<T> *Tree<T>::take(int n) {
    return this->toList()->take(n)->getData();
}

template<class T> int Tree<T>::size(void) {
    return this->toList()->size();
}

template<class T> void Tree<T>::swapChildrenFather(NodeTree<T> *n) {
    if(n->getFather() != NULL) {
        T tmp = n->getData();
        n->setData(n->getFather()->getData());
        n->getFather()->setData(tmp);
    }
}

template<class T> void Tree<T>::show(void) {
    
    //IMPLEMENT

}

template<class T> List<NodeTree<T> *> *Tree<T>::toList(void) {
    List<NodeTree<T> *> *output = new List<NodeTree<T> *>();
    if(root != NULL) {
        Queue<NodeTree<T> *> *aux = new Queue<NodeList<T> *>();
        NodeList<T> *it = root->getChildrens()->getHead();
        output->add(root);
        aux->queue(root);
        do {

            //IMPLEMENT

        } while(it->hasNext());     
    }
    return output;
}
