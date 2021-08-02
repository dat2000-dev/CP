struct Matrix
{
	int a[DIM][DIM];
	int *operator [] (int r)
	{
		return a[r];
	};

	Matrix(int x = 0) // gan duong cheo chinh = 1
	{
		memset(a, 0, sizeof a);
		if (x)
		{
			for(int i = 0; i < DIM; i++) a[i][i] = x;
		}
	}
} const I(1);

Matrix operator * (Matrix A, Matrix B)
{
	const ll mod2 = ll(mod) * mod;
	Matrix C;
	for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++)
		{
			ll w = 0;
			for(int k = 0; k < DIM; k++)
			{
				w += ll(A[i][k]) * B[k][j];
				if (w >= mod2) w -= mod2;
			}
			C[i][j] = w % mod;
		}
	}
	return C;
}

Matrix operator ^ (Matrix A, ll b)
{
	Matrix R = I;
	for (; b > 0; b /= 2)
	{
		if (b % 2) R = R*A;
		A = A*A;
	}
	return R;
}
