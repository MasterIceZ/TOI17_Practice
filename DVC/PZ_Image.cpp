/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PZ_Image
 * ALGO		: Divide and Conquer
 * DATE		: 20 Aug 2021
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

char v[666][666];

pair<int, int> divide(int a, int b, int c, int d, int sz){
	if(sz == 1){
		return make_pair(v[a][b] - '0', 2);
	}
	int midx = (a + c) >> 1;
	int midy = (b + d) >> 1;
	pair<int, int> aa = divide(a, b, midx, midy, sz / 2);
	pair<int, int> bb = divide(midx + 1, b, c, midy, sz / 2);
	pair<int, int> cc = divide(a, midy+1, midx, d, sz / 2);
	pair<int, int> dd = divide(midx + 1, midy + 1, c, d, sz / 2);
	if(aa.first != 2 && aa.first == bb.first && bb.first == cc.first && cc.first == dd.first){
		return aa;
	}
	else{
		return make_pair(2, 1 + aa.second + bb.second + cc.second + dd.second);
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> v[i][j];
		}
	}
	auto ans = divide(1, 1, n, n, n);
	cout << ans.second;
	memset(v, '\0', sizeof v);
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
