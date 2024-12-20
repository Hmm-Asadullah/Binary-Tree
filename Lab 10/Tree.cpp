#include<iostream>
using namespace std;
#include<queue>
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d, TreeNode* l = nullptr, TreeNode* r = nullptr)
	{
		data = d;
		left = l;
		right = r;
	}
};
class BinaryTree
{
	TreeNode* root;
public:
	BinaryTree(TreeNode* r= nullptr)
	{
		root = r;
	}
	TreeNode*& getRoot()
	{
		return root;
	}
	void insertNode(int value)
	{
		TreeNode* newNode = new TreeNode(value);
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* current = q.front();
			q.pop();
			if (current->left == nullptr)
			{
				current->left = newNode;
				return;
			}
			else
			{
				q.push(current->left);
			}
			if (current->right == nullptr)
			{
				current->right = newNode;
				return;
			}
			else
			{
				q.push(current->right);
			}
		}
	}
	void levelOrder(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		queue<TreeNode*> q; 
		q.push(root);   
		while (!q.empty())
		{
			TreeNode* current = q.front(); 
			q.pop();                   
			cout << current->data << " "; 
			if (current->left != nullptr)
			{
				q.push(current->left);
			}
			if (current->right != nullptr)
			{
				q.push(current->right);
			}
		}
	}
	void inOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inOrder(node->left);
		cout << node->data << ' ';
		inOrder(node->right);
	}
	void preOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		cout << node->data << ' ';
		preOrder(node->left);
		preOrder(node->right);
	}
	void postOrder(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << ' ';
	}
	int findHeight(TreeNode* node)
	{
		if (node == nullptr)
		{
			return -1;
		}
		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
	int countNodes(TreeNode* node)
	{
		static int i = 0;
		if (node == nullptr)
		{
			return i;
		}
		i++;
		countNodes(node->left);
		countNodes(node->right);
		return i;
	}
	bool isBalanced(TreeNode* node)
	{
		int leftHeight = findHeight(node->left);
		int rightHeight = findHeight(node->right);
		if (leftHeight == rightHeight || leftHeight + 1 == rightHeight || leftHeight == rightHeight + 1)
		{
			return true;
		}
		return false;
	}
	bool search(TreeNode* node, int value)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->data == value)
		{
			return true;
		}
		return search(node->left, value) || search(node->right, value);
	}
};
int main()
{
	BinaryTree bt;
	for (int i = 1; i < 12; i++)
	{
		bt.insertNode(i);
	}
	bt.levelOrder(bt.getRoot());
	return 0;
}