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
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int, int> P;

int main(){
	int n, m;
	while(cin >> n >> m){
		int x, y, k, dx, dy;
		cin >> x >> y >> k;
		ll ans = 0;
		rep(i, k){
			cin >> dx >> dy;
			ll step;
			if(dx > 0 && dy > 0){
				step = min((n - x) / dx, (m - y) / dy);
			}else if(dx > 0 && dy < 0){
				step = min((n - x) / dx, (1 - y) / dy);
			}else if(dx < 0 && dy > 0){
				step = min((1 - x) / dx, (m - y) / dy);
			}else if(dx < 0 && dy < 0){
				step = min((1 - x) / dx, (1 - y) / dy);
			}else if(dx == 0 && dy > 0){
				step = (m - y) / dy;
			}
			else if(dx == 0 && dy < 0){
				step = (1 - y) / dy;
			}
			else if(dx > 0 && dy == 0){
				step = (n - x) / dx;
			}
			else if(dx < 0 && dy == 0){
				step = (1 - x) / dx;
			}
			x += step * dx;
			y += step * dy;
			ans += step;	
			//cout << "step," << step << endl;
		}
		cout << ans << endl;
	}
	return 0;
}