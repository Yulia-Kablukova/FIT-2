#include "linked_list.h"	

/* Конструкторы */
LinkedList::LinkedList()
{
	tail = new node;
	tail->data = value_type();
	tail->next = tail->prev = tail;
	listSize = 0;
}

LinkedList::LinkedList(const LinkedList& other)
{
	tail = new node;
	tail->data = value_type();
	tail->next = tail->prev = tail;
	listSize = 0;

	for (const_iterator cur = other.cbegin(); cur != other.cend(); ++cur)
	{
		this->push_back(*cur);
	}
}

LinkedList::LinkedList(LinkedList&& other)
{
	if (this == &other)
		return;

	listSize = other.listSize;
	tail = other.tail;

	other.listSize = 0;
	other.tail = nullptr;
}

/* Деструктор */
LinkedList::~LinkedList()
{
	clear();
	delete tail;
}

/* Оператор присваивания */
LinkedList& LinkedList::operator=(const LinkedList& other)
{
	clear();

	for (const_iterator cur = other.cbegin(); cur != other.cend(); ++cur)
	{
		push_back(*cur);
	}

	return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other)
{
	if (this == &other)
		return *this;

	clear();

	listSize = other.listSize;
	tail = other.tail;

	other.listSize = 0;
	other.tail = nullptr;

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
	return listSize == 0;
}

value_type& LinkedList::front()
{
	return tail->next->data;
}

const value_type& LinkedList::front() const
{
	return tail->next->data;
}

value_type& LinkedList::back()
{
	return tail->prev->data;
}

const value_type& LinkedList::back() const
{
	return tail->prev->data;
}

/* Модификаторы */
//Удаляет элемент, на который указывает итератор pos.
LinkedList::iterator LinkedList::erase(iterator pos)
{
	if (pos == end())
		throw std::invalid_argument("List is empty");

	iterator it = pos.cur->next;

	pos.cur->prev->next = it.cur;
	it.cur->prev = pos.cur->prev;

	delete pos.cur;
	listSize--;

	return it;
}

//Удаляет элементы в интервале [begin, end).
LinkedList::iterator LinkedList::erase(iterator begin, iterator end)
{
	iterator it = begin;

	while (it != end)
	{
		it = erase(it);
	}

	return it;
}

//Удаляет все вхождения value в список.
int LinkedList::remove(const value_type& value)
{
	int count = 0;

	for (iterator i = begin(); i != end();)
	{
		if (*i == value)
		{
			i = erase(i);
			count++;
		}
		else
		{
			++i;
		}
	}

	return count;
}

//Очищает список.
void LinkedList::clear()
{
	for (iterator i = begin(); i != end();)
	{
		i = erase(i);
	}
}

//Удаляет последний элемент списка.
void LinkedList::pop_back()
{
	erase(--end());
}

//Удаляет первый элемент списка.
void LinkedList::pop_front()
{
	erase(begin());
}

//Добавляет значение value в конец списка.
void LinkedList::push_back(const value_type& value)
{
	insert(end(), value);
}

//Добавляет значение value в начало списка.
void LinkedList::push_front(const value_type& value)
{
	insert(begin(), value);
}

//Вставляет значение value перед элементом, на который указывает before
LinkedList::iterator LinkedList::insert(iterator before, const value_type& value)
{
	node* tmp = new node;
	tmp->data = value;
	tmp->next = before.cur;
	tmp->prev = before.cur->prev;
	tmp->prev->next = tmp;
	before.cur->prev = tmp;
	listSize++;

	return tmp;
}

/* Операторы внутренние */
//Присоединяет other к списку.
LinkedList& LinkedList::operator+=(const LinkedList& other)
{
	for (auto &item : other)
	{
		push_back(item);
	}
	return *this;
}

/* Операторы внешние */
//Сравнивает 2 листа
bool operator!=(const LinkedList& left, const LinkedList& right)
{
	if (&left == &right)
		return false;

	if (left.listSize != right.listSize)
		return true;

	for (LinkedList::const_iterator i = left.cbegin(), j = right.cbegin(); i != left.cend(); i++, j++)
	{
		if (i != j)
			return true;
	}

	return false;
}

bool operator==(const LinkedList& left, const LinkedList& right)
{
	return !(left != right);
}

//Возвращает лист объединяющий 2 листа.
LinkedList operator+(const LinkedList& left, const LinkedList& right)
{
	LinkedList list(left);
	return list += right;
}
