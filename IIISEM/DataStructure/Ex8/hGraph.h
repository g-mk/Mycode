#include<iostream>
using namespace std;

class Graph
{
 public:
  Graph();
  Graph(int,int);
  ~Graph();
  int createEdge(int ,int);
  int createRelation(int,int,string);
  int visitVertex(int , void(*fpointer)(int,int,string));
  //void Display();
 private:

  int **AdjMatrix;
  string **AdjRelation;
  int Vertex;
  int Edges;
};

