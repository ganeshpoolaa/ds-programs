/* Maze problem using backtracking */
#include <stdio.h>
#define N 4 // Maze size

int solveMazeUtil(int maze[N][N], int x,	int y, int sol[N][N]);

/* Print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	int i,j;
	for(i = 0; i < N; i++) 
	{
		for(j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

/*Check if x, y is valid index for N*N maze */
int isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if(x >= 0 && x < N && y >= 0&& y < N && maze[x][y] == 1)
		return 1;
	else
	return 0;
}

/* It returns false if no path is possible, otherwise return true and prints the path
in the form of 1s. 
Please note that there may be more than one solutions, this
function prints one of the feasible solutions.*/

int solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };

	if(solveMazeUtil(maze, 0, 0, sol)== 0) 
	{
		printf("Solution doesn't exist");
		return 0;
	}

	printSolution(sol);
	return 1;
}

/* A recursive  function to solve Maze problem */
int solveMazeUtil(int maze[N][N], int x,int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if(x == N - 1 && y == N - 1&& maze[x][y] == 1) 
	{
		sol[x][y] = 1;
		return 1;
	}

	// Check if maze[x][y] is valid
	if(isSafe(maze, x, y) == 1) 
	{
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return 0;
	
		// mark x, y as part of solution path
		sol[x][y] = 1;

		// Move forward in x direction
		if(solveMazeUtil(maze, x + 1, y, sol)==1)
			return 1;

		/* If moving in x direction doesn't give solution then
			Move down in y direction */
		if(solveMazeUtil(maze, x,
		
	
		/* If none of the above movements work then BACKTRACK: 
		unmark	x, y as part of solution path */
		sol[x][y] = 0;
		return 0;
	}

	return 0;
}

// main function
int main()
{
	int maze[N][N] ={ { 1, 0, 0, 0 },
					  { 1, 1, 0, 1 },
					  { 0, 1, 0, 0 },
					  { 1, 1, 1, 1 } };

	solveMaze(maze);
	return 0;
}

