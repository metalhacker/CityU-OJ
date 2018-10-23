#include <iostream>
using namespace std;

struct Node
{
public:
	int tag;
	Node *next;
	//Node();
};

/*Node::Node()
{
	tag = 0;
	this->next = NULL;
}*/

class Circle
{
public:
	Node *ref;
	Circle();
	~Circle();
	Node* search(int i);
	void firstAdd(int tag);
	void newAdd(int tag, int i);
	void add(int i, int tag);
	void remove(int i);
	void reverse(int i, int j);
	void print(int i);
};

Circle::Circle()
{
	ref = new Node;
	ref->next = NULL;
	ref->tag = NULL;
}

Circle::~Circle()
{
	delete ref;
}

Node* Circle::search(int i)
{
	Node* temp = new Node;
	temp = ref;
	for (int j = 0; j < i; j++)
	{
		temp = temp->next;
	}
	return temp;
}

void Circle::firstAdd(int tag)
{
	Node *newNode = new Node;
	newNode->tag = tag;
	ref->next = newNode;
}

void Circle::newAdd(int tag, int i)
{
	Node *newNode = new Node;
	newNode->tag = tag;
	newNode->next = ref->next;
	this->search(i)->next = newNode;
}

void Circle::add(int i, int tag)
{
	Node *newNode = new Node;
	newNode->tag = tag;
	newNode->next = this->search(i + 1);
	this->search(i)->next = newNode;
	//ref->next = newNode;
}

void Circle::remove(int i)
{
	this->search(i - 1)->next = this->search(i + 1);
	//ref->next = this->search(i);
}

void Circle::reverse(int i, int j)
{
	Node *temp1, *temp2;
	temp1 = this->search(j);
	temp2 = this->search(j + 1);
	for (int k = j; k > i; k--)
	{
		this->search(k)->next = this->search(k - 1);
	}
	this->search(i)->next = temp2;
	this->search(i - 1)->next = temp1;
}

void Circle::print(int i)
{
	cout << this->search(i)->tag << endl;
	//ref->next = this->search(i);
}

int main()
{
	int n, q;
	cin >> n;
	Circle Students;
	int *tempTag = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tempTag[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			Students.firstAdd(tempTag[i]);
		}
		else
		{
			Students.newAdd(tempTag[i], i);
		}
	}
	cin >> q;
	for (int j = 0; j < q; j++)
	{
		int operation, i, tag;
		cin >> operation >> i;
		i = i % n;
		if (operation == 1)
		{
			cin >> tag;
			Students.add(i, tag);
			n++;
		}
		else if (operation == 2)
		{
			Students.remove(i);
		}
		else if (operation == 4)
		{
			Students.print(i);
		}
		else
		{
			int tempj;
			cin >> tempj;
			Students.reverse(i, tempj);
		}
	}
	return 0;
}
