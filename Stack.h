#ifndef STACKDB_STACK_H
#define STACKDB_STACK_H

#include <iostream>

using namespace std;

template<class T> class Stack:public List<T> {
    public:
        Stack(void);
        void stack(T d);
        void unstack(void);
        NodeList<T> *stackTake(void);
        bool stackIsEmpty(void);
        int stackSize(void);
        void stackShow(void);
};

#endif
