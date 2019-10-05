// #include <bits/stdc++.h> 
// #include <stdio.h>
// using  namespace std;
// #define MAX 100000
// #define MAX_T 100
// float R[MAX_T][MAX];
// int TT;
// float pi = 3.141592654;
// float Vmax = -1.0;
// int partition(float *a,int start,int end)
// {
//     int pivot=a[end];
//     //P-index indicates the pivot value index
    
//     int P_index=start;
//     int i; //t is temporary variable
//     float t;
//     //Here we will check if array value is 
//     //less than pivot
//     //then we will place it at left side
//     //by swapping 
    
//     for(i=start;i<end;i++)
//     {
//     	if(a[i]>=pivot)
//         {
//             t=a[i];
//             a[i]=a[P_index];
//             a[P_index]=t;
//             P_index++;
//         }
//      }
//      //Now exchanging value of
//      //pivot and P-index
//       t=a[end];
//       a[end]=a[P_index];
//       a[P_index]=t;
    
//      //at last returning the pivot value index
//      return P_index;
//  }
//  void Quicksort(float *a,int start,int end)
//  {
//     if(start<end)
//     {
//          int P_index=partition(a,start,end);
//              Quicksort(a,start,P_index-1);
//              Quicksort(a,P_index+1,end);
//     }
// }  
// void Solve(float *a, int n, int f)
// {
//  if(n == f)
//  {
//  	Vmax = a[n-1];
//  	return;
//  }
//  if(n > f)
//  {
//  	if(a[0]/2 > a[n - f])
//  	{
//         a[0] /= 2;
//         a[n-f] = a[0];
//         Quicksort(a, 0, n-f);
//         Solve(a, n, f);
//  	}
//     else
//     {
//         Vmax = a[n-f];
//     }
//  }
//  else
//  {

//     for(int i = 1; i <= f - n; i++)
//     {
//         cout<<i<<":"<<endl;
//         a[0] /= 2;
//         a[n-1+i] = a[0];
//         Quicksort(a, 0, n-1+i);
//         for(int k = 0; k <= n-1+i; k++)
//         {
//             cout<<k<<": "<<a[k]<<endl;
//         }
//     }
//     Vmax = a[f-1];
//  }
// }
// int main()
// {
// 	cin>>TT;
// 	int N[TT], F[TT];
// 	for(int i = 0; i < TT; i++)
// 	{
// 		cin>>N[i]>>F[i];
// 		for(int j = 0; j < N[i]; j++)
// 		{
// 			cin>>R[i][j];
// 		}
// 	}
// 	for(int i = 0; i < TT; i++)
// 	{		
// 		for(int j = 0; j < N[i]; j++)
// 		{
// 			R[i][j] = pi * R[i][j] * R[i][j];
// 		}
//         Quicksort(R[i], 0, N[i] - 1);
// 		Solve(R[i], N[i], F[i]+1);
// 		printf("%.6f\n", Vmax);
// 	}
	
	
// 	/* code */
// 	return 0;
// }
#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846
#include <math.h>
using namespace std;
int t, N, F;
double r[10000];

int f(double S)
{
    int cnt = 0;
    for(int i = 0; i < N; i++) cnt += (M_PI*r[i]*r[i])/S;
    if(cnt >= F+1) return 1;
    else return 0;
}

main()
{
    cin>>t;
    while(t--)
    {
        cin>>N>>F;
        double sumOfPie = 0;
        for(int i = 0; i < N; i++)
        {
            cin>>r[i];
            sumOfPie += M_PI*r[i]*r[i];
        }
        double Smax = sumOfPie/(F+1);
        double S = Smax;
       // cout<<"Smax = "<< S<<endl;
        double max = 0;
        if(N == 1) max = Smax;
        else{
            double init = 0;
            while(S-init >= 0.000001){
                double m = (init+S)/2;
                if(f(m)){
                    if(m > max) max = m;
                    init = m;
                }
                else S = m;
            }
        }
        printf("%6lf\n", max);
    }
}