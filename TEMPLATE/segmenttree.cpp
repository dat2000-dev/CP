int n;

ll __gcd(ll u, ll v)
{
	int shift;
	if (u == 0) return v;
	if (v == 0) return u;
	shift = __builtin_ctzll(u | v);
	u >>= __builtin_ctzll(u);
	do {
		v >>= __builtin_ctzll(v);
		if (u > v) {
			uint64_t t = v;
			v = u;
			u = t;
		}
		v = v - u;
	} while (v != 0);
	return u << shift;
}

struct node{
	ll s,lz,mn,mx, gcd;
} st[1<<19];

void app(int i, ll x, int l2, int r2){
	st[i].mn+=x;
	st[i].mx+=x;
	st[i].gcd+=x;
	st[i].s+=x*(r2-l2+1);
	st[i].lz+=x;
}

void psh(int i, int l2, int m2, int r2){
	app(2*i,st[i].lz,l2,m2);
	app(2*i+1,st[i].lz,m2+1,r2);
	st[i].lz=0;
}

void upd(int l1, ll x, int i =1, int l2 = 0, int r2=n-1)
{
	if(l2==r2){
		st[i].mn=x;
		st[i].s=x;
		st[i].mx=x;
		st[i].gcd=x;
		return ;
	}
	int m2 = (l2+r2)>>1;
	psh(i,l2,m2,r2);
	if(l1<=m2) upd(l1,x,2*i,l2,m2);
	else upd(l1,x,2*i+1,m2+1,r2);
	st[i].s=st[i*2].s+st[i*2+1].s;
	st[i].mx=max(st[i*2].mx,st[i*2+1].mx);
	st[i].mn=min(st[i*2].mn,st[i*2+1].mn);
	st[i].gcd=__gcd(st[i*2].gcd,st[i*2+1].gcd);
}

void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1){
		app(i,x,l2,r2);
		return ;
	}
	int m2= (l2+r2)>>1;
	psh(i,l2,m2,r2);
	if(l1<=m2) upd2(l1,r1,x,2*i,l2,m2);
	if(m2<r1) upd2(l1,r1,x,2*i+1,m2+1,r2);
	st[i].s=st[i*2].s+st[i*2+1].s;
	st[i].mx=max(st[i*2].mx,st[i*2+1].mx);
	st[i].mn=min(st[i*2].mn,st[i*2+1].mn);
	st[i].gcd=__gcd(st[i*2].gcd,st[i*2+1].gcd);
}

ll get_sum(int l1, int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1) return st[i].s;
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	return (l1<=m2?get_sum(l1,r1,2*i,l2,m2):0)+(m2<r1?get_sum(l1,r1,2*i+1,m2+1,r2):0);
}

ll get_max(int l1, int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1) return st[i].mx;
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	return max((l1<=m2?get_max(l1,r1,2*i,l2,m2):0LL),(m2<r1?get_max(l1,r1,2*i+1,m2+1,r2):0LL));
}

ll get_min(int l1, int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1) return st[i].mn;
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	return min((l1<=m2?get_min(l1,r1,2*i,l2,m2):0LL),(m2<r1?get_min(l1,r1,2*i+1,m2+1,r2):0LL));
}

ll get_gcd(int l1, int r1, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1) return st[i].gcd;
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	return __gcd((l1<=m2?get_gcd(l1,r1,2*i,l2,m2):0LL),(m2<r1?get_gcd(l1,r1,2*i+1,m2+1,r2):0LL));
}
