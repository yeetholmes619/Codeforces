// Efficient C++ program to
// find out Eulerian path
#include <bits/stdc++.h>
using namespace std;

// Function to find out the path
// It takes the adjacency matrix
// representation of the graph as input
void findpath(Graph &g, int n)
{
	vector<int> numofadj;

	// Find out number of edges each vertex has
	for (int i = 0; i < n; i++)
		numofadj.push_back(accumulate((g.adj[i]).size());

	// Find out how many vertex has odd number edges
	int startpoint = 0, numofodd = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (numofadj[i] % 2 == 1)
		{
			numofodd++;
			startpoint = i;
		}
	}

	// If number of vertex with odd number of edges
	// is greater than two return "No Solution".
	if (numofodd > 2)
	{
		cout << "No Solution" << endl;
		return;
	}

	// If there is a path find the path
	// Initialize empty stack and path
	// take the starting current as discussed
	stack<int> stack;
	vector<int> path;
	int cur = startpoint;

	// Loop will run until there is element in the stack
	// or current edge has some neighbour.
	while (!stack.empty() or
			accumulate(graph[cur],
					graph[cur] + 5, 0) != 0)
	{
		// If current node has not any neighbour
		// add it to path and pop stack
		// set new current to the popped element
		if (accumulate(graph[cur],
					graph[cur] + 5, 0) == 0)
		{
			path.push_back(cur);
			cur = stack.top();
			stack.pop();
		}

		// If the current vertex has at least one
		// neighbour add the current vertex to stack,
		// remove the edge between them and set the
		// current to its neighbour.
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (graph[cur][i] == 1)
				{
					stack.push(cur);
					graph[cur][i] = 0;
					graph[i][cur] = 0;
					cur = i;
					break;
				}
			}
		}
	}

	// print the path
	for (auto ele : path) cout << ele << " -> ";
	cout << cur << endl;
}

// Driver Code
int main()
{
	// Test case 1
	int graph1[][5] = {{0, 1, 0, 0, 1},
					{1, 0, 1, 1, 0},
					{0, 1, 0, 1, 0},
					{0, 1, 1, 0, 0},
					{1, 0, 0, 0, 0}};
	int n = sizeof(graph1) / sizeof(graph1[0]);
	findpath(graph1, n);

	// Test case 2
	int graph2[][5] = {{0, 1, 0, 1, 1},
					{1, 0, 1, 0, 1},
					{0, 1, 0, 1, 1},
					{1, 1, 1, 0, 0},
					{1, 0, 1, 0, 0}};
	n = sizeof(graph1) / sizeof(graph1[0]);
	findpath(graph2, n);

	// Test case 3
	int graph3[][5] = {{0, 1, 0, 0, 1},
					{1, 0, 1, 1, 1},
					{0, 1, 0, 1, 0},
					{0, 1, 1, 0, 1},
					{1, 1, 0, 1, 0}};
	n = sizeof(graph1) / sizeof(graph1[0]);
	findpath(graph3, n);
}

// This code is contributed by
// sanjeev2552

