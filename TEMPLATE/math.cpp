int nck[3010][3010];

void init_nck(){
	for(int i = 0 ;i < 3010;i++){
		nck[i][0] = 1;
		for(int j = 1;j <= i;j++){
			nck[i][j] = nck[i - 1][j] + nck[i - 1][j - 1];
			if(nck[i][j] >= mod)
				nck[i][j] -= mod;
		}
	}
}

int add(int a, int b) {
	if (a + b >= mod) return a + b - mod;
	return a + b;
}

int sub(int a, int b) {
	if (a - b < 0) return a - b + mod;
	return a - b;
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

int binpow(int a, int b) {
	if (b <= 0) return 1;
	if (b % 2) return mul(a, binpow(a, b - 1));
	int m = binpow(a, b / 2);
	return mul(m, m);
}


int rev(int a) {
	return binpow(a, mod - 2);
	// return a^-1
}

// (a^b)%mod
inline int modpow(int a, int b, int m = mod) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return ret;
}

ll tg[4];

void mp2(ll x[],ll y[],ll z[])
{
	tg[0]=(x[0]*y[0]+x[1]*y[2])%mod;
	tg[1]=(x[0]*y[1]+x[1]*y[3])%mod;
	tg[2]=(x[2]*y[0]+x[3]*y[2])%mod;
	tg[3]=(x[2]*y[1]+x[3]*y[3])%mod;
	z[0]=tg[0];z[1]=tg[1];z[2]=tg[2];z[3]=tg[3];
}

ll fibonacci(ll n){
	ll t[4]={0,1,1,1},r[4]={0,1,1,1};
	tg[0] = tg[1] = tg[2] = tg[3] = 0;
	while(n)
	{
		if(n&1) mp2(r,t,r);
		mp2(t,t,t);
		n>>=1;
	}
	return r[2]%mod;
}
