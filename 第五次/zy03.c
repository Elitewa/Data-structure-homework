#include <stdio.h>
#define M 7
#define N 7
int maze[M][N] = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}},start1=1,start2=1,end1=5,end2=5,success=0,i,j;
int visit(int i,int j)
{
	maze[i][j]=2;
	if(i==end1&&j==end2)
		success=1;
	if(success!=1&&maze[i][j+1]==0)
		visit(i,j+1);
	if(success!=1&&maze[i+1][j]==0)
		visit(i+1,j);
	if(success!=1&&maze[i][j-1]==0)
		visit(i,j-1);
	if(success!=1&&maze[i-1][j]==0)
		visit(i-1,j);
	if(success!=1)
		maze[i][j]=3;
	return success;
}
void print(int i,int j)
{
	printf("(%d,%d)\n",i,j);
	maze[i][j]=4;
	if(i==end1&&j==end2)
		return;
	else if(maze[i][j+1]==2)
		print(i,j+1);
	else if(maze[i+1][j]==2)
		print(i+1,j);
	else if(maze[i][j-1]==2)
		print(i,j-1);
	else if(maze[i-1][j]==2)
		print(i-1,j);
	
}
void main()
{
	if(visit(start1,start2)==1)
		print(start1,start2);
	else
		printf("\n没有找到出口！\n");
}
