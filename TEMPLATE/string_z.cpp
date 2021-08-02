template <class S> vector<int> z_algo(const S& s) {
	int n = int(s.size());
	vector<int> r(n+1);
	r[0] = 0;
	for (int i = 1, j = 0; i <= n; i++) {
		int& k = r[i];
		k = (j + r[j] <= i) ? 0 : min(j + r[j] - i, r[i - j]);
		while (i + k < n && s[k] == s[i + k]) k++;
		if (j + r[j] < i + r[i]) j = i;
	}
	r[0] = n;
	r.pop_back();
	return r;
}
