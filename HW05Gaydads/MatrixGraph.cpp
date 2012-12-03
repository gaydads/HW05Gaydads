#include "MatrixGraph.h"
#include "Graph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes) {

	//std::vector<std::vector<EdgeWeight> >


	num_edges = 0;
	M = std::vector<std::vector<EdgeWeight>>(num_nodes);
	for (int i = 0; i < num_nodes; i++) {
		M[i] = std::vector<EdgeWeight>(num_nodes);
	}
}

MatrixGraph::~MatrixGraph() {
	//Not Needed
}

 /*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	//Duplicates not a problem I think...
	  //Preconditions...
	  if (0 <= u < M.size()   && 0 <= v < M.size() && u!=v && weight >0) {
		 M[u][v] = weight;
		 M[v][u] = weight;
		 num_edges++;
	  }
}

 /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	if (u >= 0 && u < M.size() && v >= 0 && v < M.size()) {
		return M[u][v];	
	}
	else {
		return 0;
	}

}

/*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	//Precondition...
	EList adj_list;

	if (u >= 0 && u < M.size()){
		for(int i=0; i<M[u].size(); i++) {
			if(M[u][i] !=0 ) {
				adj_list.push_back(NWPair(i, M[u][i]));
			}
		}
	}
	return adj_list;
}

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
unsigned MatrixGraph::degree(NodeID u) const {
	if (0 <= u < M.size() ){
		return getAdj(u).size();
	}
	return 0;
}

/*
   * Return the number of nodes in the graph.
   */
unsigned MatrixGraph::size() const {
	return M.size();
}

/* 
   * Return the number of edges in the graph.
   */
unsigned MatrixGraph::numEdges() const {
	return num_edges;
}
