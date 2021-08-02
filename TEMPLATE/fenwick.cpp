struct Fenwick
{
	vector<ll> t;
	Fenwick(int n)
	{
		t.assign(n+1,0);
	}
	void reset(int n)
	{
		t.clear();
		t.assign(n+1, 0);
	}
	void update(int p, ll v)
	{
		for (; p < (int)t.size(); p += (p&(-p))) t[p] += v;
	}
	ll sum(int r)
	{
		ll s = 0;
		for (; r; r -= (r&(-r))) s += t[r];
		return s;
	}
	ll get_sum(int l, int r)
	{
		if(l == 0) return sum(r);
		return sum(r) - sum(l-1);
	}
};
