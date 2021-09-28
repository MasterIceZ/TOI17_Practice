/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Modern Dictionary
 * ALGO		: Kahn's Algorithm
 * DATE		: 28 Sep 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int in[111], ok[111];
vector<int> adj[30];

int to_num(char s){
	return s - 'a';
}

char to_char(int x){
	return x + 'a';
}

void solve(){
	int n;
	cin >> n;
	set<char> st;
	string word, word2;
	cin >> word;
	if(n == 1){
		cout << "?";
		return ;
	}
	for(auto x: word){
		st.insert(x);
	}
	dbg(st.size());
	for(int i=2; i<=n; ++i){
		cin >> word2;
		for(int j=0; j<min(word.size(), word2.size()); ++j){
			if(word[j] != word2[j]){
				adj[to_num(word[j])].push_back(to_num(word2[j]));
				in[to_num(word2[j])]++;
				ok[to_num(word[j])] = ok[to_num(word2[j])] = 1;
				break;
			}
		}
		for(int j=0; j<word2.size(); ++j){
			st.insert(word2[j]);
		}
		word = word2;
	}
	queue<int> q;
	for(set<char>::iterator it=st.begin(); it != st.end(); ++it){
		if(in[to_num(*it)] == 0 && ok[to_num(*it)]){
			q.push(to_num(*it));
		}
	}
	queue<int> ans;
	while(!q.empty()){
//		d(q);
		if(q.size() != 1){
			cout << "?";
			return ;
		}
		int now = q.front();
		q.pop();
		ans.push(now);
		for(auto x: adj[now]){
			if(--in[x] == 0){
				q.push(x);
			}
		}
	}
	if(ans.size() != st.size()){
		cout << "!";
		return; 
	}
	while(!ans.empty()){
		cout << to_char(ans.front()); 
		ans.pop();
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
