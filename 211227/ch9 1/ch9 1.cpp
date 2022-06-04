#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int blob_check(int grid[][MAX], int x, int y,int cnt);

int main(void){
	int grid[MAX][MAX] = { {0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,0,1,0},
		{0,1,0,0,0,1,0},
		{0,0,1,0,1,1,0} };
	int x=0;
	int y=0;
	int blob = 0;
	//show grid
	printf("Grid:\n");
	for (int i = 1; i <= MAX-2; i++){
		for (int j = 1; j <= MAX-2; j++){
			printf("%d  ", grid[i][j]);
		}
		printf("\n");
	}
	//check blob and display the result
	printf("\n");
	for (int i = 0; i < MAX-2; i++){
		for (int j = 0; j < MAX-2; j++){
			int count = 0;
			count = blob_check(grid, i+1, j+1,count);
			if (count!=0){
				printf("Number of cells: %d\n", count);
				blob++;
			}
		}
	}
	printf("Total blob: %d\n", blob);

	system("pause");
	return 0;
}

int blob_check(int grid[][MAX], int x, int y,int cnt) {
	int dirY[] = {-1,-1,-1,0,0,1,1,1};
	int dirX[] = {-1,0,1,-1,1,-1,0,1};
	if (grid[y][x]==1){
		cnt++;
		grid[y][x] = 0;
	}for (int i = 0; i < 8; i++){
		if (grid[y+dirY[i]][x+dirX[i]]==1){
			y += dirY[i];
			x += dirX[i];
			cnt=blob_check(grid, x, y,cnt);
		}

	}
	return cnt;
}