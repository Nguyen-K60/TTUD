#include <bits/stdc++.h> 
#define MAX 2000
int ROW, COL;
int M[MAX][MAX];
int visited[MAX][MAX];
int largest = 0;
int f = 0;
int rowNbr[] = { -1,  0, 0, 1}; 
int colNbr[] = {  0, -1, 1, 0 }; 
using namespace std;
int isSafe( int row, int col) 
{ 

    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
} 

// the 8 neighbours as adjacent vertices 
void DFS( int row, int col ) 
{ 
    // These arrays are used to get 
    // row and column numbers of 8 
    // neighbours of a given cell 
    
    f++;
    // Mark this cell as visited 
    visited[row][col] = 1; 
  
    // Recur for all connected neighbours 
    for (int k = 0; k < 4; ++k) 
    {
        if (isSafe(row + rowNbr[k], col + colNbr[k]) )
        {
        	
            DFS( row + rowNbr[k], col + colNbr[k]); 
        }
    }
    //visited[row][col] = 0;
} 
  
// The main function that returns 
// count of islands in a given boolean 
// 2D matrix 
int countIslands() 
{ 
    // Make a bool array to mark visited cells. 
    // Initially all cells are unvisited 
     

  
    // Initialize count as 0 and 
    // travese through the all cells of 
    // given matrix 
    int count = 0; 
    for (int i = 0; i < ROW; ++i) 
        for (int j = 0; j < COL; ++j) 
  
            // If a cell with value 1 is not 
            if (M[i][j] && !visited[i][j]) { 
                // visited yet, then new island found 
                // Visit all cells in this island. 
                DFS(i, j); 
  				if(f > largest)
  				{
  					largest = f;
  				}
                // and increment island count 
                ++count; 
                f = 0;
            } 
  
    return count; 
}
int main()
{
	cin>>ROW>>COL;
    string str[ROW];
	for(int i = 0; i < ROW; i++)
	{
		cin>>str[i];
	}
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            M[i][j] = atoi(str[i].substr(j, 1).c_str());
            visited[i][j] = 0;
        }
    }
	cout<<countIslands()<<endl;
	cout<<largest;
	return 0;
}