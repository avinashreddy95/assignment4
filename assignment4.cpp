#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

#define INF INT_MAX
#define NIL -1

void dijkstra(vector<vector<int>> &graph, int source, int n)
{
    int distance[n], parent[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INF;
        parent[i] = NIL;
    }

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u;

        for (int i = 0; i < n; i++)
            if (!visited[i] && min > distance[i])
                min = distance[i], u = i;

        visited[u] = true;

        for (int i = 0; i < n; i++)
            if (!visited[i] && graph[u][i] && distance[u] != INF &&
                distance[u] + graph[u][i] < distance[i])
            {
                parent[i] = u;
                distance[i] = distance[u] + graph[u][i];
            }
    }

    cout << "Vertex\tDistance\tPath";

    for (int i = 0; i < n; i++)
    {
        int path[n], u = i, path_index = 0;

        while (u != NIL)
        {
            path[path_index] = u;
            path_index++;
            u = parent[u];
        }

        cout << "\n"
             << i << " -> " << source << " \t" << distance[i] << "\t\t";

        for (int j = path_index - 1; j >= 0; j--)
            cout << path[j] << " ";
    }
}

int main()
{

    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  int source, dest;
    cout << "Enter source node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> dest;

    dijkstra(graph, source, dest);

    return 0;
}
