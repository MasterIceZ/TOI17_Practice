/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: PT_MeanMax
 * ALGO		: Binary Search
 * DATE		: 31 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

const double offset = 1e-6;
const int MxN = 300301;

double qs[MxN], a[MxN], qsmn[MxN], l, r;

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	l = 0, r = 1e6;
	while(r - l > offset){
		bool ok = false;
		double mid = (l + r + (offset)) / 2;
		for(int i=1; i<=n; ++i){
			qs[i] = qs[i-1] + a[i] - mid;
			qsmn[i] = min(qs[i], qsmn[i-1]);
			if(i>=k && qs[i] - qsmn[i - k] >= 0){
				ok = true;
			}
		}
		if(ok){
			l = mid;
		}
		else{
			r = mid - (offset);
		}
	}
	cout << fixed << setprecision(1) << r;
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
