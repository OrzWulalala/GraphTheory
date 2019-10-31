
void Dijkstra() 
{
	//memset(visited,0,sizeof(visited);
	///初始化dist和pre,起始点到各顶点i的距离
	for (int i = 1; i <= n; i++) {
		dist[i] = e[s][i];
		pre[i] = s; ///s-->i
	}
	visited[s] = 1;
	for (int i = 2; i <= n; i++) {
		int min = INF, u;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && dist[i] < min) {
				min = dist[i];
				u = i;
			}
		}
		visited[u] = 1;
		///遍历u的邻接顶点，更新dist
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && dist[u] + e[u][i] < dist[i]) {
				dist[i] = dist[u] + e[u][i];
				pre[i] = u;
			}
		}
	}
	printf("%d\n", dist[t]);
 
}
