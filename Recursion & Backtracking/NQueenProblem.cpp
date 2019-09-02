#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

#define N 4

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; ++i)
		if(board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j>=0; --i,--j)
		if(board[i][j])
			return false;
	for (i = row, j = col; i < N && j>=0; ++i,--j)
		if(board[i][j])
			return false;

	return true;
}

bool solveQproblem(int board[N][N], int col)
{
	if(col>=N)
		return true;
	for (int i = 0; i < N; ++i)
	{
		if(isSafe(board,i,col))
		{
			board[i][col] = 1;
			if(solveQproblem(board,col+1))
				return true;
			board[i][col] = 0;
		}

	}
	return false;
}

int main(int argc, char const *argv[])
{
	int board[N][N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
				board[i][j] = 0;
	if((solveQproblem(board,0)))
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				std::cout<<board[i][j]<<" ";
			std::cout<<'\n';
		}
			
	}
	else
		std::cout<<"No Solution"<<'\n';
	return 0;
}
