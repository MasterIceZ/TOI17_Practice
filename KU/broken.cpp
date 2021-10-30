/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

const int di[] = {-1, 0};
const int dj[] = {0, -1};

void solve(){
	int n, cnt = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.emplace(n, n);
	while(!q.empty()){
		pair<int, int> now = q.front();
		q.pop();
		for(int i=0; i<2; ++i){
			int ii = now.first + di[i];
			int jj = now.second + dj[i];
			if(ii < 1 || jj < 1 || ii > n || jj > n){
				continue;
			}
			if(a[ii][jj] != '.'){
				continue;
			}
			a[ii][jj] = 'X';
			q.emplace(ii, jj);
			cnt++;
		}
	}
	cout << 1 + cnt;
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
