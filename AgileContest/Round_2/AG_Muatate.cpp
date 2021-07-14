/*
 * AUTHOR	: Hydrolyzed~
 * TASK		:
 * CENTER	: RYW
 * DATE		: 26 Jun 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using pii = pair<int, int>;
using pip = pair<int, pair<int, int>>;
using ll = long long;

int n, m;
string a, b;

const int MxN = 1e5 + 10;
int ac[MxN], at[MxN], ct[MxN], ca[MxN], ta[MxN], tc[MxN];

void solve(){
	int l, r;
	cin >> l >> r;
	int AC = ac[r + 1] - ac[l];
	int AT = at[r + 1] - at[l];
	int CA = ca[r + 1] - ca[l];
	int CT = ct[r + 1] - ct[l];
	int TA = ta[r + 1] - ta[l];
	int TC = tc[r + 1] - tc[l];
	int ans = 0, nin;
	// AC
	nin = min(AC, CA);
	ans += nin;
	AC -= nin, CA -= nin;
	
	// AT
	nin = min(TA, AT);
	ans += nin;
	AT -= nin, TA -= nin;
	
	// CT
	nin = min(CT, TC);
	ans += nin;
	CT -= nin, TC -= nin;
	
	if(AT + TA + AC + CA + CT + TC == 0){
		cout << ans;
		return ;
	}
	if(TC != 0 && CA != 0 && AT != 0){
		if(TC != CA || CA != AT){
			cout << -1;
			return ;
		}
		else{
			cout << ans + 2 * TC;
			return ;
		}
	}
	if(CT != 0 && TA != 0 && AC != 0){
		if(CT != AC || AC != TA){
			cout << -1;
			return ;
		}
		else{
			cout << ans + 2 * CT;
			return ;
		}
	}
	cout << -1;
	
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q = 1;
	cin >> n >> q;
	cin >> a >> b;
	for(int i=1; i<=a.size(); ++i){
		ac[i] = ac[i-1] + (a[i-1] == 'A' && b[i-1] == 'C');
		at[i] = at[i-1] + (a[i-1] == 'A' && b[i-1] == 'T');
		ct[i] = ct[i-1] + (a[i-1] == 'C' && b[i-1] == 'T');
		ca[i] = ca[i-1] + (a[i-1] == 'C' && b[i-1] == 'A');
		ta[i] = ta[i-1] + (a[i-1] == 'T' && b[i-1] == 'A');
		tc[i] = tc[i-1] + (a[i-1] == 'T' && b[i-1] == 'C');
	}
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
