#include <iostream>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
#define MAX 16
#define INT_MAX 999999
int n;
double dist[MAX][MAX];
int VISITED_ALL; // 
int dp[65536][MAX]; //65536 = 2^MAX
typedef std::pair < double, std::vector<int> > myPair;
std::map < std::pair<int, int>, std::vector<int> > myMap;
myPair tsp(int mask,int current) // 
{   
   std::vector <int> v;
   v.push_back(current);
   if(mask==VISITED_ALL)
   {
      return std::make_pair(dist[current][0], v);
   }
   if(dp[mask][current]!=-1)
   {
      return std::make_pair(dp[mask][current], myMap[std::make_pair(mask, current)]);
   }
   //Now from current node, we will try to go to every other node and take the min ans
   
   int ans = INT_MAX;
   //Visit all the unvisited cities and take the best route
   for(int k = 0; k < (n+1); k++)
   {
      if((mask & (1<<k)) == 0) // k haven't been visited
      {
         int newMask = mask | (1<<k);
         myPair m = tsp(newMask, k);
         double newAns = dist[current][k] + m.first;           
         if(newAns < ans)
         {
            ans = newAns;
            std::cout<<"TSP("<<bitset<5>(mask)<<", "<<current<<")"<<endl;
            std::cout<<"ans "<<ans<<endl;
            std::cout<<"before: "<<endl;
            for(int i = 0; i < v.size(); i++)
            {
               cout<<v[i]<<" ";
            }
            cout<<endl;
            int first = v[0];
            v.clear();
            v.push_back(first);
            cout<<"after: "<<endl;
            for(int i = 0; i < v.size(); i++)
            {
               cout<<v[i]<<" ";
            }
            cout<<endl;
            std::vector<int> v1 = m.second;
            for(int i = 0; i < v1.size(); i++)
            {
               v.push_back(v1[i]);
            }
            cout<<"after push v1"<<endl;
            for(int i = 0; i < v.size(); i++)
            {
               cout<<v[i]<<" ";
            }
            cout<<endl;
         }
      }
   }      
   dp[mask][current] = ans;
   myMap[std::make_pair(mask, current)] = v;
   return std::make_pair(ans, v);
} 
int main()
{
   cin>>n;
   for(int i = 0; i <= n ; i++)
   {
      for(int j = 0; j <= n; j++)
      {
         cin>>dist[i][j];
      }
      cout<<endl;
   }
    /* init the dp array */
      for(int i=0;i<(1<<(n+1));i++)
   {
      for(int j=0;j<n+1;j++)
      {
         dp[i][j] = -1;
      }
   }
   VISITED_ALL = (1<<(n+1)) -1;
   myPair m = tsp(1,0);
   cout<<m.first<<std::endl;
   std::cout<<"path"<<std::endl;
   for(int i = 0; i < m.second.size(); i++)
   {
      std::cout<<m.second[i]<<" ";
   }
   std::cout<<std::endl;
return 0;
}