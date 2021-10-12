#include <stdio.h>
#include <stdlib.h>
#include "math.h"

double step(double x);
double sigmoid(double x);

int main(int argc, char* argv[]) {
	double input[4][2] = { 0,0,0,1,1,0,1,1 };
	double w[2] = { -0.2,0.2 };
	double thold = 0.0;
	double x[2];
	double bias = 1, w0 = -0.5;

	double y = 0;
	const int xnum = 2;
	int cnt = 0;
	double error = 0;

	double alpa = 0.1;

	int iteration = 0, i;
	double sum = 0;
	double error_tot = 0.0;

	printf("로젠블렛 퍼셉트론 OR연산 학습 \n");
	while (1) {
		printf(" \n%d 회차(epoch)\n", iteration);
		printf("가중치 : w[0] : %lf, w[1] : %lf \n", w[0], w[1]);
		for (i = 0; i < 4; i++) {
			for (cnt = 0; cnt < xnum; cnt++) x[cnt] = input[i][cnt];
			for (cnt = 0; cnt < xnum; cnt++) sum += (x[cnt] * w[cnt]);
			sum += (bias * w0);
			
			//y = step(sum);
			if (sigmoid(sum) > 0.5) y = 1;
			else y = 0;

			error = (x[0] || x[1]) - y;
			error_tot += error;

			printf("%f %f 결과값 : %lf \n", x[0], x[1], y);
		}
		for (cnt = 0; cnt < xnum; cnt++) w[cnt] = w[cnt] + alpa * x[cnt] * error_tot;

		if (error_tot <= thold) break;
		else error_tot = 0;
		iteration++;
		sum = 0.0;
	}
	system("PAUSE");
	return 0;
}

double step(double x) {
	if (x >= 0) return 1;
	else return 0;
}

double sigmoid(double x) {
	return 1.0 / (1.0 + exp(-x));
}