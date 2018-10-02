#include"hGraph.h"
#include"hQueue.h"
Graph :: Graph()
{

}

Graph :: Graph(int nVert,int nEdge)
{
 Vertex=nVert;
 Edges=nEdge;
 AdjMatrix = new int*[nVert];
 AdjRelation = new string*[nVert];
 for(int i=0;i<nVert;i++)
 {
  AdjMatrix[i]= new int[nVert];
  AdjRelation[i]= new string[nVert];
 }
 for(int i=0;i<nVert;i++)
  for(int j=0;j<nVert;j++)
  {
   AdjMatrix[i][j]=0;
   AdjRelation[i][j]=" ";
  }
}

Graph :: ~Graph()
{
 for(int i=0;i<Vertex;i++)
  {
   delete []AdjMatrix[i];
   delete []AdjRelation[i];
  }
 delete []AdjMatrix;
 delete []AdjRelation;
}

int Graph :: createEdge(int Vertex1,int Vertex2)
{
 if(AdjMatrix[Vertex1][Vertex2]==0)
  AdjMatrix[Vertex1][Vertex2]=1;
 else
  return 0;
 return 1;
}

int Graph :: createRelation(int Vert1,int Vert2,string relet)
{
 if(AdjRelation[Vert1][Vert2]==" ")
  AdjRelation[Vert1][Vert2]= relet;
 else
  return 0;
 return 1;
}

int Graph :: visitVertex(int vert,void(*fpointer)(int,int,string))
{
    int nFlag=0;
    bool *Visited = new bool[Vertex];
    for(int i=0;i<Vertex;i++)
        Visited[i]=false;
    Visited[vert]=true;
    CQueue q;
    q.Enqueue(vert);
    while(!q.isEmpty())
    {
        vert = q.ReturnFront();
        q.Dequeue();
        for(int w=0;(w<Vertex);w++)
        {
            if(AdjMatrix[vert][w]&&!Visited[w])
            {
                nFlag=1;
                fpointer(vert,w,AdjRelation[vert][w]);
                q.Enqueue(w);
                Visited[w]=true;
            }
        }

    }
    delete []Visited;
    return nFlag;
}
/*void Graph :: Display()
{
    for(int i=0;i<Vertex;i++)
    {
        for(int j=0;j<Vertex;j++)
        {
            cout<<AdjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<Vertex;i++ )
    {
        for(int j=0;j<Vertex;j++)
        {
            cout<<AdjRelation[i][j]<<" ";
        }
        cout<<endl;
    }
}*/






