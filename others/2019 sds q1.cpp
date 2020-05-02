
#include <stdio.h>
#define MAX 10000
int chk(int* a, int color, int n);

int main() {
	int t, n, k, i, j, l;
	int tmp, cnt, start;
	int a[MAX + 1] = { 0, };
	int c[MAX + 1] = { 0, };

	scanf("%d", &t);
	for (l = 1; l <= t; l++) {
		scanf("%d %d", &n, &k);
		for (i = 0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		cnt = 0;
		tmp = 1;
		a[0] = 1;
		a[n - 1] = k;
		for (i = 1; i<n; i++) {
			if (a[i] == 0 && cnt == 0 && a[i - 1] != 0) {
				tmp = a[i - 1];
				cnt = 1;
				start = i;
			}
			else if (a[i] == tmp && cnt == 1) {
				for (j = start; j<i; j++) {
					a[j] = tmp;
				}
			}
			if (a[i] != 0) cnt = 0;
		}
		start = 0;
		if (n != k) {
			for (i = 0; i < k; i++) {
				for (j = 0; j<n; j++) c[j] = a[j];
				tmp = chk(c, i + 1, n);
				if (start < tmp) start = tmp;
			}
		}
		else { start = 1; }

		printf("#%d %d\n", l, start);

		//printf("\n");
		//for (i = 0; i<n; i++) printf("%d ", c[i]);

	}




	return 0;
}

int chk(int* a, int color, int n) {
	int i, j, cnt = 0;
	int tmp = 1, find = 0;
	int nzero[MAX] = { 0, };
	for (i = 0; i < n; i++) {
		if (a[i] != 0 && find == 0) {
			cnt = a[i];
			nzero[i] = 1;
		}
		else if (a[i] == 0 && find == 0) {
			find = 1;
			tmp = i;
		}
		else if (find == 1 && a[i] != 0) {
			if (color >= cnt && color <= a[i]) {
				for (j = tmp; j < i; j++) a[j] = color;
			}
			else {
				for (j = tmp; j < i; j++) a[j] = a[i];
			}
			find = 0;
			cnt = a[i];
			nzero[i] = 1;
		}
	}

	//for (i = 0; i<n; i++) printf("%d ", a[i]);
	//printf("\n");
	for (i = 1; i < n; i++) {
		if (a[i] != a[i - 1] && a[i] != a[i - 1] + 1) {
			tmp = a[i] - a[i - 1];
			cnt = 1;
			if ((a[i] == a[i + 1] && i != n - 1) && nzero[i] == 0) {
				for (j = i; j < i + tmp; j++) {
					a[j] = a[i - 1] + cnt;
					cnt++;
				}
			}
			else {
				for (j = i - 1; j > i - tmp; j--) {
					a[j] = a[i] - cnt;
					cnt++;
				}
			}
		}
	}
	cnt = 0;
	for (i = 1; i < n; i++) {
		if (a[i] == color) cnt++;
	}

	//for (i = 0; i<n; i++) printf("%d ", a[i]);
	//printf("\n\n");
	return cnt;
}