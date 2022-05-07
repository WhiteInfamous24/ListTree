#ifndef NODELISTDB_NODELIST_H
#define NODELISTDB_NODELIST_H

#include <iostream>

using namespace std;

template<class T> class NodeList {
    private:
        T data;
        NodeList<T> *next;
        NodeList<T> *previous;
    public:
        NodeList(void);
        NodeList(T d);
        NodeList(T d, NodeList<T> *n, NodeList<T> *p);
        void setData(T d);
        void setNext(void);
        void setNext(NodeList<T> *n);
        void setPrevious(void);
        void setPrevious(NodeList<T> *p);
        T getData(void);
        NodeList<T> *getNext(void);
        NodeList<T> *getPrevious(void);
        bool hasNext(void);
        bool hasPrevious(void);
};

#endif
