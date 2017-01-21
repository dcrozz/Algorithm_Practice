int isPostorderResult( int a[], int n )
{
	return helper(a,0,n-1);
}

int helper(int a[], int s, int e)
{
	if (s==e) return 1;
	int i = e-1;
	while(a[i] > a[e] && i >= s) i--;
	if( !help(a,i+1,e-1) )
		return 0;
	int k = 1; //什么东西
	while(a[e] < a[i] && i >= s) i--;
	return help(a,s,1);

}
