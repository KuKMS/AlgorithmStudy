#include <stdio.h>
#include <stdlib.h>
#define Max 100000
//백준 1931
struct meet {
	int out;
	int in;
}a[Max+1];

int compare(const void *first, const void *second)
{
	struct meet *a = (struct meet*)first;
	struct meet *b = (struct meet*)second;

	if (a->out > b->out) {
		return 1;
	}
	else if (a->out == b->out) {
		if (a->in > b->in) return 1;
		else if (a->in == b->in) return 0;
		else return -1;
	}
	else
		return -1;
}


int main() {
	int i,temp;
	int N;
	int ans=1;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d", &a[i].in,&a[i].out);
	qsort(a, N, sizeof(struct meet) , compare);

	temp = a[0].out;
	for (i = 1; i < N; i++) {
		if (temp <= a[i].in) {
			temp = a[i].out;
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}









