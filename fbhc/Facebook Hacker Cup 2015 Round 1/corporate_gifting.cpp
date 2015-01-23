#include <assert.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// Each subtree is associated with a SubSolution.
struct SubSolution {
	long long
		ideal_root_value, // ideal gift cost for root of this subtree.
		ideal_total,      // tree total if root gets to be ideal_root_value.
		secondary_total;  // best total if root can't be ideal_root_value.
};

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector< vector<int> > childrenof(N);
		for (int i = 0; i < N; i++) {
			int m;
			cin >> m;
			if (m != 0)
				childrenof[m-1].push_back(i);
		}

		vector<int> nodes;
		nodes.push_back(0);
		for (int i = 0; i < nodes.size(); i++) {
			for (auto child : childrenof[nodes[i]])
				nodes.push_back(child);
		}

		reverse(nodes.begin(), nodes.end());

		assert(nodes.size() == N);
		assert(nodes.back() == 0);
		assert(childrenof[nodes.front()].size() == 0);

		vector<SubSolution> cache(N);

		for (auto node : nodes) {
			long long max_ideal_child_value = 0;
			for (auto child : childrenof[node]) {
				max_ideal_child_value = max(
					max_ideal_child_value,
					cache[child].ideal_root_value);
			}

			cache[node].ideal_total = LLONG_MAX;
			cache[node].secondary_total = LLONG_MAX;
			for (
					long long node_value = 1;
					node_value <= max_ideal_child_value+2;
					node_value++) {

				long long total = node_value;

				for (auto child : childrenof[node]) {
					total +=
						node_value != cache[child].ideal_root_value ?
							cache[child].ideal_total :
							cache[child].secondary_total;
				}

				if (total < cache[node].ideal_total) {
					cache[node].secondary_total = cache[node].ideal_total;
					cache[node].ideal_root_value = node_value;
					cache[node].ideal_total = total;
				} else if (total < cache[node].secondary_total) {
					cache[node].secondary_total = total;
				}
			}
		}

		assert(cache[nodes.front()].ideal_root_value == 1);
		assert(cache[nodes.front()].ideal_total == 1);
		assert(cache[nodes.front()].secondary_total == 2);

		cout << "Case #" << t << ": " << cache[0].ideal_total << endl;
	}
}
