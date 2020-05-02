
// 백준1920

#include <stdio.h>
#include <stdlib.h>
#define Max 100000
int static compare(const void* f, const void* s) {
	if (*(int*)f > *(int*)s) return 1;
	else if (*(int*)f < *(int*)s) return -1;
	else return 0;
}


int main() {
	int i = 0;
	int N,M = 0;
	int a[Max];
	int b[Max];
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	qsort(a, N, sizeof(int), compare);

	scanf("%d", &M);
	for (i = 0; i < M; i++) scanf("%d", &b[i]);

	for (i = 0; i < M; i++) {
		if (bsearch(&b[i],a,N,sizeof(int),compare) != NULL) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
