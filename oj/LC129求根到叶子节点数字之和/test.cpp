#include<iostream>
#include"solution.h"

using namespace std;

int main(){
    TreeNode root=TreeNode(1),a=TreeNode(2),b=TreeNode(3);
    root.left=&a;
    root.right=&b;
    
    cout<<Solution().sumNumbers(&root)<<endl;


}
