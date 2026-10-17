class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> smallestInt;
        queue<TreeNode*> toProcess;

        toProcess.push(root);

        while(!toProcess.empty()) {
          TreeNode* curr = toProcess.front();
          toProcess.pop();
          if(curr == nullptr) continue;
          int currVal = curr->val;
          if(smallestInt.size() < k) smallestInt.push(currVal);

          else if(currVal < smallestInt.top()) {
            smallestInt.pop();
            smallestInt.push(currVal);
          }          
            toProcess.push(curr->left);
            toProcess.push(curr->right);
        }
        return smallestInt.top();
    }
};
