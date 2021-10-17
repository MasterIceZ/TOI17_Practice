#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int a[55][55];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	if(n <= 5 && m <= 5){
		set<int> s;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				s.insert(a[i][j]);
			}
		}
		cout << (s.size() >= 5) << "\n";
		return 0;
	}	
	int cnt = 0;
	for(int i=1; i<=n-4; ++i){
		for(int j=1; j<=m-4; ++j){
			set<int> s;
			for(int k=i; k<=i + 4; ++k){
				for(int l=j; l<=j+4; ++l){
					s.insert(a[k][l]);
				}
			}
			cnt += (s.size() >= 5);
		}
	}
	cout << cnt << "\n";
	return 0;
}
