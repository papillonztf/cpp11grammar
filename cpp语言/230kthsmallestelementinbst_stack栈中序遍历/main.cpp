#include<stack>
 
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //基于stack适配器非递归中序：时间、空间复杂度均为O(k)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> tempStack;
        TreeNode* tempNodePtr=root;
        int ret=0;
        while((!tempStack.empty())||tempNodePtr){
            while(tempNodePtr){
                tempStack.push(tempNodePtr);
                tempNodePtr=tempNodePtr->left;
            }

            tempNodePtr=tempStack.top()->right;
            if(!(--k))
              ret=tempStack.top()->val;
            tempStack.pop();
        }
        return ret;
        
    }
};
