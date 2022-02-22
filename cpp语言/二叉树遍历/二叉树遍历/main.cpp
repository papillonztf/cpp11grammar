#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node
{
public:
	int GetValue();
	Node* GetLeft();
	Node* GetRight();
};
class BinTree
{
public:
	int GetValue();
	Node* GetRoot();
	BinTree* GetLeft();
	BinTree* GetRight();
	int size();
};

int main()
{
	
}

void Preorder(BinTree* bintree )
{
	////循环左链
	//BinTree* p = bintree;
	//stack<BinTree*> s;
	//while (p!=NULL||s.empty()!=0)
	//{
	//	//循环一条左链,
	//	while (p != NULL)
	//	{
	//		cout << p->GetValue() << " ";
	//		s.push(p);
	//		p = p->GetLeft();
	//	}
	//	//确定下一条左链的首指针
	//	if (!s.empty())
	//	{
	//		p = s.top()->GetRight();
	//		s.pop();
	//	}
	//}

	//
	stack<Node*> s;
	Node*p=bintree->GetRoot();
	while (p!=0||s.empty()!=0)
	{
		//左链压栈
		while (p != 0)
		{
			p->GetValue();
			p = p->GetLeft();
			s.push(p);
            
		}
		//确定下一条左链的首指针
		if (s.empty()!=0)
		{
			p = s.top()->GetRight();
			s.pop();
		}
	}
}	
void Preorder(BinTree* bintree)
{
	BinTree* p = bintree;
	if (p != NULL)
	{
		cout << p->GetValue << " ";
		Preorder(p->GetLeft());
		Preorder(p->GetRight());
	}
}


void Inorder(BinTree* bintree)
{
	//循环左链
	BinTree* p = bintree;
	stack<BinTree*> s;
	while (p != NULL || s.empty() != 0)
	{
		//循环一条左链
		while (p != NULL)
		{
			
			s.push(p);
            
			p = p->GetLeft();
		}
		//确定下一条左链的首指针
		if (!s.empty())
		{
			//输出位置为每条链的顶部
			s.top()->GetValue();

			p = s.top()->GetRight();
			s.pop();
		}
	}
}


void Inorder(BinTree* bintree)
{
	BinTree* p = bintree;
	if (p != NULL)
	{
		Inorder(p->GetLeft());
		cout << p->GetValue() << " ";
		Inorder(p->GetRight());
	}
}

//void Postorder(BinTree* bintree)
//{
//	//循环左链
//	
//	BinTree*  cur;
//	BinTree*  pre = NULL;//保留前一个已显示的结点
//	stack<BinTree*> s;
//	s.push(bintree);
//	while (!s.empty())
//	{
//		cur = s.top();
//		//若当前结点是叶子节点或者当前结点的左或右结点已被显示，则显示该结点并pop出去。
//		if ((cur->GetLeft()==NULL && cur->GetRight()==NULL) || 
//			((pre==cur->GetLeft() || pre==cur->GetRight()) && pre!=NULL ))
//		{
//			cout << cur->GetValue << " ";
//			pre = cur;
//			s.pop();
//		}
//		//否则不显示，并将当前结点的右结点，左结点依次push入栈。锯齿型中-右-左 扫描
//		else
//		{
//			if (cur->GetRight() != NULL)
//				s.push(cur->GetRight());
//			if (cur->GetLeft() != NULL)
//				s.push(cur->GetLeft());
//		}
//
//	}
//}


void Postorder(BinTree * root)
{
	//采用循环实现一边压栈，一边遍历显示，出栈
	stack<Node*> s;
	
	Node* cur;
	Node* pre = NULL;
	s.push(root->GetRoot());
	while (s.empty!=0)
	{
		cur=s.top();
		//若preptr!=0且当前的栈顶的结点是叶子结点或满足其左或右子结点已显示。则显示该栈顶结点，并弹出
		if ((cur->GetLeft()==0&&cur->GetRight==0)||((pre==cur->GetLeft()||pre==cur->GetRight())&&pre!=0))
		{
			cout << cur->GetValue()<< " ";
			pre = cur;
			s.pop();
		}
		//否则不显示，而是依次将该栈顶结点的右结点和左结点压栈
		else
		{
			if (cur->GetRight() != 0) s.push(cur->GetRight());
			if (cur->GetLeft() != 0) s.push(cur->GetLeft());
		}
	}
}


void Postorder(BinTree* bintree)
{
	BinTree* p = bintree;
	if (p!=NULL)
	{
		Postorder(p->GetLeft());
		Postorder(p->GetRight());
		cout<<p->GetValue()<<" ";
	}
}

void Levorder(BinTree* bintree)//二叉树层次遍历
{
	queue<BinTree* > q;
	q.push(bintree);
	int i=0;
	int count=0;
	while (count<=bintree->size())
	{
		i = q.size();
		count += i;
		while (i)
		{
			cout << q.front()->GetValue() << " ";
			if (q.front()->GetLeft() != NULL)
				q.push(q.front()->GetLeft());
			if (q.front()->GetLeft() != NULL)
				q.push(q.front()->GetRight());
			q.pop();
			i--;
		}
		cout << endl;
	}
}
