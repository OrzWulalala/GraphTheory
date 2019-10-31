/*
kruskal板子
*/
struct edge
{
	int u;
	int v;
	int dis;
}e[N+10];

int find_father(int x)//找集体老大，并查集的一部分 
{
	if(f[x]!=x)f[x] = find_father(f[x]);
	return f[x];
}
void Union(int x,int y)//加入团体，并查集的一部分 
{
	f[father(y)]=find_father(x);
}
int main()
{
	scanf("%d%d",&n,&m);//输入点数，边数 
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].dis);//输入边的信息 
	}
	for(int i=1;i<=n;i++) fat[i]=i;//自己最开始就是自己的老大 （初始化） 
	sort(e1,e+1+m,cmp);//按权值排序（kruskal的体现） 
	for(int i=1;i<=m;i++)//从小到大遍历 
	{
		if(k==n-1) break;//n个点需要n-1条边连接 
		if(find_father(e[i].u)!=find_father(e[i].v))//假如不在一个团体 
		{
			Union(e[i].u,e[i].v);//加入 
			tot+=e[i].dis;//记录边权 
			k++;//已连接边数+1 
		}
	}
	printf("%d",tot);
	return 0;
}
