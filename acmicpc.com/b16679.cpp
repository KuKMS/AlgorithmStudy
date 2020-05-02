////문제: 16679
#include <stdio.h>
#include <math.h>
#define MAX 20



int main()
{
	int T;
	int i,j,l;	//매개변수
	int n, k;	//n: 주사위 수, k: 목표
	int dice[MAX];
	int sum;
	long long int ans1 = 0;


	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &n, &k);
		sum = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &dice[j]);
			sum += dice[j];
		}
		//sum 이 목표를 넘으면 출력
		if (sum >= k) {
			printf("%d\n1", pow(6,n));
			for (l = 1; l < n; l++) {
				printf(" 0");
			}
			break;
		}
		// 작은것 부터 선택.







	}

    return 0;
}