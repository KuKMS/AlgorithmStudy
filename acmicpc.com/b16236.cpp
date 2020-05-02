#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int x,y;	// 상어 위치
int ssize;	// 상어 크기
vector< pair<int,int> > fish[7]; //생선위치
int field[21][21]; //맵 상태
int cnt[7];
int visit[21][21];

int vclr(){
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			visit[i][j]=0;
		}
	}
}

vector<int> bfs(){
	vector<int> nxy;
	
	queue< pair <int,int>> q;
	q.push(make_pair(x,y));
	visit[x][y]=1;
	if(!q.empty()){
		q.pop();
		if(x-1>=0){
			if(visit[x-1][y] == 0){
				if(field[x-1][y]<=ssize){
					nxy.push_back(x-1);
					nxy.push_back(y);
					return nxy;
				}else if(field[x-1][y] == 0){
					q.push_back(make_pair(x-1,y);
					visit[x-1][y]=1;
				}
			}
		}
		if(y-1>=0){
			if(visit[x][y-1] == 0){
				if(field[x][y-1]<=ssize){
					nxy.push_back(x);
					nxy.push_back(y-1);
					return nxy;
				}else if(field[x][y-1] == 0){
					q.push_back(make_pair(x,y-1);
					visit[x][y-1]=1;
				}
			}
		}
		if(y+1>=0){
			if(visit[x][y+1] == 0){
				if(field[x][y+1]<=ssize){
					nxy.push_back(x);
					nxy.push_back(y+1);
					return nxy;
				}else if(field[x][y+1] == 0){
					q.push_back(make_pair(x,y+1);
					visit[x][y+1]=1;
				}
			}
		}
		if(x+1>=0){
			if(visit[x+1][y] == 0){
				if(field[x+1][y]<=ssize){
					nxy.push_back(x+1);
					nxy.push_back(y);
					return nxy;
				}else if(field[x+1][y] == 0){
					q.push_back(make_pair(x+1,y);
					visit[x+1][y]=1;
				}
			}
		}
		
	}
	return nxy;
}



int main(){
	int input;
	int ans=0;
	scanf("%d", &N);
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			scanf("%d",&input);
			field[i][j]=input;
			if(input==9){
				x=i;
				y=j;
			}else if(input>0){
				fish[input].push_back(make_pair(i,j));
				cnt[input]++;
			}
		}
	}
	ssize= 2;
	
	while(1){
		//check fish num
		int lfish=0,nx=50,ny=50;
		int length = 100;
		vector<int> nxy;
		
		if(lfish ==0) {
			break;
		}else if(lfish >1){
			//search next fish.
			int length = 1;
			vclr();
			nxy = bfs();
			if(nxy.size()==0) break;
			nx= nxy[0];
			nx= nxy[1];
		}
		ans += abs(nx-x) + abs(ny-y);
	}
	
	printf("%d",ans);
	return 0;
}