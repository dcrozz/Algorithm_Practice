int MaxDistance()
{
	if(_root == NULL) return 0;
	int max = 0;
	_MaxDistance( _root, max );
	return max;
}

int _MaxDistance(Node * cur, int & max) //只返回深度
{
	if(cur== NULL) return 0;
	int leftDepth = _MaxDistance(cur->left,max);
	int rightDepth = _MaxDistance(cur->right,max);
	if( leftDepth + rightDepth > max )
		max = leftDepth + rightDepth;
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
