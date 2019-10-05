#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std; 
#define MAX 1000000
float a[MAX/2];
float t;
int i, COUNT;
int largest, l, r;
void heapify(int n, int i) 
{ 
    largest = i; // Initialize largest as root 
    l = 2*i + 1; // left = 2*i + 1 
    r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort( int n) 
{ 
    // Build heap (rearrange array) 
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(n, i); 
  
    // One by one extract an element from heap 
    for (i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(a[0], a[i]); 
  
        // call max heapify on the reduced heap 
        heapify(i, 0); 
    } 
} 
 
 
// Driver program 
int main() 
{     
    int n;
    cin>>n;
    if(n > MAX/2)
    {
    ofstream input1;
    input1.open ("input1.txt", ios::out|ios::trunc);  
    for( i = 0; i < n; i++)
    {
        if(i < MAX/2)
        {
            scanf("%f", &a[i]);
            input1<<a[i]<<endl;
        }
        else
        {
            scanf("%f", &a[i-MAX/2]);
        }
    }
    input1.close(); 
    //cout<<"sort part 2"<<endl;
    heapSort(n-MAX/2); 
    //write to file
    //cout<<"write part 2 to file"<<endl;
    ofstream output1;
    output1.open ("output1.txt", ios::out|ios::trunc);  
    for(i = 0; i < n - MAX/2; i++)
    {
        output1<<a[i]<<endl;
    }
    output1.close();
    //read input1
    //cout<<"read input 1"<<endl;
    string line;
    ifstream myfile ("input1.txt");
    COUNT = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            a[COUNT] = stof(line);
            COUNT++;
        }
        myfile.close();
    }
    else  
    {   
        cout << "Unable to open file"; 
    }
    //cout<<"sort part 1"<<endl;
    heapSort(MAX/2);
    //cout<<"write output"<<endl;
    COUNT = 0;
    ofstream output;
    output.open ("output.txt", ios::out|ios::trunc);      
    string line1;
    ifstream myfile1 ("output1.txt");
    if (myfile1.is_open())
    {
        while ( getline (myfile1,line1) )
        {
            t = stof(line1);
            while(COUNT < MAX/2 && t > a[COUNT])
            {
                printf("%.2f", a[COUNT]);
                printf(" ");
                COUNT++;
            }
            printf("%.2f", t);
            printf(" ");
        }
        myfile1.close();
    }
    else  
    {   
        cout << "Unable to open file"; 
    }
    output.close();
    if(COUNT < MAX/2)
    {
        for(i = COUNT; i < MAX/2; i++)
        {
            printf("%.2f", a[COUNT]);
            printf(" ");
        }
    }
    
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            cin>>a[i];    
        } 
        heapSort(n);
        for(i = 0; i < n; i++)
        {
            printf("%.2f", a[i]);
            printf(" ");
        }   
    }
        return 0; 
} 