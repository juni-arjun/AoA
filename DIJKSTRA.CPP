#include <iostream.h>
#include <conio.h>
#include <limits.h>

#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX], visited[MAX];
    int i, j, minDistance, nextNode;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
	distance[i] = INT_MAX;
	visited[i] = 0;
    }

    distance[source] = 0; // Distance to the source is 0

    for (i = 0; i < n - 1; i++) {
	// Find the unvisited node with the smallest distance
	minDistance = INT_MAX;
	for (j = 0; j < n; j++) {
	    if (!visited[j] && distance[j] < minDistance) {
		minDistance = distance[j];
		nextNode = j;
	    }
	}

	// Mark the node as visited
	visited[nextNode] = 1;

	// Update distances of neighbors
	for (j = 0; j < n; j++) {
	    if (graph[nextNode][j] > 0 && !visited[j]) {
		if (distance[nextNode] + graph[nextNode][j] < distance[j]) {
		    distance[j] = distance[nextNode] + graph[nextNode][j];
		}
	    }
	}
    }

    // Print the results
    cout << "Shortest distances from node " << source << ":\n";
    for (i = 0; i < n; i++) {
	if (distance[i] == INT_MAX) {
	    cout << "Node " << i << ": Unreachable\n";
	} else {
	    cout << "Node " << i << ": " << distance[i] << "\n";
	}
    }
}

void main() {
    clrscr();
    int graph[MAX][MAX], n, source, i, j;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    cin >> graph[i][j];
	}
    }

    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(graph, n, source);
    getch();
}
