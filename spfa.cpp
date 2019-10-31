void spfa(int start) 
{
	memset(dis,INF,sizeof dis);
	queue<int> q;
	q.push(start);
	dis[start]=0;
	vis[start]=1;
	while(!q.empty()) 
	{
		int cur = q.front();
		q.pop();
		vis[cur]=0;
		int up = vv[cur].size();
		for(int i = 0; i<up; i++) 
		{
			Edge now = vv[cur][i];
			int to = now.to;
			if(dis[to] > dis[cur] + now.w)
			{
				dis[to] = dis[cur]+now.w;
				if(vis[to] == 0) vis[to]=1,q.push(to);
			}
		}
	}
}
