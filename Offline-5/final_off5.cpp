#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<fstream>
#include<sstream>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3
using namespace std;

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item);
    int dequeue();
    bool empty();
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ;
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ;
		data = tempData ;
	}

	data[front] = item ;
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data;
    data = 0;
}
class Graph
{
	int v,e;
	int ** matrix ;

public:
	Graph();
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v,int w);
	bool bfs(int **mat,int source,int t,int parent[]);
	void dfs(int **rGraph, int s, bool visited[]) ;
    void fordFulkerson(int s, int t,int v);
    int minimum(int x,int y);
};


Graph::Graph()
{
	v= 0 ;
	e = 0 ;
}

void Graph::setnVertices(int n)
{
	this->v = n ;
	     matrix = (int**)malloc(sizeof(int*)*v);
    for(int i =0 ; i <v;i++)
        *(matrix+i) = (int*)malloc(sizeof(int)*v);
         for(int i =0 ; i <v;i++)
            for(int j =0 ; j <v;j++)
                matrix[i][j]=0;

}
void Graph ::  dfs(int **rGraph, int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < v; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
void Graph::addEdge(int u, int v,int w)
{

    matrix[u][v] = w;
}
int Graph:: minimum(int x,int y)
{
    int z=x>y? y:x;
    return z;
}
bool Graph::bfs(int **mat,int source,int t,int parent[] )
{
    Queue q;
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    parent[source]=-1;
    visited[source]=true;
    q.enqueue(source) ;
    while (!q.empty())
	{
		int u = q.dequeue();

		for (int x=0; x<v; x++)
		{
			if (visited[x]==false && mat[u][x] > 0)
			{
				q.enqueue(x);
				parent[x] = u;
				visited[x] = true;
			}
		}
	}
	if (visited[t] == true) return true;
	else return false;
    }
    void Graph :: fordFulkerson(int s, int t,int v)
{
    ofstream output;
    output.open("output.txt");
 	int u;
	int ** rGraph = (int**)malloc(sizeof(int*)*v);
    for(int i =0 ; i <v;i++)
        *(rGraph+i) = (int*)malloc(sizeof(int)*v);
    for(int i =0 ; i <v;i++)
            for(int j =0 ; j <v;j++)
                rGraph[i][j]=matrix[i][j];

	int parent[v];
	int max_flow = 0;
	while (bfs(rGraph, s, t,parent))
	{
		int path_flow = INT_MAX;
		for (int p=t; p!=s; p=parent[p])
		{
			u = parent[p];
			path_flow = minimum(path_flow, rGraph[u][p]);
		}
		for (int p=t; p != s; p=parent[p])
		{
			u = parent[p];
			rGraph[u][p] -= path_flow;
			rGraph[p][u] += path_flow;
		}
		max_flow += path_flow;
	}
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    dfs(rGraph, s, visited);
    for (int i = 0; i < v; i++)
      for (int j = 0; j < v; j++)
         if (visited[i] && !visited[j] && matrix[i][j])
              output << i << " - " << j << "  "<<matrix[i][j]<< endl;
	output<<"The Maximum flow is "<<  max_flow;
	output.close();
}
Graph::~Graph()
{
    v=0;
    e=0;
    delete[] matrix;
}

int main(void)
{
    int v,e;
    int s,t;
    int i;
    ifstream input;
    //ofstream output;
    //output.open("output.txt");
    input.open("geeks.txt");
    Graph g;
     input >>v;
     input >>e;
     input>>s;
     input>>t;
     g.setnVertices(v);

    while(1)
    {
        printf("1. Add edge. \n");
        cout << "2. Ford Fulkerson"<<endl;
        cout <<"3.End "<<endl;
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v,w;
            for(i=0;i<e;i++){
            input >>u;
            input>>v;
            input>>w;
            g.addEdge(u, v,w);
            }
            cout << "Added Successfully" <<endl;
        }
        if(ch==2)
        {

            g.fordFulkerson(s,t,v);
           cout << "Open the Output File" <<endl;
           //output<< "The Maximum Flow is "<<x<<endl;
           //output.close();
        }
        if(ch==3)
        {
            break;
        }

    }

}

