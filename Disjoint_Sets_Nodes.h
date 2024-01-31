#include <iostream>
#include <vector>

template <typename T>
class DisjointSet
{
    struct Node
    {
        int parent;
        int rank_;
        T data;
        int size;
        Node() : data(), parent(), rank_(), size() {}
    };
    Node *nodes = nullptr;
    int sets_{};
    int elements{};

public:
    DisjointSet(std::vector<T> values)
    {
        nodes = new Node[values.size()];
        for (int i = 0; i < values.size(); i++)
        {
            MakeSet(i);
            nodes[i].data = values[i];
        }
        sets_ = values.size();
        elements = values.size();
    }
    ~DisjointSet()
    {
        delete[] nodes;
    }

    void MakeSet(int x)
    {
        nodes[x].parent = x;
        nodes[x].rank_ = 0;
        nodes[x].size = 1;
        sets_++;
        elements++;
    }

    int FindPathCompression(int x)
    {
        if (x < 0)
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (nodes[x].parent != x)
        {
            nodes[x].parent = FindPathCompression(nodes[x].parent);
        }
        return nodes[x].parent;
    }

    void Union(int x, int y)
    {

        int rootx = FindPathCompression(x);
        int rooty = FindPathCompression(y);

        if (rootx != rooty)
        {
            if (nodes[rootx].rank_ < nodes[rooty].rank_)
            {
                nodes[rootx].parent = rooty;
                nodes[rooty].size += nodes[rootx].size;
            }
            else if (nodes[rootx].rank_ > nodes[rooty].rank_)
            {
                nodes[rooty].parent = rootx;
                nodes[rootx].size += nodes[rooty].size;
            }
            else
            {
                nodes[rooty].parent = rootx;
                nodes[rootx].size += nodes[rooty].size;
                nodes[rooty].rank_++;
            }
        }
        else
        {
            return;
        }
        --sets_;
    }

    bool IsConnected(int x, int y)
    {
        return (FindPathCompression(x) == FindPathCompression(y)) ? true : false;
    }
    int size()
    {
        return elements;
    }

    int sets()
    {
        return sets_;
    }
};
template<typename T>
class DisjointSetTree: public DisjointSet<T>{
private:
public:
    DisjointSetTree(T* data, int n);
};
template<typename T>
class DisjointSetArray: public DisjointSet<T>{
private:

public:
    DisjointSetArray(T* data,int n);
};
