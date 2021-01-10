#include <iostream>

template <typename T>
class List
{
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};
	Node<T>* head;
	int Size;
public:
	List();
	~List();
	int GetSize() { return Size; }
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void clear();
	void removeAt(int index);
	void insert(int index, T data);
	T& operator[](const int index);
};

template <typename T>
List<T>::List()
{
	head = nullptr;
	Size = 0;
}

template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = this->head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
		pop_front();
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node<T>* ToDelete = previous->pNext;
		previous->pNext = ToDelete->pNext;

		delete ToDelete;
		Size--;
	}
}

template<typename T>
void List<T>::insert(int index, T data)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	Node<T>* current = this->head;
	for (int i = 0; i <= index; i++)
	{
		if (i == index)
			return current->data;
		current = current->pNext;
	}
}

int main()
{
	List<int> lst;
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	lst.push_front(-2); // -2 5 6 7
	lst.removeAt(2); // -2 5 7
	lst.insert(2, -2);
	for(int i=0;i<lst.GetSize();i++)
		std::cout << lst[i]<<std::endl;
}