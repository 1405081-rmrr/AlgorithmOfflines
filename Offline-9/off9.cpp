// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <list>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void printVertexCover(); // prints vertex cover
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
	// Initialize all vertices as not visited.
	bool visited[V];
	for (int i=1; i<=V; i++)
		visited[i] = false;

	list<int>::iterator i;

	// Consider all edges one by one
	for (int u=1; u<=V; u++)
	{
		// An edge is only picked when both visited[u] and visited[v]
		// are false
		if (visited[u] == false)
		{
			// Go through all adjacents of u and pick the first not
			// yet visited vertex (We are basically picking an edge
			// (u, v) from remaining edges.
			for (i= adj[u].begin(); i != adj[u].end(); ++i)
			{
				int v = *i;
				if (visited[v] == false)
				{
					// Add the vertices (u, v) to the result set.
					// We make the vertex u and v visited so that
					// all edges from/to them would be ignored
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	// Print the vertex cover
	for (int i=1; i<=V; i++)
		if (visited[i])
		cout << i << " ";
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(50);
	/*g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(1,2);*/
g.addEdge (1,3);
g.addEdge (1,7);
g.addEdge (1,8);
g.addEdge (1,10);
g.addEdge (1,12);
g.addEdge (1,14);
g.addEdge (1 ,15);
g.addEdge (1, 16);
g.addEdge (1 ,19);
g.addEdge (1, 20);
g.addEdge (1, 22);
g.addEdge (1, 24);
g.addEdge (1, 26);
g.addEdge (1, 28);
g.addEdge (1, 29);
g.addEdge (1, 32);
g.addEdge (1, 33);
g.addEdge (1, 35);
g.addEdge (1, 36);
g.addEdge (1, 37);
g.addEdge (1, 38);
g.addEdge (1, 40);
g.addEdge (1, 41);
g.addEdge (1, 43);
g.addEdge (1, 46);
g.addEdge (1 ,47);
g.addEdge (1, 49);
g.addEdge (2, 3);
g.addEdge (2, 5);
g.addEdge (2, 6);
g.addEdge (2, 10);
g.addEdge (2, 11);
g.addEdge (2, 15);
g.addEdge (2, 17);
g.addEdge (2, 28);
g.addEdge (2, 29);
g.addEdge (2, 33);
g.addEdge (2, 35);
g.addEdge (2, 36);
g.addEdge (2, 44);
g.addEdge (2, 45);
g.addEdge (3 ,4);
g.addEdge (3, 5);
g.addEdge (3, 7);
g.addEdge (3, 9);
g.addEdge (3, 10);
g.addEdge (3, 12);
g.addEdge (3, 15);
g.addEdge (3, 17);
g.addEdge (3, 20);
g.addEdge (3, 22);
g.addEdge (3, 23);
g.addEdge (3, 24);
g.addEdge (3, 29);
g.addEdge (3, 30);
g.addEdge (3, 35);
g.addEdge (3, 41);
g.addEdge (3, 42);
g.addEdge (3, 49);
g.addEdge (4, 5);
g.addEdge (4, 8);
g.addEdge (4, 11);
g.addEdge (4, 13);
g.addEdge (4, 15);
g.addEdge (4, 17);
g.addEdge (4, 19);
g.addEdge (4, 21);
g.addEdge (4, 23);
g.addEdge (4, 26);
g.addEdge (4, 28);
g.addEdge (4, 33);
g.addEdge (4, 36);
g.addEdge (4, 40);
g.addEdge (4, 41);
g.addEdge (4, 43);
g.addEdge (4, 44);
g.addEdge (4, 45);
g.addEdge (4, 47);
g.addEdge (4, 48);
g.addEdge (5, 6);
g.addEdge (5, 7);
g.addEdge (5, 8);
g.addEdge (5, 9);
g.addEdge (5, 10);
g.addEdge (5, 11);
g.addEdge (5, 12);
g.addEdge (5, 13);
g.addEdge (5, 15);
g.addEdge (5, 16);
g.addEdge (5, 17);
g.addEdge (5, 18);
g.addEdge (5, 19);
g.addEdge (5, 20);
g.addEdge (5, 21);
g.addEdge (5, 22);
g.addEdge (5, 25);
g.addEdge (5, 26);
g.addEdge (5, 27);
g.addEdge (5, 28);
g.addEdge (5, 29);
g.addEdge (5, 30);
g.addEdge (5, 31);
g.addEdge (5, 32);
g.addEdge (5, 34);
g.addEdge (5, 36);
g.addEdge (5, 38);
g.addEdge (5, 39);
g.addEdge (5, 40);
g.addEdge (5, 42);
g.addEdge (5, 44);
g.addEdge (5, 45);
g.addEdge (5, 46);
g.addEdge (5, 47);
g.addEdge (5, 48);
g.addEdge (6, 7);
g.addEdge (6, 11);
g.addEdge (6, 13);
g.addEdge (6, 16);
g.addEdge (6, 17);
g.addEdge (6, 18);
g.addEdge (6, 19);
g.addEdge (6,20);
g.addEdge (6,28);
g.addEdge (6,31);
g.addEdge (6,33);
g.addEdge (6,34);
g.addEdge (6, 35);
g.addEdge (6 ,37);

	g.printVertexCover();

	return 0;
}
