//用来判断一个有向图是不是有环
//0 白色，未被访问过的节点标白色 
//- 1 灰色，已经被访问过一次的节点，则标灰色
//1 黑色，当该节点的所有后代都被访问过，则标黑色
bool dfs(int v, vector<vector<int>> &a, vector<int> &vis, int &n, bool &swi) { 
	//从一个顶点出发深度优先遍历。如果第一次访问(u,v)时v为灰色，则(u,v)为反向边。在对图的深度优先搜索中没有发现 反向边，则该图没有回路 　
	vis[v] = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[v][i] != 0 && !vis[i]) {
			dfs(i, a, vis, n, swi);
			vis[i] = 1;
		}
		if (a[v][i] != 0 && vis[i] == -1) {//从一个点出发的时候，发现有一个子节点是被访问过，但是没有访问完所有后代的，那么这时就是存在环
			printf("YES\n");
			swi = true;
			return true;
		}
	}
	return false;
}
