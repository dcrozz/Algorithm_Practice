const int MOD = 10003;

int pow(int a, int p)
{
	int r = 1;
	int t = a;
	for( int i = p; i > 0; i>>=1 )
	{
		if((i&1) == 1)
			r *= t;
		t *= t;
		r %= MOD;
		t %= MOD;
	}
}

int solve(int m, int n)
{
	return (pow(m,n) - m*pow(m-1,n-1))%MOD+MOD)%MOD;  //+MOD 防负数
}
