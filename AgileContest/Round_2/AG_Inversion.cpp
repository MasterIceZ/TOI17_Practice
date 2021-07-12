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

int cnt;
int a[10010], b[10010];

const int MOD = 1e9 + 7;

void merges(int l, int r){
	if(l == r){
		return ;
	}
	int mid = (l + r) / 2;
	merges(l, mid);
	merges(mid+1, r);
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}
		else{
			b[k++] = a[j++];
			cnt += mid + 1 - i;
			cnt %= MOD;
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= r){
		b[k++] = a[j++];
	}
	for(int i=l; i<=r; ++i){
		a[i] = b[i];
	}
	return ;
}

void solve(){
	int n;
	cnt = 0;
	for(int i=0; i<=10001; ++i){
		a[i] = i;
	}
	cin >> n;
	for(int i=1, l, r; i<=n; ++i){
		cin >> l >> r;
		if(l > 100000 || r > 10000){
			return ;
		}
		swap(a[l], a[r]);
	}
//	for(int i=1; i<=10; ++i){
//		cout << a[i] << " ";
//	}
	merges(1, 10001);
	cout << cnt;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
