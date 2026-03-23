#include <iostream>
using namespace std;

char al_tree[10000] = { '.', };

class Node{
public:
	Node(char name) {
		this->name = name;
	}
	char name;
	Node* left;
	Node* right;
};

Node root('A');
int N;

Node* findNode(Node*curr, char findName)
{
	if (curr->name == findName) return curr;
	Node *ret;
	if (curr->left)
	{
		Node* ret = findNode(curr->left, findName);
		if (ret) return ret;
	}
	if (curr->right)
	{
		Node* ret = findNode(curr->right, findName);
		if (ret) return ret;
	}
	return nullptr;

}



void pre_order(Node* curr)
{
	if (curr == nullptr)
	{
		return;
	}
	char data = curr->name;
	cout << data;
	pre_order(curr->left);
	pre_order(curr->right);
}

void in_order(Node* curr)
{
	if (curr == nullptr)
	{
		return;
	}
	char data = curr->name;
	in_order(curr->left);
	cout << data;
	in_order(curr->right);
}

void post_order(Node* curr)
{
	if (curr == nullptr)
	{
		return;
	}
	char data = curr->name;
	post_order(curr->left);
	post_order(curr->right);
	cout << data;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;



		Node* found = findNode(&root,a);
		if(b!='.')found->left = new Node(b);
		if (c != '.')found->right = new Node(c);
	}
	
	pre_order(&root);
	cout << endl;
	in_order(&root);
	cout << endl;
	post_order(&root);
	cout << endl;
	
}