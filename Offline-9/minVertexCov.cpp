#include<bits/stdc++.h>
#define SIZE  10000
#define ESIZE 100000
using namespace std;

int Graph[SIZE][SIZE];
int deg[SIZE];

class Edge
{
public:
    int u;
    int v;
    int key;//key=deg[u]+deg[v];
};

//--------------------------

class MyPriorityQueue
{
    int qSize;
    int qCapacity;
    Edge *qItem;
public:
    MyPriorityQueue()
    {
        qSize=0;
        qCapacity=ESIZE;
        qItem=new Edge[qCapacity];
    }
    MyPriorityQueue(vector<Edge> arr,int n)
    {
        qSize=n;
        qCapacity=ESIZE;
        qItem=new Edge[qCapacity];
        for(int i=0; i<n; i++)
            qItem[i]=arr[i];
        for(int i=n/2; i>=0; i--)
            heepify(i);
    }

    void heepify(int i)
    {
        int large=i;
        int left=LeftChild(i);
        int right=RightChild(i);
        if(left<qSize && qItem[left].key>qItem[large].key )
            large=left;
        if(right<qSize && qItem[right].key>qItem[large].key)
            large=right;
        if(large != i)
        {
            Edge temp=qItem[i];
            qItem[i]=qItem[large];
            qItem[large]=temp;
            heepify(large);
        }
    }
    void shiftdown(int i)
    {
        heepify(i);
    }
    void shiftUp(int i)
    {
        while(i>0 && qItem[Parent(i)].key<qItem[i].key)
        {
            Edge temp=qItem[Parent(i)];
            qItem[Parent(i)]=qItem[i];
            qItem[i]=temp;
            i=Parent(i);
        }
    }
    void insertLast(Edge n)
    {
        qSize++;
        qItem[qSize-1]=n;
        shiftUp(qSize-1);

    }
    Edge extractMax()
    {
        Edge n=qItem[0];
        qItem[0]=qItem[qSize-1];
        qSize--;
        heepify(0);
        return n;

    }
    void decreaseKey(int u,int v,int newVal)
    {
        for(int i=0; i<qSize; i++)
        {
            if(u==qItem[i].u && v==qItem[i].v)
            {
                qItem[i].key=newVal;
                shiftdown(i);
                break;
            }
        }
    }
    bool isEmpty()
    {
        if(qSize==0)
            return true;
        return false;
    }


    int Parent(int i)
    {
        return i-1/2;
    }
    int LeftChild(int i)
    {
        return 2*i+1;
    }

    int RightChild(int i)
    {
        return 2*i+2;
    }
    void printHeapItem()
    {
        for(int i=0; i<qSize; i++)
            cout<<qItem[i].key<<"("<<qItem[i].u<<" , "<<qItem[i].v<<")"<<endl;
        cout<<endl;
    }
    int getSize() { return qSize;}


};
//---------------------------------------------
























void minVertexCover1(vector<Edge> &edge,int n,int ne)
{

    srand(unsigned(time(0)));
    vector< vector<int> > cGraph(n, vector<int>(n));
    queue<Edge> edges;
    queue<int> verCover;
    Edge e;
    int count=0;
    random_shuffle(edge.begin(),edge.end());
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cGraph[i][j]=Graph[i][j];
    for(int i=0; i<ne; i++)
        edges.push(edge[i]);



    while(!edges.empty())
    {
        e = edges.front();
        edges.pop();
        if(cGraph[e.u][e.v]==1)
        {
            count++;
            count++;
            //cout<<e.u<<" "<<e.v<<endl;
            verCover.push(e.u);
            verCover.push(e.v);
            cGraph[e.u][e.v]=0;
            cGraph[e.v][e.u]=0;
            for(int i=0; i<n; i++)
            {
                cGraph[e.u][i]=0;
                cGraph[e.v][i]=0;
                cGraph[i][e.u]=0;
                cGraph[i][e.v]=0;
            }
        }
        // cout<<edges.size()<<endl;


    }
    cout<<"Vertex Cover on algo 1 : "<<count<<endl;

    /*  while(!verCover.empty())
      {
          cout<<verCover.front()+1<<" ";
          verCover.pop();
      }

    */

}



void minimumVertexCover2(vector<Edge> &edge,int n,int ne)
{
    vector< vector<int> > cGraph(n, vector<int>(n));
    // cout<<"problem"<<endl;
    MyPriorityQueue edges(edge,ne);
    queue<int> verCover;
    Edge e;
    int count=0;
    int degree[SIZE];
    //random_shuffle(edge.begin(),edge.end());
    for(int i=0; i<n; i++)
    {
        degree[i]=deg[i];
        for(int j=0; j<n; j++)
        {
            cGraph[i][j]=Graph[i][j];

        }
    }
   // cout<<"problem"<<endl;


    // for(int i=0;i<ne;i++) edges.push(edge[i]);

    while(!edges.isEmpty())
    {
        e = edges.extractMax();

        if(cGraph[e.u][e.v]==1)
        {
            count++;
            count++;
            //cout<<e.u<<" "<<e.v<<endl;
            verCover.push(e.u);
            verCover.push(e.v);
            cGraph[e.u][e.v]=0;
            cGraph[e.v][e.u]=0;
            degree[e.u]--;
            degree[e.v]--;

            for(int i=0; i<n; i++)
            {

                if(cGraph[e.u][i]==1)
                {
                    cGraph[e.u][i]=0;
                    cGraph[i][e.u]=0;
                    degree[e.u]--;
                    degree[i]--;
                    for(int j=0; j<n; j++)
                    {
                        if(cGraph[i][j]==1) edges.decreaseKey(i,j,degree[i]+degree[j]);
                    }
                }
                if(cGraph[e.v][i]==1)
                {
                    cGraph[e.v][i]=0;
                    cGraph[i][e.v]=0;
                    degree[e.v]--;
                    degree[i]--;
                    for(int j=0;j<n;j++)
                    {
                        if(cGraph[i][j]==1) edges.decreaseKey(i,j,degree[i]+degree[j]);
                    }
                }


            }

        }
      //  edges.printHeapItem();

    }
    cout<<"Vertex Cover on algo2 : "<<count<<endl;


}









int main()
{



    int numVertex,numEdge;
    cin>>numVertex>>numEdge;
    int u,v;

    vector<Edge> edge;
    // cout<<numVertex;

    for(int i=0; i<numVertex; i++)
    {
        deg[i]=0;
        for(int j=0; j<numVertex; j++)
            Graph[i][j]=0;
    }


    Edge e;

    for(int i=0; i<numEdge; i++)
    {
        // cout<<i<<endl;
        cin>>u>>v;
        Graph[u-1][v-1]=1;
        e.u=u-1;
        e.v=v-1;
        deg[u-1]++;
        deg[v-1]++;
        edge.push_back(e);

    }

    for(int i=0; i<numEdge; i++)
        edge[i].key=deg[edge[i].u]+deg[edge[i].v];
    minVertexCover1(edge,numVertex,numEdge);
    minimumVertexCover2(edge,numVertex,numEdge);

}
