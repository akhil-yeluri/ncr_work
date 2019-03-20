using namespace std;
#include<iostream>
struct queue_package
{
	int front, rear, size;
	int *queue;
};

class Queue
{
	queue_package q;

public:
	Queue()
	{
		q.front = -1;
		q.rear = -1;
		q.size = 0;
	}


	void setSize(int n)
	{
		q.size = n;
		q.queue = new int[n];
		q.front = q.rear = -1;
	}

	bool isFull()
	{
		return (q.rear==q.size-1);
	}

	bool isEmpty()
	{
		return (q.rear == -1);
	}
	void insert(int n)
	{
		if (q.front == -1)
			++q.front;
		if (!isFull())
			q.queue[++q.rear] = n;
			

		else
			cout << "cannot insert queue is full\n";
	}

	void remove()
	{
		if (!isEmpty())
		{
			int temp = q.queue[q.rear--];
			cout << temp << " deleted from queue\n";
		}

		else
			cout << "cannot perform remove operation on an empty queue\n";
	}

	void display()
	{
		for (int i = q.front; i <= q.rear; i++)
			cout << q.queue[i] <<"\n";
	}
};

int main()
{
	Queue obj;
	int n;
	cout << "Enter size of queue\n";
	cin >> n;
	obj.setSize(n);
	while (1) {
		cout << "Enter your choice \n 1.INSERT \n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n";
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter number to insert to stack\n";
			int temp;
			cin >> temp;
			obj.insert(temp);
			break;
		case 2:obj.remove();
			break;
		case 3: obj.display();
			break;
		default:return 0;
			break;
		}
	}
	return 0;
}