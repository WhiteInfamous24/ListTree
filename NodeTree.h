#ifndef NODETREEDB_NODETREE_H
#define NODETREEDB_NODETREE_H

#include <iostream>

using namespace std;

template<class T> class NodeTree {
    private:
        T data;
        NodeTree<T> *father;
        List<NodeTree<T> *> *childrens;
    public:
        NodeTree(void);
        NodeTree(T d);
        NodeTree(T d, NodeTree<T> *f);
        void setData(T d);
        void setFather(void);
        void setFather(NodeTree<T> *f);
        T getData(void);
        NodeTree<T> *getFather(void);
        List<NodeTree<T> *> *getChildrens(void);
        int level(void);
        bool hasFather(void);
        bool hasChildrens(void);
};

#endif
