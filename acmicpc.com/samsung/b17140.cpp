
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;
int r, c, k;
int a[101][101];
int u[101];
int rm, cm;
void uclr() {
	for (int i = 0; i < 101; i++) {
		u[i] = i;
	}
}
void utrm() {
	for (int i = 0; i < 101; i++) {
		if (u[i] <= 101) u[i] = 0;
	}
}
int cmp1(const void* a1, const void* b) {
	if (*(int*)a1 > * (int*)b) return 1;
	if (*(int*)a1 == *(int*)b) return 0;
	if (*(int*)a1 < *(int*)b) return -1;
}
void dbgu() {
	for (int i = 0; i < 101; i++) {
		if (u[i] != 0) {
			printf(" %d: %d\n ", i, u[i]);
		}
	}
}
void dbga() {
	for (int i = 0; i < rm; i++) {
		for (int j = 0; j < cm; j++) {
				printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int max(int a1, int a2) { if (a1 > a2)return a1; return a2; }


int main() {
	int time =0;
	
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	rm = 3;
	cm = 3;
	r--;
	c--;

	while (1) {
		int len; //가장 긴 길이
		int tmp=0;
		if (a[r][c] == k) break;
		if (time > 100) {
			time = -1;
			break;
		}
		time++;
		if (rm >= cm) { // R연산
			len = cm;
			for (int i = 0; i < rm; i++) {
				uclr();
				for (int j = 0; j < cm; j++) {
					if (a[i][j] != 0) {
						u[a[i][j]] += 1000;
					}
				}
				utrm();
				qsort(u, 101, sizeof(int), cmp1);
				for (int j = 0; j < 101; j++) {
					if (u[j] != 0) {
						tmp = j;
						break;
					}
				}
				len = max(len, (101 - tmp) * 2);
				int cnt = 0;
				int x = 0, y = 0;

				for (int j = 0; j < 101; j++) { a[i][j] = 0; }
				for (int j =tmp; j < 101; j++) {
					if (cnt >= 100) break;
					x = u[j] % 1000;
					y = u[j] / 1000;
					a[i][cnt] = x;
					a[i][cnt + 1] = y;
					cnt += 2;
				}
			}
			cm = len;
			//dbga();
		}
		else {	 //C연산
			len = rm;
			for (int i = 0; i < cm; i++) {
				uclr();
				for (int j = 0; j < rm; j++) {
					if (a[j][i] != 0) {
						u[a[j][i]] += 1000;
					}
				}
				utrm();
				qsort(u, 101, sizeof(int), cmp1);
				for (int j = 0; j < 101; j++) {
					if (u[j] != 0) {
						tmp = j;
						break;
					}
				}
				len = max(len, (101 - tmp) * 2);
				int cnt = 0;
				int x = 0, y = 0;

				for (int j = 0; j < 101; j++) { a[j][i] = 0; }
				for (int j = tmp; j < 101; j++) {
					if (cnt >= 100) break;
					x = u[j] % 1000;
					y = u[j] / 1000;
					a[cnt][i] = x;
					a[cnt+1][i] = y;
					cnt += 2;
				}
			}
			rm = len;
			//dbga();


		}


	}

	printf("%d", time);
}