#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

// ---------------------- Class NodeList

template<class T> class NodeList {
    private:
        T data;
        NodeList<T> *next;
        NodeList<T> *previous;
    public:
        NodeList(void) {
            next = NULL;
            previous = NULL;
        };
        NodeList(T d) {
            data = d;
            next = NULL;
            previous = NULL;
        };
        NodeList(T d, NodeList<T> *n, NodeList<T> *p) {
            data = d;
            next = n;
            previous = p;
        };
        void setData(T d) {
            data = d;
        };
        void setNext(void) {
            next = NULL;
        };
        void setNext(NodeList<T> *n) {
            next = n;
        };
        void setPrevious(void) {
            previous = NULL;
        };
        void setPrevious(NodeList<T> *p) {
            previous = p;
        };
        T getData(void) {
            return data;
        };
        NodeList<T> *getNext(void) {
            return next;
        };
        NodeList<T> *getPrevious(void) {
            return previous;
        };
        bool hasNext(void) {
            return next != NULL;
        };
        bool hasPrevious(void) {
            return previous != NULL;
        };
};

// ---------------------- Class List

template<class T> class List {
    private:
        NodeList<T> *head; //es el puntero al nodo cabeza de la lista
        NodeList<T> *tail; //es el puntero al nodo cola de la lista
    public:
        List(void) {
            head = NULL;
            tail = NULL;
        };
        List(NodeList<T> *n) {
            head = n;
            tail = n;
        };
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

template<class T> void List<T>::add(T d) {
    if(!this->isEmpty()) {
        NodeList<T> *nw = new NodeList<T>(d, NULL, tail);
        tail->setNext(nw);
        tail = nw;
    }
    else {
        NodeList<T> *nw = new NodeList<T>(d);
        head = nw;
        tail = nw;
    }
}

template<class T> void List<T>::addHead(T d) {
    if(!this->isEmpty()) {
        NodeList<T> *nw = new NodeList<T>(d, head, NULL);
        head->setPrevious(nw);
        head = nw;
    }
    else {
        NodeList<T> *nw = new NodeList<T>(d);
        head = nw;
        tail = nw;
    }
}

template<class T> void List<T>::add(T d, int n) {
    if(n > 0 && n <= this->size()) {
        if(n == 0)
            this->addHead(d);
        else if(n == this->size())
            this->add(d);
        else {
            NodeList<T> *tmp = this->take(n);
            NodeList<T> *nw = new NodeList<T>(d, tmp, tmp->getPrevious());
            nw->getPrevious()->setNext(nw);
            tmp->setPrevious(nw);
        }
    }
}

template<class T> void List<T>::dlte(void) {
    if(!this->isEmpty()) {
        if(head != tail) {
            NodeList<T> *tmp = tail;
            tail = tail->getPrevious();
            tail->setNext();
            delete tmp;
        }
        else {
            NodeList<T> *tmp = head;
            head = NULL;
            tail = NULL;
            delete tmp;
        }
    }
}

template <class T> void List<T>::dlteHead(void) {
    if(!this->isEmpty()) {
        if(head != tail) {
            NodeList<T> *tmp = head;
            head = head->getNext();
            head->setPrevious();
            delete tmp;
        }
        else {
            NodeList<T> *tmp = head;
            head = NULL;
            tail = NULL;
            delete tmp;
        }
    }
}

template<class T> void List<T>::dlte(int n) {
    if(!this->isEmpty() && n >= 0 && n < this->size()) {
        if(n == 0)
            this->dlteHead();
        else if(n == this->size()-1)
            this->dlte();
        else {
            NodeList<T> *tmp = this->take(n);
            tmp->getNext()->setPrevious(tmp->getPrevious());
            tmp->getPrevious()->setNext(tmp->getNext());
            delete tmp;
        }
    }
}

template<class T> NodeList<T> *List<T>::getHead(void) {
    return head;
}

template<class T> NodeList<T> *List<T>::getTail(void) {
    return tail;
}

template<class T> List<T> *List<T>::rest(void) {
    return new List<T>(head->getNext());
}

template<class T> NodeList<T> *List<T>::take(int n) {
    if(!this->isEmpty() && n >= 0 && n < this->size()) {
        if(n == 0)
            return head;
        if(n == this->size())
            return tail;
        return this->rest()->take(n-1);
    }
    return NULL;
}

template<class T> void List<T>::swap(int a, int b) {
    T tmp = this->take(a)->getData();
    this->take(a)->setData(this->take(b)->getData());
    this->take(b)->setData(tmp);
}

template<class T> int List<T>::position(T d) {
    if(head->getData() == d)
        return 0;
    else
        return 1+this->rest()->position(d);
}

template<class T> void List<T>::show(void) {
    if(!this->isEmpty()) {
        NodeList<T> *tmp = head;
        do {
            cout<<endl<<tmp->getData();
            if(tmp->getPrevious() != NULL)
                cout<<" - previous: "<<tmp->getPrevious()->getData();
            else
                cout<<" - previous: NULL";
            if(tmp->getNext() != NULL)
                cout<<" - next: "<<tmp->getNext()->getData();
            else
                cout<<" - next: NULL";
            tmp = tmp->getNext();
        } while(tmp != NULL);
        cout<<"\nhead: "<<head->getData();
        cout<<"\ntail: "<<tail->getData()<<endl;
    }
    else {
        cout<<"\nEMPTY LIST";
        if(head != NULL)
            cout<<"\nhead: "<<head->getData();
        else
            cout<<"\nhead: NULL";
        if(tail != NULL)
            cout<<"\ntail: "<<tail->getData()<<endl;
        else
            cout<<"\ntail: NULL"<<endl;
    }
}

template<class T> int List<T>::size(void) {
    if(this->isEmpty())
        return 0;
    else
        return 1+this->rest()->size();
}

template<class T> bool List<T>::isEmpty(void) {
    return head == NULL;
}

// ---------------------- Class Stack

template<class T> class Stack:public List<T> {
    public:
        Stack(void) {
            List<T>();
        };
        void stack(T d) { //apila un elemento en la pila
            this->add(d);
        };
        void unstack(void) { //desapila un elemento de la pila
            this->dlte();
        };
        NodeList<T> *stackTake(void) { //retorna un puntero al nodo proximo a salir
            return this->getTail();
        };
        bool stackIsEmpty(void) { //retorna true si la pila esta vacia
            return this->isEmpty();
        };
        int stackSize(void) { //retorna la cantidad de nodos de la pila
            return this->size();
        };
        string stackShow(void) { //muestra todos los elementos de la pila
            return this->show();
        };
};

// ---------------------- Class Queue

template<class T> class Queue:public List<T> {
    public:
        Queue(void) {
            List<T>();
        };
        void queue(T d) { //encola un elemento en la cola
            this->add(d);
        };
        void unqueue(void) { //desencola un elemento de la cola
            this->dlteHead();
        };
        NodeList<T> *queueTake(void) { //retorna un puntero al nodo proximo a salir
            return this->getHead();
        };
        bool queueIsEmpty(void) { //retorna true si la cola esta vacia
            return this->isEmpty();
        };
        int queueSize(void) { //retorna la cantidad de nodos de la cola
            return this->size();
        };
        string queueShow() { //muestra todos los elementos de la cola
            return this->show();
        };
};

// ---------------------- Class NodeTree

template<class T> class NodeTree {
    private:
        T data;
        NodeTree<T> *father;
        List<NodeTree<T> *> *childrens;
    public:
        NodeTree(void) {
            father = NULL;
            childrens = new List<NodeTree<T> *>();
        };
        NodeTree(T d) {
            data = d;
            father = NULL;
            childrens = new List<NodeTree<T> *>();
        };
        NodeTree(T d, NodeTree<T> *f) {
            data = d;
            father = f;
            childrens = new List<NodeTree<T> *>();
        };
        void setData(T d) {
            data = d;
        };
        void setFather(void) {
            father = NULL;
        };
        void setFather(NodeTree<T> *f) {
            father = f;
        };
        T getData(void) {
            return data;
        };
        NodeTree<T> *getFather(void) {
            return father;
        };
        List<NodeTree<T> *> *getChildrens(void) {
            return childrens;
        };
        int level(void) {
            if(father == NULL)
                return 0;
            else
                return 1+this->getFather()->level();
        };
        bool hasFather(void) {
            return father != NULL;
        };
        bool hasChildrens(void) {
            return !childrens->isEmpty();
        };
};

// ---------------------- Class Tree

/*
template<class T> class Tree {
    private:
        int max_childrens; //cantidad de hijos que puede tener un nodo
        NodeTree<T> *root; //puntero al nodo raiz
    public:
        Tree(void) {
            max_childrens = 0;
            root = NULL;
        };
        Tree(int n) {
            max_childrens = n;
            root = NULL;
        };
        Tree(NodeTree<T> *r, int n) {
            max_childrens = n;
            root = r;
        };
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
        
    }
    else
        this->add(d, NULL);
}

template<class T> void Tree<T>::dlte(int n) {

}

template<class T> void Tree<T>::dlteBalanced(void) {
    if(root != NULL) {
    
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
    if(root != NULL) {
        NodeList<NodeTree<T> *> *tmp = nodes->getHead();
        NodeList<NodeTree<T> *> *tmp_aux;
        cout<<endl<<tmp->getData()->getData();
        if(tmp->getData()->getFather() != NULL)
            cout<<" - father: "<<tmp->getData()->getFather()->getData()<<" - childrens: ";
        else
            cout<<" - father: NULL - childrens: ";
        if(tmp->getData()->getChildrens()->isEmpty())
            cout<<"EMPTY";
        else {
            tmp_aux = tmp->getData()->getChildrens()->getHead();
            cout<<tmp_aux->getData()->getData()<<" ";
            while(tmp_aux->hasNext()) {
                tmp_aux = tmp_aux->getNext();
                cout<<tmp_aux->getData()->getData()<<" ";
            }
        }
        while(tmp->hasNext()) {
            tmp = tmp->getNext();
            if(tmp->getData() != root) {
                cout<<endl<<tmp->getData()->getData()<<" - father: "<<tmp->getData()->getFather()->getData()<<" - childrens: ";
                if(tmp->getData()->getChildrens()->isEmpty())
                    cout<<"EMPTY";
                else {
                    tmp_aux = tmp->getData()->getChildrens()->getHead();
                    cout<<tmp_aux->getData()->getData()<<" ";
                    while(tmp_aux->hasNext()) {
                        tmp_aux = tmp_aux->getNext();
                        cout<<tmp_aux->getData()->getData()<<" ";
                    }
                }
            }
            else {
                cout<<endl<<tmp->getData()->getData()<<" - father: NULL - childrens: ";
                if(tmp->getData()->getChildrens()->isEmpty())
                    cout<<"EMPTY";
                else {
                    tmp_aux = tmp->getData()->getChildrens()->getHead();
                    cout<<tmp_aux->getData()->getData()<<" ";
                    while(tmp_aux->hasNext()) {
                        tmp_aux = tmp_aux->getNext();
                        cout<<tmp_aux->getData()->getData()<<" ";
                    }
                }
            }
        }
        cout<<endl;
    }
    else
        cout<<"\nIS EMPTY"<<endl;
}

template<class T> List<NodeTree<T> *> *Tree<T>::toList(void) {
    List<NodeTree<T> *> *output = new List<NodeTree<T> *>();
    if(root != NULL) {
        Queue<NodeTree<T> *> *aux = new Queue<NodeList<T> *>();
        NodeList<T> *it = root->getChildrens()->getHead();
        output->add(root);
        aux->queue(root);
        do {
            // --- IMPLEMENT ---
        } while(it->hasNext());     
    }
    return output;
}
*/

// ---------------------- Class MAIN

int main(int argc, char *argv[]) {
    NodeTree<int> *n1 = new NodeTree<int>();
    NodeTree<int> *n2 = new NodeTree<int>();
    cout<<n1->hasFather();
    n1->setFather(n2);
    cout<<n1->hasFather();
    n1->setFather();
    cout<<n1->hasFather();

    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}