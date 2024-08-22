// // C++ program to solve N Queen Problem using backtracking

// #include<iostream>
// using namespace std;
// #define N 4

// // ld is an array where its indices indicate row-col+N-1
// // (N-1) is for shifting the difference to store negative
// // indices
// int ld[30] = { 0 };

// // rd is an array where its indices indicate row+col
// // and used to check whether a queen can be placed on
// // right diagonal or not
// int rd[30] = { 0 };

// // Column array where its indices indicates column and
// // used to check whether a queen can be placed in that
// // row or not*/
// int cl[30] = { 0 };

// // A utility function to print solution
// void printSolution(int board[N][N])
// {
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++)
// 			cout << " " << (board[i][j]==1?'Q':'.') << " ";
// 		cout << endl;
// 	}
// }

// // A recursive utility function to solve N
// // Queen problem
// bool solveNQUtil(int board[N][N], int col)
// {
// 	// Base case: If all queens are placed
// 	// then return true
// 	if (col >= N)
// 		return true;

// 	// Consider this column and try placing
// 	// this queen in all rows one by one
// 	for (int i = 0; i < N; i++) {
		
// 		// Check if the queen can be placed on
// 		// board[i][col]
		
// 		// To check if a queen can be placed on
// 		// board[row][col].We just need to check
// 		// ld[row-col+n-1] and rd[row+coln] where
// 		// ld and rd are for left and right
// 		// diagonal respectively
// 		if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1)
// 			&& cl[i] != 1) {
			
// 			// Place this queen in board[i][col]
// 			board[i][col] = 1;
// 			ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

// 			// Recur to place rest of the queens
// 			if (solveNQUtil(board, col + 1))
// 				return true;

// 			// If placing queen in board[i][col]
// 			// doesn't lead to a solution, then
// 			// remove queen from board[i][col]
// 			board[i][col] = 0; // BACKTRACK
// 			ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
// 		}
// 	}

// 	// If the queen cannot be placed in any row in
// 	// this column col then return false
// 	return false;
// }

// // This function solves the N Queen problem using
// // Backtracking. It mainly uses solveNQUtil() to
// // solve the problem. It returns false if queens
// // cannot be placed, otherwise, return true and
// // prints placement of queens in the form of 1s.
// // Please note that there may be more than one
// // solutions, this function prints one of the
// // feasible solutions.
// bool solveNQ()
// {
// 	int board[N][N] = { { 0, 0, 0, 0 },
// 						{ 0, 0, 0, 0 },
// 						{ 0, 0, 0, 0 },
// 						{ 0, 0, 0, 0 } };

// 	if (solveNQUtil(board, 0) == false) {
// 		cout << "Solution does not exist";
// 		return false;
// 	}

// 	printSolution(board);
// 	return true;
// }

// // Driver program to test above function
// int main()
// {
// 	solveNQ();
// 	return 0;
// }

// // This code is contributed by Aditya Kumar (adityakumar129)

#include<iostream>
#include<vector>
using namespace std; 
int N; 


// function for printing the solution 
void printSol(vector<vector<int >> board) 
{ 
for(int i = 0;i<N;i++){ 
	for(int j = 0;j<N;j++){ 
		cout<<board[i][j]<<" "; 
	} 
	cout<<"\n"; 
} 
} 

/* Optimized isSafe function 
isSafe function to check if current row contains or current left diagonal or current right diagonal contains any queen or not if 
yes return false 
else return true 
*/

bool isSafe(int row ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals) 
{ 
	
if(rows[row] == true || left_digonals[row+col] == true || Right_digonals[col-row+N-1] == true){ 
	return false; 
} 
	
return true; 
} 

// Recursive function to solve N-queen Problem 
bool solve(vector<vector<int>>& board ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals) 
{	 
	// base Case : If all Queens are placed 
	if(col>=N){ 
		return true; 
	} 

	/* Consider this Column and move in all rows one by one */
	for(int i = 0;i<N;i++) 
	{ 
		if(isSafe(i,col,rows,left_digonals,Right_digonals) == true) 
		{ 
			rows[i] = true; 
			left_digonals[i+col] = true; 
			Right_digonals[col-i+N-1] = true; 
			board[i][col] = 1; // placing the Queen in board[i][col] 
				
				/* recur to place rest of the queens */

			if(solve(board,col+1,rows,left_digonals,Right_digonals) == true){ 
				return true; 
			} 
				
			// Backtracking 
			rows[i] = false; 
			left_digonals[i+col] = false; 
			Right_digonals[col-i+N-1] = false; 
			board[i][col] = 0; // removing the Queen from board[i][col] 

		} 
	} 

		return false; 
} 


int main() 
{ 
// Taking input from the user 

cout<<"Enter the no of rows for the square Board : "; 
cin>>N; 


// board of size N*N 
vector<vector<int>>board(N,vector<int>(N,0)); 


	// array to tell which rows are occupied 
vector<bool>rows(N,false);		 

// arrays to tell which diagonals are occupied					 
vector<bool>left_digonals(2*N-1,false); 
vector<bool>Right_digonals(2*N-1,false); 


bool ans = solve(board , 0, rows,left_digonals,Right_digonals); 

if(ans == true){ 

	// printing the solution Board 
	printSol(board); 
} 
else{ 
	cout<<"Solution Does not Exist\n"; 
} 
} 
// This Code is Contributed by Parshant Rajput 
