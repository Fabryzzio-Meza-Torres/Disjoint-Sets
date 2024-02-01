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
//Disjoint set from array
template<typename T>
class DisjointSetArray
{
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<T> data;
    int sets_{};
    int elements{};
    public:
    DisjointSetArray(std::vector<T> values)
    {
        parent.resize(values.size());
        rank.resize(values.size());
        data = values;
        for (int i = 0; i < values.size(); i++)
        {
            MakeSet(i);
        }
        sets_ = values.size();
        elements = values.size();}
    void MakeSet(int x){
        parent[x] = x;
        rank[x] = 0;
        sets_++;
        elements++;}
    int FindPathCompression(int x){
        if (x < 0)
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (parent[x] != x)
        {
            parent[x] = FindPathCompression(parent[x]);
        }
        return parent[x];}
    void Union(int x, int y){
        int rootx = FindPathCompression(x);
        int rooty = FindPathCompression(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
            }
            else if (rank[rootx] > rank[rooty])
            {
                parent[rooty] = rootx;
            }
            else
            {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
        else
        {
            return;
        }
        --sets_;}
    bool IsConnected(int x, int y){
        return (FindPathCompression(x) == FindPathCompression(y)) ? true : false;}
    int size(){
        return elements;}
    int sets(){
        return sets_;}
    void print(){
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << "Data: " << data[i] << " Parent: " << parent[i] << " Rank: " << rank[i] << std::endl;
        }}
    };
