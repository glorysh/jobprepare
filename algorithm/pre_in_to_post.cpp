#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, pre[maxn], in[maxn];
vector<int> ans;

void dfs(int pb, int pe, int ib, int ie) {
    if (pb > pe) return;
    int val = pre[pb];
    int i;
    for (i = ib; i <= ie; ++i) {
        if (in[i] == val) 
            break;
    }
    ans.push_back(val);
    dfs(pb + i - ib + 1, pe, i + 1, ie);
    dfs(pb + 1, pb + i - ib, ib, i - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> pre[i];
    for (int i = 0; i < n; ++i) cin >> in[i];
    dfs(0, n - 1, 0, n - 1);
    for (int i = n - 1; i >= 0; --i) cout << ans[i] << " ";
}