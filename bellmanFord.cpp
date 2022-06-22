#include <bits/stdc++.h>
using namespace std;
struct Edge {
   int source, destination, weight;
};
struct Graph {
   int V, E;
   struct Edge* edge;
};
struct Graph* graph(int V, int E) {
   struct Graph* g= new Graph;
   g->E = E;
   g->V = V;
   g->edge = new Edge[E];
   return g;
}
void shortest_path(struct Graph* g,int source) {
   int E = g->E, V = g->V, distance[V],u,v,weight;
   for (int i = 0; i< V; i++){
      distance[i] = INT_MAX;
	}
      distance[source] = 0;
   for (int i = 1; i <= V - 1; i++) {
      for (int j = 0; j < E; j++) {
         weight = g->edge[j].weight;
         v = g->edge[j].destination;
         u = g->edge[j].source;
         if (distance[u] + weight < distance[v] && distance[u] != INT_MAX){
         distance[v] = weight + distance[u];
	}
      }
   }
   for (int i = 0; i < E; i++) {
      weight = g->edge[i].weight;
      v = g->edge[i].destination;
      u = g->edge[i].source;
      if (distance[u] + weight < distance[v] && distance[u] != INT_MAX) {
         printf("negative weight cycle is present");
         return;
      }
   }
   printf("Vertex: \t");
   for (int i = 0; i < V; ++i)
      printf("%d \t", i);
      printf("\nshortest path: ");
   for (int i = 0; i < V; ++i)
      printf("%d \t",distance[i]);
   return;
}
int main() {
    int v,e,a,b,w,s;
    cout<< "Enter number of vertices:";
    cin>> v;
    cout<< "Enter number of edges:";
    cin>> e;
    cout<< "Enter the edges:";
   struct Graph* g = graph(v, e);
   for(int i = 0; i < e;i++) {
        cin>> a;
        cin>>b;
        cin>> w;
        g->edge[i].source = a;
        g->edge[i].destination = b;
        g->edge[i].weight = w;
    }
    cout<< "Enter source vertex:";
    cin>> s;
   shortest_path(g, s);
   return 0;
}
