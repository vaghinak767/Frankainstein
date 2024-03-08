#include "double_linked_list.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
    l_great = nullptr;
    l_small = nullptr;
}

List::List(value_type size)
{
    Node *ptr = new Node;
    Node *ptr = new Node;
    ptr->data = 0;
    head = ptr;
    tail = ptr;
    for(int i = 0; i < size - 1; ++i)
    {
        Node *ptr = new Node;
        ptr->data = 0;
        ptr->previous = tail;
        ptr->small = tail;
        ptr->graet = nullptr;
        ptr->next = nullptr;
        tail->great = ptr;
        tail->next = ptr;
        tail = ptr; 
    }
}

List::List(size_type size, const_reference init)
{
    Node *ptr = new Node;
    Node *ptr = new Node;
    ptr->data = init;
    head = ptr;
    tail = ptr;
    for(int i = 0; i < size - 1; ++i)
    {
        Node *ptr = new Node;
        ptr->data = init;
        ptr->previous = tail;
        ptr->small = tail;
        ptr->graet = nullptr;
        ptr->next = nullptr;
        tail->great = ptr;
        tail->next = ptr;
        tail = ptr; 
    }
}

List::List(std::initializer_list<int> init)
{
    Node* ptr = new Node;
    head = ptr;
    ptr->data = *(init.begin());
    tail = ptr;
    l_great = ptr;
    l_small = ptr;
    int size = init.size();
    for(int i = 1; i < size; ++i)
    {
        push_back(*(init.begin() + i));
    }
}

template<typename input_iterator>
List::List(input_iterator f, input_iterator l)
{
    Node *ptr = new Node;
    head = ptr;
    ptr->data = *f;
    tail = ptr;
    l_great = ptr;
    l_small = ptr;
    ++f;
    ++l;
    while(f != l && f)
    {
        push_back(*f);
        ++f;
    }
}

List::~List()
{
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

List::List(const List &other)
{
    Node* tmp = other.head;
    while(tmp)
    {
        this->push_back(tmp->data);
        tmp = tmp->next;
    }
    this->m_size = other.m_size;
}

const List &List::operator=(const List &other)
{
    if(this == &other)
    {
        return *this;
    }
    Node *obj = this->head;
    while(obj)
    {
        Node *tmp = obj;
        obj = obj->next;
        delete tmp; 
    }
    this->head = this->tail = nullptr;
    Node* tmp = other.head;
    while(tmp)
    {
        this->push_back(tmp->data);
        tmp = tmp->next;
    }
    this->m_size = other.m_size;
    return *this;
}

List::List(List &&other)
{
    head = other.head;
    tail = other.tail;
    l_great = other.l_great;
    l_small = other.l_small;
    m_size = other.m_size;
    other.head = other.tail = nullptr;
    other.l_small = other.l_great = nullptr;
    other.m_size = 0;
}

const List &List::operator=(List &&other)
{
    this->head = other.head;
    this->tail = other.tail;
    this->l_great = other.l_great;
    this->l_small = other.l_small;
    this->m_size = other.m_size;
    other.head = other.tail = nullptr;
    other.l_small = other.l_great = nullptr;
    other.m_size = 0;
    return *this;
}

bool List::empty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

void List::push_back(int el)
{
    ++m_size;
    if (head == nullptr && tail == nullptr)
    {
        Node *ob = new Node;
        tail = ob;
        head = ob;
        ob->data = el;
        l_great = ob;
        l_small = ob;
        return;
    }
    Node *ob = new Node;
    ob->data = el;
    Node *tmp = l_great;
    Node *ptr = nullptr;
    while (tmp != nullptr && tmp->data > ob->data)
    {
        ptr = tmp;
        tmp = tmp->small;
    }
    ob->great = ptr;
    ob->small = tmp;
    if (tmp != nullptr)
    {
        tmp->great = ob;
    }
    if (ptr != nullptr)
    {
        ptr->small = ob;
    }
    ob->previous = tail;
    ob->next = nullptr;
    tail->next = ob;
    tail = ob;
    if (ob->great == nullptr)
    {
        l_great = ob;
    }
    if (ob->small == nullptr)
    {
        l_small = ob;
    }
}

void List::push_front(int el)
{
    ++m_size;
    if (head == nullptr && tail == nullptr)
    {
        Node *ob = new Node;
        tail = ob;
        head = ob;
        ob->data = el;
        l_great = ob;
        l_small = ob;
        return;
    }
    Node *ob = new Node;
    ob->data = el;
    Node *tmp = l_great;
    Node *ptr = nullptr;
    while (tmp != nullptr && tmp->data > ob->data)
    {
        ptr = tmp;
        tmp = tmp->small;
    }
    ob->great = ptr;
    ob->small = tmp;
    if (tmp != nullptr)
    {
        tmp->great = ob;
    }
    if (ptr != nullptr)
    {
        ptr->small = ob;
    }
    ob->previous = nullptr;
    ob->next = head;
    head->previous = ob;
    head = ob;
    if (ob->great == nullptr)
    {
        l_great = ob;
    }
    if (ob->small == nullptr)
    {
        l_small = ob;
    }
}

void List::dis()
{
    Node *tmp = tail;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->previous;
    }
    std::cout << std::endl;
}

