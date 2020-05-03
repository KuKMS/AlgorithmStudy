
#include <cstdio>
#include <vector>

using namespace std;

int R, C, M;
int king;
int seas[101][101];
int sead[101][101];
int seaz[101][101];
int us[101][101];
int ud[101][101];
int uz[101][101];
int direction[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
void dbg() {
	for (int j = 1; j <= R; j++) {
		for (int k = 1; k <= C; k++) {
			printf("%d ", seaz[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void uclr() {
	for (int j = 1; j <= R; j++) {
		for (int k = 1; k <= C; k++) {
			us[j][k] = 0;
			ud[j][k] = 0;
			uz[j][k] = 0;
		}
	}
}

int main() {
	int a1,a2,a3,a4,a5;
	int ans=0;
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {

		scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
		seas[a1][a2] =a3;
		sead[a1][a2] = a4;
		seaz[a1][a2] = a5;
	}
	king = 0;
	for (int i = 1; i <= C; i++) { //100회
		king++;
		int top = R + 1; //맨 위의 상어 높이.
		for (int j = 1; j <= R; j++) {
			if (seaz[j][king] > 0) {
				ans += seaz[j][king];
				seas[j][king] = 0;
				sead[j][king] = 0;
				seaz[j][king] = 0;
				break;
			}
		}
		uclr();
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				if (seaz[j][k] > 0) {
					int ns = seas[j][k];
					int nr=j, nc=k;
					int tmp = nr;
					switch (sead[j][k]) {
					case 1:
						ns %= 2 * (R - 1);
						nr += ns * (-1);
						tmp = nr;
						if (nr <= 0 && nr >= (R * (-1) + 2)) {
							sead[j][k] = 2;
							nr = tmp * (-1) + 2;
						}
						else if (nr < (R * (-1) + 2)) {
							nr = 2 * (R - 1) - (tmp * (-1));
						}
						break;
					case 2:
						ns %= 2 * (R - 1);
						nr += ns * (1);
						tmp = nr;
						if (nr>R && nr<2*R) {
							sead[j][k] = 1;
							nr = 2 * R - tmp;
						}
						else if (nr>=2*R) {
							nr = nr - 2 * (R - 1);
						}
						break;
					case 4:
						ns %= 2 * (C - 1);
						nc += ns * (-1);
						tmp = nc;
						if (nc <= 0 && nc >= (C * (-1) + 2)) {
							sead[j][k] = 3;
							nc = tmp * (-1) + 2;
						}
						else if (nc < (C * (-1) + 2)) {
							nc = 2 * (C - 1) - (tmp * (-1));
						}
						break;
					case 3:
						ns %= 2 * (C - 1);
						nc += ns * (1);
						tmp = nc;
						if (nc > C && nc < 2 * C) {
							sead[j][k] = 4;
							nc = 2 * C - tmp;
						}
						else if (nc >= 2 * C) {
							nc = nc - 2 * (C - 1);
						}
						break;




					default: break;
					}


					if (seaz[j][k] > uz[nr][nc]) { //0이거나 잡아먹을수 있다면 갱신.
						us[nr][nc] = seas[j][k];
						ud[nr][nc] = sead[j][k];
						uz[nr][nc] = seaz[j][k];
					}
					seas[j][k] = 0;
					sead[j][k] = 0;
					seaz[j][k] = 0;
				}
			}
		}
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				seas[j][k] = us[j][k];
				sead[j][k] = ud[j][k];
				seaz[j][k] = uz[j][k];
			}
		}
	}

	printf("%d", ans);
	return 0;
}