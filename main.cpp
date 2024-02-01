#include <iostream>
#include <vector>
#include "Disjoint_Sets_Nodes.h"
#include <ios>
using namespace std;

int main()
{
    // Example usage of DisjointSet
    vector<int> values = {0, 1, 2, 3, 4, 5};
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
    vector<int> values1 = {5,6,7,8,9,10};
    DisjointSetArray<int> disjointSetArray(values1);
    //Imprimr DisjointSetArray
    disjointSetArray.Union(5, 6);
    disjointSetArray.Union(7, 8);
    disjointSetArray.Union(9, 10);
    disjointSetArray.print();
    cout << "Number of sets: " << disjointSetArray.sets() << endl;
    cout << "Size of the disjoint set: " << disjointSetArray.size() << endl;


    

    return 0;
}