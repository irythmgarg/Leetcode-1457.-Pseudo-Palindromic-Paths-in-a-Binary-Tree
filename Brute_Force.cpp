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
    /**
     * Helper function to check if the current frequency array can form a palindrome.
     * A path can be rearranged into a palindrome if at most one value has an odd frequency.
     */
    bool check_palindrome(vector<int> arr) {
        int odds = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                odds++;
                if (odds > 1)
                    return false;  // More than one odd count – not a pseudo-palindrome
            }
        }
        return true;  // At most one odd count – pseudo-palindrome is possible
    }

    int ans = 0;  // Global counter for pseudo-palindromic paths

    /**
     * Recursive DFS function to explore all root-to-leaf paths and update count if path is pseudo-palindromic.
     * 
     * @param root Current node being visited
     * @param arr Frequency array storing the count of digits (1 to 9) in the current path
     */
    void takesum(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;

        // Increment frequency of current node's value
        arr[root->val]++;

        // If it's a leaf node, check if the path is pseudo-palindromic
        if (!root->left && !root->right) {
            if (check_palindrome(arr))
                ans++;
            arr[root->val]--;  // Backtrack before returning
            return;
        }

        // Recurse to left and right children
        takesum(root->left, arr);
        takesum(root->right, arr);

        // Backtrack: remove current node's value from frequency array
        arr[root->val]--;
    }

    /**
     * Main function to initiate DFS and return total count of pseudo-palindromic paths.
     * 
     * @param root Root of the binary tree
     * @return Number of pseudo-palindromic root-to-leaf paths
     */
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root)
            return 0;
        vector<int> arr(10, 0);  // Frequency array for digits 1 to 9
        takesum(root, arr);
        return ans;
    }
};
