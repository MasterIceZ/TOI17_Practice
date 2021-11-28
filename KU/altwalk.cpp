/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: altwalk
 * ALGO		: Breadth First Search
 * DATE		: 26 Nov 2021
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

char a[33][33];
set<pair<int, int>> st;

const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int k=0; k<4; ++k){
			int ii = di[k] + now.first;
			int jj = dj[k] + now.second;
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(a[ii][jj] == a[now.first][now.second] || st.count(make_pair(ii, jj))){
				continue;
			}
			st.emplace(ii, jj);
			q.emplace(ii, jj);
		}
	}
	cout << st.size();
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
