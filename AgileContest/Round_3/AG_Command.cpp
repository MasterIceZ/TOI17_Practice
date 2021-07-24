/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: AG_Command
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

void solve(){
	int t, n;
	cin >> t >> n;
	if(t == 1){
		cout << "ACVVVACVVV";
	}
	else if(t == 2){
//		cout << "ACVVVVVVACVVVVV";
		cout << "ACVVVVVACVVVVVV";
	}
	else if(t == 3){
		for(int i=1; i<=3; ++i){
			cout << "ACVVVVVVVV";
		}
	}
	else if(t == 4){
		cout << "ACVVVVVVVVVVVVVVVVVVVVVVVACVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	}
	
	else if(t == 5){
		cout << "ACVVVVVV";
		cout << "ACVVVVVV";
		cout << "ACVVVACVVV";
		cout << "ACVVVVVAC";
		for(int i=1; i<=31; ++i){
			cout << "V";
		}
	}
	else if(t == 7){
		cout << "ACVVAC";
		for(int i=1; i<=254197; ++i){
			cout << "V";
		}
	}
	else if(t == 10){
		cout << "ACVVVVV";
		cout << "ACVVVVVVV";
		cout << "AC";
		for(int i=1; i<=27017; ++i){
			cout << "V";
		}
	}
	else if(t == 12){
		for(int i=1; i<=15; ++i){
			cout << "ACVVV";
		}
	}
	else{
		cout << "AC";
		for(int i=1; i<=353; ++i){
			cout << "V";
		}
		cout << "AC";
		for(int i=1; i<=353; ++i){
			cout << "V";
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
