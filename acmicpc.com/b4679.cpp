
// 백준4679
#include <stdio.h>
#define MAX 10000
int dn(int n) {
	int ans = n;
	while (n != 0) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main() {
	int a[MAX+1];
	int i,b;
	for (i = 0; i < MAX+1; i++) a[i] = 1;
	for (i = 1; i < MAX + 1; i++) {
		b = dn(i);
		if (b <= 10000)a[dn(i)] = 0;
	}
	for (i = 1; i < MAX + 1; i++) {
		if (a[i] == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}
