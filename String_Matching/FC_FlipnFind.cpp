/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: FC_Filp n' Find
 * ALGO		: Rabin Karp
 * DATE		: 16 Nov 2021
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

char txt[100100], pat[1010][11];
int cnt[(1 << 11)];
bool have[(1 << 11)];

void solve(){
	int k, n, m;
	cin >> k >> n >> m >> (txt + 1);
	int sum = 0, cut = (1 << (n - 1));
	for(int i=1; i<=m; ++i){
		sum = (sum << 1) + (txt[i] - '0');
		if(i >= n){
			cnt[sum] += 1;
			sum -= (txt[i - n + 1] - '0') * cut;
		}
	}
	int ans = 0;
	for(int i=1; i<=k; ++i){
		cin >> (pat[i] + 1);
		int cur = 0;
		for(int j=1; j<=n; ++j){
			cur *= 2;
			cur += (pat[i][j] - '0');
		}
		ans += cnt[cur];
		have[cur] = 1;
	}
	int q;
	cin >> q;
	while(q--){
		string opr;
		cin >> opr;
		if(opr == "Find"){
			cout << ans << "\n";
		}
		else{
			int idx, cur = 0;
			cin >> idx;
			idx += 1;
			int l = max(idx + 1 - n, 1);
			int r = min(idx - 1 + n, m);
			dbg(l, r);
			dbg(idx + 1 - n, idx - 1 + n);
//			Delete
			for(int i=l; i<=r; ++i){
				cur *= 2;
				cur += (txt[i] - '0');
				if(i - l + 1 >= n){
					cnt[cur] -= 1;
					if(have[cur]){
						ans -= 1;
					}
					cur -= (txt[i - n + 1] - '0') * cut;
				}
			}
//			Add
			txt[idx] = !(txt[idx] - '0') + '0';
			cur = 0;
			for(int i=l; i<=r; ++i){
				cur *= 2;
				cur += (txt[i] - '0');
				if(i - l + 1 >= n){
					cnt[cur] += 1;
					if(have[cur]){
						ans += 1;
					}
					cur -= (txt[i - n + 1] - '0') * cut;
				}
			}
		}
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
