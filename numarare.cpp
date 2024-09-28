#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ifstream fin("numarare.in");
	ofstream fout("numarare.out");

	int n, m;
	fin >> n >> m;

	vector<vector<int>> adj1(n + 1, vector<int>());
	vector<set<int>> second_graph_children(n + 1, set<int>());
	vector<int> calc_paths(n + 1, 0), visited(n + 1, 0);
	stack<int> stk;

	// citim muchiile din primul graf si le adaugam invers in lista de adiacenta
	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;
		adj1[b].push_back(a);
	}

	// citim muchiile din al doilea graf si le adaugam invers in lista de adiacenta
	for (int i = 0; i < m; i++) {
		int a, b;
		fin >> a >> b;
		second_graph_children[b].insert(a);
	}

	calc_paths[1] = 1;
	stk.push(n);

	// parcurgem in adancime graful
	while (!stk.empty()) {
		// luam nodul din varful stivei
		int node = stk.top();
		// marcam nodul ca vizitat
		visited[node] = 1;

		// daca nodul mai are vecini cu care sa actualizeze numarul de cai
		if (!adj1[node].empty()) {
			// luam ultimul vecin al nodului
			int vec = adj1[node].back();

			// daca muchia curenta este comuna in ambele grafuri
			if (second_graph_children[node].count(vec)) {
				// daca vecinul nu a fost vizitat, il adaugam in stiva
				if (!visited[vec]) {
					stk.push(vec);
				} else {
					// altfel, actualizam numarul de cai pentru nodul curent
					// si eliminam vecinul din lista de adiacenta
					calc_paths[node] =
									(calc_paths[node] + calc_paths[vec]) % MOD;
					adj1[node].pop_back();
				}
			} else {
				// daca muchia nu este comuna ambelor grafuri,
				// il eliminam din lista de adiacenta
				adj1[node].pop_back();
			}
		} else {
			// altfel, daca am calculat numarul total de cai
			// pana la nodul curent, il eliminam din stiva
			stk.pop();
		}
	}

	// afisam numarul de lanturi elementare comune pentru nodul n
	fout << calc_paths[n] << '\n';

	return 0;
}
