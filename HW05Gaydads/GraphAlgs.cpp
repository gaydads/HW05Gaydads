#include "GraphAlgs.h"

int* bestTour;
double bestTourLength;
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
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	bestTour = new int [G->size()];
	for(int i=0; i<G->size(); i++) {
		bestTour[i] = i;
	}

	bestTourLength = length(bestTour, G);

	tour(bestTour, G->size(), 0, G);
	std::vector<NodeID> nodes (G->size());
	for(int i =0; i<G->size(); i++) {
		nodes[i] = bestTour[i];
	}
	std::pair<std::vector<NodeID>,EdgeWeight> ret (nodes,bestTourLength);
	return ret;
}

void tour(int* arr, int n, int startingPlace, Graph* G)
{
	if(G->size() - startingPlace == 1) {
		/* Sum up the length of the permutation
		and see if it is smaller than the best seen
		*/
		if(length(arr,G) < length(bestTour,G)) {
			bestTour = arr;
		}
	}
	else {
		for(int i=startingPlace; i<n; i++) {
			swap(arr,arr[startingPlace],arr[i]);
			tour(arr,n,startingPlace+1,G);
			swap(arr,arr[startingPlace],arr[i]);
		}
	}
}


EdgeWeight length(int* tour, Graph* G)
{
	EdgeWeight length = 0;
	for (int i=0; i<G->size()-1; i++) {
		length+= G->weight(tour[i], tour[i+1]);
	}
	length += G->weight(tour[G->size()-1], tour[0]);
	return length;
}

void swap(int* arr, int place1, int place2)
{
	int dummy = arr[place1];
	arr[place1] = arr[place2];
	arr[place2] = dummy;
}