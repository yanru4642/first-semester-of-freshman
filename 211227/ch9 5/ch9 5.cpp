#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void prt_maze(char maze[][MAX]);
int find_path(char maze[][MAX],int x,int y,int status,int *step);

int main(void){
	int x = 0;	//初始的x座標
	int y = 1;	//初始的y座標
	int status = 0;	//是否有路徑
	int step;	//計算走幾步
	char maze1[MAX][MAX] = { 
		{'X','X','X','X','X','X','X','X','X','X'},
		{'X','_','_','_','_','_','_','_','_','X'},
		{'X','_','X','X','_','X','_','X','_','X'},
		{'X','_','_','X','_','X','X','_','_','X'},
		{'X','_','X','X','X','_','_','_','X','X'},
		{'X','_','_','_','_','X','X','_','X','X'},
		{'X','X','_','X','_','X','_','_','_','X'},
		{'X','_','_','_','_','X','X','X','_','X'},
		{'X','_','X','X','_','_','_','_','*','X'},
		{'X','X','X','X','X','X','X','X','X','X'}};
	char maze2[MAX][MAX] = {
		{'X','X','X','X','X','X','X','X','X','X'},
		{'X','_','_','_','_','X','_','_','X','X'},
		{'X','_','X','X','_','_','_','X','_','X'},
		{'X','_','X','_','X','X','_','X','_','X'},
		{'X','_','_','_','X','_','_','_','_','X'},
		{'X','X','_','X','_','X','X','_','X','X'},
		{'X','_','_','_','_','_','_','_','_','X'},
		{'X','_','X','_','X','X','_','X','_','X'},
		{'X','X','_','_','X','_','_','_','X','X'},
		{'X','X','X','X','X','X','X','X','X','X'}};

	//maze 1
	status = 0;
	step = 0;
	status=find_path(maze1, x+1, y+1,status,&step);
	if (status){
		printf("Maze 1 path found.\n");
		printf("Step(s): %d\n\n", step);
	}
	else {
		printf("Maze 1 path NOT found.\n");
	}
	prt_maze(maze1);
	printf("X:牆壁  _:空氣  *:終點  V:路徑  n:死路\n\n");


	//maze 2
	status= 0;
	step = 0;
	status = find_path(maze2, x + 1, y + 1, status ,&step);
	if (status) {
		printf("Maze 2 path found.\n");
		printf("Step(s): %d\n\n", step);
	}
	else {
		printf("Maze 2 path NOT found.\n");
	}
	prt_maze(maze2);
	printf("X:牆壁  _:空氣  *:終點  V:路徑  n:死路\n\n");


	system("pause");
	return 0;
}

void prt_maze(char maze[][MAX]) {
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++) {
			printf("%c  ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int find_path(char maze[][MAX], int x, int y, int status, int* step) {
	int dirX[] = { -1,0,1,0 };
	int dirY[] = { 0,1,0,-1 };
	for (int i = 0; i < 4; i++) {
		if (maze[x + dirX[i]][y + dirY[i]] == '*') {
			x += dirX[i];
			y += dirY[i];
			status=1;
			return status;
		}
		else if (maze[x + dirX[i]][y + dirY[i]] == '_') {
			x += dirX[i];
			y += dirY[i];
			maze[x][y] = 'V';
			*step += 1;
			status = find_path(maze, x, y, status, step);
			return status;

		}
		
	}

	for (int i = 0; i < 4; i++) {
		if (maze[x + dirX[i]][y + dirY[i]] == 'V') {
			maze[x][y] = 'n';
			x += dirX[i];
			y += dirY[i];
			step -= 1;
			status = find_path(maze, x, y, status, step);
			return status;
		}
	}
	return status;
}