void List::display()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void List::display_dec()
{
    Node *tmp = l_small;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->great;
    }
    std::cout << std::endl;
}

void List::display_inc()
{
    Node *tmp = l_great;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->small;
    }
    std::cout << std::endl;
}

void List::erase(int pos)
{
    if(pos > m_size)
    {
        return;
    }
    --m_size;
    Node *tmp = head;
    --pos;
    while (pos > 0)
    {
        tmp = tmp->next;
        --pos;
    }
    if (tmp == head)
        head = head->next;
    if (tmp == tail)
        tail = tail->previous;
    if (tmp == l_great)
        l_great = l_great->small;
    if (tmp == l_small)
        l_small = l_small->great;
    if (tmp->small && tmp->small->great)
        tmp->small->great = tmp->great;
    if (tmp->previous && tmp->previous->next)
        tmp->previous->next = tmp->next;
    if (tmp->great && tmp->great->small)
        tmp->great->small = tmp->small;
    if (tmp->next && tmp->next->previous)
        tmp->next->previous = tmp->previous;
    delete tmp;
}

void List::erase(int first, int last)
{
    if (first >= last)
    {
        return;
    }
    if (l_great->data < first)
    {
        return;
    }
    if (l_great->data < last && l_small->data >= first)
    {
        Node *tmp = l_small;
        while (tmp != nullptr)
        {
            Node *ptr = tmp;
            tmp = tmp->great;
            delete ptr;
        }
        l_great = nullptr;
        l_small = nullptr;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node *tmp = l_small;
    if (first > tmp->data)
    {
        while (tmp->data < first)
        {
            tmp = tmp->great;
        }
    }
    if (l_great->data < last - 1)
    {
        clear(tmp);
        // while(tmp)
        // {
        //     if(tmp->small && tmp->small->great)
        //         tmp->small->great = tmp->great;
        //     if(tmp->previous && tmp->previous->next)
        //         tmp->previous->next = tmp->next;
        //     if(tmp->great && tmp->great->small)
        //         tmp->great->small = tmp->small;
        //     if(tmp->next && tmp->next->previous)
        //         tmp->next->previous = tmp->previous;
        //     Node *ptr = tmp;
        //     if((tmp->next != nullptr) && (!tmp->next->previous))
        //     {
        //         head = tmp->next;
        //     }
        //     if((tmp->previous != nullptr) && (!tmp->previous->next))
        //     {
        //         tail = tmp->previous;
        //     }
        //     if((tmp->small != nullptr) && (!tmp->small->great))
        //     {
        //         l_great = tmp->small;
        //     }
        //     if((tmp->great != nullptr) && (!tmp->great->small))
        //     {
        //         l_small = tmp->great;
        //     }
        //     tmp = tmp->great;
        //     if(!tmp)
        //     {
        //         delete ptr;
        //         return;
        //     }
        //     else
        //     {
        //         first = tmp->data;
        //         delete ptr;
        //     }
        // }
        return;
    }
    clear(tmp, first, last);
    // while(first < last)
    // {
    //     if(tmp->small && tmp->small->great)
    //         tmp->small->great = tmp->great;
    //     if(tmp->previous && tmp->previous->next)
    //         tmp->previous->next = tmp->next;
    //     if(tmp->great && tmp->great->small)
    //         tmp->great->small = tmp->small;
    //     if(tmp->next && tmp->next->previous)
    //         tmp->next->previous = tmp->previous;
    //     Node *ptr = tmp;
    //     if((tmp->next != nullptr) && (!tmp->next->previous))
    //     {
    //         head = tmp->next;
    //     }
    //     if((tmp->previous != nullptr) && (!tmp->previous->next))
    //     {
    //         tail = tmp->previous;
    //     }
    //     if((tmp->small != nullptr) && (!tmp->small->great))
    //     {
    //         l_great = tmp->small;
    //     }
    //     if((tmp->great != nullptr) && (!tmp->great->small))
    //     {
    //         l_small = tmp->great;
    //     }
    //     tmp = tmp->great;
    //     if(!tmp)
    //     {
    //         delete ptr;
    //         return;
    //     }
    //     else
    //     {
    //         first = tmp->data;
    //         delete ptr;
    //     }
    // }
}

void List::pop_back()
{
    if (tail)
    {
        --m_size;
        if (tail->small && tail->small->great)
            tail->small->great = tail->great;
        if (tail->previous && tail->previous->next)
            tail->previous->next = tail->next;
        if (tail->great && tail->great->small)
            tail->great->small = tail->small;
        if (tail == l_great)
            l_great = l_great->small;
        if (tail == l_small)
            l_small = l_small->great;
        Node *tmp = tail;
        tail = tail->previous;
        delete tmp;
    }
}

void List::pop_front()
{
    if (head)
    {
        --m_size;
        if (head->small && head->small->great)
            head->small->great = head->great;
        if (head->great && head->great->small)
            head->great->small = head->small;
        if (head->next && head->next->previous)
            head->next->previous = head->previous;
        if (head == l_great)
            l_great = l_great->small;
        if (head == l_small)
            l_small = l_small->great;
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int List::size()
{
    return m_size;
}

void List::insert(int index, int data)
{
    int ind = index;
    if(index > m_size + 1 || index < 1)
    {
        return;
    }
    ++m_size;
    Node *tmp = head;
    --index;
    while(index)
    {
        tmp = tmp->next;
        --index;
    }
    Node *ob = new Node;
    std::cout << m_size << std::endl;
    if(ind == m_size)
    {
        ob->next = nullptr;
        ob->previous = tail;
        tail->next = ob;
        tail = ob;
        ob->data = data;
    }
    else
    {
        ob->next = tmp;
        ob->previous = tmp->previous;
        ob->data = data;
        if(tmp != head)
        tmp->previous->next = ob;
        tmp->previous = ob;
    }
    Node *ptr2 = l_great;
    Node *ptr1 = l_small;
    if(ind == 1)
    {
        head = ob;
    }
    while(1)
    {
        if(ptr2->data <= data)
        {
            if(ptr2->great)
            ptr2->great->small = ob;
            else 
            l_great = ob;
            ob->small = ptr2;
            ob->great = ptr2->great;
            ptr2->great = ob;
            return;
        }
        if(ptr1->data >= data)
        {
            ob->small = ptr1->small;
            if(ptr1->small)
            ptr1->small->great = ob;
            else
            l_small = ob;
            ptr1->small = ob;
            ob->great = ptr1;
            return;
        }
        ptr1 = ptr1->great;
        ptr2 = ptr2->small;
    }
}

int List::get(int index)
{
    return (*this)[index];
}

void List::remove(int el)
{
    Node* tmp = l_small;
    while(tmp->data != el)
    {
        tmp = tmp->great;
        if(tmp == nullptr)
        {
            return;
        }
    }
    Node* ptr = tmp;
    sort(tmp);
    delete ptr;
}

int List::operator[](int index)
{
    if(index > m_size)
    {
        return -1;
    }
    Node *tmp = head;
    while(index)
    {
        tmp = tmp->next;
        --index;
    }
    return tmp->data;
}

bool List::operator==(const List& ob)const
{
    if(this->m_size != ob.m_size)
    {
        return false;
    }
    Node* tmp = this->l_small;
    Node* tmp1 = ob.l_small;
    while(tmp)
    {
        if(tmp->data != tmp1->data)
        {
            return false;
        }
        tmp = tmp->great;
        tmp1 = tmp1->great;
    }
    return true;
}

const List List::operator+(const List& ob)
{
    Node* tmp = this->l_small;
    List res;
    while(tmp)
    {
        res.push_back(tmp->data);
        tmp = tmp->great;
    }
    tmp = ob.l_small;
    while(tmp)
    {
        res.push_back(tmp->data);
        tmp = tmp->great;
    }
    return res;
}

List::base_iterator::~base_iterator()
{
	this->ptr = nullptr;
}

bool List::base_iterator::operator==(const base_iterator& rhv)const
{
	return this->ptr == rhv.ptr;
}

bool List::base_iterator::operator!=(const base_iterator& rhv)const
{
	return this->ptr != rhv.ptr;
}

explicit List::base_iterator::base_iterator(Node* ptr)
{
    this->ptr = ptr;
}

List::const_iterator::const_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
	ptr = nullptr;
}

List::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
	this->ptr = rhv.ptr;
}

List::const_reference List::const_iterator::operator*() const
{
    return ptr->data;
}

List::const_pointer List::const_iterator::operator->() const
{
    return &(ptr->data);
}

const List::const_iterator& List::const_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->next;
    return *this;
				
} 

