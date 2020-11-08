#include<stdio.h>
#include<conio.h>
#define N 8
int solveNQ();
int solveNQUtil(int [N][N],int);
int isSafe(int [N][N], int, int);
void printSolution(int [N][N]);

int main(){
	clrscr();
	solveNQ();
	getch();
	return 0;
}
int solveNQ(){
	int i;
	for(i=0;i<N;i++){
	int board[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
			   ,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if(solveNQUtil(board,i)==0){
		printf("\nNo Solution exists!\n");
//		return 0;
		continue;
	}
	printSolution(board);
	}
	return 1;
}
int solveNQUtil(int board[N][N],int col){
	int i;
	if(col>=N)
		return 1;
	for(i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col]=1;
			if(solveNQUtil(board,col+1))
				return 1;
			board[i][col]=0;
		}
	}
	return 0;
}
int isSafe(int board[N][N],int row,int col){
	int i,j;
	for(i=0;i<col;i++)
		if(board[row][i])
			return 0;
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return 0;
	for(i=row,j=col;j>=0 && i<N;i++,j--)
		if(board[i][j])
			return 0;
	return 1;
}
void printSolution(int board[N][N]){
	int i,j;
	static int sol=1;
	printf("\n\nSolution %d\n\n",sol++);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%3d",board[i][j]);
		printf("\n");
	}
}
