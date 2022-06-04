/*perpendicular bisector*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*Function prototype*/
float get_slope(float, float, float, float);

int main(void) {
	float x1 = 0, y1 = 0;		//point 1
	float x2 = 0, y2 = 0;		//point 2
	float xMid = 0, yMid = 0;	//midpoint between point 1 and point 2
	float slope = 0;			//slope 
	float vSlope = 0;			//perpendicular slope

	//Get point 1 and point 2
	printf("Please enter the first point (format:x1  y1)> ");
	scanf("%f %f", &x1, &y1);
	printf("Please enter the second point (format:x2  y2)> ");
	scanf(" %f %f", &x2, &y2);

	//compute the slope of the line between point 1 and point 2
	slope = get_slope(x1, y1, x2, y2);

	//compute the midpoint
	xMid = (x1 + x2) / 2;
	yMid = (y1 + y2) / 2;

	//compute perpendicular slope
	vSlope = -1 / slope;
	/*printf("%f,%f\n", x1, y1);
	printf("%f,%f\n", x2,y2);
	printf("%f\n", slope);
	printf("%f", vSlope);*/

	//display the result in each case
	if (x1 == x2 && y1 == y2) {
		printf("\n兩點為同座標，無法求出垂直平分線\n");
	}
	else if (slope == 0) {
		printf("\n第一點座標( %f , %f )\n", x1, y1);
		printf("\n第二點座標( %f , %f )\n", x2, y2);
		printf("\n垂直平分線為: x = %.2f\n", xMid);
	}
	else if (slope != 0 && vSlope != 0) {
		printf("\n第一點座標( %f , %f )\n", x1, y1);
		printf("\n第二點座標( %f , %f )\n", x2, y2);
		printf("\n垂直平分線為: y = %.2fx + %.2f\n", vSlope, yMid - (vSlope * xMid));
	}
	else
	{
		printf("\n第一點座標( %f , %f )\n", x1, y1);
		printf("\n第二點座標( %f , %f )\n", x2, y2);
		printf("\n垂直平分線為: y = %.2f\n", yMid);
	}

	return(0);
}

float
get_slope(float x1, float y1, float x2, float y2) {
	return((y2 - y1) / (x2 - x1));
}
