#include "ListGraph.h"
#include <vector>
#include "Graph.h"
#pragma once

typedef std::list<NWPair> EList;


ListGraph::ListGraph(int numNodes) {
	edgeList = std::vector<EList>();
	for (int i = 0; i < numNodes; i++){
		edgeList.push_back(EList(NULL));
	}	
		num_edges = 0;
}
ListGraph::~ListGraph() {
	for(int i = 0; i < edgeList.size(); i++){
		  edgeList.pop_back();
	}
}

  // Modifiers

/*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
  void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	  bool duplicate = false;
	  //Preconditions...
	  if (0 <= u < edgeList.size() && 0 <= v < edgeList.size() && u!=v) {
		  //Iterate edgeList
		  for(std::list<NWPair>::const_iterator i = edgeList.at(u).begin(); i != edgeList.at(u).end(); i++){
			  if(i->first == v && i->second == weight){
				duplicate = true;
			  }
		  }
		  //If there is no duplicate, add weighted edge
		  if (!duplicate) {
			edgeList.at(u).push_back(NWPair(v,weight));
			edgeList.at(v).push_back(NWPair(u,weight));
			num_edges++;
		}
	  }
  }
  
  // Inspectors
  /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	  if (0 <= u < edgeList.size() && 0 <= v < edgeList.size()) {
		for( std::list<NWPair>::const_iterator i = edgeList.at(u).begin(); i != edgeList.at(u).end(); i++) {
			if (i->first == v) {
				return i->second;
			}
		}
	  }
	  return 0;
  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	  if (0 <= u < edgeList.size()) {
		  return edgeList.at(u);
	  }
  }
  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned ListGraph::degree(NodeID u) const {
	  if (0 <= u < edgeList.size()) {
		  return getAdj(u).size();
	  }
	  return 0;
  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned ListGraph::size() const {
	  return edgeList.size();
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned ListGraph::numEdges() const {
	  return num_edges;
  }
