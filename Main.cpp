#include <iostream>
#include <vector>
#include <queue>

void graph(int start, int end) {
	// Vertex
	std::vector<std::vector<int>> vertex = {
		{0, 1, 3, 0, 0},
		{0, 0, 1, 0, 5},
		{0, 0, 0, 2, 0},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0}
	};

	// Queue to store node weight
	// I use Queue because if we store it in vector, it stored in reverse and need more work to do.
	std::queue<int> nodes;

	// Find the shortest path using dijkstra
	int k = 0;
	for (int i = start - 1; i < end; i++) {
		int weight = 0;
		for (int j = k; j < end; j++) {
			// If there is no edge between nodes, skip the iteration
			if (vertex[i].at(j) == 0) continue;

			// Compare weights
			if (vertex[i].at(j) <= weight || weight == 0) {
				weight = vertex[i].at(j);
				nodes.push(weight);
				k = j;
				continue;
			}
		}
	}

	// Declare a vector so we could print for the output
	std::vector<int> paths;

	// Transfer all queue to vector one by one
	while (!nodes.empty()) {
		paths.push_back(nodes.front());
		nodes.pop();
	}

	// Output
	std::cout << "Start: " << start << "\tEnd: " << end << std::endl;

	std::cout << "+-------------------------------+\n";
	std::cout << "|\tPaths\t|\tWeight\t|\n";
	std::cout << "+-------------------------------+\n";

	for (int i = 0; i < paths.size(); i++) {
		std::cout << "|\tPath " << i << "\t|\t" << paths[i] << "\t|" << std::endl;
	}

	std::cout << "+-------------------------------+\n";
}

int main() {
	graph(2, 5);

	return 0;
}