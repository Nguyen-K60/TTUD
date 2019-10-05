#include <bits/stdc++.h> 
#include <stdio.h>
#include <cmath> 
#include <iomanip> 
using namespace std;
#define MAX 100000
int N, x[MAX], y[MAX], a[MAX], b[MAX];
double MIN = 100000000;
int first = -1, second = -1;
// Function for finding sum of larger numbers 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
string multiply(string num1, string num2) 
{ 
    // generate the result string 
    string s = ""; 
    if((num1.at(0) == '-' || num2.at(0) == '-') && (num1.at(0) != '-' || num2.at(0) != '-' )) 
    {
        s+="-"; 
    } 
    if(num1.at(0) == '-' && num2.at(0)!='-') 
    { 
           num1 = num1.substr(1); 
    } 
    else if(num1.at(0) != '-' && num2.at(0) == '-') 
    { 
        num2 = num2.substr(1); 
    } 
    else if(num1.at(0) == '-' && num2.at(0) == '-') 
    { 
        num1 = num1.substr(1); 
        num2 = num2.substr(1); 
    } 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(len1 + len2, 0); 
  
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
          
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
  
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            // Carry for next iteration 
            carry = sum/10; 
  
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
  
    
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 
int Search(int x, int y) 
{
	for(int i = 0; i < N; i++)
	{
		if(a[i] == x)
		{
			if(b[i] == y)
			{

				return i;
			}
		}
	}
	return -1;
}
int partition(int start,int end)
{
    int pivot=x[end];
    //P-index indicates the pivot value index
    
    int P_index=start;
    int i,t; //t is temporary variable
    
    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 
    
    for(i=start;i<end;i++)
    {
    	if(x[i]<=pivot)
        {
            t=x[i];
            x[i]=x[P_index];
            x[P_index]=t;
            t = y[i];
            y[i] = y[P_index];
            y[P_index] = t;
            P_index++;
            
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=x[end];
      x[end]=x[P_index];
      x[P_index]=t;
      t=y[end];
      y[end]=y[P_index];
      y[P_index]=t;
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
	double f;
	for(int i = 0; i < N-1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			int xx = x[j] - x[i];
			if(xx > MIN)
			{
				break;
			}
			int yy = y[j] - y[i];		
			string sx = multiply(to_string(xx), to_string(xx));
			string sy = multiply(to_string(yy), to_string(yy));		
			string s = findSum(sx, sy);
			f = sqrtl(atoi(s.c_str()));
			//f = std::sqrt(xx*xx+yy*yy);
			if(f < MIN)
			{
				first = j;
				second = i;
				MIN = f;
			}
		}
	}
}
int main()
{
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>x[i]>>y[i];
		a[i] = x[i];
		b[i] = y[i];
	}
	Quicksort(0, N-1);
	Solve();
	int sm = Search(x[first], y[first]);
	int l = Search(x[second], y[second]);
	if(sm < l)
	{
		printf("%d %d %.6lf",sm, l, MIN );
	}
	else
	{
		printf("%d %d %.6lf",l, sm, MIN );
	}
	return 0;
}