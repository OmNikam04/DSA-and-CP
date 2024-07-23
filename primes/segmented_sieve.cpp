#include<bits/stdc++.h>
using namespace std;

/**************
 * 
 * SEGMENTED SIEVE
 * 
****************/

// All primes numbers in ranges like 10^12 to 10^14
// TC:  root(R)*log*log*root(R)
vector<int> sieve(int n){
    vector<bool>is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i<=n; i++){
        if(is_prime[i])
            for(int j = i*i; j<=n; j+=i)
                is_prime[j] = false;
    }

    return is_prime;
}

vector<bool> getPrimesInRange(long long L, long long R){
    vector<int>primes = sieve(sqrt(R));
    vector<int>isPrime(R-L+1, true);

    for(long long i=2; i*i<=R; i++){
        if(!prime[i])continue;
        for(long long j = max(i*i, (L+i-1)/i*i); j<=R; j+=i)
            isPrime[j-L]= false;
    }
    if(L==1) isPrime[0] = false;
    return isPrime;
}

int main(){

    return 0;
}