const List::const_iterator& List::const_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
}

const List::const_iterator& List::const_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = rhv.ptr;
}

const List::const_iterator List::const_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_iterator tmp = *this;
    ptr = ptr->next;
    return tmp;
} 

const List::const_iterator& List::const_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->previous;
    return *this;
}

const List::const_iterator List::const_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_iterator tmp = *this;
    ptr = ptr->previous;
    return tmp;
}

explicit List::const_iterator::const_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::iterator::iterator(const base_iterator& rhv) : const_iterator(rhv)
{
    *this = rhv;
}

List::iterator::iterator(base_iterator&& rhv) : const_iterator(rhv)
{
    *this= rhv;
}

List::reference List::iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::pointer List::iterator::operator->()
{
    return &(ptr->data);
}

const List::iterator& List::iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::iterator& List::iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

explicit List::iterator::iterator(Node* ptr) : const_iterator(ptr)
{
    this->ptr = ptr;
}

List::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

List::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

const List::const_reverse_iterator& List::const_reverse_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

List::const_reference List::const_reverse_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::const_pointer List::const_reverse_iterator::operator->()const
{
    return &(ptr->data);
}

const List::const_reverse_iterator& List::const_reverse_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->next;
    return *this;
}

const List::const_reverse_iterator List::const_reverse_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_reverse_iterator tmp = *this;
    ptr = ptr->next;
    return tmp;
}

