#include "linked_list.h"

/* Конструкторы */
LinkedList::LinkedList()
{
	tail = new node;
	tail->next = tail->prev = tail;
	listSize = 0;
}

LinkedList::LinkedList(const LinkedList & other)
{
	listSize = other.listSize;
	tail = other.tail;
}

LinkedList::LinkedList(LinkedList && other)
{
	listSize = other.listSize;
	this->tail = other.tail;

	other.listSize = 0;
	other.tail = nullptr;
}

/* Деструктор */
LinkedList::~LinkedList()
{
	delete[] this;
}

/* Оператор присваивания */
LinkedList & LinkedList::operator=(const LinkedList & other)
{
	clear();

	for (node* cur = other.tail->next; cur != other.tail; cur = cur->next)
	{
		push_back(cur->data);
	}

	return *this;
}

LinkedList & LinkedList::operator=(LinkedList && other)
{
	clear();

	for (node* cur = other.tail->next; cur != other.tail; cur = cur->next)
	{
		//push_back(cur->data);
	}

	return *this;
}

/* Доступ к итераторам */
//Возвращает итератор, указывающий на первый элемент списка.
LinkedList::iterator LinkedList::begin()
{
	return tail->next;
}

LinkedList::const_iterator LinkedList::begin() const
{
	return tail->next;
}

LinkedList::const_iterator LinkedList::cbegin() const
{
	return tail->next;
}

//Возвращает итератор, указывающий на элемент списка, следующий за последним
//т.е. отсутствующий в списке.
LinkedList::iterator LinkedList::end()
{
	return tail;
}

LinkedList::const_iterator LinkedList::end() const
{
	return tail;
}

LinkedList::const_iterator LinkedList::cend() const
{
	return tail;
}

int LinkedList::size() const
{
	return listSize;
}

bool LinkedList::empty() const
{
	if (listSize)
		return false;
	return true;
}

value_type & LinkedList::front()
{
	return tail->next->data;
}

const value_type & LinkedList::front() const
{
	return tail->next->data;
}

value_type & LinkedList::back()
{
	return tail->data;
}

const value_type & LinkedList::back() const
{
	return tail->data;
}

/* Модификаторы */
//Удаляет элемент, на который указывает итератор pos.
LinkedList::iterator LinkedList::erase(iterator pos)
{
	pos.cur->prev->next = pos.cur->next;
	pos.cur->next->prev = pos.cur->prev;

	delete pos.cur;
	listSize--;

	return tail->next;
}

//Удаляет элементы в интервале [begin, end).
LinkedList::iterator LinkedList::erase(iterator begin, iterator end)
{
	begin.cur->prev->next = end.cur;
	end.cur->prev = begin.cur->prev;

	for (iterator i = begin; i != end; i++)
	{
		delete &i;
		listSize--;
	}

	return tail->next;
}

//Удаляет все вхождения value в список.
int LinkedList::remove(const value_type & value)
{
	int count = 0;

	for (iterator i = tail->next; i != tail; i++)
	{
		if (i.cur->data == value)
		{
			delete &i;
			count++;
		}
	}
	listSize -= count;

	return count;
}

//Очищает список.
void LinkedList::clear()
{
	for (iterator i = tail->next; i != tail; i++)
	{
		delete &i;
	}
	listSize = 0;
	tail->next = tail->prev = tail;
}

//Удаляет последний элемент списка.
void LinkedList::pop_back()
{
	if (empty())
		return;

	node* tmp = tail->prev;

	tail->prev = tail->prev->prev;
	tail->prev->next = tail;

	delete tmp;
	listSize--;
}

//Удаляет первый элемент списка.
void LinkedList::pop_front()
{
	if (empty())
		return;

	node* tmp = tail->next;

	tail->next = tail->next->next;
	tail->next->prev = tail;

	delete tmp;
	listSize--;
}

//Добавляет значение value в конец списка.
void LinkedList::push_back(const value_type & value)
{
	insert(tail, value);
}

//Добавляет значение value в начало списка.
void LinkedList::push_front(const value_type & value)
{
	insert(tail->next, value);
}

//Вставляет значение value перед элементом, на который указывает before
LinkedList::iterator LinkedList::insert(iterator before, const value_type & value)
{
	node* tmp = new node;
	tmp->data = value;
	tmp->next = before.cur;
	tmp->prev = before.cur->prev;
	tmp->prev->next = tmp;
	before.cur->prev = tmp;

	return tmp;
}

/* Операторы внутренние */
//Присоединяет other к списку.
LinkedList & LinkedList::operator+=(const LinkedList & other)
{
	for (const_iterator i = other.cbegin(); i != other.cend(); i++)
	{
		push_back(i.cur->data);
	}
	return *this;
}

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList & left, const LinkedList & right)
{
	if (left.listSize != right.listSize)
		return true;

	for (LinkedList::const_iterator i = left.cbegin(), j = right.cbegin(); i != left.cend(); i++, j++)
	{
		if (i != j)
			return true;
	}

	return false;
}

bool operator==(const LinkedList & left, const LinkedList & right)
{
	return !operator!=(left, right);
}

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList & left, const LinkedList & right)
{
	LinkedList *list = new LinkedList;
	list->operator=(left);
	list->operator+=(right);
	return *list;
}
