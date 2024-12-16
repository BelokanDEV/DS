#pragma once

#define MAX_VERTICES	1024

// ���� ���յ��� �����ϴ� Ŭ����.
class VertexSets {
	int		parent[MAX_VERTICES];
	int		size;
public:
	VertexSets(int nSets) {
		size = nSets;
		for (int i = 0; i<nSets; i++)
			parent[i] = -1;
	}
	bool IsRoot(int i) { return parent[i] < 0; }

	int findSet(int vertex) {
		int id = vertex;
		while (!IsRoot(id)) id = parent[id];
		return id;
	}

	void unionSets(int s1, int s2) {
		parent[s1] = s2;
		size--;
	}
};