const List::const_reverse_iterator& List::const_reverse_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->previous;
    return *this;
}

const List::const_reverse_iterator List::const_reverse_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_reverse_iterator tmp = *this;
    ptr = ptr->previous;
    return tmp;
}

explicit List::const_reverse_iterator::const_reverse_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::reverse_iterator::reverse_iterator(const base_iterator& rhv) : const_reverse_iterator(rhv)
{
    *this = rhv;
}

List::reverse_iterator::reverse_iterator(base_iterator&& rhv) : const_reverse_iterator(rhv)
{
    *this = rhv;
}

List::reference List::reverse_iterator::operator*()
{
    return ptr->data;
}

List::pointer List::reverse_iterator::operator->()
{
    return &(ptr->data); 
}

const List::reverse_iterator& List::reverse_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::reverse_iterator& List::reverse_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

explicit List::reverse_iterator::reverse_iterator(Node* ptr) : const_reverse_iterator(ptr)
{
    this->ptr = ptr;
}

List::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

List::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

const List::const_asc_iterator& List::const_asc_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
}

const List::const_asc_iterator& List::const_asc_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
}

List::const_reference List::const_asc_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::const_pointer List::const_asc_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::const_asc_iterator& List::const_asc_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->great;
    return *this;
}

const List::const_asc_iterator List::const_asc_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_asc_iterator tmp = *this;
    ptr = ptr->great;
    return tmp;
}

const List::const_asc_iterator& List::const_asc_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->small;
    return *this;
}

const List::const_asc_iterator List::const_asc_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_asc_iterator tmp = *this;
    ptr = ptr->small;
    return tmp;
}

explicit List::const_asc_iterator::const_asc_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::asc_iterator::asc_iterator(const base_iterator& rhv) : const_asc_iterator(rhv)
{
    *this = rhv;
}

List::asc_iterator::asc_iterator(base_iterator&& rhv) : const_asc_iterator(rhv)
{
    *this = rhv;
}

List::reference List::asc_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::pointer List::asc_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::asc_iterator& List::asc_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::asc_iterator& List::asc_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

explicit List::asc_iterator::asc_iterator(Node* ptr) : const_asc_iterator(ptr)
{
    this->ptr = ptr;
}

List::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

List::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

const List::const_desc_iterator& List::const_desc_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::const_desc_iterator& List::const_desc_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}
List::const_reference List::const_desc_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::const_pointer List::const_desc_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::const_desc_iterator& List::const_desc_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->small;
    return *this;
}

const List::const_desc_iterator List::const_desc_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_desc_iterator tmp = *this;
    ptr = ptr->small;
    return tmp;
}

const List::const_desc_iterator& List::const_desc_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    ptr = ptr->great;
    return *this;
}

const List::const_desc_iterator List::const_desc_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    const_desc_iterator tmp = *this;
    ptr = ptr->great;
    return tmp;
}

