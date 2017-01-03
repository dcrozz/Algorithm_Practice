//指针表示
struct treeNode
{
	Data data;
	treeNode *lson, *rson;
} *root;
//数组表示
struct treeNode
{
	Data data;
	int pid;
	int lson(){return pid << 1;}
	int rson(){return pid << 1 | 1;}
}nodes[ MAXNODES ];

//构造线段树
void segtree_build(int p, int l, int r)
{
	nodes[p].reset(p, l, r); // 初始化第p个节点的数据域，根据实际情况实现reset函数
	if( l < r )
	{
		int mid = ( l + r ) >> 1;
		segtree_build( p << 1, l, mid );
		segtree_build( p << 1 | 1, mid + 1, r );
		nodes[p].updateFromSon(); //回溯，利用左右节点信息来更新当前节点,updateFromSon这个函数的实现需要根据实际情况进行求解
	}
}

//更新
void segtree_insert( int p, int l, int r, int x, int y, ValueType val )
{
	if( !is_intersect(l, r, x, y) )
	{
		return;
	}
	if( is_contain(l, r, x, y) )
	{
		nodes[p].updateByValue(val);
		return ; 
	}
	nodes[p].giveLazyToSon();
	int mid = (l + r) >> 1;
	segtree_insert( p << 1, l, mid, x, y, val );
	segtree_insert( p << 1 | 1, mid +1, r, x, y, val );
	nodes[p].updateFromSon();
}

void segtree_query(int p, int l, int r, int x, int y, treeNode * ans)
{
	if( !is_intersect(l, r, x, y) )
	{
		return;
	}
	if( is_contain( l,r,x,y ) )
	{
		ans.mergeQuery(p);
		return;
	}
	nodes[p].giveLazyToSon();
	int mid = (l + r) >> 1;
	segtree_query( p << 1, l, mid, x, y, ans );
	segtree_query( p << 1 | 1, mid + 1, r, x, y, ans );
	nodes[p].updateFromSon();
}


