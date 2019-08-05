bool sieve[1000000];
vector<int> primes;
void sieveMake(int n)
{
	//change sieve size according to n
	for(int i=0;i<n;i++)
		sieve[i]=1;
	sieve[0]=0;sieve[1]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(sieve[i])
		{
			for(int j=i*i;j<=n;j+=i)
			{
				sieve[j]=0;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(sieve[i])
			primes.pb(i);
	}
}
