/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Romance of the Three Kingdoms
 * ALGO		: Breadth First Search, Depth First Search
 * DATE		: 7 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

struct Q{
	int i, j, w;
};

char a[55][55];
int r, c, gr[55][55], ch[55][55];
int val[5];

void dfs(int i, int j, int id){
	gr[i][j] = id;
	for(int k=0; k<4; ++k){
		int ii = di[k] + i;
		int jj = dj[k] + j;
		if(ii < 1 || jj < 1 || ii > r || jj > c){
			continue;
		}
		if(a[ii][jj] == 'X' && !gr[ii][jj]){
			dfs(ii, jj, id);
		}
	}
}

queue<Q> q;

int bfs2(int i, int j, int v){
	while(!q.empty()){
		q.pop();
	}
	q.push({i, j, 0});
	ch[i][j] = v;
	while(!q.empty()){
		Q now = q.front();
		q.pop();
		if(gr[now.i][now.j] == v){
			return now.w;
		}
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > r || jj > c || ch[ii][jj] == v){
				continue;
			}
			ch[ii][jj] = v;
			q.push({ii, jj, now.w + 1});
		}
	}
}

int bfs3(int v){
	while(!q.empty()){
		q.pop();
	}
	val[1] = 0, val[2] = 0, val[3] = 0;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(gr[i][j] == v){
				q.push({i, j, 0});
				ch[i][j] = v;	
			}
		}
	}
	while(!q.empty()){
		Q now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.i;
			int jj = dj[k] + now.j;
			if(ii < 1 || jj < 1 || ii > r || jj > c || ch[ii][jj] == v){
				continue;
			}
			if(gr[ii][jj] && val[gr[ii][jj]]){
				continue;
			}
			ch[ii][jj] = v;
			val[gr[ii][jj]] = now.w + 1;
			q.push({ii, jj, now.w + 1});
		}
	}
	for(int i=1; i<=3; ++i){
		if(i != v && val[i] == 0){
			return INT_MAX;
		}
	}
	return val[1] + val[2] + val[3] - 2;
}

void solve(){
	int it = 0;
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; ++i){
		scanf(" %s", a[i] + 1);
	}
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			if(a[i][j] == 'X' && !gr[i][j]){
				dfs(i, j, ++it);
			}
		}
	}
	int ans = 1e9 + 10;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			dbg(i, j);
			ans = min(ans, bfs2(i, j, 1) + bfs2(i, j, 2) + bfs2(i, j, 3) - 2);
			memset(ch, false, sizeof ch);
		}
	}
	printf("%d\n", min({ans, bfs3(1), bfs3(2), bfs3(3)}));
	return ;
}

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << "\n";
	}
	return 0;
}

