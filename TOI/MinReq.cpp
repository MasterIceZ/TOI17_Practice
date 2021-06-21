/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Minimum Requirement
 * ALGO		: Brute Force
 * DATE		: 19 June 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 1e7 + 2;

int p[15];
int l[15], a[15], s[15], t[15], qr[MxN], qs[15];
int n, m, x;

bool val(int t){
	vector<int> mkr(n+1);
	for(int j, i=1; i<=n; ++i){
		for(j=1; j<=n; ++j){
			if(mkr[j]){
				continue;
			}
			int lb = p[i];
			int rb = p[i+1];
			int cnt = 0, ch = 1;
			while(lb < rb && ch){
				++cnt;
				int nx = upper_bound(qs+lb, qs+rb, l[j] - a[i] + qs[lb-1]) - qs;
				if(nx == lb){
					ch = 0;
				}
				lb = nx;
			}
			if(ch && cnt <= t){
				mkr[j] = 1;
				break;
			}
		}
		if(j == n + 1){
			return 0;
		}
	}
	return 1;
}

bool solve2(int x){
	for(int i=1; i<=n; ++i){
		cin >> p[i];
	}
	p[n+1] = m;
	do{
		if(val(x))
		return true;
	}while(next_permutation(a+1, a+n+1));
	return false;
}

void solve(){
	cin >> n >> m >> x;
	for(int i=1; i<=n; ++i){
		cin >> l[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=m; ++i){
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	for(int i=1; i<=x; ++i){
		cin >> qr[i];
	}
	sort(l+1, l+n+1);
	for(int i=1; i<=x; ++i){
		cout << (solve2(i)?"P":"F") << "\n";
	}
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
