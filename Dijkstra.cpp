#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairs_int;
class Graph
    {
    list<pair<int, int>>* list_adjacent;
    int V;
public:
    Graph(int V)
    {
        list_adjacent = new list<pairs_int>[V];
        this->V = V;
    }
    void edge_add(int u, int v, int w){
    list_adjacent[v].push_back(make_pair(u, w));
    list_adjacent[u].push_back(make_pair(v, w));
    }
    void shortestPath(int source){
    vector<int> distance(V, 0x3f3f3f3f);
    distance[source] = 0;
    int v,wt;
    priority_queue<pairs_int, vector<pairs_int>, greater<pairs_int>> priorityqueue;
    priorityqueue.push(make_pair(0, source));
    while (!priorityqueue.empty()) {
        int u = priorityqueue.top().second;
        priorityqueue.pop();
        list<pair<int, int>>::iterator it;
        for (it = list_adjacent[u].begin(); it != list_adjacent[u].end(); ++it) {
            wt = (*it).second;
            v = (*it).first;
            if (distance[v] > distance[u] + wt) {
                distance[v] = distance[u] + wt;
                priorityqueue.push(make_pair(distance[v], v));
            }
        }
    }
    printf("Vertex: \t");
   for (int i = 0; i < V; ++i)
      printf("%d \t", i);
      printf("\nshortest path: ");
   for (int i = 0; i < V; ++i)
      printf("%d \t",distance[i]);

}
};

int main()
{
    int v,e,a,b,w,s;
    cout<< "Enter number of vertices:";
    cin>> v;
    cout<< "Enter number of edges:";
    cin>> e;
    cout<< "Enter the edges:";
   Graph graph(v);
   for(int i = 0; i < e;i++) {
        cin>> a;
        cin>>b;
        cin>> w;
        graph.edge_add(a, b, w);

    }
    cout<< "Enter source vertex:";
    cin>> s;
   graph.shortestPath(s);


    return 0;
}
