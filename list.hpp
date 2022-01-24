
#ifndef LIST_HPP
#define LIST_HPP

#include <ostream>

class list
{
public:
    typedef int value_type;
    typedef unsigned int size_type;

private:
    class node;

public:
    size_type size() const;
    bool empty() const;
    void push_front(const value_type& value);
    void push_back(const value_type& value);
    void pop_front();
    void pop_back();
    friend std::ostream& operator<<(std::ostream& out, const list& l);

private:
    node* m_head;

public:
    list();
    list(size_type n, const value_type& default_value);
    list(const list& b);
    const list& operator=(const list& c);
    ~list();
};

#endif
