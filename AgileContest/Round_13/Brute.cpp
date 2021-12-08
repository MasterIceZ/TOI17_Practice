/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dist[666][666];

const int di[] = {-1, 1, -1, 1, -1, 1};
const int dj[] = {0, 0, -1, -1, 1, 1};

void solve(){
	pair<int, int> st, ed;
	cin >> st.first >> st.second >> ed.first >> ed.second;
	st.first += 300;
	st.second += 300;
	ed.first += 300;
	ed.second += 300;
	queue<pair<int, int>> q;
	q.emplace(st);
	memset(dist, -1, sizeof dist);
	dist[st.first][st.second] = 0;
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		dbg(now.first, now.second);
		if(now == ed){
			cout << dist[ed.first][ed.second];
			return ;
		}
		for(int k=0; k<6; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(dist[ii][jj] == -1){
				dist[ii][jj] = dist[now.first][now.second] + 1;
				q.emplace(ii, jj);
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int m, q = 1;
	cin >> m >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
