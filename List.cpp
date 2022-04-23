#include "List.h"

#include <iostream>

using namespace std;

template<class T> List<T>::List(void) {
    head = NULL;
    tail = NULL;
}

template<class T> List<T>::List(NodeList<T> *n) {
    head = n;
    tail = n;
}

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