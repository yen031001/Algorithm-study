
#include <iostream>
using namespace std;



typedef struct _Node
{
	int pos;
	struct _Node* next;
	struct _Node* prev;
	int level;
}Node;

Node* head = NULL;
Node* tail = NULL;

int main()
{
	int N, K;
	int check[100001] = { 0 };


	cin >> N;
	cin >> K;

	int answer = 0;

	Node* final = (Node*)malloc(sizeof(Node));
	Node* position = (Node*)malloc(sizeof(Node));
	position->pos = N;
	position->next = NULL;
	position->prev = NULL;
	position->level = 0;
	check[position->pos] = 1;

	head = position;
	tail = position;


	while (position != NULL)
	{

		if (position->pos == K)
		{
			answer = position->level;
			final = position;
			break;
		}

		if (position->pos - 1 >= 0 && check[position->pos - 1] == 0)
		{

			Node* left = (Node*)malloc(sizeof(Node));
			check[position->pos - 1] = 1;
			left->pos = position->pos - 1;
			left->next = NULL;
			left->prev = position;
			left->level = position->level + 1;
			tail->next = left;
			tail = left;

		}



		if (position->pos + 1 <= 100000 && check[position->pos + 1] == 0)
		{
			Node* right = (Node*)malloc(sizeof(Node));
			check[position->pos + 1] = 1;
			right->pos = position->pos + 1;
			right->level = position->level + 1;
			right->next = NULL;
			right->prev = position;
			tail->next = right;
			tail = right;
		}



		if (position->pos * 2 <= 100000 && check[position->pos * 2] == 0)
		{
			Node* doub = (Node*)malloc(sizeof(Node));
			check[position->pos * 2] = 1;
			doub->pos = position->pos * 2;
			doub->level = position->level + 1;
			doub->next = NULL;
			doub->prev = position;
			tail->next = doub;
			tail = doub;
		}


		position = position->next;
		

	}
	cout << answer << endl;

	int* route_list = (int*)malloc((answer + 1) * sizeof(int));
	int index = 0;

	while (final != NULL)
	{
		route_list[index] = final->pos;
		final = final->prev;
		index=index + 1;
	}

	for (index=index-1; index >= 0; index--)
	{
		cout << route_list[index]<<' ';
	}

	while (head != NULL)
	{
		Node* temp = head;
		head = head->next;
		free(temp);
	}

	free(route_list);
}

