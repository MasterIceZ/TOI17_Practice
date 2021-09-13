#include<bits/stdc++.h>
using namespace std;

const int MxN = 1e6 + 10;
int a[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	while(k--){
		int cou = 0, ptr = 1;
		for(int i=1, x; i<=m; ++i){
			cin >> x;
			if(ptr > n){
				continue;
			}
			while(ptr <= n && a[ptr] < x - l){
				ptr += 1;
			}
			if(ptr > n){
				continue;
			}
			while(ptr <= n && a[ptr] <= x + l){
				ptr += 1;
				cou += 1;
			}
		}
		cout << cou << "\n";
	}
	return 0;
}
