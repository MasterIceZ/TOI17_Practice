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

int dist[10][333][333];
char a[333][333];

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve(){
	cin >> n;
	cout << -1;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int r, c, q;
	cin >> r >> c >> q;
	pair<int, int> stp;
	for(int i=1; i<=r; ++i){
		for(int j=1; j<=c; ++j){
			cin >> a[i][j];
			if(a[i][j] == 'J'){
				stp = make_pair(i, j);
			}
		}
	}
	memset(dist, 0x3f, sizeof dist);
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
