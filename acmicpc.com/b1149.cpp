#include <stdio.h>
#include <math.h>
#define Max 1000
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  
//백준 1149

int main() {
	int i;
	int N;
	int a[Max+2][3];
	int d[Max + 1][3];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
	for (i = 0; i < 3; i++) a[0][i] = d[0][i] = 0;
	for (i = 1; i <= N; i++) {
		d[i][0] = MIN(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = MIN(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = MIN(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}
	printf("%d", MIN(d[N][0], MIN(d[N][1], d[N][2])));
	return 0;
}
