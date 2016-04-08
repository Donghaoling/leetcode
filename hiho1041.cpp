#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define MAX 110
vector<int> child[MAX];
int a[MAX][MAX], order[MAX];
bitset<MAX> reach[MAX];
int ok = 0, seq = 0, n, m;
void canReach(int v) { //判断v可以直接到达的节点，并且存入reach数组中
	reach[v][v] = 1;
	for (int i = 0; i < child[v].size(); ++i) {
		int b = child[v][i];
		if (b != v) {
			canReach(b);
			reach[v] |= reach[b];           //v的孩子能到的点，v都能到
		}
	}
}
void dfs(int v) {
	if (v == order[seq]) {
		seq++;
	}
	if (seq == m) {
		ok = 1;
		return;
	}
	while (seq < m) {//对当前节点，如果order序列还没有搜索完，那么就可以退回来再搜索
		int temp = seq;
		int c = order[seq];
		for (int i = 0; i < child[v].size(); ++i) {//对它的每棵子树
			int b = child[v][i];
			if (b != v) {
				if (reach[b][c] && a[v][b]) {//如果有可达（a[v][b] == 1）的子树包含序列的当前点order[seq]，那么就搜索该子树，同时其他子树就无需再搜索了。
					a[v][b] = 0;
					dfs(b);
					break; //其他的子树就无需再搜索了，直接break
				}
			}
		}
		if (temp == seq) { //没有子树包含序列的当前节点，直接返回
			return;
		}
	}
}
int main() {
	FILE *f;
	freopen_s(&f, "a.txt", "r", stdin);
	int num;
	scanf_s("%d", &num);
	while (num > 0) {
		ok = 0;
		seq = 0;
		scanf_s("%d", &n);
		for (int i = 0; i < MAX; ++i) {
			reach[i].reset();
			child[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int v1, v2;
			scanf_s("%d%d", &v1, &v2);
			a[v1][v2] = 1;
			a[v2][v1] = 1;
			child[v1].push_back(v2);
		}
		scanf_s("%d", &m);;
		for (int i = 0; i < m; ++i) {
			cin >> order[i];
		}
		canReach(1);
		dfs(1);
		if (ok) printf("YES\n");
		else printf("NO\n");
		num--;
	}
	return 0;
}

