/*
 > 本质:
    二叉树遍历+计算依赖
 > 延伸:
    求根到叶子结点数字之和就是记录路径,如1234--->1-2-3-4
 > 思路&&效率分析:
    V1.0:基于stack<pair<TreeNode,int>>的DFS
        a.一个K层的满二叉数,BFS要2^(K-1)遍入栈递进,2^(K-1)-1遍出栈递退.
          共计2^k-1次push元素操作,2^K-1-1pop元素操作
          如4层满二叉数,4遍入栈3遍出栈,15次push,14次pop
        b.需要各结点的sum,以便换边时可用
    V1.1:基于递归的DFS
        a.相对于v1.0,不需要保存各节点的sum
    V2.0:基于deque<pair<TreeNode,int>>BFS
        a.对于4层满二叉数,4遍入栈,3遍出栈;2^4-1次push操作,2^4-1-2^3次pop
          显然,相比DFS,BFS效率更高
        b.只需保存上层元素的sum.
 

 * */



#include<iostream>
#include<stack>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
     

        
        /*V1.0*/
        stack<pair<TreeNode*,int>> nodePairStack;//存指针:注意指针失效和指针本意
        int sum = 0;
        TreeNode* curNodePtr = root;
        int i = 0;
        if (root != nullptr){
            while ((nodePairStack.empty() == false)
                  || (curNodePtr != nullptr)) {
                //左链深度递进子结构:while中push的范围[root,最后一个结点]。
                while(curNodePtr != nullptr) {
                    sum = sum*10+curNodePtr->val;
                    nodePairStack.push(make_pair(curNodePtr, sum));
                    curNodePtr = curNodePtr->left;
                }

                //换边操作:两种方式，一是基于现有的内存while一遍一遍去找到非空右子树；二是再新建一个while直到pop到非空的右子树
                if(nodePairStack.empty() != true) {
                    curNodePtr=nodePairStack.top().first;
                    if((curNodePtr ->left == nullptr) //叶子结点
                        && (curNodePtr->right == nullptr)) {
                        i += nodePairStack.top().second;
                    }
                    
                    curNodePtr=nodePairStack.top().first->right;
                    if(curNodePtr != nullptr) {
                        sum = nodePairStack.top().second;
                    
                    }
                    nodePairStack.pop();
                }
            }
        }
        else 
          i=0;
        return i;

       /*//v1.1:基于前序遍历与元素sum分离
        stack<TreeNode*> nodeStack;
        int sum=0;
        bool isPop=false;
        TreeNode* curNodePtr = root;
        while(nodeStack.empty() !=0 
            ||curNodePtr != nullptr) {
            while(curNodePtr != nullptr) {
                nodeStack.push(curNodePtr);
                curNodePtr=curNodePtr->left;
            }
            if(nodeStack.empty() == false) {
                if(isPop ==false && nodeStack.top()->right ==nullptr){}
            }
        
        }
        */
    /*v2.0:层序遍n
     }
};
