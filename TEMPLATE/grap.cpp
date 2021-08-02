struct Graph
{
	struct edge
	{
		int v; ll weight;
	};
	vector<vector<edge> > adj;
	int n;

	Graph(int _n)
	{
		adj.resize(_n);
		n = _n;
	}

	void addedge(int u, int v, ll c)
	{
		edge tmp;
		tmp.v = v; tmp.weight = c;
		adj[u].pb(tmp);
		tmp.v = u;
		adj[v].pb(tmp);
	}

	void reset()
	{
		adj.clear();
	}

	vector<ll> dist; // mang lưu duong di dấu vết
	vector<int> par;

	void bfs(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		queue<int> q; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v;
				if(dist[v] >= INFI)
				{
					dist[v] = dist[u] + 1;
					par[v] = u;
					q.push(v);
				}
			}
		}
	}

	void dijkstra(int s)
	{
		ll INFI = ll(1e18);
		dist.clear();
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		priority_queue<pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		pq.push(make_pair(0, s));
		while(!pq.empty())
		{
			int u = pq.top().ss; ll d = pq.top().ff; pq.pop();
			if(d>dist[u]) continue;
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v; ll w = adj[u][i].weight;
				if(d + w < dist[v])
				{
					dist[v] = d + w;
					par[v] = u;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
	}

	ll shortest(int s, int e) //returns the distance min by Dijkstra
	{
		dijkstra(s);
		return dist[e];
	}

	vector<vector<ll>> d;

	void Floyd()
	{
		ll INFIN = ll(1e18);
		d.resize(n);
		for(int i = 0; i < n; i++)
		{
			d[i].assign(n, INFIN);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < adj[i].size(); j++)
			{
				d[i][adj[i][j].v] = adj[i][j].weight;
			}
			d[i][i] = 0;
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

};
