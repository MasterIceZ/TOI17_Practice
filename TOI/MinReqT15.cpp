#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define FOE(x, a) for(auto& x : a)
const int mxN = 11, mxM=1e7+10;
int n,m,q,l[mxN],a[mxN],qs[mxM],qry[mxN],pos[mxN];

bool check(int t) {
	vector<bool> mk(n+1, false);
	for(int i=1,j; i<=n; ++i) { //group student
		for(j=1; j<=n; ++j) { // choose lift
			if(mk[j]) continue;
			int lb = pos[i], rb=pos[i+1],cnt=0,ch=1;
			while(lb<rb&&ch) {
				++cnt;
				int nx = upper_bound(qs+lb, qs+rb, l[j]-a[i]+qs[lb-1])-qs;
				if(nx==lb) ch=0;
				lb=nx;
			}
			if(ch&&cnt<=t) {mk[j]=1;break;}
		}
		if(j==n+1) return 0;
	}
	return 1;
}
bool solve(int t) {
	for(int i=1; i<=n; ++i)
		cin >> pos[i];
	pos[n+1]=m;
	do {
		if(check(t)) return 1;
	}while(next_permutation(a+1, a+1+n));
	return 0;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i)
		cin >> l[i];
	for(int i=1; i<=n; ++i)
		cin >> a[i];
	for(int i=1; i<=m; ++i)
		cin >> qs[i], qs[i]+=qs[i-1];
	for(int i=1; i<=q; ++i)
		cin >> qry[i];
	sort(l+1, l+1+n);
	for(int i=1; i<=q; ++i)
		cout << (solve(qry[i])?"P":"F") << "\n";
	return 0;
}

