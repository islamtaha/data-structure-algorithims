#include "ArrayList.h"
#include <iostream>
using namespace algo;
using namespace std;

int main(){
    ArrayList<int> xs;
    xs.insert(0);
    xs.insert(1);
    xs.insert(2);
    xs.insert(3);

    cout << xs[0] << endl;
    cout << xs[3] << endl;

    cout << xs.remove(1) << endl;
    cout << xs[1] << endl;

    xs.clear();
    cout << xs[3];

    return 0;
}
