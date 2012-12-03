#include "GraphAlgs.h"
#include <fstream>
#include <iostream>

using namespace std;
int* bestTour;
std::vector<NodeID> bestTour2;
double bestTourLength;
bool bestTourChecked;
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
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {

	int size = G->size();
	bestTour = new int[size];
	for(int i=0; i<size; i++) {
		bestTour[i] = i;
		bestTour2.push_back(i);
	}

	bestTourLength = length(bestTour, G);
	bestTourChecked = true;
	//Should start from space 1 to save time...
	//012 same length as 120 and 201...
	//no need to permutate the first node, keep starting node the same?
	tour(bestTour, size, 1, G);

	std::pair<std::vector<NodeID>,EdgeWeight> ret (bestTour2,bestTourLength);
	return ret;
}


//Tour function adapted from class lecture
void tour(int* arr, int n, int startingPlace, Graph* G) {
	if((n - startingPlace) == 1) {
		/* Sum up the length of the permutation
		and see if it is smaller than the best seen
		*/
		if (length(arr,G) == bestTourLength) {
			cout<<"same!"<<endl;
		}
		if(length(arr,G) < bestTourLength) {
			bestTourLength = length(arr,G);
			
			int size = G->size();
			for(int i=0; i<size; i++) {
				bestTour2[i] = arr[i];
			}
		}
	}

	else {
		for(int i=startingPlace; i<n; i++) {
			
			swap(arr,startingPlace, i);
			for(int j=0; j<n; j++) {
				cout<<arr[j];
				if(j == n-1) {
					cout<<endl;
				}
			}
			tour(arr,n,startingPlace+1, G);
			swap(arr,startingPlace, i);
		}
	}
}


EdgeWeight length(int* tour, Graph* G)
{
	int size = G->size();
	EdgeWeight length = 0;
	for (int i=0; i<size-1; i++) {
		//If the tour is too long already, stop
		if(length >bestTourLength && bestTourChecked == true) {
			return length;
		}
		length+= G->weight(tour[i], tour[i+1]);
	}
	length += G->weight(tour[size-1], tour[0]);
	return length;
}

void swap(int* arr, int place1, int place2)
{
	int dummy = arr[place1];
	arr[place1] = arr[place2];
	arr[place2] = dummy;
}