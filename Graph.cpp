/*
 * Graph.cpp
 *
 *  Created on: 17 Mar 2018
 *      Author: gilfredoremon
 */

#include <random>
#include "Graph.h"

using namespace std;
using namespace dijkstra;

static inline double prob()
{
	return rand()/(double(RAND_MAX) + 1.0);
}

/* Use this function if edges should be double
 *
static inline double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
*/

static inline unsigned fRand(unsigned min, unsigned max)
{
	return static_cast<unsigned>(rand()%(max-min+1)+min);
}

Graph::Graph(const unsigned nV, const double density, const Edge min_edge, const Edge max_edge): data(nV), value(nV), n_v(nV), n_e(), min_edge(min_edge), max_edge(max_edge)
{
	srand(time(0)); // Seed rand()

	// Allocate the memory
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];
		value[i] = static_cast<Value>(0);
	}

	// Generate the graph
	for(unsigned i = 0; i < n_v; ++i)
	{
		for(unsigned j = 0; j < n_v; ++j)
		{
			if(i == j)
			{
				data[i][j] = static_cast<Edge>(0);
			}
			else
			{
				if(prob() < density)
				{
					if(static_cast<Edge>(0) == data[i][j])
					{
						n_e++; // Increase number of edges
					}

					// Define the edge cost based on class defined range
					data[i][j] = data[j][i] = fRand(min_range, max_range);
				}
				else
				{
					data[i][j] = data[j][i] = static_cast<Edge>(0);
				}
			}
		}
	}
}

Graph::Graph(const Graph& obj):data(obj.V()), value(obj.V()), n_v(obj.V()), n_e(obj.E()), min_edge(obj.min_edge), max_edge(obj.max_edge)
{
	// Allocate the memory & copy data
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];
		value[i] = obj.value[i];

		for(unsigned j = 0; j < n_v; ++j)
		{
			data[i][j] = obj.get_edge(i,j);
		}
	}
}

Graph& Graph::operator= (const Graph& obj)
{
	// Program could check whether obj and referenced object are equal
	// Clear memory if it is not empty
	for(unsigned i = 0; i < n_v; ++i)
	{
		delete[] data[i];
	}

	data.clear(); // Clear vector

	// Copy the data
	n_v = obj.V();
	n_e = obj.E();
	data.resize(n_v);
	value.resize(n_v);
	max_edge = obj.max_edge;
	min_edge = obj.min_edge;

	// Allocate the memory & copy data
	for(unsigned i = 0; i < n_v; ++i)
	{
		data[i] = new Edge[n_v];
		value[i] = obj.value[i];

		for(unsigned j = 0; j < n_v; ++j)
		{
			data[i][j] = obj.get_edge(i,j);
		}
	}

	return *this;
}

Graph::~Graph()
{
	for(unsigned i = 0; i < n_v; ++i)
	{
		delete[] data[i];
	}
}


unsigned Graph::V() const
{
	return n_v;
}

unsigned Graph::E() const
{
	return n_e;
}

bool Graph::adjacent(const Node x, const Node y) const
{
	if((x < n_v) && (y < n_v))
	{
		return (data[x][y] != no_edge);
	}
	else
	{
		return false;
	}
}

vector<Node> Graph::neighbors(const Node x) const
{
	vector<Node> neighbors;

	if(x < n_v)
	{
		for(Node i = 0; i < n_v; ++i)
		{
			if(data[x][i])
			{
				neighbors.push_back(i);
			}
		}
	}

	return neighbors;
}

Edge Graph::get_edge(const Node x, const Node y) const
{

	if((x < n_v) && (y < n_v))
	{
		return data[x][y];
	}
	else
	{
		return 0.0;
	}
}

Value Graph::get_value(const Node x) const
{

	if(x < n_v)
	{
		return value[x];
	}
	else
	{
		return static_cast<Value>(0);
	}
}

void Graph::set_value(const Node x, const Value new_val)
{

	if(x < n_v)
	{
		value[x] = new_val;
	}
}

void Graph::clear_values()
{
	for(unsigned i = 0; i < n_v; ++i)
	{
		value[i] = static_cast<Value>(0);
	}
}
