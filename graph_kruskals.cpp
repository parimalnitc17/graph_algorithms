#include <bits/stdc++.h>
using namespace std;

struct edge {
	int weight;
	int st;
	int dest;
};

bool uniona(edge a, int parent[]) {
	int x = a.st;
	while (parent[x] != x) {
		x = parent[x];
	}
	int y = a.dest;
	while (parent[y] != y) {
		y = parent[y];
	}
	if (y == x) {
		return false;
	}
	parent[y] = x;
	return true;


}

bool compare(edge i1, edge i2) {
	return i1.weight < i2.weight;
}
int main()
{
	int V, E;
	cin >> V >> E;
	edge* edgelist = new edge[E];
	for (int i = 0; i < E; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edgelist[i].st = x;
		edgelist[i].dest = y;
		edgelist[i].weight = z;
	}
	sort(edgelist, edgelist + E, compare);
	/*for (int i = 0; i < E; i++) {
		cout << edgelist[i].st << " " << edgelist[i].dest << " " << edgelist[i].weight << endl;
	}*/

	int* parent = new int[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}
	int count = 0;
	int i = 0;
	while (count < V - 1) {
		if (uniona(edgelist[i], parent)) {
			cout << edgelist[i].st << " " << edgelist[i].dest << " " << edgelist[i].weight << endl;
			count++;
		}
		i++;
	}
	delete[] parent;
	delete[] edgelist;

	return 0;
}
