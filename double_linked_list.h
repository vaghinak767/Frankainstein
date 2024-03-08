#include "node.h"
class List
{
public:
	using value_type = int;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
public:
    List();
    List(value_type size);
    List(size_type size, const_reference init);
    List(const List &other);
    List(List &&other);
    List(std::initializer_list<int> init);
    template<typename inpute_iterator>
    List(intput_iterator f, input_iterator l);
    ~List();
    const List &operator=(const List &other);
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
	class base_iterator
    {
        friend List;
    public:
        ~base_iterator();
        bool operator==(const base_iterator& rhv) const;
        bool operator!=(const base_iterator& rhv) const;
    protected:
        explicit base_iterator(Node* ptr);
    protected:
        Node* ptr = nullptr;
    };
	public:
		class const_iterator : public base_iterator
		{
			friend List;
			public:
				const_iterator(const base_iterator& rhv);
				const_iterator(base_iterator&& rhv);	
				const const_iterator& operator=(const base_iterator& rhv);
				const const_iterator& operator=(base_iterator&& rhv);
				const_reference operator*() const;
				const_pointer operator->() const;
				const const_iterator& operator++();
				const const_iterator operator++(value_type);
				const const_iterator& operator--();
				const const_iterator operator--(value_type);
			protected:
				explicit const_iterator(Node* ptr);
		};
	public:
		class iterator : public const_iterator
		{
			friend List;
		public:
			iterator(const base_iterator& rhv);
			iterator(base_iterator&& rhv);
			reference operator*();
			pointer operator->();
			const iterator& operator=(const base_iterator& rhv);
			const iterator& operator=(base_iterator&& rhv);
		protected:
			explicit iterator(Node* ptr);
		};
	public:
    class const_reverse_iterator : public base_iterator
    {
        friend List;
    public:
        const_reverse_iterator(const base_iterator& rhv);
        const_reverse_iterator(base_iterator&& rhv);
        const const_reverse_iterator& operator=(const base_iterator& rhv);
        const const_reverse_iterator& operator=(base_iterator&& rhv);
        const_reference operator*() const;
        const_pointer operator->() const;
        const const_reverse_iterator& operator++();
        const const_reverse_iterator operator++(value_type);
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator--(value_type);
    protected:
        explicit const_reverse_iterator(Node* ptr);
    };
	public:
    class reverse_iterator : public const_reverse_iterator
    {
        friend List;
    public:
        reverse_iterator(const base_iterator& rhv);
        reverse_iterator(base_iterator&& rhv);
        reference operator*();
        pointer operator->();
		const reverse_iterator& operator=(const base_iterator& rhv);
        const reverse_iterator& operator=(base_iterator&& rhv);
    protected:
        explicit reverse_iterator(Node* ptr);
    };
	public:
	class const_asc_iterator :public base_iterator
    {
        friend List;
    public:
        const_asc_iterator(const base_iterator& rhv);
        const_asc_iterator(base_iterator&& rhv);
        const const_asc_iterator& operator=(const base_iterator& rhv);
        const const_asc_iterator& operator=(base_iterator&& rhv);
        const_reference operator*() const;
        const_pointer operator->() const;
        const const_asc_iterator& operator++();
        const const_asc_iterator operator++(value_type);
        const const_asc_iterator& operator--();
        const const_asc_iterator operator--(value_type);
    protected:
        explicit const_asc_iterator(Node* ptr);
    };
	public:
		class asc_iterator : public const_asc_iterator
		{
			friend List;
		public:
			asc_iterator(const base_iterator& rhv);
			asc_iterator(base_iterator&& rhv);
			reference operator*();
			pointer operator->();
			const asc_iterator& operator=(const base_iterator& rhv);
			const asc_iterator& operator=(base_iterator&& rhv);
		protected:
			explicit asc_iterator(Node* ptr);
		};
public:
	class const_desc_iterator : public base_iterator
	{
		friend List;
	public:
		const_desc_iterator(const base_iterator& rhv);
		const_desc_iterator(base_iterator&& rhv);
		const const_desc_iterator& operator=(const base_iterator& rhv);
		const const_desc_iterator& operator=(base_iterator&& rhv);
		const_reference operator*() const;
		const_pointer operator->() const;
		const const_desc_iterator& operator++();
		const const_desc_iterator operator++(value_type);
		const const_desc_iterator& operator--();
		const const_desc_iterator operator--(value_type);
	protected:
		explicit const_desc_iterator(Node* ptr);
	};
public:
    class desc_iterator : public const_desc_iterator
    {
        friend List;
    public:
        desc_iterator(const base_iterator& rhv);
        desc_iterator(base_iterator&& rhv);
        reference operator*();
        pointer operator->();
        const desc_iterator& operator=(const base_iterator& rhv);
        const desc_iterator& operator=(base_iterator&& rhv);
    protected:
        explicit desc_iterator(Node* ptr);
    };
public:
    class const_multi_iterator : public base_iterator
    {
        friend List;
    public:
        const_multi_iterator(const base_iterator& rhv);
        const_multi_iterator(base_iterator&& rhv);
        const const_multi_iterator& operator=(const base_iterator& rhv);
        const const_multi_iterator& operator=(base_iterator&& rhv);
        const_reference operator*() const;
        const_pointer operator->() const;
        const const_multi_iterator& operator++();
        const const_multi_iterator operator++(value_type);
        const const_multi_iterator& operator--();
        const const_multi_iterator operator--(value_type);
        void chmod();
    protected:
        explicit const_multi_iterator(Node* ptr);
        bool mode = true;
    };
public:
    class multi_iterator : public const_multi_iterator
    {
        friend List;
    public:
        multi_iterator(const base_iterator& rhv);
        multi_iterator(base_iterator&& rhv);
        reference operator*();
        pointer operator->();
        const multi_iterator& operator=(const base_iterator& rhv);
        const multi_iterator& operator=(base_iterator&& rhv);     
    protected:
        explicit multi_iterator(Node* ptr);
    };
public:
    class const_multi_reverse_iterator : public base_iterator
    {
        friend List;
    public:
        const_multi_reverse_iterator(const base_iterator& rhv);
        const_multi_reverse_iterator(base_iterator&& rhv);
        const const_multi_reverse_iterator& operator=(const base_iterator& rhv);
        const const_multi_reverse_iterator& operator=(base_iterator&& rhv);
        const_reference operator*() const;
        const_pointer operator->() const;
        const const_multi_reverse_iterator& operator++();
        const const_multi_reverse_iterator operator++(value_type);
        const const_multi_reverse_iterator& operator--();
        const const_multi_reverse_iterator operator--(value_type);
        void chmod();
    protected:
        explicit const_multi_reverse_iterator(Node* ptr);
        bool mode = true;
    };
public:
    class multi_reverse_iterator : public const_multi_reverse_iterator
    {
        friend List;
    public:
        multi_reverse_iterator(const base_iterator& rhv);
        multi_reverse_iterator(base_iterator&& rhv);
        reference operator*();
        pointer operator->();
        const multi_reverse_iterator& operator=(const base_iterator& rhv);
        const multi_reverse_iterator& operator=(base_iterator&& rhv);
    protected:
        explicit multi_reverse_iterator(Node* ptr);
    };
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
