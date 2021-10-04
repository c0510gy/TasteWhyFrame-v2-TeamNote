#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <complex>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

class RabinKarp {
public:
	int n;
	string str;
	int mod = 10003;

	RabinKarp(string s) {
		str = s;
		n = str.length();
	}

	bool solve(int len) {
		vector<vector<int>> v(mod);
		int h = 0;
		int pow2 = 1;
		for (int i = len - 1; i >= 0; i--) {
			h = (h + (str[i] * pow2) % mod) % mod;
			if (i > 0) pow2 = (pow2 * 2) % mod;
		}
		v[h].push_back(0);
		for (int i = 1; i <= n - len; i++) {
			h = (h - (pow2 * str[i - 1]) % mod + mod) % mod;
			h = (h * 2) % mod;
			h = (h + str[i + len - 1]) % mod;
			for (int p : v[h]) {
				bool eq = true;
				for (int j = 0; j < len; j++) {
					if (str[p + j] != str[i + j]) {
						eq = false;
						break;
					}
				}
				if (eq) return true;
			}
			v[h].push_back(i);
		}
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	RabinKarp r = RabinKarp(s);
	int lo = 1, hi = s.length();
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (r.solve(mid)) lo = mid + 1;
		else hi = mid;
	}
	cout << lo - 1;

	return 0;
}
