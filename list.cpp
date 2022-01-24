#include "list.hpp"

#include <cassert>

class list::node
{
public:
    value_type m_value;
    node* m_next;

public:
    node(value_type v, node* n)
        : m_value(v)
        , m_next(n)
    {
    }

    ~node()
    {
    }
};

std::ostream& operator<<(std::ostream& out, const list& l)
{
    list::node* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

list::size_type list::size() const
{
    node* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

bool list::empty() const
{
    return (m_head == nullptr);
}

void list::push_front(const value_type& value)
{
    node* new_node = new node(value, m_head);
    m_head = new_node;
}

void list::push_back(const value_type& value)
{
    node* new_node = new node(value, nullptr);
	if(empty()){
		m_head = new_node;
		return;
	}
    node* current = m_head;
    while(current->m_next != nullptr)
    {
      current = current->m_next;
    }

    current->m_next = new_node;
}

void list::pop_front()
{
	if(empty()){
		return;
	}
	node* old_head = m_head;
    m_head = m_head->m_next;
	delete old_head;
}

void list::pop_back()
{
	if(empty()){
		return;
	}
	if(m_head->m_next == nullptr){
		delete m_head;
		m_head = nullptr;
		return;
	}
	node* current = m_head->m_next;
	node* prev    = m_head;
	while(current->m_next != nullptr){
		prev = current;
		current = current->m_next;
	}
	delete current;
	prev->m_next = nullptr;
}

list::list()
    : m_head(nullptr)
{
}

list::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
{
    node* current = nullptr;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr);
        if (current != nullptr) {
            current->m_next = new_node;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        current = new_node;
    }
}

list::list(const list& b)
		: m_head(nullptr)
{
	node * b_current = b.m_head;

	while (b_current != nullptr)
	{
			push_back(b_current->m_value);
			b_current = b_current->m_next;
	}
}

const list& list::operator=(const list& c)
{
    while(!empty())
		{
				pop_back();
		}
	node * c_current = c.m_head;
	while(c_current != nullptr){
			push_back(c_current->m_value);
	}
    return *this;
}

list::~list()
{
    while(!empty())
		{
				pop_back();
		}
}
