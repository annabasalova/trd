#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key - сколько меньше
//find_by_order - элемент под номером

auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937_64 gen(seed);

int get_random(){
    std::uniform_int_distribution<int> dist(33, 126);
    return dist(gen);
}

std::istream& operator >> (std::istream& in, pii& p)
{
    in >> p.fi >> p.se;
    return in;
}

std::ostream& operator << (std::ostream &os, const pii &p)
{
    return os << p.fi << " " << p.se;
}

void solve() { }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_cnt = 1;
    cin >> test_cnt;

    while (test_cnt--) {
        solve();
    }
}
