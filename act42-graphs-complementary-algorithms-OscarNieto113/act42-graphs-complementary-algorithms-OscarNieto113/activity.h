#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author: Oscar Eduardo Nieto Espitia
// Date: 12 / 11 / 2021
// =========================================================

#include "ugraph.h"

// =================================================================
// Performs Deph First Search for topologicalSort.
//
// @param v, a Vertex.
// @param graph, a graph.
// @param reached, a set that saves the vertex that has in common.
// @param TS, an stack that saves the topologicalSort.
// =================================================================
template <class Vertex>
void dfs2(Vertex v, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, std::stack<Vertex> &TS) {

  typename std::set<Vertex>::iterator itr;

  reached.insert(v);

  std::set<Vertex> connected = graph->getConnectionFrom(v);
  for (itr = connected.begin(); itr != connected.end(); itr++){
    if (reached.find(*itr) == reached.end()){
      dfs2(*itr, graph, reached, TS);
    }
  }
  TS.push(v);
}
//O (N + M)

// =================================================================
// Performs topologicalSort.
//
// @param graph, a graph.
// @return aux, gives the arrengement for topologicalSort
// =================================================================
template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex>* graph) {

  std::stringstream aux;//Si
  std::vector<Vertex> itr;//Si

  std::set<Vertex> reached;
	std::stack<Vertex> TS;

  itr = graph->getVertexes();

  for (int i = itr.front() ; i != itr.back(); i++){
    if (reached.find(i) == reached.end()){
      dfs2(i, graph, reached, TS);
    }
  }

  aux << "[";
  while (TS.empty()==false) {
    aux << TS.top() << " ";
    TS.pop();
  }
  aux.seekp(-1,aux.cur); aux << ']';

  return aux.str();
}
//O (N + M)

// =================================================================
// Checks if the graph is a Bipartite.
//
// @param graph, a graph.
//
// @return bool
// =================================================================
template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex>* graph) {
  typename std::vector<Vertex>::iterator itr;
  typename std::set<Vertex>::iterator j;

  typename std::set<Vertex> reached;
  std::queue<Vertex> Q;

  typename std::vector<Vertex> vertexes = graph -> getVertexes();
  int n = vertexes.size();
  Vertex start = vertexes[0];
  int Color[n];
  bool Bipartite = true;

  if(isCyclic(start, graph, reached, -1)){
    return false;
  }

  for(int i = 0; i < n; i++ ){
    Color[i] = -1;
  }

  Color[start] = 1;
  Q.push(start);
  while(!Q.empty()){
    Vertex u = Q.front();
    Q.pop();
    std::set<Vertex> connections = graph -> getConnectionFrom(u);
    for(int i = 0; i < n; ++i ){
      bool edgeExist = std::binary_search(connections.begin(), connections.end(), Color[i]);
      if (edgeExist && Color[i] == -1){
        Color[i] = 1 - Color[u];
        Q.push(Color[i]);
      }
      else if (edgeExist && Color[i] == Color[u]){
          Bipartite = false;
      }

    }
  }
  return Bipartite;
}
//O (N^2)

// =================================================================
// Checks if the graph is Cyclic.
//
// @param v, a Vertex.
// @param graph, a graph.
// @param reached, a set that saves the vertex that has in common.
// @param TS, an stack that saves the topologicalSort.
//
// @return bool
// =================================================================
template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex>* graph,
  std::set<Vertex> &reached, Vertex parent) {

  std::stack<Vertex> explored;
  typename std::set<Vertex>::iterator itr;

  explored.push(v);
  Vertex j = explored.top();
  explored.pop();
  reached.insert(j);
  std::set<Vertex> connected = graph->getConnectionFrom(j);

  for (itr = connected.begin(); itr != connected.end(); itr++) {
    if (reached.find(*itr) == reached.end()){
      if (isCyclic(*itr, graph, reached, parent)){
        return true;
      }
    }
    else{
      if (*itr > parent){
        return true;
      }
    }
  }
  return false;
}
//O (N + M)

// =================================================================
// Checks if the graph is a tree.
//
// @param graph, a graph.
//
// @return bool
// =================================================================
template <class Vertex>
bool isTree(const UnweightedGraph<Vertex>* graph) {

  typename std::vector<Vertex> itr;

  std::set<Vertex> reached;

  itr = graph -> getVertexes();
  Vertex start = itr.front();

  if (isCyclic(start, graph, reached, -1)){
    return false;
  }
  for (int j = itr.front(); j != itr.back(); j++){
    if (reached.find(j) == reached.end()){
      return false;
    }
  }
  return true;
}
//O (N + M)

#endif /* ACTIVITY_H */
