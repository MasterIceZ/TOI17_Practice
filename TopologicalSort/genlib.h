#include <cstdlib>
#include <vector>
#include <ctime>
#include <set>
#include <tuple>
#include <unordered_map>

using namespace std;

namespace util{
	vector<int> sieveoferathos(int l, int r){
		vector<int> ret;
		unordered_map<int, int> mp;
		l = max(2, l);
		for(int i=l; i<=r; ++i){
			if(!mp[i]){
				ret.push_back(i);
				for(int j=i*i; j<=r; j+=i){
					mp[j] = 1;
				}
			}
		}
		return ret;
	}
	bool isPrime(int u){
		if(u <= 1){
			return false;
		}
		if(u <= 3){
			return true;
		}
		if(u % 2 == 0 || u % 3 == 0){
			return false;
		}
		for(int i=5; i*i<=u; i+=6){
			if(u % i == 0 || u % (i + 2) == 0){
				return false;
			}
		}
		return true;
	}
}

void startGen(){
	srand(time(NULL));
}

int rand_int(int l = 1, int r = 10){
	if(l > r){
		return -1;
	}
	return (rand() % (r - l + 1)) + l;
}

string rand_str(int sz=1, char l='a', char r='z'){
	string s;
	for(int i=1; i<=sz; ++i){
		char newchr = (char)rand_int(l, r);
		s += newchr;
	}
	return s;
}

template<typename T> vector<T> rand_perm(vector<T> v){
	random_shuffle(v.begin(), v.end());
	return v;
}

vector<int> rand_perm(int n){
	vector<int> v;
	for(int i=1; i<=n; ++i){
		v.push_back(i);
	}
	return rand_perm(v);
}

template<typename T> T choose(vector<T> v){
	return v[rand_int(0, v.size() - 1)];	
}

int rand_prime(int l=1, int r=100){
	vector<int> v = util::sieveoferathos(l, r);
	return choose(v);
}

set<tuple<int, int>> gen_tree(int n, bool print = true){
	set<tuple<int, int>> s;
	for(int i=2; i<=n; ++i){
		int u = rand_int(1, i - 1), v = i;
		if(u == v){
			continue;
		}
		if(print){
			printf("%d %d\n", u, v);
		}
		s.emplace(u, v);
	}
	return s;
}

set<tuple<int, int>> gen_connected_graph(int n, int m, bool print = true){
	set<tuple<int, int>> s;
	for(int i=1; i<n; ++i){
		if(print){
			printf("%d %d\n", i, i+1);
		}
		s.emplace(i, i + 1);
	}
	while((int)s.size() != m){
		int a = rand_int(1, n), b = rand_int(1, n);
		int u = min(a, b), v = max(a, b);
		if(u == v || s.count(make_tuple(u, v))){
			continue;
		}
		if(print){
			printf("%d %d\n", u, v);
		}
		s.emplace(u, v); 
	}
	return s;
}

set<tuple<int, int>> gen_graph(int n, int m, bool print = true){
	set<tuple<int, int>> s;
	while((int)s.size() != m){
		int a = rand_int(1, n), b = rand_int(1, n);
		int u = min(a, b), v = max(a, b);
		if(u == v || s.count(make_tuple(u, v))){
			continue;
		}
		if(print){
			printf("%d %d\n", u, v);
		}
		s.emplace(u, v);
	}
	return s;
}

set<tuple<int, int>> gen_complete_graph(int n, bool print = true){
	set<tuple<int, int>> s;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			if(print){
				printf("%d %d\n", i, j);
			}
			s.emplace(i, j);
		}
	}
	return s;
}

vector<vector<char>> gen_table(int n, int m, char a, int b, bool print = true){
	vector<vector<char>> t(n + 1, vector<char>(m + 1));
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			int rnd = rand_int(1, 2);
			t[i][j] = rnd % 2 ? a : b;
			if(print){
				printf("%c", t[i][j]);
			}
		}
		if(print){
			printf("\n");
		}
	}
	return t;
}
