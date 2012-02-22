#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <cstring>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define SORT(__a) sort(__a.begin(), __a.end())
#define RSORT(__a) sort(__a.rbegin(), __a.rend())
#define INF INT_MAX
#define VS vector<string>
#define VI vector<int>
#define PB push_back
#define clr(__v,__x) memset(__v, __x, sizeof __v);
#define rep(i, n) FOR(i,0,n)
#define all(a) a.begin(), a.end()

const double PI  = acos(-1.0);
const int MOD = 1000000007;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int, int> P;

int main(){
	int n, m;
	while(cin >> n >> m){
		ll ans = 1;
		string in[101];
		rep(i, n) cin >> in[i];
		rep(i, m){
			set <char> s;
			rep(j, n){
				s.insert(in[j][i]);
			}
			ans *= s.size();
			cout << ans << endl;
			if(ans >= MOD) ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}