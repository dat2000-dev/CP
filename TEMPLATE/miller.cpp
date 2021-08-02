/**
	funtion check (a^s)*d
	paramater: uint64_t x
	return (s,d)
*/
pair<ll, ll > factor(ll x){
	ll s=0;
	while((x&1)==0){
		s++;
		x>>=1;
	}
	return {s, x};
}

/**
	funtion pow(a,d,n)
	paramater: uint64_t -> a,d,n
	return (a^d)%n
*/
ll Pow(ll a, ll d, ll n){
	ll res=1;
	a%=n;
	while(d){
		if(d&1) res=res*a%n;
		a=a*a%n;
		d>>=1;
	}
	return res;
}

bool miller_check(ll s, ll d, ll n, ll a){
	if(n==a) return true;
	ll p = Pow(a,d,n);
	if(p==1) return true;
	while(s--){
		if(p==n-1) return true;
		p=p*p%n;
	}
	return false;
}

bool miller(ll n){
	if(n<2) return false;
	if(n%2==0) return n==2;
	ll s,d;
	tie(s,d) = factor(n-1);
	return miller_check(s,d,n,2)&&miller_check(s,d,n,3) && miller_check(s,d,n,7) && miller_check(s,d,n,41) && miller_check(s,d,n,61);
}
