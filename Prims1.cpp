#include <iostream>
using namespace std;

#define INF 1000000 // Increased for safety

class Graph
{
  int n;
  int **graph;

public:
  Graph()
  {
    cout << "\nEnter number of vertices in the graph : ";
    cin >> n;

    graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
      graph[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        graph[i][j] = 0;
      }
    }
  }

  void readGraph()
  {
    int u, v, w;
    cout << "\nEnter edges & weight (u v w), or -1 -1 -1 to stop:\n";
    while (true)
    {
      cin >> u >> v >> w;
      if (u == -1 && v == -1 && w == -1)
      {
        return;
      }
      else if (u == -1 || v == -1 || w == -1)
      {
        cout << "\nInvalid vertex or weight -1 !! Enter again !";
      }
      else if (u >= n || v >= n || u < 0 || v < 0)
      {
        cout << "\nVertex out of range !! Enter again !";
      }
      else
      {
        graph[u][v] = w;
        graph[v][u] = w;
      }
    }
  }

  void printGraph()
  {
    cout << "\nAdjacency Matrix:";
    for (int i = 0; i < n; i++)
    {
      cout << "\n" << i << " : ";
      for (int j = 0; j < n; j++)
      {
        cout << graph[i][j] << " ";
      }
    }
  }

  void prims()
  {
    int **cost = new int *[n];
    for (int i = 0; i < n; i++)
    {
      cost[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];
      }
    }

    int *visited = new int[n];
    int *distance = new int[n];
    int *from = new int[n];

    int source;
    cout << "\n\nEnter source : ";
    cin >> source;

    for (int i = 0; i < n; i++)
    {
      visited[i] = 0;
      distance[i] = cost[source][i];
      from[i] = source;
    }
    visited[source] = 1;
    distance[source] = 0;

    int ne = n - 1;
    int mincost = 0;

    while (ne > 0)
    {
      int v = -1, mindist = INF;
      for (int i = 0; i < n; i++)
      {
        if (!visited[i] && distance[i] < mindist)
        {
          mindist = distance[i];
          v = i;
        }
      }

      if (v == -1) break; // No more reachable vertices

      int u = from[v];
      visited[v] = 1;
      cout << "\nAdd edge ( " << u << " , " << v << " ) with weight " << cost[u][v];
      mincost += cost[u][v];

      for (int i = 0; i < n; i++)
      {
        if (!visited[i] && distance[i] > cost[v][i])
        {
          distance[i] = cost[v][i];
          from[i] = v;
        }
      }
      ne--;
    }

    cout << "\n\nMinimum cost = " << mincost;

  }
};

int main()
{
  Graph g;
  g.readGraph();
  g.printGraph();
  g.prims();
  return 0;
}
