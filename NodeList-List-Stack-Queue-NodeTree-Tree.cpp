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
        void add(T d); //agrega un nodo en la cola
        void add(T d, int n); //agrega un nodo en la posicion n
        void dlteHead(bool b); //borra el nodo cabeza donde b indica si se hara un borrado fisico del nodo
        void dlteTail(bool b); //borra el nodo cola donde b indica si se hara un borrado fisico del nodo
        void dlte(int n, bool b); //borra el nodo en la posicion n donde b indica si sera un borrado fisico del nodo
        NodeList<T> *getHead(void); //retorna un puntero al nodo cabeza
        NodeList<T> *getTail(void); //retorna un puntero al nodo cola
        NodeList<T> *take(int n); //retorna un puntero al nodo en la posicion n
        List *rest(void); //retorna la lista sin el nodo cola
        int size(void); //retorna un entero que indica la cantidad de nodos de la lista
        void swap(int a, int b); //efectua un swap entre la informacion del nodo en la posicion a con el nodo en la posicion b
        int position(T d); //retorna un entero indicando la posicion donde se encuentra el dato d
        void show(void); //muestra todos los elementos de la lista
        bool isEmpty(void); //retorna true si la lista esta vacia
};

template<class T> void List<T>::add(T d) {
    if(head != NULL) {
        NodeList<T> *nw = new NodeList<T>(d, NULL, tail);
        tail->setNext(nw);
        tail = nw;
    }
    else {
        NodeList<T> *nw = new NodeList<T>(d, NULL, NULL);
        head = nw;
        tail = nw;
    }
}

template<class T> void List<T>::add(T d, int n) {
    if(n <= this->size() && n > 0) {
        if(n == this->size())
            this->add(d);
        else if(n == 0) {
            NodeList<T> *nw = new NodeList<T>(d, head, NULL);
            head->setPrevious(nw);
            head = nw;
        }
        else {
            NodeList<T> *tmp = this->take(n);
            NodeList<T> *nw = new NodeList<T>(d, tmp, tmp->getPrevious());
            nw->getPrevious()->setNext(nw);
            tmp->setPrevious(nw);
        }
    }
}

template <class T> void List<T>::dlteHead(bool b) {
    if(!this->isEmpty()) {
        if(head != tail) {
            NodeList<T> *tmp = head;
            head = head->getNext();
            head->setPrevious();
            if(b)
                delete tmp;
        }
        else {
            NodeList<T> *tmp = head;
            head = NULL;
            tail = NULL;
            if(b)
                delete tmp;
        }
    }
}

template<class T> void List<T>::dlteTail(bool b) {
    if(!this->isEmpty()) {
        if(head != tail) {
            NodeList<T> *tmp = tail;
            tail = tail->getPrevious();
            tail->setNext();
            if(b)
                delete tmp;
        }
        else {
            NodeList<T> *tmp = tail;
            head = NULL;
            tail = NULL;
            if(b)
                delete tmp;
        }
    }
}

