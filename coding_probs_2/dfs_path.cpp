#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x):value(x){
        left = right = nullptr;
    }
};

class Solution{
    private:
        int maxSum;
        int dfs(TreeNode* node){
            if(node == nullptr) return 0;

            int leftSum = max(0,dfs(node->left));
            int rightSum = max(0,dfs(node->right));
            maxSum = max(maxSum, node->value+leftSum+rightSum);
            cout << "max sum is" << maxSum << "for node with value" << node->value << endl;

            return node->value + max(leftSum, rightSum);
        }
    public:
        int maxPathSum(TreeNode* root) {
            maxSum = INT_MIN;
            dfs(root);
            return maxSum;
        }

};

int main()
{
    Solution obj;
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int maxSum = obj.maxPathSum(root);
    cout << "Maximum Path Sum: "<< maxSum << endl;
    return 0;
}