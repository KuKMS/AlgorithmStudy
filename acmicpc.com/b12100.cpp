class map{
public:
	int pane[21][21];
	int size = 20;
	map* up =NULL;
	map* down = NULL;
	map* left = NULL;
	map* right = NULL;
	int num() {
		int large = 0;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				if (large < pane[i][j]) large = pane[i][j];
			}
		}
		return large;
	}
};

using namespace std;
int N;
void up(map* map2);
void down(map* map2);
void left(map* map2);
void right(map* map2);


int dfs(int num, map* map1) {
	if (num >= 5) return map1->num();
	int max = 0;
	int tmp = 0;

	map map_up;
	map map_down;
	map map_left;
	map map_right;
	map1->up = &map_up;
	map1->down = &map_down;
	map1->left = &map_left;
	map1->right = &map_right;
	//복사
	map_up.size = map1->size;
	map_down.size = map1->size;
	map_left.size = map1->size;
	map_right.size = map1->size;
	for (int i = 0; i < map1->size; i++) {
		for (int j = 0; j < map1->size; j++) {
			map_up.pane[i][j] = map1->pane[i][j];
			map_down.pane[i][j] = map1->pane[i][j];
			map_left.pane[i][j] = map1->pane[i][j];
			map_right.pane[i][j] = map1->pane[i][j];
		}
	}


	up(&map_up);
	max = dfs(num + 1, &map_up);
	down(&map_down);
	tmp = dfs(num + 1, &map_down);
	if (tmp > max) max = tmp;
	left(&map_left);
	tmp = dfs(num + 1, &map_left);
	if (tmp > max) max = tmp;
	right(&map_right);
	tmp = dfs(num + 1, &map_right);
	if (tmp > max) max = tmp;

	return max;
}
void up(map* map2) {
	int size = map2->size;
	//모으기
	int tmp;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] != 0) {
				tmp = i;
				while (map2->pane[tmp - 1][j] != 0 && tmp >= 0) {
					tmp--;
				}
				if (tmp != i) {
					map2->pane[tmp][j] = map2->pane[i][j];
					map2->pane[i][j] = 0;
				}
			}
		}
	}
	//합치기
	for (int i = 1; i < size; i+=2) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] == map2->pane[i - 1][j]) {
				map2->pane[i - 1][j] *= 2;
				map2->pane[i][j] = 0;
			}
		}
	}
	//모으기
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] != 0) {
				tmp = i;
				while (map2->pane[tmp - 1][j] != 0 && tmp >= 0) {
					tmp--;
				}
				if (tmp != i) {
					map2->pane[tmp][j] = map2->pane[i][j];
					map2->pane[i][j] = 0;
				}
			}
		}
	}
}
void down(map* map2) {
	int size = map2->size;
	//모으기
	int tmp;
	for (int i = size-2; i >=0; i--) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] != 0) {
				tmp = i;
				while (map2->pane[tmp + 1][j] != 0 && tmp < size) {
					tmp++;
				}
				if (tmp != i) {
					map2->pane[tmp][j] = map2->pane[i][j];
					map2->pane[i][j] = 0;
				}
			}
		}
	}
	//합치기
	for (int i = 1; i < size; i += 2) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] == map2->pane[i - 1][j]) {
				map2->pane[i][j] *= 2;
				map2->pane[i-1][j] = 0;
			}
		}
	}
	//모으기
	for (int i = size - 2; i >= 0; i--) {
		for (int j = 0; j < size; j++) {
			if (map2->pane[i][j] != 0) {
				tmp = i;
				while (map2->pane[tmp + 1][j] != 0 && tmp < size) {
					tmp++;
				}
				if (tmp != i) {
					map2->pane[tmp][j] = map2->pane[i][j];
					map2->pane[i][j] = 0;
				}
			}
		}
	}
}

void left(map* map2) {
	int size = map2->size;
	int tmp;
	//모으기
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			tmp = j;
			while (map2->pane[i][tmp - 1] != 0 && tmp >= 0) {
				tmp--;
			}
			if (tmp != j) {
				map2->pane[i][tmp] = map2->pane[i][j];
				map2->pane[i][j] = 0;
			}
		}
	}
	//합치기
	for (int i = 0; i < size; i ++) {
		for (int j = 1; j < size; j+=2) {
			if (map2->pane[i][j] == map2->pane[i][j-1]) {
				map2->pane[i][j-1] *= 2;
				map2->pane[i][j] = 0;
			}
		}
	}
	//모으기
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			tmp = j;
			while (map2->pane[i][tmp - 1] != 0 && tmp >= 0) {
				tmp--;
			}
			if (tmp != j) {
				map2->pane[i][tmp] = map2->pane[i][j];
				map2->pane[i][j] = 0;
			}
		}
	}
}
void right(map* map2) {
	int size = map2->size;
	int tmp;
	//모으기
	for (int i = 0; i < size; i++) {
		for (int j = size - 2; j >= 0 ; j--) {
			tmp = j;
			while (map2->pane[i][tmp + 1] != 0 && tmp < size) {
				tmp++;
			}
			if (tmp != j) {
				map2->pane[i][tmp] = map2->pane[i][j];
				map2->pane[i][j] = 0;
			}
		}
	}
	//합치기
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j += 2) {
			if (map2->pane[i][j] == map2->pane[i][j - 1]) {
				map2->pane[i][j] *= 2;
				map2->pane[i][j-1] = 0;
			}
		}
	}
	//모으기
	for (int i = 0; i < size; i++) {
		for (int j = size - 2; j >= 0; j--) {
			tmp = j;
			while (map2->pane[i][tmp + 1] != 0 && tmp < size) {
				tmp++;
			}
			if (tmp != j) {
				map2->pane[i][tmp] = map2->pane[i][j];
				map2->pane[i][j] = 0;
			}
		}
	}
}



int main() {
	scanf("%d", &N);
	int temp,ret;
	map init_map;
	init_map.size = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp);
			init_map.pane[i][j] = temp;
		}
	}
	ret = dfs(0, &init_map);
	printf("%d", ret);

}