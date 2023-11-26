#include <iostream>
using namespace std;
class TreeNode
{
	public: 
    int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};
class BinarySearchTree
{
	public: 
    TreeNode *root;
	bool alternate;
	BinarySearchTree()
	{
		this->root = nullptr;
		this->alternate = false;
	}
	void addNode(int data)
	{
		TreeNode *node = new TreeNode(data);
		if (this->root == nullptr)
		{

			this->root = node;
		}
		else
		{
			TreeNode *find = this->root;
			while (find != nullptr)
			{
				if (find->data >= data)
				{
					if (find->left == nullptr)
					{
						find->left = node;
						return;
					}
					else
					{
						find = find->left;
					}
				}
				else
				{
					if (find->right == nullptr)
					{
						find->right = node;
						return;
					}
					else
					{
			
						find = find->right;
					}
				}
			}
		}
	}
	int leafSum(TreeNode *node)
	{
		if (node != nullptr)
		{
			if (node->left == nullptr && 
                node->right == nullptr)
			{
				this->alternate = !this->alternate;
				if (this->alternate)
				{
					return node->data;
				}
			}
			else
			{
				return this->leafSum(node->left) + 
                       this->leafSum(node->right);
			}
		}
		return 0;
	}
	int alternateLeafSum()
	{

		this->alternate = false;
		return this->leafSum(this->root);
	}
};
int main()
{
    int t;
    cin>>t;
    while(t--){
	BinarySearchTree *tree = new BinarySearchTree();
	int n;
	cin>>n;
	while(n--)
	{
	    int x;
	    cin>>x;
	    tree->addNode(x);
	}
	cout << tree->alternateLeafSum() <<'\n';
    }
	return 0;
}
