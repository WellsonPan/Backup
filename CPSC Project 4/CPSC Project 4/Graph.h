#pragma once
#include <vector>
using namespace std;

class Graph {
private:
	// TO DO
	// member variables and functions to implement the public member functions
	int **matrix;

public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				matrix[row][col] = 0;
			}
		}
	}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		matrix[v][u] = 1;
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	vector<int> adjacentVertices(int v) {
		vector<int> vertices;
		int counter = 0;
		for (int index = 0; index < (sizeof matrix[v] / sizeof(int)); index++)
		{
			if (matrix[v][index] == 1)
			{
				vertices[counter] = index;
				counter++;
			}
		}
		return vertices;
	}

	// TO DO
	// return a list of vertices that appear between v and w, starting with v and ending with w
	// vertices should not be repeated
	vector<int> getPath(int v, int w) {
		vector<int> path;
		int a = v, b = w;
		while (a != b)
		{
			for (int index = 0; index < (adjacentVertices(v)).size(); index++)
			{
				cout << "code sucks" << endl;
			}
		}
		return path;
	}
};