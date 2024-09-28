#include <bits/stdc++.h>

using namespace std;

// implementarea algoritmului Dijkstra pentru gasirea distantelor
// minime de la un nod de start la toate celelalte noduri
vector<long long> dijkstra(long long start,
						   vector<vector<pair<long long, long long>>> &adj) {
	long long n = adj.size();
	// initializam distantele cu o valoare mare
	vector<long long> dist(n, 1e14);
	// coada de prioritati pentru a selecta nodul cu distanta minima
	priority_queue<pair<long long, long long>,
	vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

	// distanta de la nodul de start la el insusi este 0
	dist[start] = 0;
	pq.push({0, start});

	// parcurgem coada de prioritati
	while (!pq.empty()) {
		// nodul curent
		long long node = pq.top().second;
		// distanta pana la nodul curent
		long long nodeDist = pq.top().first;
		// eliminam nodul curent din coada
		pq.pop();

		// daca distanta pana la nodul curent este diferita de
		// distanta calculata anterior, trecem la urmatorul nod
		if (nodeDist != dist[node]) {
			continue;
		}

		// parcurgem vecinii nodului curent
		for (auto &edge : adj[node]) {
			// nodul vecin
			long long nextNode = edge.first;
			// costul muchiei
			long long edgeWeight = edge.second;

			// daca am gasit o cale mai scurta pana la nodul vecin,
			// actualizam distanta si adaugam nodul in coada
			if (dist[node] + edgeWeight < dist[nextNode]) {
				dist[nextNode] = dist[node] + edgeWeight;
				pq.push({dist[nextNode], nextNode});
			}
		}
	}

	// returnam vectorul de distante
	return dist;
}

int main() {
	ifstream fin("drumuri.in");
	ofstream fout("drumuri.out");

	long long n, m;
	fin >> n >> m;

	// initializam listele de adiacenta
	vector<vector<pair<long long, long long>>>
		adj(n + 1, vector<pair<long long, long long>>()),
		adj_rev(n + 1, vector<pair<long long, long long>>());

	// citim muchiile si le adaugam in listele de adiacenta
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		fin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj_rev[b].push_back({a, c});
	}

	long long x, y, z;
	fin >> x >> y >> z;

	// calculam distantele minime de la
	// nodurile de start la toate celelalte noduri
	vector<long long> distX = dijkstra(x, adj);
	vector<long long> distY = dijkstra(y, adj);
	vector<long long> distZ = dijkstra(z, adj_rev);

	// initializam distanta minima cu o valoare mare
	long long min_dist = 1e14;

	// iteram peste punctul de intersectie al drumurilor de la x la z si
	// de la y la z combinand costurile si actualizam solutia minima
	for (long long i = 1; i <= n; i++) {
		long long dist = 1LL * (distX[i] + distY[i] + distZ[i]);
		min_dist = min(min_dist, dist);
	}

	// afisam distanta minima
	fout << min_dist << '\n';

	return 0;
}
