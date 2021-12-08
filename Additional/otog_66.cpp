#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const int MxN = 200200;
int a[MxN], b[MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		if(a[i] * 2 >= a[n]){
			break;
		}
		cnt++;
	}
	int cnt2 = 0, j = 1;
	for(int i=n; i>=1; --i){
		if(a[1] * 2 >= a[i]){
			break;
		}
		cnt2++;
	}
	cout << min(cnt, cnt2);
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
