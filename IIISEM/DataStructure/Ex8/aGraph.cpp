#include"hGraph.h"
void visit(int vert1,int vert2,string relation)
{
    cout<<vert1+1<<" -> "<<vert2+1<<" Relation is: "<<relation<<endl;
}

int main()
{
    int nVertex,nEdges;
    int nVert1,nVert2;
    int nStatusE,nStatusR;
    string sRelation;
    cout<<"\nEnter the No.of Vertex: ";
    cin>>nVertex;
    cout<<"\nEnter the No. of Edges: ";
    cin>>nEdges;
    Graph g(nVertex,nEdges);
    cout<<"\nEnter the Vertex No. who has the Edge:\n";
    for(int i=0;i<nEdges;i++)
    {
        cout<<"\nEnter the Two Vertex which has the Edge between them: \n";
        cout<<"\nVertex 1:";
        cin>>nVert1;
        cout<<"\nVertex 2:";
        cin>>nVert2;
        cout<<"\nEnter the Relation Between Them:";
        cin>>sRelation;
        nStatusE=g.createEdge(nVert1-1,nVert2-1);
        nStatusR=g.createRelation(nVert1-1,nVert2-1,sRelation);
        if(nStatusE&&nStatusR)
            cout<<"\nEdge has been Created between Vertex "<<nVert1<<" and Vertex "<<nVert2<<".\n";
        else
        {
            i--;
            cout<<"\nAlready there is an Edge.\n\n";
        }
    }
    //g.Display();
    while(nStatusE!=0)
    {
        cout<<"\nEnter the Stating Vertex:";
        cin>>nVertex;
        nStatusR=g.visitVertex(nVertex-1,visit);
        if(nStatusR==0)
            cout<<"\n No Adjacent Vertex for the given Vertex \n";
        cout<<"\nPress 1 to Continue BFT with Some other Vertex: ";
        cin>>nStatusE;
    }
    cout<<"\n\nThank You\n\n";
}
