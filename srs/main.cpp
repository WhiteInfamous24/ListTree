#include "NodeList.h"
#include "NodeList.cpp"
#include "List.h"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "NodeTree.h"
#include "NodeTree.cpp"
#include "Tree.h"
#include "Tree.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
    List<int> *l = new List<int>();
    l->add(24);
    l->show();
    
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
