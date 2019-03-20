using namespace std;
#include<iostream>

struct Tree
{
	int data;
	struct Tree * left;
	struct Tree * right;
};


class BST
{
	struct Tree *root;

public:
	BST()
	{
		root = NULL;
	}

	struct Tree* insertData(int element,struct Tree *root)
	{
		if (root == NULL)
		{
			root = new Tree;
			root->data = element;
			root->left = NULL;
			root->right = NULL;
			cout << element << "is inserted into bst\n";
			return root;
		}

		else
		{
			struct Tree * temp;
			temp = root;
			if (temp->data < element)
			{
				temp->right=insertData(element,temp->right);
			}
			else
			{
				temp->left=insertData(element, temp->left);
			}
		}
	}

	struct Tree* getRoot()
	{
		return root;
	}

	void inorder(struct Tree* root)
	{
		if (root != NULL) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
};

int main()
{
	BST bst;
	int n;
	while (1)
	{
		bst.insertData(12, bst.getRoot());
		bst.insertData(11, bst.getRoot());
		bst.insertData(8, bst.getRoot());
		cout << "1 to display\n";
		cin >> n; 
		switch (n)
		{
		
		case 1:bst.inorder(bst.getRoot());
			break;
		}
	}

	return 0;
}