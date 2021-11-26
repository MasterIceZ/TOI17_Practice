#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == 1){
				cout << "x";
			}
			else if(j == n / 2 + 1){
				cout << "x";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(j == 1 || j == n || i == n){
				cout << "x";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(j == 1 || j == n){
				cout << "x";
			}
			else if(i == j && i <= n / 2 + 1){
				cout << "x";
			}
			else if(i <= n / 2 + 1 && i + j == 1 + n){
				cout << "x";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(i == 1 || i == n / 2 + 1 || i == n){
				cout << "x";
			}
			else if(i < n / 2 + 1 && j == 1){
				cout << "x";
			}
			else if(i > n / 2 + 1 && j == n){
				cout << "x";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(i == 1 || j == 1 || i == n || j == n){
				cout << "x";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(j == n / 2 + 1){
				cout << "*";
			}
			else if(i == n){
				cout << "*";
			}
			else if(i + j == n / 2 + 2){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << "  ";
		for(int j=1; j<=n; ++j){
			if(i == 1 || i == n / 2 + 1 || i == n){
				cout << "*";
			}
			else if(i < n / 2 + 1 && j == 1){
				cout << "*";
			}
			else if(i > n / 2 + 1 && j == n){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
