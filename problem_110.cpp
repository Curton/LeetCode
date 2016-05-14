/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Code by covey
class Solution{
public:
    // subfunction of isBalanced
    // return -1: imbalance
    // return 0/1: balance
    int isBalanced_(TreeNode *root)
    {
        // null case
        if(root == NULL)
        {
            return 0;
        }
        // not null, search two part
        int leftPart  = isBalanced_(root->left);
        int rightPart = isBalanced_(root->right);
        // check if two part imbalance
        if(leftPart == -1 || rightPart == -1 || (leftPart-rightPart > 1 ) || (leftPart-rightPart < -1) )
        {
            /*
             * depth different between two part >1
             * one of part had imbalance
             * return imbalance
             */
            return -1;
        }
        if(leftPart - rightPart < 0)
        {
            // right part heavy
            return ++rightPart;
        }
        else
        {
            // left paet heavey or same
            return ++leftPart;
        }
    }

    bool isBalanced(TreeNode *root)
    {
        if(root == NULL)
        {
            // empty tree is balance
            return true;
        }
        else
        {
            return (isBalanced_(root) != -1);
        }
    }
};
// Code by covey