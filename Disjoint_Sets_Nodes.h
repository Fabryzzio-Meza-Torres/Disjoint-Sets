#include <iostream>
#include <unordered_map>

template <typename T>
struct Node
{
    Node<T> *parent;
    int rank_;
    T data;

    Node() : parent(nullptr), rank_(0), data(T()) {}
    Node(T value) : parent(nullptr), rank_(0), data(value) {}
    Node(T value, int height) : parent(nullptr), rank_(height), data(value) {}
    Node(T value, int height, Node<T> *father) : parent(father), rank_(height), data(value) {}
};

template <typename T>
class DisjointSet
{
public:
    ~DisjointSet();

    void MakeSet(Node<T> *x)
    {
        x->parent = x;
    }

    Node<T> *Find(Node<T> *temp)
    {
        if (temp->parent != temp)
        {
            temp->parent = Find(temp->parent);
        }
        return temp->parent;
    }

    void Union(Node<T> *x, Node<T> *y)
    {
        if (x == nullptr || y == nullptr)
        {
            return;
        }

        Node<T> *rootx = Find(x);
        Node<T> *rooty = Find(y);

        if (rootx != rooty)
        {
            if (rootx->rank_ < rooty->rank_)
            {
                rootx->parent = rooty;
            }
            else if (rootx->rank_ > rooty->rank_)
            {
                rooty->parent = rootx;
            }
            else
            {
                rooty->parent = rootx;
                rootx->rank_++;
            }
        }
    }

    bool IsConnected(Node<T> *x, Node<T> *y)
    {
        return Find(x) == Find(y);
    }
};