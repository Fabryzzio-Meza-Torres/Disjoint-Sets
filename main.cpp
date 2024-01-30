#include <iostream>
#include <unordered_map>
#include "Disjoint_Sets_Nodes.h"
using namespace std;

int main()
{
    DisjointSet<int> dsu; // Create a DisjoinSet object to manage integers

    // Example usage:
    // Create some nodes
    Node<int> *node1 = new Node<int>(10);
    Node<int> *node2 = new Node<int>(20);
    Node<int> *node3 = new Node<int>(30);

    // Make sets for the nodes
    dsu.MakeSet(node1);
    dsu.MakeSet(node2);
    dsu.MakeSet(node3);

    // Perform operations on the nodes
    dsu.Union(node1, node2); // Union node1 and node2

    // Check connectivity
    if (dsu.IsConnected(node1, node2))
    {
        cout << "node1 and node2 are connected\n";
    }
    else
    {
        cout << "node1 and node2 are not connected\n";
    }

    if (dsu.IsConnected(node1, node3))
    {
        cout << "node1 and node3 are connected\n";
    }
    else
    {
        cout << "node1 and node3 are not connected\n";
    }

    return 0;
}