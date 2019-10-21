#include <bits/stdc++.h> 
#include <list>
using namespace std; 
#define ll long long int 
ll N, M, K;

ll binomialCoeff(ll n, ll k)  
{   
    // Since C(n, k) = C(n, n-k)  
    ll num = 1;
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)]   
    for (int i = 0; i < k; ++i)  
    {  
        num *= (n-i);

    }  
    return num; 
} 
int getValue(std::list<int>& l,int n)
{
  std::list<int>::iterator i = l.begin();
  std::advance(i, n);
  return *i;
}
void Solve()
{
    int n = N, m = M, k = K;
    int num = 0;
    ll bino[M];
    for(int i = 1; i <= M; i++)
    {
        bino[i] = binomialCoeff(N-M+i, i);
       // cout<<N-M+i<<"C"<<i<<" = "<<bino[i]<<endl;
        if(k > bino[i])
        {
            num++;
        }
        else
        {
            break;
        }
    }
    //cout<<"num = "<<num<<endl;
    if(num == M)
    {
        cout<<-1;
        return;
    }
    int idx = num;
    for(int i = 1; i <= (M-num-1); i++)
    {
        cout<<i<<" ";
    }
    list<int> li;
    for(int i = M-num; i <= N; i++)
    {
        li.push_back(i);
    }
    for(int i = 1; i <= num; i++)
    {
        ll bi = bino[idx];
        int pos = k/bi;  
        if(k%bi == 0)
        {
            pos--;
        }      
        int vl = getValue(li, pos);
        cout<<vl<<" ";
        li.remove(vl);
        idx--;
        k -= (bi*pos);
        //cout<<"k = "<<k<<endl;
    }
    cout<<getValue(li, k-1);
}
int main() 
{     
    cin>>N>>M>>K;
    Solve();
    return 0; 
}