explicit List::const_desc_iterator::const_desc_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::desc_iterator::desc_iterator(const base_iterator& rhv) : const_desc_iterator(rhv)
{
    *this = rhv; 
}

List::desc_iterator::desc_iterator(base_iterator&& rhv) : const_desc_iterator(rhv)
{
    *this = rhv; 
}

List::reference List::desc_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::pointer List::desc_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::desc_iterator& List::desc_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
}

const List::desc_iterator& List::desc_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
}

explicit List::desc_iterator::desc_iterator(Node* ptr) : const_desc_iterator(ptr)
{
    this->ptr = ptr;
}

List::const_multi_iterator::const_multi_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

List::const_multi_iterator::const_multi_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

const List::const_multi_iterator& List::const_multi_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::const_multi_iterator& List::const_multi_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

List::const_reference List::const_multi_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::const_pointer List::const_multi_iterator::operator->()const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::const_multi_iterator& List::const_multi_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        ptr = ptr->next;
        return *this;
    }
    ptr = ptr->great;
    return *this;
}

const List::const_multi_iterator List::const_multi_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        const_multi_iterator tmp = *this;
        ptr = ptr->next;
        return tmp;
    }
    const_multi_iterator tmp = *this;
    ptr = ptr->great;
    return tmp;
}

const List::const_multi_iterator& List::const_multi_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        ptr = ptr->previous;
        return *this;
    }
    ptr = ptr->small;
    return *this;
}

const List::const_multi_iterator List::const_multi_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        const_multi_iterator tmp = *this;
        ptr = ptr->previous;
        return tmp;
    }
    const_multi_iterator tmp = *this;
    ptr =ptr->small;
    return tmp;
}

void List::const_multi_iterator::chmod()
{
    mode = !mode;
}

explicit List::const_multi_iterator::const_multi_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::multi_iterator::multi_iterator(const base_iterator& rhv) : const_multi_iterator(rhv)
{
    *this = rhv;
}

List::multi_iterator::multi_iterator(base_iterator&& rhv) : const_multi_iterator(rhv)
{
    *this = rhv;
}

List::reference List::multi_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::pointer List::multi_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::multi_iterator& List::multi_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::multi_iterator List::multi_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

explicit List::multi_iterator::multi_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

List::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv) : base_iterator(rhv)
{
    *this = rhv;
}

const List::const_multi_reverse_iterator& List::const_multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
    return *this;
}

const List::const_multi_reverse_iterator List::const_multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
    return *this;
}

List::const_reference List::const_multi_reverse_iterator::operator*() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::const_pointer List::const_multi_reverse_iterator::operator->() const
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::const_multi_reverse_iterator& List::const_multi_reverse_iterator::operator++()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        ptr = ptr->great;
        return *this;
    }
    ptr = ptr->next;
    return *this;
}

const List::const_multi_reverse_iterator List::const_multi_reverse_iterator::operator++(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        const_multi_reverse_iterator tmp = *this;
        ptr = ptr->great;
        return tmp;
    }
    const_multi_reverse_iterator tmp = *this;
    ptr = ptr->next;
    return tmp;
}

const List::const_multi_reverse_iterator& List::const_multi_reverse_iterator::operator--()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        ptr = ptr->small;
        return *this;
    }
    ptr = ptr->previous;
    return *this;
}

const List::const_multi_reverse_iterator List::const_multi_reverse_iterator::operator--(value_type)
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    if(mode)
    {
        const_multi_reverse_iterator tmp = *this;
        ptr = ptr->small;
        return tmp;
    }
    const_multi_reverse_iterator tmp = *this;
    ptr = ptr->previous;
    return tmp;
}

void List::const_multi_reverse_iterator::chmod()
{
    mode = !mode;
}

explicit List::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr) : base_iterator(ptr)
{
    this->ptr = ptr;
}

List::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv) : const_multi_reverse_iterator(rhv)
{
    *this = rhv;
}

List::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv) : const_multi_reverse_iterator(rhv)
{
    *this = rhv;
}

List::reference List::multi_reverse_iterator::operator*()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return ptr->data;
}

List::pointer List::multi_reverse_iterator::operator->()
{
    if(!ptr)
    {
        throw std::out_of_range(" ");
    }
    return &(ptr->data);
}

const List::multi_reverse_iterator& List::multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    *this = rhv;
}

const List::multi_reverse_iterator& List::multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    *this = rhv;
}

explicit multi_reverse_iterator(Node* ptr)
{
    this->ptr = ptr;
}
