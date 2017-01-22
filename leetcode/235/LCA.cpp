//对于BST求LCA
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int hi = p->val > q->val ? p->val : q->val ;
        int lo = q->val + p->val - hi;
        // if ( root == NULL) return NULL;
        // if ( root->val == hi || root->val == lo) return root;
        // if ( root->val >lo && root->val <hi) return root;
        // if ( root->val < lo) return lowestCommonAncestor( root->right,p,q);
        // if ( root->val > hi) return lowestCommonAncestor( root->left,p,q);
		// july是这样写的,这样就不用递归了
		while (true)
		{
			if (root->val < lo)
				root = root->right;
			else if (root->val > hi)
				root = root->left;
			else
				return root;
				
		}
    }
};
