#include "node.h"

class List
{
public:
    List();
    ~List();
    List(const List &other);
    const List &operator=(const List &other);
    List(List &&other);
    const List &operator=(List &&other);
    bool empty();
    void push_back(int el);
    void push_front(int el);
    void display_inc();
    void display_dec();
    void display();
    void erase(int pos);
    void erase(int first, int last);
    void dis();
    void pop_back();
    void pop_front();
    int size();
    void insert(int index, int data);
    int get(int index);
    void remove(int el);
    int operator[](int index);
    bool operator==(const List& ob)const;
    const List operator+(const List& ob);
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *l_great = nullptr;
    Node *l_small = nullptr;
    int m_size = 0;
    void sort(Node *tmp)
    {
        --m_size;
        if (tmp->small && tmp->small->great)
            tmp->small->great = tmp->great;
        if (tmp->previous && tmp->previous->next)
            tmp->previous->next = tmp->next;
        if (tmp->great && tmp->great->small)
            tmp->great->small = tmp->small;
        if (tmp->next && tmp->next->previous)
            tmp->next->previous = tmp->previous;
        Node *ptr = tmp;
        if ((tmp->next != nullptr) && (!tmp->next->previous))
        {
            head = tmp->next;
        }
        if ((tmp->previous != nullptr) && (!tmp->previous->next))
        {
            tail = tmp->previous;
        }
        if ((tmp->small != nullptr) && (!tmp->small->great))
        {
            l_great = tmp->small;
        }
        if ((tmp->great != nullptr) && (!tmp->great->small))
        {
            l_small = tmp->great;
        }
    }
    void clear(Node *tmp)
    {
        while (tmp)
        {
            Node* ptr = tmp;
            sort(tmp);
            tmp = tmp->great;
            if (!tmp)
            {
                delete ptr;
                return;
            }
            else
            {
                delete ptr;
            }
        }
    }
    void clear(Node *tmp, int first, int last)
    {
        while (first < last)
        {
            Node* ptr = tmp;
            sort(tmp);
            tmp = tmp->great;
            if (!tmp)
            {
                delete ptr;
                return;
            }
            else
            {
                first = tmp->data;
                delete ptr;
            }
        }
    }
};