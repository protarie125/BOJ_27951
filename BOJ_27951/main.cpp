#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto hs = vi(n);
	auto h1 = int{ 0 };
	auto h2 = int{ 0 };
	auto h3 = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		cin >> hs[i];

		if (1 == hs[i]) {
			++h1;
		}
		else if (2 == hs[i]) {
			++h2;
		}
		else {
			++h3;
		}
	}

	int u, d;
	cin >> u >> d;

	h1 -= min(u, h1);
	h2 -= min(d, h2);

	if (0 < h1 || 0 < h2) {
		cout << "NO";
		return 0;
	}

	auto now = n;
	auto ans = vector<char>(n);
	auto h3s = vi{};
	for (auto i = 0; i < n; ++i) {
		if (1 == hs[i]) {
			ans[i] = 'U';
			--u;
		}
		else if (2 == hs[i]) {
			ans[i] = 'D';
			--d;
		}
		else {
			h3s.push_back(i);
		}
	}

	while (0 < u || 0 < d) {
		for (const auto& idx : h3s) {
			if (0 < u) {
				ans[idx] = 'U';
				--u;
			}
			else {
				ans[idx] = 'D';
				--d;
			}
		}
	}

	cout << "YES\n";
	for (const auto& c : ans) {
		cout << c;
	}

	return 0;
}