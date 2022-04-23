#ifndef QUEUEDB_QUEUE_H
#define QUEUEDB_QUEUE_H

#include <iostream>

using namespace std;

template<class T> class Queue:public List<T> {
    public:
        Queue(void);
        void queue(T d);
        void unqueue(void);
        NodeList<T> *queueTake(void);
        bool queueIsEmpty(void);
        int queueSize(void);
        void queueShow();
};

#endif