#include <iostream>
#include <unordered_map>
using namespace std;

template <typename T>
struct Node
{
    Node *parent;
    int rank;
    T data;
    Node() : parent(nullptr), rank(0), data(T()) {}
    Node(T value) : parent(nullptr), rank(0), data(value) {}
    Node(T value, int height) : parent(nullptr), rank(height), data(value) {}
    Node(T value, int height, Node *father) : parent(father), rank(height), data(value) {}
};

template <typename T>
class DisjoinSet
{
private:
    unordered_map<T, Node> nodes;

public:
    ~DisjoinSet();
    void MakeSet(T x)
    {
        Node *newNode = Node(x);
        newNode->parent = newNode;
        nodes[x] = newNode;
    }

    Node *Find(Node *temp)
    {
        if (temp->parent != temp)
        {
            temp->parent = find(temp->parent);
        }
        return temp->parent;
    }
    void Union(Node *x, Node *y)
    {
        if (x || y == nullptr)
        {
            return;
        }
        Node *rootx = find(x);
        Node *rooty = find(y);

        if (rootx != rooty)
        {
            if (rootx->rank < rooty->rank)
            {
                rootx->parent = rooty;
            }
            else if (rootx->rank > rooty->rank)
            {
                rooty->parent = rootx;
            }
            else if (rootx->rank == rooty->rank)
            {
                rooty->parent = rootx;
                rootx->rank++
            }
        }
    }
    bool isConnected(Node *x, Node *y)
    {
        Node *temp = find(x);
        Node *temp2 = find(y);
        return (temp == temp2) ? true : false;
    }
};