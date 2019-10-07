//liet ke hoan vi
#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
int nums[MAX];
int n,k;
void Solve(int n, int K)
{
    int f = 1;
    int index = -1;
    for(int i = 1; i <= n; i++)
    {
        f *= i;
        if(f > K)
        {
            index = i-1;
            f /= i;
            break;
        }
    }
    if(index == -1)
    {
        cout<<-1;
        return ;
    }
    int dt = n - index - 1;
    int cur = 1;
    for(int i = 1; i <= dt; i++)
    {
        nums[i] = i;
        cur++;
    }
    std::vector<int> v; 
    for(int i = dt+1; i <= n; i++)
    {
        v.push_back(i);
    }
    for(int i = 1; i < (n-dt); i++)
    {
        if(K > 0)
        {
            int p;
            if(K%f == 0)
            {
                p = K/f-1;
            }
            else
            {
                p = K/f;
            }
            nums[cur] = v.at(p);
            cur++;           
            v.erase(v.begin()+p);
            K -= f*p;        
            f /= index;
            index--;
        }
        else
        {
            nums[cur] = v.at(0);
            v.erase(v.begin());
            cur++;
        }
    }
    nums[cur] = v.at(0);
    for(int i = 1; i <= n; i++)
    {
        cout<<nums[i]<<" ";
    }
}
int main()
{
    cin>>n>>k;
    Solve(n, k);
    return 0;
}
