 #include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;
class Edge{
public:
    int source;
    int dest;
    int weight;

};
bool compare(Edge e1, Edge e2)
{
    return e1.weight<e2.weight;
}
int findParent(int v, int *parent)
{
    if(parent[v]==v)
    {
        return v;
    }
    return findParent(parent[v],parent);
}
void Kruskals(Edge*input,int n, int E)
{
    sort(input,input+E,compare);
    ofstream outputfile;
    outputfile.open("output.txt");
    int c=0;
    Edge *output= new Edge[n-1];
    int *parent= new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count != n-1)
    {
        Edge currentEdge= input[i];
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent != destParent)
        {
            output[count]=currentEdge;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(output[i].source<output[i].dest)
        {
            outputfile<<output[i].source<<" "<<output[i].dest<<endl;
            c=c+output[i].weight;
        }
        else{
           outputfile<<output[i].dest<<" "<<output[i].source<<endl;
           c=c+output[i].weight;
        }
    }
    outputfile << "Cost is : "<<c;
    cout << "Please open the OUTPUT FILE "<<endl;
    outputfile.close();

}
int main()
{
    int n,E;
    ifstream inputfile;
    inputfile.open("testfile.txt");
   // cin>>n>>E;
   inputfile>>n;
   inputfile>>E;
    Edge*input=new Edge[E];
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        inputfile>>s;
        inputfile>>d;
        inputfile>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    Kruskals(input,n,E);
}
