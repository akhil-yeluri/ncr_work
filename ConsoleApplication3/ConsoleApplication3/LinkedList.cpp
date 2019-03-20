using namespace std;
#include<iostream>
struct node
{
	int data;
	struct node * next;
};

class LinkedList
{
	struct node * start;

public:
	LinkedList()
	{
		start = NULL;
	}
	void insertAtBegining(int ele)
	{
		if (start == NULL)
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = NULL;
			start = nn;
		}
		else
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = start;
			start = nn;
		}

	}

	void insertAtEnd(int ele)
	{
		if (start == NULL)
		{
			struct node *nn = new node;
			nn->data = ele;
			nn->next = NULL;
			start = nn;
		}

		else
		{
			struct node * temp, *nn;
			nn = new node;
			nn->data = ele;
			temp = start;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = nn;
			nn->next = NULL;
		}
	}


	void insertAtPosition(int ele, int position)
	{
		struct node * temp, *nn;
		temp = start;
		while (temp != NULL && temp->data != position)
			temp = temp->next;
		if (temp != NULL)
		{
			nn = new node;
			nn->data = ele;
			if (temp->next != NULL)
				nn->next = temp->next;
			else
				nn->next = NULL;
			temp->next = nn;
			return;
		}
		cout << "Specified Element not found\n";
	}

	void deleteAtBegining()
	{
		if (start == NULL)
		{
			cout << "Empty Linked...Delete operation cannot be performed ";
			return;
		}
		if (start->next == NULL) {
			start = NULL;
			cout << "Delete Successful\n";
			return;
		}

		else
		{
			struct node * temp;
			temp = start;
			start = temp->next;
			delete temp;
			cout << "Delete Successful\n";
		}
	}

	void deleteAtEnd()
	{
		if (start == NULL)
		{
			cout << "Empty LinkedList.. Delete Failed\n";
			return;
		}

		if (start->next == NULL) {
			start = NULL;
			cout << "Delete Successful\n";
			return;
		}

		else
		{
			struct node * temp, *temp2;
			temp = start;
			while (temp->next->next != NULL)
				temp = temp->next;
			temp2 = temp->next;
			temp->next = NULL;
			delete temp2;
			cout << "Delete successful";
		}
	}

	void deleteElement(int ele)
	{
		if (start == NULL)
		{
			cout << "Empty LinkedList\n Delete failed";
			return;
		}

		if (start->data == ele)
		{
			start = NULL;
			cout << "Delete Successful\n";
			return;
		}
		struct node*temp=start,*nn;
		while (temp != NULL)
		{
			if (temp->next->data == ele && temp->next->next!=NULL)
			{
				struct node *temp2;
				temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				cout << "Delete successful";
				return;
			}

			if (temp->next->data == ele && temp->next->next == NULL)
			{
				struct node *temp2;
				temp2 = temp->next;
				temp->next = NULL;
				delete temp2;
				cout << "Delete successful";
				return;
			}
			temp = temp->next;
		}
		cout << "Element not found";
		return;
	}


	void display()
	{
		if (start == NULL)
		{
			cout << "Empty LinkedList\n";
			return;
		}
		struct node * temp;
		temp = start;
		while (temp->next!= NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << temp->data<<"\n";
	}
};


int main()
{
	LinkedList obj;
	while (1) {
		cout << "1.insert at begining\n2.insert at end\n3.insert at position\n4.Delete at begining\n5.Delete at end\n6.Delete element\n7.display\n";
		int n;
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to insert into linked list\n";
			 cin >> n;
			 obj.insertAtBegining(n);
			 break;

		case 2:cout << "enter element to insert into linked list\n";
			cin >> n;
			obj.insertAtEnd(n);
			break;
		case 3:cout << "Enter element and value of element in linkedlist to insert after\n"; int n2;
			    cin >> n>>n2;
			    obj.insertAtPosition(n,n2);
			    break;
		case 4:obj.deleteAtBegining();
			break;
		case 5:obj.deleteAtEnd();
			break;
		case 6:cout << "enter element to delete from linked list\n";
			cin >> n;
			obj.deleteElement(n);
			break;
		case 7:obj.display();
			break;
		default:return 0;
			break;
		}
	}
	return 0;
}