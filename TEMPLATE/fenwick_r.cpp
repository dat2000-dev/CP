//fenwick_r
struct FenwickRange
{
	vector<ll> fw, fw2;
	int siz;
	FenwickRange(int N)
	{
		fw.assign(N+1,0);
		fw2.assign(N+1,0);
		siz = N+1;
	}
	void reset(int N)
	{
		fw.assign(N+1,0);
		fw2.assign(N+1,0);
		siz = N+1;
	}
	void update(int l, int r, ll val) //[l, r] + val
	{
		for (int tl = l; tl < siz; tl += (tl&(-tl)))
		{
			fw[tl] += val, fw2[tl] -= val * ll(l - 1);
		}
		for (int tr = r + 1; tr < siz; tr += (tr&(-tr)))
		{
			fw[tr] -= val, fw2[tr] += val * ll(r);
		}
	}
	ll sum(int r) //[1, r]
	{
		ll res = 0;
		for (int tr = r; tr; tr -= (tr&(-tr)))
		{
			res += fw[tr] * ll(r) + fw2[tr];
		}
		return res;
	}
	ll query(ll l, ll r)
	{
		if(l == 0) return sum(r);
		else return sum(r)-sum(l-1);
	}
};