template<class T> void List<T>::dlte(int n, bool b) {
    if(!this->isEmpty() && n < this->size() && n >= 0) {
        if(n == 0)
            this->dlteHead(b);
        else if(n == this->size()-1)
            this->dlteTail(b);
        else {
            NodeList<T> *tmp = this->take(n);
            tmp->getNext()->setPrevious(tmp->getPrevious());
            tmp->getPrevious()->setNext(tmp->getNext());
            if(b)
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

template<class T> NodeList<T> *List<T>::take(int n) {
    if(!this->isEmpty() && n < this->size() && n >= 0) {
        if(n == 0)
            return head;
        if(n == this->size()-1)
            return tail;
        return this->rest()->take(n);
    }
    return NULL;
}

template<class T> List<T> *List<T>::rest(void) {
    List* tmp = new List(tail->getPrevious());
    return tmp;
}

template<class T> int List<T>::size(void) {
    if(this->isEmpty())
        return 0;
    else
        return 1+this->rest()->size();
}

template<class T> void List<T>::swap(int a, int b) {
    T tmp = this->take(a)->getData();
    this->take(a)->setData(this->take(b)->getData());
    this->take(b)->setData(tmp);
}

template<class T> int List<T>::position(T d) {
    if(!this->isEmpty()) {
        int counter = 0;
        NodeList<T> *tmp = head;
        while(tmp->getData() != d) {
            tmp = tmp->getNext();
            counter++;
        }
        return counter;
    }
}

template<class T> void List<T>::show(void) {
    if(!this->isEmpty()) {
        NodeList<T> *tmp = head;
        cout<<endl<<tmp->getData();
        if(tmp->getPrevious() != NULL)
            cout<<" - previous: "<<tmp->getPrevious()->getData();
        else
            cout<<" - previous: NULL";
        if(tmp->getNext() != NULL)
            cout<<" - next: "<<tmp->getNext()->getData();
        else
            cout<<" - next: NULL";
        while(tmp->hasNext()) {
            tmp = tmp->getNext();
            cout<<endl<<tmp->getData();
            if(tmp->getPrevious() != NULL)
                cout<<" - previous: "<<tmp->getPrevious()->getData();
            else
                cout<<" - previous: NULL";
            if(tmp->getNext() != NULL)
                cout<<" - next: "<<tmp->getNext()->getData();
            else
                cout<<" - next: NULL";
        }
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
        void unstack(bool b) { //desapila un elemento de la pila donde b indica si se hara un borrado fisico del nodo
            this->dlteTail(b);
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
        void unqueue(bool b) { //desencola un elemento de la cola donde b indica si se hara un borrado fisico del nodo
            this->dlteHead(b);
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
        T data; //dato del nodo
        NodeTree<T> *father; //puntero al nodo padre
        List<NodeTree<T> *> *childrens; //lista para almacenar punteros a nodos hijos
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
        void setData(T d) { //setea un dato d al nodo
            data = d;
        };
        void setFather(NodeTree<T> *f) { //setea un nodo como padre del nodo
            father = f;
        };
        T getData(void) { //retorna el valor del dato del nodo
            return data;
        };
        NodeTree<T> *getFather(void) { //retorna el puntero al padre del nodo
            return father;
        };
        List<NodeTree<T> *> *getChildrens(void) { //retorna el puntero a la lista de nodos hijos
            return childrens;
        };
        int level(void) { //retorna un entero que indica el nivel en el que se encuentra el nodo
            if(father == NULL)
                return 0;
            else
                return 1+this->getFather()->level();
        };
};

// ---------------------- Class Tree

template<class T> class Tree {
    private:
        int n_childrens; //cantidad de hijos que puede tener un nodo
        int n_childrens_counter; //contador para controlar el llenado de nodos hijos
        NodeList<NodeTree<T> *> *father_mark; //puntero al nodo que sera padre del proximo nodo
        NodeTree<T> *root; //puntero al nodo raiz
        List<NodeTree<T> *> *nodes; //lista de punteros a todos los nodos del arbol
    public:
        Tree(void) {
            n_childrens = 2; //valor de hijos por default (arbol binario)
            n_childrens_counter = 0;
            root = NULL;
            father_mark = NULL;
            nodes = new List<NodeTree<T> *>();
        };
        Tree(int n) {
            n_childrens = n;
            n_childrens_counter = 0;
            root = NULL;
            father_mark = NULL;
            nodes = new List<NodeTree<T> *>();
        };
        Tree(NodeTree<T> *r, int n) {
            n_childrens = n;
            n_childrens_counter = 0;
            root = r;
            father_mark = r;
            nodes = new List<NodeTree<T> *>(r);
        };
        void addBalanced(T d); //añade un dato d en un nuevo nodo llenando por nivel
        void dlteBalanced(bool b); //elimina el ultimo nodo donde b indica si se hara un borrado fisico del nodo
        NodeTree<T> *take(int n); //retorna un puntero al nodo en la posicion n
        NodeTree<T> *getRoot(void); //retorna un puntero a la raiz
        int size(void); //retorna la cantidad de nodos del arbol
        void swapChildrenFather(NodeTree<T> *n); //efectua un swap entre la informacion del nodo n y su nodo padre
        void show(void); //muestra todos los elementos del arbol forma de lista
        List<NodeTree<T> *> *toList(bool b); //retorna todos los elementos del arbol en forma de lista donde b indica si se hara un borrado fisico del nodo
        Queue<NodeTree<T> *> *toQueue(bool b); //retorna todos los elementos del arbol en forma de cola donde b indica si se hara un borrado fisico del nodo
        Stack<NodeTree<T> *> *toStack(bool b); //retorna todos los elementos del arbol en forma de pila donde b indica si se hara un borrado fisico del nodo
};

template<class T> void Tree<T>::addBalanced(T d) {
    if(root != NULL) {
        if(n_childrens_counter == n_childrens)
            father_mark = father_mark->getNext();
        NodeTree<T> *nw = new NodeTree<T>(d, father_mark->getData());
        father_mark->getData()->getChildrens()->add(nw);
        nodes->add(nw);
        if(n_childrens_counter < n_childrens)
            n_childrens_counter++;
        else
            n_childrens_counter = 1;
    }
    else {
        NodeTree<T> *nw = new NodeTree<T>(d);
        root = nw;
        nodes->add(nw);
        father_mark = nodes->getHead();
    }
}

template<class T> void Tree<T>::dlteBalanced(bool b) {
    if(root != NULL) {
        NodeTree<T> *tmp = nodes->getTail()->getData();
        if(tmp != root) {
            tmp->getFather()->getChildrens()->dlteTail(true);
            nodes->dlteTail(true);
            if(n_childrens_counter > 1)
                n_childrens_counter--;
            else if(nodes->getTail()->getData() != root)
                n_childrens_counter = n_childrens;
            else
                n_childrens_counter = 0;
            if(n_childrens_counter == n_childrens)
                father_mark = father_mark->getPrevious();
        }
        else {
            n_childrens_counter = 0;
            root = NULL;
            father_mark = NULL;
            nodes->dlteTail(true);
        }
        if(b)
            delete tmp;
    }
}

template<class T> NodeTree<T> *Tree<T>::take(int n) {
    return nodes->take(n);
}

template<class T> NodeTree<T> *Tree<T>::getRoot(void) {
    return root;
}

template<class T> int Tree<T>::size(void) {
    return nodes->size();
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

template<class T> List<NodeTree<T> *> *Tree<T>::toList(bool b) {
    List<NodeTree<T> *> *output = new List<NodeTree<T> *>();
    if(root != NULL) {
        NodeTree<T> *tmp_1 = root;
        NodeTree<T> *tmp_2 = NULL;
        Queue<NodeTree<T> *> *queue = new Queue<NodeTree<T> *>();
        queue->queue(tmp_1);
        while(!queue->queueIsEmpty()) {
            tmp_1 = queue->queueTake()->getData();
            queue->unqueue(b);
            output->add(tmp_1);
            if(!tmp_1->getChildrens()->isEmpty()) {
                tmp_2 = tmp_1->getChildrens()->getHead()->getData();
                tmp_1->getChildrens()->dlteHead(b);
                queue->queue(tmp_2);
            }
            while(!tmp_2->getFather()->getChildrens()->isEmpty()) {
                tmp_2 = tmp_2->getFather()->getChildrens()->getHead()->getData();
                queue->queue(tmp_2);
                tmp_2->getFather()->getChildrens()->dlteHead(b);
            }
        }
    }
    return output;
}

template<class T> Queue<NodeTree<T> *> *Tree<T>::toQueue(bool b) {
    Queue<NodeTree<T> *> *output = new Queue<NodeTree<T> *>();
    if(root != NULL) {
        NodeTree<T> *tmp_1 = root;
        NodeTree<T> *tmp_2 = NULL;
        Queue<NodeTree<T> *> *queue = new Queue<NodeTree<T> *>();
        queue->queue(tmp_1);
        while(!queue->queueIsEmpty()) {
            tmp_1 = queue->queueTake()->getData();
            queue->unqueue(b);
            output->queue(tmp_1);
            if(!tmp_1->getChildrens()->isEmpty()) {
                tmp_2 = tmp_1->getChildrens()->getHead()->getData();
                tmp_1->getChildrens()->dlteHead(b);
                queue->queue(tmp_2);
            }
            while(!tmp_2->getFather()->getChildrens()->isEmpty()) {
                tmp_2 = tmp_2->getFather()->getChildrens()->getHead()->getData();
                queue->queue(tmp_2);
                tmp_2->getFather()->getChildrens()->dlteHead(b);
            }
        }
    }
    return output;
}

template<class T> Stack<NodeTree<T> *> *Tree<T>::toStack(bool b) {
    Stack<NodeTree<T> *> *output = new Stack<NodeTree<T> *>();
    if(root != NULL) {
        NodeTree<T> *tmp_1 = root;
        NodeTree<T> *tmp_2 = NULL;
        Queue<NodeTree<T> *> *queue = new Queue<NodeTree<T> *>();
        queue->queue(tmp_1);
        while(!queue->queueIsEmpty()) {
            tmp_1 = queue->queueTake()->getData();
            queue->unqueue(b);
            output->stack(tmp_1);
            if(!tmp_1->getChildrens()->isEmpty()) {
                tmp_2 = tmp_1->getChildrens()->getHead()->getData();
                tmp_1->getChildrens()->dlteHead(b);
                queue->queue(tmp_2);
            }
            while(!tmp_2->getFather()->getChildrens()->isEmpty()) {
                tmp_2 = tmp_2->getFather()->getChildrens()->getHead()->getData();
                queue->queue(tmp_2);
                tmp_2->getFather()->getChildrens()->dlteHead(b);
            }
        }
    }
    return output;
}

// ---------------------- Class MAIN

int main(int argc, char *argv[]) {
    Tree<int> *t = new Tree<int>(5);
    for(int i = 0; i < 100; i++)
        t->addBalanced(i);
    t->show();

    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}