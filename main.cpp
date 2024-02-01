#include <iostream>
#include <vector>
#include "Disjoint_Sets_Nodes.h"
#include <ios>
using namespace std;

int main()
{
    // Example usage of DisjointSet
    vector<int> values = {0, 1, 2, 3, 4, 5};    
    vector<int> va = {6,7,8,9,10,11};

    DisjointSet<int> disjointSet(values);

    disjointSet.Union(0, 1);
    disjointSet.Union(2, 3);
    disjointSet.Union(4, 5);
    disjointSet.Union(1, 3);

    cout << "Number of sets: " << disjointSet.sets() << endl;
    cout << "Size of the disjoint set: " << disjointSet.size() << endl;

    cout << "Is 0 connected to 2? " << boolalpha << disjointSet.IsConnected(0, 2) << endl;
    cout << "Is 1 connected to 4? " << boolalpha << disjointSet.IsConnected(1, 4) << endl;

    //DisjointSet with array
    int dato[]= {0, 1, 2, 3, 4};
    int n = sizeof(dato) / sizeof(dato[0]);

    DisjointSetArray<int> disjointSetArray(dato, n);

    disjointSetArray.Union(0, 1);
    disjointSetArray.Union(2, 3);
    disjointSetArray.Union(1, 4);

    cout << "Is 0 connected to 3? " << boolalpha << disjointSetArray.IsConnected(0, 3) << endl;
    cout << "Is 0 connected to 4? " << boolalpha << disjointSetArray.IsConnected(0,4) << endl;
    return 0;
}
