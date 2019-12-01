
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>
#include <sstream>
#define NULL_VALUE -999999
#define INFINITY 999999

using namespace std;

class Graph
{
	int nVertices, nEdges ;
	//int w;
	bool directed ;
	//int ** matrix ;

public:
	Graph(bool dir = false);
	~Graph();
	int ** matrix ;
	void setnVertices(int n);
	void addEdge(int u, int v,int w);
    int printSolution(int dist[], int n);
    void printGraph();
    int minDistance(int dist[], bool sptSet[]);
    void dijkstra( int src);

};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ;

}
void Graph::setnVertices(int n)
{
	this->nVertices = n ;

    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0;
    }

}
int Graph::minDistance(int dist[],bool sptSet[])
{
    {
   int min = INT_MAX, min_index;

   for (int v = 0; v < nVertices; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
}

void Graph::addEdge(int u, int v,int w)
{

    //matrix[u][v] = 1;
   // nEdges++;
    //int w;
    //cout<<"Enter weight : "<<endl;
    //cin>>w;
    matrix[u][v]=w;
    matrix[v][u]=w;
}
int Graph:: printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < nVertices; i++)
      printf("%d  %\t\t %d\n", i, dist[i]);
}

void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}
void Graph::dijkstra(int src)
   {

   int dist[nVertices];


     bool sptSet[nVertices];
     for (int i = 0; i < nVertices; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < nVertices-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < nVertices; v++)
         if (!sptSet[v] && matrix[u][v]!=0 && dist[u] != INT_MAX
                                       && dist[u]+matrix[u][v] < dist[v])
            dist[v] = dist[u] + matrix[u][v];
     }
     printSolution(dist, nVertices);
}


Graph::~Graph()
{
    nVertices=0;
    nEdges=0;
    delete[] matrix;

}

int main(void)
{
    int n;
    //int i=0;
    int s[50];
    Graph g;
   /* ifstream file("testfile.txt");
    if(!file) //Always test the file open.
    {
                cout<<"Error opening output file"<<endl;
               // system("pause");
                return -1;
    }*/
    //printf("Enter number of vertices: ");
    //scanf("%d", &n);
    //g.setnVertices(n);

    while(1)
    {
        printf("1.File Read. \n");
        printf("2.Dijkstra  3. Exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
                ifstream file("test1file.txt");
    if(!file) //Always test the file open.
    {
                cout<<"Error opening output file"<<endl;
               // system("pause");
                return -1;
    }
            int u, v,x,p,q,r;
            string line;
            while(getline(file, line))
    {

        stringstream  lineStream(line);

        int value,i=0;
        // Read an integer at a time from the line
        while(lineStream >> value)
        {
            // Add the integers from a line to a 1D array (vector)
                 s[i]=value;
                 //i++;
                 //cout<<s[i]<<" ";
                 i++;

        }
        n=i;
        cout<<"File Read Completed!!!";

        cout<<endl;
        cout<<endl;
        //cout<<i<<endl;
    }
        int ver=s[0];
        g.setnVertices(ver);
        for(int i=1;i<n;i++)
        {
            if(i%3==1)
            {
                 p=s[i];
                continue;
            }
            if(i%3==2)
            {
                 q=s[i];
                continue;
            }
            if(i%3==0)
            {
                 r=s[i];
                g.addEdge(p,q,r);
            }
        }

        }
        if(ch==2)
        {
            g.dijkstra(0);
        }
        else if(ch==3)
        {
            break;
        }
    }

}
