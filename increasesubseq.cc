#include <bits/stdc++.h>

using namespace std;
int arr[100000];
int N;
int LongestIncreasingSubsequenceLength() 
{ 
    int S[100000];
    S[1] = 1;
    int ans = S[1];
    for(int i = 2; i <= N; i++)
    {
        S[i] = 1;
        for(int j = 1; j<= i-1; j++)
        {
            if(arr[j] < arr[i] && S[i] < (S[j] + 1))
            {
                S[i] = S[j] + 1;
            }
        }
        if(ans < S[i])
        {
            ans = S[i];
        }
    }
    return ans; 
}
main(){
    cin>>N;
    for(int i = 1; i <= N; i++)
    {
        cin>>arr[i];
    }  
    cout<<LongestIncreasingSubsequenceLength();
    return 0;
}