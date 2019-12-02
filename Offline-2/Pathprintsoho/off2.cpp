#include <bits/stdc++.h>
#include<stdio.h>
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
};


struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 0; i < V-1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}


    ofstream outputFile;
    int count=0;
    outputFile.open("output.txt");
    outputFile << "Vertex   Distance from Source\n";
      for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])

            count++;
    }

     if(count>0)
     {
         cout << "Negative Cycle exists!!!\n";
     }
     else
     {
          for (int i = 0; i < V; i++){
    outputFile<<i<<' '<<' '<<' '<<"\t"<<dist[i]<<endl;
   }
     }
   cout<<"SUCCESSFUL!!!"<<endl;
    outputFile.close();
	//return;
}

// Driver program to test above functions
int main(void)
{
    int n;
    int s[50];
    struct Graph* graph;
    /*int v,e;
    cin>>v;
    cin>>e;
    graph = createGraph(v,e);*/
    while(1)
    {
        printf("1.File Read. \n");
        printf("2.Bellman  3. Exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
               ifstream file("testfile.txt");
               //  ifstream file("testfile.txt");
                  ///ifstream file("test.txt");
                /// ifstream file("bellman1.txt");
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
        //int ver=s[0];
        int k=0;
        graph = createGraph(s[0], s[1]);
        //g.setnVertices(ver);
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
                 //struct Graph* graph = createGraph(s[0], s[1]);

                //g.addEdge(p,q,r);
                graph->edge[k].src = p;
                graph->edge[k].dest = q;
                graph->edge[k].weight = r;
                k++;
            }
        }
  cout<<"File Read Completed!!!"<<endl;
        }
        if(ch==2)
        {

            BellmanFord(graph,s[2]);
        }
        else if(ch==3)
        {
            break;
        }
    }

}

