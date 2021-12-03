#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int SZ = 1e6 + 3;

struct HSH{
	ll mp[SZ], keep[SZ];
	void insert(ll key, ll val){
		ll k = key % SZ;
		mp[k] = val;
		keep[k] = key;
	}
	ll read(ll key){
		ll k = k % SZ;
		return mp[k];
	}
} mp;

int len;
char s[20020];

ll conv(char s){
	if(s == 'A'){
		return 2;
	}
	if(s == 'T'){
		return 1;
	}
	if(s == 'C'){
		return 4;
	}
	return 3;
}

ll change(){
	ll curr = 0;
	for(int i=0; i<len; ++i){
		curr *= 7;
		curr += conv(s[i]);
		curr %= SZ;
	}
	return curr;
}

void solve(){
	int n;
	scanf("%d", &n);
	scanf(" %s", s);
	len = strlen(s);
	ll h = change();
	mp.insert(h, 1);
	for(int i=2; i<=n; ++i){
		scanf(" %s", s);
		ll now = change();
		mp.insert(now, i);
	}
	while(scanf(" %s", s)){
		if(s == NULL){
			return ;
		}
		ll cur = 0;
		for(int i=0; i<len; ++i){
			cur *= 7;
			cur += s[i];
			cur %= SZ;
		}
		int now = mp.read(cur);
		printf("%s\n", now ? "YES": "NO");
	}
	return ;
}

int main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
//		cout << endl;
	}
	return 0;
}
