#include "GraphAlgs.h"

//
#include <iostream>
//
#pragma once

using namespace std;
/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */

std::pair<std::vector<NodeID>, EdgeWeight> GraphAlgs::TSP(Graph* G) {

	//std::vector<NodeID>(G.size()) nodes;
	//EList tour;
	
	/*
	//OK I GOT THIS TO WORK WITH...
  virtual EdgeWeight weight(NodeID u, NodeID v) const;
  virtual std::list<NWPair> getAdj(NodeID u) const;
  virtual unsigned degree(NodeID u) const;
  virtual unsigned size() const;
  virtual unsigned numEdges() const;
	*/

	std::pair<std::vector<NodeID>, EdgeWeight> ret;
	std::list<std::list<NWPair>> nodes;
	for(int i=0; i<G->size(); i++) {
		nodes.push_back(G->getAdj(i));
	}
	cout <<G->size()<<endl;
	cout <<nodes.size()<<endl;

	////AHHHHHHHHHH!!!! I can't think
	double tourLength = 0;
	for(int i=0; i<nodes.size; i++) {
		ret->first.push_back(nodes[i]);
		nodes[i]
		
	}


	//create vector of all pairs...? i don't know....
	/*for(int i=0; i<G.size(); i++) {
		for(int j=0; j<G->NodeID.getAdj().size(); j++) {
		nodes.push_back(G.getAdj(i));
		}
	}
	*/

	return ret;
}
void GraphAlgs::tour(std::vector<NodeID> nodes, int n, int starting_place) {
	if(n-starting_place == 1) {
		for(int i=0; i<nodes.size(); i++) {
			////
		}
	}

}

/*
matrix
	std::vector<std::vector<EdgeWeight> > M;
	int num_edges;

list
	std::vector<EList> edgeList;
	int num_edges;

Graph
	typedef unsigned NodeID;
	typedef double EdgeWeight;
	typedef std::pair<NodeID, EdgeWeight> NWPair;

*/

