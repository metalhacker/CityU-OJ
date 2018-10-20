#include <iostream>
using namespace std;
int preOrder[100];
int inOrder[100];

class node
{
public:
	int num;
	node* left;
	node* right;
	node(int n)
	{
		num = n;
		left = NULL;
		right = NULL;
	}
};

class tree
{
public:
	node* root;
	tree()
	{
		root = NULL;
	}
	node* createTree(int preStart, int preEnd, int inStart, int inEnd)
	{
		if (preStart > preEnd || inStart > inEnd)
			return NULL;
		else
		{
			node* temp = new node(preOrder[preStart]);
			int i = 0;
			while (inOrder[i] != temp->num)
				i++;
			temp->left = createTree(preStart + 1, preStart + i - inStart, inStart, i - 1);
			temp->right = createTree(preStart + i - inStart + 1, preEnd, i + 1, inEnd);
			return temp;
		}
	}
	void getPostOrder(node* temp)
	{
		if (temp == NULL)
			return;
		getPostOrder(temp->left);
		getPostOrder(temp->right);
		if (temp != root)
			cout << temp->num << " ";
		else
			cout << temp->num << endl;
	}
};

int main()
{
	int cases;
	cin >> cases;
	while (cases > 0)
	{
		cases--;
		int numOfNodes;
		cin >> numOfNodes;
		for (int i = 0; i < numOfNodes; i++)
			cin >> preOrder[i];
		for (int i = 0; i < numOfNodes; i++)
			cin >> inOrder[i];
		tree myTree;
		myTree.root = myTree.createTree(0, numOfNodes - 1, 0, numOfNodes - 1);
		myTree.getPostOrder(myTree.root);
	}
	return 0;
}

