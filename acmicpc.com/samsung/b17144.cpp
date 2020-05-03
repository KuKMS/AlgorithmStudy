#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int N,M;
int R, C, T;
int ans;
int field[51][51];
int update[51][51];
int direction[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int air;
vector<pair<int,int>> dust;
void fpr() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%2d ", field[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void uclr() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			update[i][j] = 0;
		}
	}
}


int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &field[i][j]);
			if (field[i][j] == -1) {
				air = i;
			}
			else if (field[i][j] > 0) {
				dust.push_back(make_pair(i, j));
			}
		}
	}
	for (int tc = 0; tc < T; tc++) {
		uclr();
		for (int i = 0; i < dust.size();i++){
			int a = dust[i].first;
			int b = dust[i].second;
			int dir[4] = {0,0,0,0};
			int dcnt = 0;
			if (field[a][b] >= 5) {
				if (a - 1 >= 0) {
					if (field[a - 1][b] != -1) {
						dir[0] = 1;
						dcnt++;
					}
				}
				if (b - 1 >= 0) {
					if (field[a][b - 1] != -1) {
						dir[1] = 1;
						dcnt++;
					}
				}
				if (a + 1 < R) {
					if (field[a + 1][b] != -1) {
						dir[2] = 1;
						dcnt++;
					}
				}
				if (b + 1 < C) {
					if (field[a][b + 1] != -1) {
						dir[3] = 1;
						dcnt++;
					}
				}
				int tobe = field[a][b] / 5;
				for (int k = 0; k < 4; k++) {
					if (dir[k] == 1) {
						update[a + direction[k][0]][b + direction[k][1]] += tobe;
					}
				}
				field[a][b] -= tobe * dcnt;
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				field[i][j] += update[i][j];
			}
		}
		//upper side
		int tmp1 = 0;
		int tmp2 = 0;
		for (int i = 1; i <= C - 2; i++) {
			tmp1 = field[air - 1][i];
			field[air - 1][i] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = air - 1; i > 0; i--) {
			tmp1 = field[i][C - 1];
			field[i][C - 1] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = C - 1; i >= 1; i--) {
			tmp1 = field[0][i];
			field[0][i] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = 0; i < air - 1; i++) {
			tmp1 = field[i][0];
			field[i][0] = tmp2;
			tmp2 = tmp1;
		}
		//down side
		tmp1 = 0; tmp2 = 0;

		for (int i = 1; i <= C - 2; i++) {
			tmp1 = field[air][i];
			field[air][i] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = air; i < R-1; i++) {
			tmp1 = field[i][C - 1];
			field[i][C - 1] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = C - 1; i >= 1; i--) {
			tmp1 = field[R-1][i];
			field[R-1][i] = tmp2;
			tmp2 = tmp1;
		}
		for (int i = R-1; i >air; i--) {
			tmp1 = field[i][0];
			field[i][0] = tmp2;
			tmp2 = tmp1;
		}
		dust.clear();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (field[i][j] > 0) dust.push_back(make_pair(i, j));
			}
		}

	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += field[i][j];
		}
	}
	ans +=2;
	printf("%d", ans);
	return 0;
}