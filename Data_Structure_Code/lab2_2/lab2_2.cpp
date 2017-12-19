#include<iostream>
using namespace std;

template <class Elem>
class Link
{
public:
	Elem element;
	Link *next;

	Link(const Elem& elemval, Link* nextval = NULL)
	{
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL)
	{
		next = nextval;
	}
};

template <class Elem>
class Stack
{
public:
	Link<Elem>* top;
	Link<Elem>* buttom;
	int size;

	bool pop();
	bool push(const Elem& item);
	void print();
	Stack();
	Stack(const Elem& item);
};

template<class Elem>
Stack<Elem>::Stack()
{
	top = NULL;
	buttom = NULL;
	size = 0;
}

template<class Elem>
Stack<Elem>::Stack(const Elem& item)
{
	buttom = top = new Link<Elem>(item, NULL);
	size = 1;
}

template<class Elem>
bool Stack<Elem>::pop()
{
	if (top == NULL)
	{
		cout << " 无法弹出，Stack中无元素。" << endl;
		return false;
	}
	Link<Elem>* temp = buttom;
	while(temp->next != top)
		temp = temp->next;
	top = temp;
	size--;
	delete top->next;
	return true;
}

template<class Elem>
bool Stack<Elem>::push(const Elem& item)
{
	if (top == NULL)
		buttom = top = new Link<Elem>(item,NULL);
	else
	{
		top->next = new Link<Elem>(item, NULL);
		top = top->next;
	}
	size++;
	return true;
}

template<class Elem>
void Stack<Elem>::print()
{
	Link<Elem>* temp = buttom;
	for (int i = 0; i < size; i++)
	{
		cout << temp->element << " <- " ;
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Stack<int> a(0);
	a.push(1);
	a.push(3);
	a.push(5);
	a.push(6);
	a.pop();
	a.print();
	system("pause");
}