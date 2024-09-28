#include <bits/stdc++.h>

using namespace std;

// functie utilitara pentru a gasi componentele tare conexe (SCC) intr-un graf
void SCCUtil(int u, vector<int> &disc, vector<int> &low, stack<int> &S,
             vector<bool> &stackMember, vector<vector<int>> &adj,
             vector<vector<int>> &SCCs) {
    static int time = 0;

    // initializeaza timpul de descoperire si timpul minim de vizitare
    disc[u] = low[u] = ++time;
    S.push(u);
    stackMember[u] = true;

    // parcurge toti vecinii nodului u
    for (int v : adj[u]) {
        // daca v nu a fost vizitat, il viziteaza si
        // actualizeaza timpul minim de vizitare
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, S, stackMember, adj, SCCs);
            low[u] = min(low[u], low[v]);
        } else if (stackMember[v]) {
            // daca v este in stiva, actualizeaza timpul minim de vizitare
            low[u] = min(low[u], disc[v]);
        }
    }

    // daca u este radacina unei componente tare conexe,
    // scoate toate nodurile din stiva
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (S.top() != u) {
            scc.push_back(S.top());
            stackMember[S.top()] = false;
            S.pop();
        }
        scc.push_back(S.top());
        stackMember[S.top()] = false;
        S.pop();
        SCCs.push_back(scc);
    }
}

// functie pentru a gasi toate componentele tare conexe (SCC) intr-un graf
vector<vector<int>> findSCCs(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<int> disc(V + 1, -1), low(V + 1, -1);
    stack<int> S;
    vector<bool> stackMember(V + 1, false);
    vector<vector<int>> SCCs;

    // parcurge toate nodurile si gaseste SCC
    for (int i = 1; i <= V - 1; i++) {
        if (disc[i] == -1) {
            SCCUtil(i, disc, low, S, stackMember, adj, SCCs);
        }
    }

    return SCCs;
}

int main() {
    ifstream fin("scandal.in");
    ofstream fout("scandal.out");

    int n, m;
    fin >> n >> m;
    vector<vector<pair<int, int>>> adj1(n * 2 + 1, vector<pair<int, int>>());
    vector<vector<int>> adj2(n * 2 + 1, vector<int>());

    // citeste muchiile si le adauga in lista de adiacenta
    for (int i = 0; i < m; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        adj1[a].push_back({b, c});
    }

    // construieste un nou graf in functie de reguli
    for (int i = 1; i <= n; i++) {
        for (pair<int, int> p : adj1[i]) {
            // adaugam muchiile (implicatiile) in functie de
            // regulile logice ce pleaca din nodul curent
            int vec = p.first;
            int rule = p.second;
            // in reprezentarea noastra, nodul i inseamna prezenta persoanei i,
            // iar nodul i + n inseamna absenta ei
            if (rule == 0) {
                adj2[n + i].push_back(vec);
                adj2[n + vec].push_back(i);
            } else if (rule == 1) {
                adj2[i].push_back(n + vec);
                adj2[vec].push_back(i);
            } else if (rule == 2) {
                adj2[i].push_back(vec);
                adj2[vec].push_back(n + i);
            } else if (rule == 3) {
                adj2[i].push_back(n + vec);
                adj2[vec].push_back(n + i);
            }
        }
    }

    // gaseste toate componentele tare conexe in noul graf
    vector<vector<int>> SCCs = findSCCs(adj2);
    vector<int> invited, colored(n + 1, 0);

    // iteram peste toate componentele tare conexe
    for (vector<int> scc : SCCs) {
        // adaugam in lista de invitati pe cei ale caror noduri ce reprezinta
        // prezenta se gasesc inaintea nodurilor ce reprezinta absenta
        for (int v : scc) {
            if (v > n) {
                colored[v - n] = 1;
            } else if (!colored[v]) {
                invited.push_back(v);
                colored[v] = 1;
            }
        }
    }

    // afiseaza numarul de persoane invitate si lista lor
    fout << invited.size() << '\n';
    for (int p : invited) {
        fout << p << '\n';
    }

    return 0;
}
