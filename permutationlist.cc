//liet ke hoan vi
#include <iostream>
using namespace std;
#define MAX 100000
int nums[MAX];
long long n,K;
int r = 0;
int f = 1;
void reverse(int A[], int i, int j){
    while(i < j){
        swap(A[i], A[j]);
        i++;
        j--;
    }
}
 void shiftRight(int a[], int s, int e){
    int temp = a[e];
    for(int i = e; i > s; i--){
        a[i] = a[i-1];
    }
    a[s] = temp;
}
void kthPermutation(int n, int k){
    int factorial[n+1] ;

    factorial[0] = 1;
    factorial[1] = 1;
    nums[0] = 1;
    
    for (int i = 2; i <= n; i++) {
        nums[i-1] = i;
        factorial[i] = i*factorial[i - 1];
    }
    
    if(k <= 1){
        return ;
    }
    if(k >= factorial[n]){
        reverse(nums, 0, n-1);
        return ;
    }
    
    k -= 1;//0-based 
    for(int i = 0; i < n-1; i++){
        int fact = factorial[n-i-1];
        //index of the element in the rest of the input set
        //to put at i position (note, index is offset by i)
        int index = (k/fact);
        //put the element at index (offset by i) element at position i 
        //and shift the rest on the right of i
        shiftRight(nums, i, i+index);
        //decrement k by fact*index as we can have fact number of 
        //permutations for each element at position less than index
        k = k - fact*index;
    }
    r = 1;
    return ;
    
    
}


int main()
{
	cin>>n>>K;
	
	kthPermutation(n,  K);
    if(r == 1)
    {
        for(int i = 0; i < n; i++)
        {
            cout<<nums[i]<<" ";
        }
    }
    else cout<<-1;
	return 0;
}
