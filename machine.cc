#include <iostream>
using namespace std;
#define MAX 1000009
int a[MAX], b[MAX];
int n;
int partition(int start,int end)
{
    int pivot=a[end];
    //P-index indicates the pivot value index
    
    int P_index=start;
    int i,t; //t is temporary variable
    
    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 
    
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            t=b[i];
            b[i]=b[P_index];
            b[P_index]=t;
            P_index++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[end];
      a[end]=a[P_index];
      a[P_index]=t;
      t=b[end];
      b[end]=b[P_index];
      b[P_index]=t;
     //at last returning the pivot value index
     return P_index;
 }
 void Quicksort(int start,int end)
 {
    if(start<end)
    {
         int P_index=partition(start,end);
             Quicksort(start,P_index-1);
             Quicksort(P_index+1,end);
    }
} 
void Solve()
{
	int r = -1;
	int temp = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = n; j > i; j--)
		{
			if(b[i] >= a[j])
			{
				break;
			}
			else
			{
				temp = b[i] + b[j] - a[i] - a[j];
				if(r < temp)
				{
					r = temp;
				}
			}
		}
	}
	cout<<r;
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i]>>b[i];
	}
	Quicksort(1,n);
	Solve();
	return 0;
}