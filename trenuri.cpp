#include <bits/stdc++.h>

using namespace std;

const int mMax = 2e5;

int main() {
	ifstream fin("trenuri.in");
	ofstream fout("trenuri.out");

	int idx_nr = 0;

	string x, y;
	fin >> x >> y;

	map<string, int> Idx;
	vector<vector<int>> adj(mMax + 2, vector<int>());
	vector<int> max_path(mMax + 2, 0), visited(mMax + 2, 0);
	stack<int> stk;

	// daca nodurile x si y nu au fost inca indexate, le indexam
	if (!Idx[x]) {
		Idx[x] = ++idx_nr;
	}
	if (!Idx[y]) {
		Idx[y] = ++idx_nr;
	}

	int m;
	fin >> m;

	// pentru fiecare muchie, verificam daca nodurile au fost deja indexate
	// apoi adaugam muchia inversa in lista de adiacenta
	for (int i = 0; i < m; i++) {
		string a, b;
		fin >> a >> b;

		if (!Idx[a]) {
			Idx[a] = ++idx_nr;
		}
		if (!Idx[b]) {
			Idx[b] = ++idx_nr;
		}

		adj[Idx[b]].push_back(Idx[a]);
	}

	// initializam lungimea maxima a caii de la nodul x la el insusi cu 1 si
	// adaugam nodul y in stiva pentru a incepe parcurgerea in adancime
	max_path[Idx[x]] = 1;
	stk.push(Idx[y]);

	// parcurgem in adancime graful pana cand stiva devine goala
	while (!stk.empty()) {
		// luam nodul din varful stivei
		int node = stk.top();
		// marcam nodul ca fiind vizitat
		visited[node] = 1;

		// daca nodul mai are vecini cu care nu a actualizat lungimea sa maxima
		if (!adj[node].empty()) {
			int vec = adj[node].back();

			// daca vecinul nu a fost vizitat, il adaugam in stiva
			if (!visited[vec]) {
				stk.push(vec);
			} else {
				// daca vecinul a fost vizitat si lungimea
				// maxima a caii pana la el nu este 0
				if (max_path[vec] != 0) {
					// actualizam lungimea maxima a caii pana nodul curent
					max_path[node] = max(max_path[node], max_path[vec] + 1);
				}
				// eliminam vecinul din lista de adiacenta a nodului curent
				adj[node].pop_back();
			}
		} else {
			// daca nodul nu mai are vecini utili, il eliminam din stiva
			stk.pop();
		}
	}

	// afisam lungimea maxima a caii de la
	// nodul x la nodul y
	fout << max_path[Idx[y]] << '\n';

	return 0;
}
