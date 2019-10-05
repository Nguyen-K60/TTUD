#include <bits/stdc++.h>

using namespace std;
int arr[5555555];
int N;
int LongestIncreasingSubsequenceLength(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
        if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else { 
            // TO check whether the element is not present before hand 
            auto it = find(tail.begin(), tail.begin() + length, v[i]); 
            if (it != tail.begin() + length) { 
                continue; 
            } 
            // If not present change the tail element to v[i] 
            it = upper_bound(tail.begin(), tail.begin() + length, v[i]); 
            *it = v[i]; 
        } 
    } 
  
    return length; 
}
main(){
    cin>>N;
    for(int i = 1; i <= N; i++)
    {
        cin>>arr[i];
    } 
    vector<int> v;
    for(int i = 1; i <= N; i++)
    {
        v.push_back(arr[i]);
    } 
    cout<<LongestIncreasingSubsequenceLength(v);
    return 0;
}