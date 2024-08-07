#include<bits/stdc++.h>
using namespace std;

/**************
 * 
 * SIEVE OF EROSTHOSIS
 * 
****************/

// All primes numbers in range [1..n]
// TC: O(n*log*log*n)
// SC: O(n)
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

int main(){

    return 0;
}
