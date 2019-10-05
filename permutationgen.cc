#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int h[MAX];
int n;
void reverse(int A[], int i, int j){
    while(i < j){
        swap(A[i], A[j]);
        i++;
        j--;
    }
}
int nextPermutation(int nums[], int length) {
    int k = -1;
    for (int i = length - 1; i > 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    } 
    if (k == -1) {
        reverse(nums, 1, length);
        return 0;
    }
    int l = -1;
    for (int i = length; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        } 
    } 
    swap(nums[k], nums[l]);
    reverse(nums, k + 1, length); 
    return 1;
}


int main()
{
	int r = -1;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>h[i];
	}
	if(nextPermutation(h, n) == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            cout<<h[i]<<" ";
        }
    }
	else
	{
		cout<<r;
	}
	return 0;
	
}