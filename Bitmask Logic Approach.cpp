/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;               // Value of the node (1 to 9)
    TreeNode *left;        // Left child pointer
    TreeNode *right;       // Right child pointer

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;  // Counter to keep track of valid pseudo-palindromic paths

    /**
     * Recursive DFS function that uses a bitmask to track odd/even frequencies of digits.
     * 
     * @param root Current node being visited
     * @param val Bitmask representing parity of counts (odd/even) for digits 1-9
     */
    void takesum(TreeNode* root, int val) {
        if (!root)
            return;

        // Toggle the bit corresponding to the current node's value
        val = val ^ (1 << root->val);

        // If it's a leaf node, check if at most one bit is set in the bitmask
        if (!root->left && !root->right) {
            if ((val & (val - 1)) == 0)  // Only one or zero bits are set
                ans++;
            return;
        }

        // Recur to left and right children with updated bitmask
        takesum(root->left, val);
        takesum(root->right, val);
    }

    /**
     * Main function that initializes recursion and returns result.
     * 
     * @param root Root of the binary tree
     * @return Total number of pseudo-palindromic root-to-leaf paths
     */
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root)
            return 0;
        int count = 0;  // Initial bitmask value
        takesum(root, count);
        return ans;
    }
};
