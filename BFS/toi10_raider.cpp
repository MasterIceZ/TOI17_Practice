/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi10_raider
 * ALGO		: Breadth First Search
 * DATE		: 24 Nov 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define warn(...) 0
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int i, j, cnt;
};

const int MxN = 110;
int a[MxN][MxN], mark[MxN][MxN];
int n, mid;

const int di1[] = {-1, -1, 0, 0, 1, 1};
const int dj1[] = {-1, 0, 1, -1, -1, 0};
const int di2[] = {-1, -1, 0, 0, 1, 1};
const int dj2[] = {0, 1, -1, 1, 0, 1};

void create_start(queue<Node>& q){
	if(a[mid][1] == 1){
		q.push({mid, 1, 1});
		mark[mid][1] = 1;
	}
	if(a[mid + 1][1] == 1){
		q.push({mid + 1, 1, 1});
		mark[mid + 1][1] = 1;
	}
	if(a[mid - 1][1]  == 1){
		q.push({mid - 1, 1, 1});
		mark[mid - 1][1] = 1;
	}
}

void solve(){
	int m;
	cin >> n >> m;
	mid = n / 2 + 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	queue<Node> q;
	create_start(q);
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		dbg(now.i, now.j, now.cnt);
		if(now.i == mid && now.j == m){
			cout << now.cnt;
			return ;
		}
		if(now.i % 2 == 0){
			for(int k=0; k<6; ++k){
				int ii = now.i + di1[k];
				int jj = now.j + dj1[k];
				if(ii < 1 || jj < 1 || ii > n || jj > m){
					continue;
				}
				if(a[ii][jj] && (now.cnt + 1) % a[ii][jj] == 0 && mark[ii][jj] != now.cnt + 1){
					q.push({ii, jj, now.cnt + 1});
					mark[ii][jj] = now.cnt + 1;
				}
			}
		}
		else{
			for(int k=0; k<6; ++k){
				int ii = now.i + di2[k];
				int jj = now.j + dj2[k];
				if(ii < 1 || jj < 1 || ii > n || jj > m){
					continue;
				}
				if(a[ii][jj] && (now.cnt + 1) % a[ii][jj] == 0 && mark[ii][jj] != now.cnt + 1){
					q.push({ii, jj, now.cnt + 1});
					mark[ii][jj] = now.cnt + 1;
				}
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
