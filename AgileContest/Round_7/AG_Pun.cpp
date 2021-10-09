/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Pun
 * ALGO		: Dijkstra Algorithm
 * DATE		: 9 Oct 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int i, j, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};
const int MxN = 1010;
ll v[MxN][MxN], dist[MxN][MxN];

void solve(){
	memset(dist, 0x3f, sizeof dist);
	int n, m;
	cin >> n >> m;
	priority_queue<Node> pq;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> v[i][j];
			if(i == 1){
				pq.push({i, j, v[i][j]});
			}
		}
	}
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.i == n){
			cout << now.w;
			return ;
		}
		for(int k=0; k<4; ++k){
			int ii = now.i + di[k], jj = now.j + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m){
				continue;
			}
			ll nxt = now.w + v[ii][jj];
			if(dist[ii][jj] > nxt){
				dist[ii][jj] = nxt;
				pq.push({ii, jj, nxt});
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
