/*
 * Dijkstra.cpp
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#include "Graph.h"
#include "ShortestPath.h"

using namespace dijkstra;

// Calculation based on HW2 description
static double average_path_calculation(const Graph& g)
{
	double avg_path = 0.0;
	ShortestPath sp(g);

	for(unsigned i = 0; i < g.V(); ++i)
	{
		avg_path += static_cast<double>(sp.path_size(0, i)) / g.V();
	}

	return avg_path;
}

// Calculation based on https://en.wikipedia.org/wiki/Average_path_length
static double average_shortest_path(const Graph& g)
{{
	double avg_path = 0.0;
	ShortestPath sp(g);

	for(unsigned i = 0; i < g.V(); ++i)
	{
		for (unsigned j = 0; j < g.V()-1; ++j)
		{
			if(i != j)
			{
				avg_path += static_cast<double>(sp.path_size(i, j));
			}
		}

	}

	avg_path = avg_path / (g.V() * (g.V()-1));

	return avg_path;
}}

ostream& operator<<(ostream& os, const Graph& obj)
{
	os << "\t";

	for(unsigned i = 0; i < obj.V(); ++i)
	{
		os << i << "\t";
	}

	os << endl;

	for(unsigned i = 0; i < obj.V(); ++i)
	{
		os << i << ":\t";
		for(unsigned j = 0; j < obj.V(); ++j)
		{
			os << obj.get_edge(i, j) << "\t";
		}
		os << endl;
	}

	return os;
}

int main()
{
	Graph a(50, 0.2);
	Graph b(50, 0.4);
	Graph d(20, 0.1);

	cout << d << endl;

	ShortestPath sp(d);
	vector<Node> path = sp.path(0, 6);

	// Print shortest path sequence
	for(unsigned i = 0; i <path.size(); ++i)
	{
		cout << "<" << path[i] << ">";
	}
	cout << endl;

	// Print out average path length calculations
	cout << "20% density, 50 nodes: " << average_path_calculation(a) << endl;
	cout << "20% density, 50 nodes: " << average_shortest_path(a) << endl;
	cout << "40% density, 50 nodes: " << average_path_calculation(b) << endl;
	cout << "40% density, 50 nodes: " << average_shortest_path(b) << endl;

	return 0;
}

