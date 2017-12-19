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
class List
{
	//virtual void clear() = 0;
	virtual bool insert(const Elem&) = 0;
	virtual bool append(const Elem&) = 0;
	virtual bool remove(Elem&) = 0;
	virtual void setStart() = 0;
	virtual void setEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int leftLength() const = 0;
	virtual int rightLength() const = 0;
	virtual bool setPos(int pos) = 0;
	virtual bool getValue(Elem &) const = 0;
	virtual void print() const = 0;
};

template<class Elem>
class intLList :public List<Elem>
{
public:
	Link<Elem>* head;
	Link<Elem>* tail;
	Link<Elem>* fence;
	int leftcnt;
	int rightcnt;
	void init()
	{
		fence = tail = head = new Link<Elem>;
		leftcnt = rightcnt = 0;
	}
	void removerall()
	{
		while (head != NULL)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}
	bool insert(const Elem&);
	bool setPos(int pos);
	int rightLength() const;
	int leftLength() const;
	bool getValue(Elem &) const;
	bool append(const Elem&);
	bool remove(Elem&);
	void setStart();
	void setEnd();
	void prev();
	void next();
	//int leftLength() const;
	//int rightLength() const;
	void print() const;
};

template<class Elem>
bool intLList<Elem>::insert(const Elem& item)
{
	fence->next = new Link<Elem>(item, fence->next);
	if (tail == fence)
		tail = fence->next;
	rightcnt++;
	return true;
}; 

template <class Elem> 
bool intLList<Elem>::setPos(int pos)
{ 
	if ((pos < 0) || (pos > rightcnt + leftcnt)) 
		return false; 
	fence = head; 
	for (int i = 0; i<pos; i++) 
		fence = fence->next; 
	rightcnt = rightcnt + leftcnt - pos; 
	leftcnt = pos; 
	return true; 
}

template <class Elem> 
int intLList<Elem>::rightLength() const { return rightcnt; } 

template <class Elem> 
int intLList<Elem>::leftLength() const { return leftcnt; }

template <class Elem> 
bool intLList<Elem>::getValue(Elem& it) const
{ 
	if (rightLength() == 0) 
		return false; 
	it = fence->next->element; 
	return true; 
}

template <class Elem> 
bool intLList<Elem>::append(const Elem& item)
{ 
	tail = tail->next = new Link<Elem>(item, NULL); 
	rightcnt++; 
	return true; 
}

template <class Elem> 
bool intLList<Elem>::remove(Elem& it)
{
	if (fence->next == NULL) 
		return false; it = fence->next->element; 
	Link<Elem>* ltemp = fence->next; 
	fence->next = ltemp->next; 
	if (tail == ltemp) 
		tail = fence; 
	delete ltemp;
	rightcnt--; 
	return true; 
}

template <class Elem> 
void intLList<Elem>::setStart()
{ 
	fence = head; 
	rightcnt += leftcnt; 
	leftcnt = 0; 
}
template <class Elem> 
void intLList<Elem>::setEnd()
{ 
	fence = tail; 
	leftcnt += rightcnt; 
	rightcnt = 0; 
}

template <class Elem> 
void intLList<Elem>::prev()
{
	Link<Elem>* temp = head; 
	if (fence == head) return;
	while (temp->next!=fence) 
		temp=temp->next; 
	fence = temp; 
	leftcnt--; 
	rightcnt++; 
}

template <class Elem> 
void intLList<Elem>::next()
{
	if (fence == tail) return; 
	fence = fence->next; 
	leftcnt++; 
	rightcnt--; 
}

template <class Elem> 
void intLList<Elem>::print() const
{ 
	Link<Elem>* temp = head; 
	cout << "< "; 
	while (temp != fence) 
	{ 
		cout << temp->next->element << " ";
		temp = temp->next; 
	} 
	cout << " | "; 
	while (temp->next != NULL) 
	{ 
		cout << temp->next->element << " ";
		temp = temp->next; } cout << ">\n";
}



int main()
{
	intLList<int> a;
	a.init();
	a.insert(10);
	a.insert(12);
	a.insert(14);
	a.print();
	a.next();
	a.print();
	//a.next();
	//a.next();
	a.setPos(2);
	a.print();
	a.prev();
	a.print();
	a.remove(a.fence->element);
	a.print();
	system("pause");
}