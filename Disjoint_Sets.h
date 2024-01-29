#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    Node *parent;
    int rank;
    T data;
};

template <typename T>
class DisjoinSet
{
public:
    ~DisjoinSet();
    void MakeSet(int x)
    {
        parent[x] = x;
    }
    int Find(int x);
    void Union(int x, int y);
    // verifica si hay un camino entre x e y
    bool isConnected(int x, int y);
};