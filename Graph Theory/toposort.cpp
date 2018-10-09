#define N 100000

vector<int> g[N + 1];
bool in_stack[N + 1];
bool seen[N + 1];
int ans[N + 1];
stack<int> s;
int n;

/* O(V + E). Returns true if a cycle is found from u. */
bool dfs(int u){
	int v, i;

	// Visiting current vertex u.
	seen[u] = true;
	in_stack[u] = true;

	for (i = 0; i < (int)g[u].size(); i++){
		v = g[u][i];

		if (!seen[v]){
			if (dfs(v)){
				return true;
			}
		}
		else if (in_stack[v]){
			// Found cycle.
			return true;
		}
	}

	in_stack[u] = false;
	s.push(u);

	return false;
}

/* O(V + E). Returns true if a topological sorting exists. */
bool toposort(){
	int u, i;

	memset(seen, false, sizeof(seen));

	for (u = 1; u <= n; u++){
		if (!seen[u]){
			if (dfs(u)){
				// If a cycle is found, there is no topological sorting.
				return false;
			}
		}
	}

	// Filling up the answer.
	for (i = 1; i <= n; i++){
		ans[i] = s.top();
		s.pop();
	}

	return true;
}