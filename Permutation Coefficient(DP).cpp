/*
Permutation Coefficient

Permutation refers to the process of arranging all the members of a given set to form a sequence. The number of permutations on a set of n elements is given by n! , where “!” represents factorial.
The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements.
*/

// A O(n) solution that uses  
// table fact[] to calculate  
// the Permutation Coefficient 

// Returns value of Permutation 
// Coefficient P(n, k) 
int permutationCoeff(int n, int k) 
{ 
    int fact[n + 1]; 
  
    // Base case 
    fact[0] = 1; 
  
    // Calculate value  
    // factorials up to n 
    for(int i = 1; i <= n; i++) 
       fact[i] = i * fact[i - 1]; 
  
    // P(n,k) = n! / (n - k)! 
    return fact[n] / fact[n - k]; 
} 

// A O(n) time and O(1) extra 
// space solution to calculate 
// the Permutation Coefficient 

  
int PermutationCoeff(int n, int k) 
{ 
    int P = 1; 
  
    // Compute n*(n-1)*(n-2)....(n-k+1) 
    for (int i = 0; i < k; i++) 
        P *= (n-i) ; 
  
    return P; 
} 
  