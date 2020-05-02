#include <stdio.h>
#define Max 1000
//백준 11399
int main() {
	int i,j,temp;
	int N;
	int a[Max];
	int ans=0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	for (i = 1; i < N ; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	temp = 0;
	for (i = 0; i < N; i++) {
		temp += a[i];
		ans += temp;
	}
	printf("%d", ans);
	return 0;
}