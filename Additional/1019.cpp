/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: DNA
 * ALGO		: Dynamic Programming
 * DATE		: 20 July 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

char s[222], t[222];
int dp[222][222];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> (s + 1) >> (t + 1);
	stack<char> st;
	int pos, nax = 0;
	int lens = strlen(s + 1), lent = strlen(t + 1);
	for(int i=1; i<=lens; ++i){
		for(int j=1; j<=lent; ++j){
			if(s[i] == t[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > nax){
					pos = i;
					nax = dp[i][j];
				}
			}
		}
	}
	while(nax--){
		st.push(s[pos--]);
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
	cout << endl;
	return 0;
}
