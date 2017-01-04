#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cc system("pause");
typedef struct
{
	// int pid;
	int l,r;
	long long  sum;
	long long lazy_tag;
//}nodes[100];
}Tree;
Tree nodes[10000000];

long long v[100005];

void segtreeBuild(int p, int l, int r)
{
	nodes[p].l = l;
	nodes[p].r = r;
	nodes[p].lazy_tag = 0;

	if (l == r) 
	{
		nodes[p].sum = v[l];//输入数组的值
		return;//没写为什么没报错啊
	}
	// if (l<r) 
	// {
		int mid = (l+r) >>1;
		segtreeBuild(p<<1 ,l,mid);
		segtreeBuild(p<<1 | 1, mid+1,r);
	// }
	nodes[p].sum = nodes[p<<1].sum + nodes[p<<1|1].sum;
}

void insert(int p, int x, int y, long long num)
{
	if( nodes[p].l >= x && nodes[p].r <=y ) //如果要插入的区间完全包含左右孩子
	{
		nodes[p].lazy_tag += num; //只要加个lazytag
		// printf("**step=%d\n",step);
		// printf("**store=%d\n",tree[step].store);
		// printf("**sum=%d\n\n",tree[step].sum);
		return;
	}
	else if( nodes[p].l >= x && nodes[p].r >= y ) //包含了左孩子(区间左端点)但是没到右孩子
	{
		nodes[p].sum += (y - nodes[p].l +1) *num;
	}
	else if( nodes[p].l <= x && nodes[p].r <= y) // 过了左端点 包含右端点 nodes[p]=[6,10], [x,y] = [1,7]
	{
		nodes[p].sum += ( nodes[p].r - x + 1)*num;
	}
	else if( nodes[p].l <=x && nodes[p].r >= y ) //在左右端点之间
	{
		nodes[p].sum += (y-x+1) * num;
	}
	int mid = (nodes[p].l + nodes[p].r) >>1;
	if( mid >= x)
	{
		insert(p<<1,x,y,num);
	}
	if( mid+1 <=y )
	{
		insert(p<<1|1,x,y,num);
	}
}

long long sum;
void search(int p, int x, int y)
{
	if( nodes[p].l >= x && nodes[p].r <= y )
	{
		sum += (nodes[p].sum + (nodes[p].r-nodes[p].l+1)*nodes[p].lazy_tag);
		return;
	}
	else
	{
		nodes[p<<1].lazy_tag += nodes[p].lazy_tag;
		nodes[p<<1|1].lazy_tag += nodes[p].lazy_tag;
		nodes[p].sum += ((nodes[p].r-nodes[p].l + 1 ) * nodes[p].lazy_tag);
		nodes[p].lazy_tag = 0;
	}
	int mid = (nodes[p].l + nodes[p].r) >>1;
	if( mid >= x)
	{
		search(p<<1,x,y);
	}
	if( mid+1 <=y )
	{
		search(p<<1|1,x,y);
	}
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);//输入线段长度和问题个数
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
		}
		segtreeBuild(1,1,n);
		while(q--)
		{
			char ch;
			int a,b;
			long long c;
			getchar();
			scanf("%c%d%d",&ch,&a,&b);
			if(ch == 'Q')
			{
				sum = 0;
				search(1,a,b);
				printf("%lld\n",sum);
			}
			else
			{
				scanf("%lld",&c);
				insert(1,a,b,c);
			}
		}
	}
}
