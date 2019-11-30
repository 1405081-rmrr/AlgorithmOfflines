#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define NULL_VALUE -999999
#define INFINITY 999999

using namespace std;

class Graph
{
	int nVertices, nEdges ;
	bool directed ;

public:
	Graph(bool dir = false);
	~Graph();
	int ** matrix ;
	void setnVertices(int n);
	void addEdge(int u, int v,int w);
	void writeToFile( int x[]);
    int printSolution(int dist[], int n);
    void printGraph();
    void printPath(int parent[], int j) ;
    //int minDistance(int dist[], bool sptSet[]);
    void bellman( int src,int edge);


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

void Graph::addEdge(int u, int v,int w)
{
    matrix[u][v]=w;
    //matrix[v][u]=w;
}
void Graph::printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return  ;

    printPath(parent, parent[j]);
    printf(" %d ", j);
    //cout<<"The paths are : "<<endl;
    //cout << j ;
}
void Graph::bellman(int src,int edge)
   {

    int parent[nVertices],p;
   int dist[nVertices];
     for (int i = 0; i < nVertices; i++){
        dist[i] = INT_MAX;
        parent[src]=-1;

     }
     dist[src] = 0;
     for(int s=0;s<edge;s++){
       //int u = minDistance(dist, sptSet);
       //sptSet[u] = trues
       for(int x=0;x<nVertices;x++){
       for (int v = 0; v < nVertices; v++){
         if (matrix[x][v]!=0 && dist[x] != INT_MAX && dist[x]+matrix[x][v] < dist[v]){
            dist[v] = dist[x] + matrix[x][v];
            parent[v] = x;
         }
       }
       }
     }
    ofstream outputFile;
    int count=0;
    outputFile.open("output.txt");
    outputFile << "Vertex   Distance from Source\n";
  /* for (int i = 0; i < nVertices; i++){
    outputFile<<i<<' '<<' '<<' '<<"\t"<<dist[i]<<endl;
    printPath(parent,i);
   cout<<endl;
   cout<<"Source -> ";
   }*/
     for(int s=0;s<edge;s++){
       for(int x=0;x<nVertices;x++){
       for (int v = 0; v < nVertices; v++){
         if (matrix[x][v]!=0 && dist[x] != INT_MAX && dist[x]+matrix[x][v] < dist[v])
            {//dist[v] = dist[x] + matrix[x][v];
             //cout << "Negative Cycle exists!!!\n";
             count++;

       }
       }

     }
     }
     if(count>0)
     {
         cout << "Negative Cycle exists!!!\n";
     }
     else
     {
            for (int i = 0; i < nVertices; i++){
    outputFile<<i<<' '<<' '<<' '<<"\t"<<dist[i]<<endl;

   printPath(parent,i);
   cout<<endl;
   cout<<"Source -> ";
   //cout<<p;

   }
     }
     cout<<endl;
   cout<<"SUCCESSFUL!!!"<<endl;
    outputFile.close();


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
    int s[50];
    Graph g;


    while(1)
    {
        printf("1.File Read. \n");
        printf("2.Bellman  3. Exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
                ifstream file("testfile.txt");
    if(!file)
    {
                cout<<"Error opening output file"<<endl;

                return -1;
    }
            int u, v,x,p,q,r;
            string line;
            while(getline(file, line))
    {

        stringstream  lineStream(line);

        int value,i=0;

        while(lineStream >> value)
        {

                 s[i]=value;

                 i++;

        }
        n=i;


        cout<<endl;
        cout<<endl;

    }
        int ver=s[0];
        g.setnVertices(ver);
        for(int i=2;i<n;i++)
        {
            if(i%3==2)
            {
                 p=s[i];
                continue;
            }
            if(i%3==0)
            {
                 q=s[i];
                continue;
            }
            if(i%3==1)
            {
                 r=s[i];
                g.addEdge(p,q,r);
            }
        }
  cout<<"File Read Completed!!!"<<endl;
        }
        if(ch==2)
        {
            g.bellman(s[2],s[1]);
        }
        else if(ch==3)
        {
            break;
        }
    }

}


