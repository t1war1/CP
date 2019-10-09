vector<int> primes;
void primeFactors(int n)  
{
    if(n%2==0)  
    {
        primes.pb(2);
        while (n % 2 == 0)  
        {  
            n = n/2;  
        }  
    }
    
  
    int sqt=sqrt(n);
    for (int i = 3; i <=sqt ; i = i + 2)  
    {  
        if(n%i==0)
        {
            primes.pb(i);
            while (n % i == 0)  
            {  
                n = n/i;  
            } 
        }
         
    }  
 
    if (n > 2)  
        primes.pb(n); 
}  