#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
    public:
    vector<int> *adjList;

    Graph(vector<Edge> const &edges, int N)
    {
        adjList = new vector<int>[N];
    
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
    ~Graph()
    {
        delete[] adjList;
    }
};
string color[] =
{
    "BROWN", "BLUE", "GREEN", "LAVENDER", "ORANGE", "PINK", "RED" ,"YELLOW"
    "VIOLET", "GOLD", "GRAY", "INDIGO", "SILVER"
};
void colorGraph(const Graph &graph, int N)
{
    unordered_map<int, int> result;

    for (int u = 0; u < N; u++)
    {
        unordered_set<int> assigned;
        
        for (int i : graph.adjList[u])
        {
            if (result[i])
            {
                assigned.insert(result[i]);
            }
        }
        int color = 1;
        for (auto &c: assigned )
        {
            if (color != c)
            {
                break;
            }
            color++;
        }
        result[u] = color;
    }
    
    for (int v = 0; v < N; v++)
    {
        cout << "Color assigned to vertex " << v+1 << " is  "
        << color[result[v]] << endl;
    }
}
int main()
{
    vector<Edge> edges =
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4},
        {4, 7}, {5, 8}, {8, 9}, {6, 7}, {7, 10}, {8, 10}, {9, 11}
    };

    int N = 12;
    
    Graph graph(edges, N);
    colorGraph(graph, N);
    
    return 0;
}
