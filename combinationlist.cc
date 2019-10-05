#include <bits/stdc++.h> 
using namespace std; 
int n, m, K;
int COUNT = 0;
int f = -1;
vector<int> tmp;
void makeCombiUtil(int n, int left, int k) 
{ 
    // Pushing this vector to a vector of vector 
    if (k == 0) { 
        COUNT++;
        if(COUNT == K)
        {
            f = 1;
            for(int i = 0; i < m; i++)
            {
                cout<<tmp[i]<<" ";
            }
        }
        return; 
    } 
  
    // i iterates from left to n. First time 
    // left will be 1 
    for (int i = left; i <= n; ++i) 
    { 
        
        tmp.push_back(i); 
        makeCombiUtil(n, i + 1, k - 1); 
  
        // Popping out last inserted element 
        // from the vector 
        tmp.pop_back(); 
    } 
} 
  
// Prints all combinations of size k of numbers 
// from 1 to n. 
void makeCombi(int n, int k) 
{     
    makeCombiUtil(n, 1, k); 
} 
  
// Driver code 
int main() 
{ 
    
    cin>>n>>m>>K;
    // given number 

    makeCombi(n, m); 
    if(f == -1)
    {
        cout<<f;
    }
    return 0; 
}