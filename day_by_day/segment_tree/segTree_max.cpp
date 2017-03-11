struct treeNode{
	// int data;
	int pid;
	int lson(){ return pid << 1; }
	int rson(){ return pid << 1 | 1; }
	int l,r;
	int max;
}nodes[100];

void treeNode::reset( int p, int l, int r )
{
	pid = p;
	max = srcArray[l];
}

void treeNode::updateByValue(int val)
{
	max = val;
}

void treeNode::mergeQuery(int p)
{
	// max = max(nodes[p].l,nodes[p].r);
	max = getmax( max, nodes[p].max );// 这边的max,nodes[p].max值不是一样的吗， 只是为了后面的updateFromSon才这样写的吗
	
}

void treeNode::updateFromSon()
{
	max = nodes[lson()].max;
	mergeQuery(rson());
}

void segtree_build(int p,int l, int r)
{
	//遍历到p，注意是数组，直接初始化
	nodes[p].reset(p,l,r);
	if ( l < r )
	{
		mid = (l + r) >> 1;
		// segtree_build( (l+r)<< 1,l,mid );
		// segtree_build( (l+r)<< 1 | 1, mid+1 ,r);
		// 是数组编号*2
		segtree_build( p << 1,l,mid );
		segtree_build( p << 1 | 1, mid+1 ,r);
		nodes[p].updateFromSon();// 这里是算sum
	}
}

void segtree_update(int p, int l, int r, int x, int y, int val) // 比如全部加一个val
{
	if ( !is_intersect(l,r,x,y)) return;
	// else //这边的else完全是多写的 很蠢
	// {
		if (is_contain(l,r,x,y)) //x,y 包含 l,r 
		{
			nodes[p].updateByValue(val);
		}
		// else // 不管包不包含都要往下遍历的
		// {
			nodes[p].giveLazyToSon(); //加一个lazy tag
			mid = (l+r) >> 1;
			segtree_update(p<<1,l,mid,x,y,val);
			segtree_update(p<<1 | 1,mid+1,x,y,val);
			nodes[p].updateFromSon(); //孩子节点回溯

		}
	// }
}

void segtree_query(int p, int l, int r, int x, int y, treeNode * ans)// ans 用来保存得到的结果
{
	if( !is_contain(l,r,x,y) ) return;
	if( is_contain(l,r,x,y) )
	{
		// nodes[p].
		ans.mergeQuery(p);//更新当前解
		return;
	}
	nodes[p].giveLazyToSon();
	mid = (l+r) >> 1;
	segtree_update(p<<1,l,mid,x,y,ans);
	segtree_update(p<<1 | 1,mid+1,r,x,y,ans);
	nodes[p].updateFromSon(); //孩子节点回溯
}

