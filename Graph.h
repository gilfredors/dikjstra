/*
 * Graph.h
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>

using namespace std;

namespace dijkstra
{
	typedef unsigned Node;
	typedef unsigned Edge;
	typedef unsigned Value;

	const Edge min_range = 1;
	const Edge max_range = 10;
	const Edge no_edge = 0;

	class Graph
	{
	public:

		// Constructor
		Graph(const unsigned nV = 0, const double density = 0, const Edge min_edge = 1, const Edge max_edge = 10);

		// Copy constructor
		Graph(const Graph& obj);

		// Assignment operator
		Graph& operator= (const Graph& obj);

		// Destructor
		~Graph();

		// Returns the number of vertices in the graph
		unsigned V() const;

		// Returns the number of edges in the graph
		unsigned E() const;

		// Tests whether there is an edge from node x to node y.
		bool adjacent(const Node x, const Node y) const;

		// Lists all nodes y such that there is an edge from x to y.
		vector<Node> neighbors(const Node x) const;

		Edge get_edge(const Node x, const Node y) const;

		Value get_value(const Node x) const;

		void set_value(const Node x, const Value new_val);

		void clear_values();

	private:
		vector<Edge*> data; // Data representation of graph
		vector<Value> value; // Value representation for nodes
		unsigned n_v; // Number of vertices
		unsigned n_e; // Number of edges
		Edge min_edge; // Min value of edges
		Edge max_edge; // Max value of edges
	};

}

#endif /* GRAPH_H_ */
