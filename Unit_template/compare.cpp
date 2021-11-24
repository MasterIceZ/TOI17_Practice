#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#define warn(...) 0
#endif

using ll = long long;

int n = 8;
int x[1010] = {1, 3, 8, 1, 3, 7, 2 ,3};
int y[1010] = {0, 2, 4, 2, 1, 3, 1, 3};
int a[1010] = {0, 1, 2, 3, 4, 5, 6, 7};

bool cmp(int u, int v){
	if(x[u] == x[v]){
		return y[u] < y[v];
	}
	return x[u] < x[v];
}

void solve(){
	sort(a, a + n, cmp);
	dbg(to_vector(x, 0, n - 1));
	dbg(to_vector(y, 0, n - 1));
	dbg(to_vector(a, 0, n - 1));
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
