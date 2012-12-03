#include "GraphAlgs.h"
#include <fstream>
#include <iostream>

using namespace std;

std::vector<NodeID> bestTour2;
int* bestTour;
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

	//bestTourChecked = false;
	//int size2 = G->size();
	//std::vector<NodeID>bestTour2 (size2);
	int size = G->size();
	bestTour = new int[size];
	for(int i=0; i<size; i++) {
		bestTour[i] = i;
		bestTour2.push_back(i);
	}


	cout<<bestTour[0]<<endl;
	bestTour[0] =1;
	cout<<bestTour[0]<<endl;

	bestTourLength = length(bestTour, G);
	cout<<"BEFORE"<<endl;
	cout<<bestTourLength<<endl;
	for(int i =0; i<size; i++) {
	cout<<bestTour[i];
	}

	//bestTourChecked = true;
	tour(bestTour, size, 0, G);

	for(int j=0; j<size; j++) {
				cout << bestTour[j];
				if(j==size-1) {
					cout<<"AFTER TOURED"<<endl;
				}
				}
	//bestTourLength = length(bestTour, G);
	std::vector<NodeID> nodes (size);
	for(int i =0; i<size; i++) {
		nodes[i] = bestTour[i];
	}
	//bestTourLength = length(bestTour,G);
	
	std::pair<std::vector<NodeID>,EdgeWeight> ret (bestTour2,bestTourLength);
	cout<<"AFTER"<<endl;
	cout<<bestTourLength<<endl;
	for(int i =0; i<size; i++) {
	cout<<bestTour[i];
	}
	return ret;
}

void tour(int* arr, int n, int startingPlace, Graph* G) {
	//int* arrTour= new int[n];
	if((n - startingPlace) == 1) {
		/* Sum up the length of the permutation
		and see if it is smaller than the best seen
		*/
	double len1 = length(arr,G);
	double len2 = length(bestTour,G);
		if(length(arr,G) < bestTourLength) {
			bestTourLength = length(arr,G);
			//bestTour = arr;
			int size = G->size();
			for(int i=0; i<size; i++) {
				bestTour[i] =  arr[i];
				bestTour2[i] = arr[i];
				//bestTour2[i] = bestTour[i];
				//bestTour = arr;
			}
			//cout<<"change"<<endl;
				for(int j=0; j<n; j++) {
				cout << bestTour[j];
				if(j==n-1) {
					cout<<"CHANGE"<<bestTourLength<<endl;
				}
				}

			}
		}

	else {
		for(int i=startingPlace; i<n; i++) {
			swap(arr,startingPlace, i);


			for(int j=0; j<n; j++) {
				cout << bestTour[j];
				if(j==n-1) {
					cout<<endl;
				}
				}
/*
			for(int j=0; j<n; j++) {
				cout << bestTour[j];
				if(j==n-1) {
					cout<<endl;
				}
				}*/
				

			tour(arr,n,startingPlace+1, G);
			swap(arr,startingPlace, i);
		}
	}
	//cout<<"BEST:"<<bestTourLength<<endl;
}


EdgeWeight length(int* tour, Graph* G)
{
	int size = G->size();
	EdgeWeight length = 0;
	for (int i=0; i<size-1; i++) {
		//if(length>bestTourLength && bestTourChecked == true) {
			//return length;
		//}
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