#include "MatrixGraph.h"
#include "Graph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	num_edges = 0;
	M = std::vector<std::vector<EdgeWeight> >(num_nodes);
	for (int i = 0; i < num_nodes; i++){
		M[i] = std::vector<EdgeWeight>(num_nodes);
		for (int j = 0; j < num_nodes; j++){
			M[i][j] = 0;
		}
	}
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	EdgeWeight x = 0;
	return 0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{
	std::list<NWPair> adj;
	return adj;
}

unsigned MatrixGraph::degree(NodeID u) const{
	return 0;
}

unsigned MatrixGraph::size() const
{
	return 0;
}

unsigned MatrixGraph::numEdges() const
{
	return 0;
}
