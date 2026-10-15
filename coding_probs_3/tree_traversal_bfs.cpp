//https://algo.monster/liteproblems/102

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> levelorder(TreeNode * root){
  vector<vector<int>> result;
  queue<TreeNode*> nodequeue;
  nodequeue.push(root);

  while(!nodequeue.empty()){
    vector<int> currentlevel;
    int levels = nodequeue.size();
    for(int i=0;i<level;i++){
      TreeNode *node = nodequeue.front();
      nodequeue.pop();
      currentlevel.push_back(nodequeue->val);

      if(node->left)
        nodequeue.push(node->left);
      if(node->right)
        nodequeue.push(node->right);    
    }
    result.push_back(currentlevel);
  }
  return result;
}