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

char a[110][110];

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int hei = 0, wid = 0;
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		v.emplace_back(a, b);
		hei = max(hei, b);
		wid = max(wid, a + 2 * b);
	}
	sort(v.begin(), v.end());
	memset(a, '.', sizeof a);
	for(auto x: v){
		int cur = x.first + 2 * x.second;
		for(int i=1; i<=x.second; ++i){
			for(int j=x.first+i - 1; j<=cur-i; ++j){
				if(j == x.first + i - 1){
					if(a[i][j] == '.'){
						a[i][j] = '/';
					}
					else if(a[i][j] == '\\'){
						a[i][j] = 'v';
					}
					else{
						a[i][j] = 'X';
					}
				}
				else if(j == cur - i){
					if(a[i][j] == '.'){
						a[i][j] = '\\';
					}
					else if(a[i][j] == '/'){
						a[i][j] = 'v';
					}
					else{
						a[i][j] = 'X';
					}
				}
				else{
					a[i][j] = 'X';
				}
			}
		}
	}
	for(int i=hei; i>=1; --i){
		for(int j=1; j<=wid - 1; ++j){
			cout << a[i][j];
		}
		cout << "\n";
	}
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
