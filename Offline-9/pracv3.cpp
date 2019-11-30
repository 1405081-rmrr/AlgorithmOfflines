#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
#define NULL_VALUE -999999


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
	void addEdge(int u, int v);
	void print(int v);
	int *a;
	int *b;
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
    for(int i=1;i<=nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=1;j<=nVertices;j++)
            matrix[i][j] = 0;
    }
	a=new int[n];
	b=new int[n];
}

void Graph::addEdge(int u, int v)
{
    matrix[u][v]=1;
    matrix[v][u]=1;
}
void Graph :: print(int v)
{
	int c=0;
	int k=1;
	int max;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(matrix[i][j]==1)
			{
				c++;
			}
		}
		a[i]=c;
		c=0;
	}
	for(int i=1;i<=v;i++)
	{
		cout << a[i] <<" ";
	}
	cout <<endl;
}
Graph::~Graph()
{
    nVertices=0;
    nEdges=0;
    delete[] matrix;
    delete a;

}

int main(void)
{
	ifstream file;
	file.open("test1.txt");
	if(!file)
	{
		cout << "Error Opening File"<<endl;
		return -1;
	}
	int v,e,f,t;
	file>>v;
	file>>e;
	Graph g;
	g.setnVertices(v);
	for(int i=0;i<e;i++)
	{
		file>>f;
		file>>t;
		g.addEdge(f,t);
	}
	g.print(v); 

	return 0; 
}


