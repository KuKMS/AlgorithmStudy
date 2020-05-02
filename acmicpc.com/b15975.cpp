#include <stdio.h>
#include <math.h>
#define MAX 100000
#//백준 15975

int main() {
	int i,j;	//매개변수
	int tmp,swaptmp[2];
	int N;
	int data[MAX][2]; //   coord, color
	int sum=0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &data[i][0], &data[i][1]);
	}

	//sort
	for (i = 0; i < N - 1; i++) {
		tmp = i;
		for (j = i + 1; j < N; j++) {
			if (data[tmp][1] < data[j][1]) {
				tmp = j;
			}
			if (data[tmp][1] == data[j][1]){
				if (data[tmp][0] < data[j][0]) {
					tmp = j;
				}
			}
		}
		if (i != tmp) {
			swaptmp[0] = data[tmp][0];
			swaptmp[1] = data[tmp][1];
			data[tmp][0] = data[i][0];
			data[tmp][1] = data[i][1];
			data[i][0] = swaptmp[0];
			data[i][1] = swaptmp[1];
		}
	}


	//printf("\n");
	//for (i = 0; i < N; i++) {
	//
	//	printf("%d %d\n", data[i][0], data[i][1]);
	//}
	//calculating
	for (i = 0; i < N; i++) {
		tmp = 0;
		if (data[i][1] != 0) {
			if (i == 0) {
				if (data[i][1] == data[i + 1][1]){
					tmp= data[i][0] - data[i+1][0];
				}
			}
			else if (i == N) {
				if (data[i][1] == data[i - 1][1]) {
					tmp= data[i-1][0] - data[i][0];
				}
			}
			else {
				if (data[i][1] == data[i - 1][1]) {
					tmp = data[i-1][0] - data[i][0];
				}
				if (data[i][1] == data[i + 1][1]) {
					if (tmp >= data[i][0] - data[i + 1][0] || tmp==0) {
						tmp = data[i][0] - data[i + 1][0];
					}
				}
			}
			//printf("%d th = %d\n", i, tmp);
			sum += tmp;
		}
	}

	printf("%d", sum);


	return 0;
}