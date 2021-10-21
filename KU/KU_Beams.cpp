/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: KU_Beams
 * ALGO		: Two Pointers
 * DATE		: 19 Oct 2021
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

const int MxN = 550;
int a[MxN], b[MxN];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> b[i];
	}
	int i = 0, j = 0, cnt = 0;
	while(i <= n && j <= m){
		bool done = false;
		while(a[i] <= b[j] && i < n){
			i += 1;
			if(i % 2 != j % 2 && a[i - 1] != b[j]){
				cnt++;
			}
			else if(a[i] <= b[j] && a[i - 1] > b[j - 1]){
				cnt++;
			}
			else if(a[i] >= b[j] && a[i - 1] < b[j - 1]){
				cnt++;
			}
			done = true;
		}
		while(b[j] < a[i] && j < m){
			j += 1;
			if(i % 2 != j % 2 && b[j - 1] != a[i]){
				cnt++;
			}
			else if(b[j] <= a[i] && b[j - 1] > a[i - 1]){
				cnt++;
			}
			else if(b[j] >= a[i] && b[j - 1] < a[i - 1]){
				cnt++;
			}
			done = true;
		}
		if(!done){
			break;
		}
		dbg(i, j);
	}
	cout << cnt + 1;
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
