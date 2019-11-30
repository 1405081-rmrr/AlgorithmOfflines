#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct Edge
{
	int src, dest, weight;
};

struct Graph
{

	int V, E;
	struct Edge* edge;
	int *p;
	int *r;
	void kruskal (struct Graph *graph,int e,int v);

};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
    return graph;
}


void Graph :: kruskal(struct Graph *graph,int e,int v)
{
	ofstream outfile;
	outfile.open("output.txt");
	int cost=0;
	int f=0;
	int m,n;
	p=new int [v];
	r=new int[v];
    for(int i=0;i<V;i++)
	{
		p[i]=i;
		r[i]=0;
	}
	for(int i=0;i<e;i++)
	{
		int a=graph->edge[i].src;
		int b=graph->edge[i].dest;
		int c=graph->edge[i].weight;
		if((p[a]==a) && (p[b]==b))
        {
        cost=cost+c;
        outfile << "(" << a << ","<< b << ")" <<endl;
        if(r[a]>r[b])
	{

		p[b]=a;
		r[a]++;

	}
	else if(r[a]<r[b])
	{

		p[a]=b;
		r[b]++;
	}
	else
	{
		p[b]=a;
		r[a]++;
	}
        }
        else if(p[a]==p[b]) continue;
        else
        {
            while(1)
            {
                m=p[a];
                n=p[b];
                if(p[m]==m && p[n]==n)
                {
                    break;
                }


                a=m;
                b=n;
            }
            if(p[m]==p[n]) continue;
       else if(r[m]>r[n])
	{
		p[n]=m;
		r[m]++;
	}
	else if(r[m]<r[n])
	{
		p[m]=n;
		r[n]++;
	}
	else
	{
		p[n]=m;
		r[m]++;
	}
        cost = cost+c;
        outfile << "(" <<  graph->edge[i].src << ","<<graph->edge[i].dest << ")"  <<endl;
        }

	}
    outfile << "MST Weight is "<< " "<<cost;
    cout << "Please open the output file to see output\n";
    outfile.close();


}
int main(void)
{
    int n,c,v,e,p,q,r,k=0;
    ifstream inFile;
    struct Graph* graph;
    while(1)
    {
        printf("1.File Read.\n");
        printf("2. Exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
        //inFile.open("testfile.txt");
       //  inFile.open("input.txt");
          inFile.open("hr.txt");
        //  inFile.open("hr1.txt");
        inFile>>v;
        inFile>>e;
        graph = createGraph(v, e);
   for(int i=0;i<e;i++){
        inFile>>p;
        inFile>>q;
        inFile>>r;


            graph->edge[k].src = p;
        	graph->edge[k].dest = q;
            graph->edge[k].weight = r;
            k++;
   }
        cout <<endl;
        cout << endl;
   for (int i = 0; i < e-1; i++)

       // Last i elements are already in place
       for (int j = 0; j < e-i-1; j++)
           if (graph->edge[j].weight>graph->edge[j+1].weight)
           {
           		int x=graph->edge[j].src;
           		int y=graph->edge[j].dest;
           		int z=graph->edge[j].weight;
           		graph->edge[j].src=graph->edge[j+1].src;
           		graph->edge[j].dest=graph->edge[j+1].dest;
           		graph->edge[j].weight=graph->edge[j+1].weight;
           		graph->edge[j+1].src=x;
           		graph->edge[j+1].dest=y;
				graph->edge[j+1].weight=z;

		   }

        /*for(int i=0;i<e;i++)
        {
        	cout << graph->edge[i].src << " " << graph->edge[i].dest << " " << graph->edge[i].weight;
        	cout <<endl;
		}
		cout << "Successfully Sorted !!! \n";*/
			 graph->kruskal(graph,e,v);

        }


        else if(ch==2)
        {
            break;
        }
    }

}

