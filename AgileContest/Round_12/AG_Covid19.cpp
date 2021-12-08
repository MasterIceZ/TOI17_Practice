/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Covid 19
 * ALGO		: Breadth First Search, Heap
 * DATE		: 2 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int di[] = {0, 1};
const int dj[] = {1, 0};

int dist[1010][1010], a[1010][1010];
bool visited[1010][1010];

struct B{
	int val, i;
	bool operator < (const B& o) const{
		if(val != o.val){
			return val < o.val;
		}
		return i < o.i;
	}
};

vector<int> adj[3030];

void solve(){
	int n, maxx = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	visited[1][1] = true;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		dbg(now.first, now.second);
		adj[dist[now.first][now.second]].push_back(a[now.first][now.second]);
		for(int k=0; k<2; ++k){
			int ii = now.first + di[k];
			int jj = now.second + dj[k];
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(visited[ii][jj]){
				continue;
			}
			visited[ii][jj] = true;
			q.emplace(ii, jj);
			dist[ii][jj] = dist[now.first][now.second] + 1;
			maxx = max(maxx, dist[ii][jj]);
		}
	}
	priority_queue<B> pq;
	int ans = 0;
	for(int i=2*n-2; i>=1; --i){
		for(auto x: adj[i]){
			pq.push({x, i});
		}
		ans += pq.top().val;
		pq.pop();
	}
	cout << ans;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
