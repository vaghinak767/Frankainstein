#include "node.h"
class List
{
public:
  using value_type = int;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using pointer = value_type *;
  using const_pointer = const value_type *;

public:
  List();
  List(value_type size);
  List(size_type size, const_reference init);
  List(const List &other);
  List(List &&other);
  List(std::initializer_list<int> init);
  template <typename inpute_iterator>
  List(inpute_iterator f, inpute_iterator l);
  ~List();
  const List &operator=(const List &other);
  const List &operator=(List &&other);
  const List &operator=(std::initializer_list<value_type> init);
  bool operator==(const List &rhv) const;
  bool operator!=(const List &rhv) const;
  bool operator<(const List &rhv) const;
  bool operator<=(const List &rhv) const;
  bool operator>(const List &rhv) const;
  bool operator>=(const List &rhv) const;
  bool empty();
  void push_back(int el);
  void push_front(int el);
  void display_inc();
  void display_dec();
  void display();
  void erase(int pos);
  void erase(int first, int last);
  void dis();
  void insert(int index, int data);
  void pop_back();
  void pop_front();
  int size();
  int get(int index);
  void remove(int el);
  int operator[](int index);
  bool operator==(const List &ob) const;
  const List operator+(const List &ob);
  void swap(List &rhv);
  size_type size() const;
  void resize(size_type s, const_reference init = value_type());
  void clear() noexcept;
  const_reference front() const;
  reference front();
  const_reference back() const;
  reference back();
  const_reference min() const;
  reference min();
  const_reference max() const;
  reference max();
  void reveres();
  template <typename iter>
  iter erase(iter pos);
  template <typename iter>
  iter erase(iter f, iter l);

private:
  class base_iterator
  {
    friend List;

  public:
    ~base_iterator();
    bool operator==(const base_iterator &rhv) const;
    bool operator!=(const base_iterator &rhv) const;

  protected:
    explicit base_iterator(Node *ptr);

  protected:
    Node *ptr = nullptr;
  };

public:
  class const_iterator : public base_iterator
  {
    friend List;

  public:
    const_iterator(const base_iterator &rhv);
    const_iterator(base_iterator &&rhv);
    const const_iterator &operator=(const base_iterator &rhv);
    const const_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_iterator &operator++();
    const const_iterator operator++(value_type);
    const const_iterator &operator--();
    const const_iterator operator--(value_type);

  protected:
    explicit const_iterator(Node *ptr);
  };

public:
  class iterator : public const_iterator
  {
    friend List;

  public:
    iterator(const base_iterator &rhv);
    iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const iterator &operator=(const base_iterator &rhv);
    const iterator &operator=(base_iterator &&rhv);

  protected:
    explicit iterator(Node *ptr);
  };

public:
  class const_reverse_iterator : public base_iterator
  {
    friend List;

  public:
    const_reverse_iterator(const base_iterator &rhv);
    const_reverse_iterator(base_iterator &&rhv);
    const const_reverse_iterator &operator=(const base_iterator &rhv);
    const const_reverse_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_reverse_iterator &operator++();
    const const_reverse_iterator operator++(value_type);
    const const_reverse_iterator &operator--();
    const const_reverse_iterator operator--(value_type);

  protected:
    explicit const_reverse_iterator(Node *ptr);
  };

public:
  class reverse_iterator : public const_reverse_iterator
  {
    friend List;

  public:
    reverse_iterator(const base_iterator &rhv);
    reverse_iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const reverse_iterator &operator=(const base_iterator &rhv);
    const reverse_iterator &operator=(base_iterator &&rhv);

  protected:
    explicit reverse_iterator(Node *ptr);
  };

public:
  class const_asc_iterator : public base_iterator
  {
    friend List;

  public:
    const_asc_iterator(const base_iterator &rhv);
    const_asc_iterator(base_iterator &&rhv);
    const const_asc_iterator &operator=(const base_iterator &rhv);
    const const_asc_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_asc_iterator &operator++();
    const const_asc_iterator operator++(value_type);
    const const_asc_iterator &operator--();
    const const_asc_iterator operator--(value_type);

  protected:
    explicit const_asc_iterator(Node *ptr);
  };

public:
  class asc_iterator : public const_asc_iterator
  {
    friend List;

  public:
    asc_iterator(const base_iterator &rhv);
    asc_iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const asc_iterator &operator=(const base_iterator &rhv);
    const asc_iterator &operator=(base_iterator &&rhv);

  protected:
    explicit asc_iterator(Node *ptr);
  };

public:
  class const_desc_iterator : public base_iterator
  {
    friend List;

  public:
    const_desc_iterator(const base_iterator &rhv);
    const_desc_iterator(base_iterator &&rhv);
    const const_desc_iterator &operator=(const base_iterator &rhv);
    const const_desc_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_desc_iterator &operator++();
    const const_desc_iterator operator++(value_type);
    const const_desc_iterator &operator--();
    const const_desc_iterator operator--(value_type);

  protected:
    explicit const_desc_iterator(Node *ptr);
  };

public:
  class desc_iterator : public const_desc_iterator
  {
    friend List;

  public:
    desc_iterator(const base_iterator &rhv);
    desc_iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const desc_iterator &operator=(const base_iterator &rhv);
    const desc_iterator &operator=(base_iterator &&rhv);

  protected:
    explicit desc_iterator(Node *ptr);
  };

public:
  class const_multi_iterator : public base_iterator
  {
    friend List;

  public:
    const_multi_iterator(const base_iterator &rhv);
    const_multi_iterator(base_iterator &&rhv);
    const const_multi_iterator &operator=(const base_iterator &rhv);
    const const_multi_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_multi_iterator &operator++();
    const const_multi_iterator operator++(value_type);
    const const_multi_iterator &operator--();
    const const_multi_iterator operator--(value_type);
    void chmod();

  protected:
    explicit const_multi_iterator(Node *ptr);
    bool mode = true;
  };

public:
  class multi_iterator : public const_multi_iterator
  {
    friend List;

  public:
    multi_iterator(const base_iterator &rhv);
    multi_iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const multi_iterator &operator=(const base_iterator &rhv);
    const multi_iterator &operator=(base_iterator &&rhv);

  protected:
    explicit multi_iterator(Node *ptr);
  };

public:
  class const_multi_reverse_iterator : public base_iterator
  {
    friend List;

  public:
    const_multi_reverse_iterator(const base_iterator &rhv);
    const_multi_reverse_iterator(base_iterator &&rhv);
    const const_multi_reverse_iterator &operator=(const base_iterator &rhv);
    const const_multi_reverse_iterator &operator=(base_iterator &&rhv);
    const_reference operator*() const;
    const_pointer operator->() const;
    const const_multi_reverse_iterator &operator++();
    const const_multi_reverse_iterator operator++(value_type);
    const const_multi_reverse_iterator &operator--();
    const const_multi_reverse_iterator operator--(value_type);
    void chmod();

  protected:
    explicit const_multi_reverse_iterator(Node *ptr);
    bool mode = true;
  };

public:
  class multi_reverse_iterator : public const_multi_reverse_iterator
  {
    friend List;

  public:
    multi_reverse_iterator(const base_iterator &rhv);
    multi_reverse_iterator(base_iterator &&rhv);
    reference operator*();
    pointer operator->();
    const multi_reverse_iterator &operator=(const base_iterator &rhv);
    const multi_reverse_iterator &operator=(base_iterator &&rhv);

  protected:
    explicit multi_reverse_iterator(Node *ptr);
  };

protected:
  iterator find(const_reference elem);
  iterator rfind(const_reference elem);

public:
  void organize_left(Node *ptr);
  void organize_right(Node *ptr);
  const_iterator cbegin() const;
  const_iterator cend() const;
  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;
  const_asc_iterator cabegin() const;
  const_asc_iterator caend() const;
  const_desc_iterator cdbegin() const;
  const_desc_iterator cdend() const;
  const_multi_iterator cmbegin() const;
  const_multi_iterator cmend() const;
  const_multi_iterator cmabegin() const;
  const_multi_iterator cmaend() const; 
  const_multi_reverse_iterator cmrbegin() const;
  const_multi_reverse_iterator cmrend() const;
  const_multi_reverse_iterator cmrdbegin() const;
  const_multi_reverse_iterator cmrdend() const;
  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
  asc_iterator abegin();
  asc_iterator aend();
  desc_iterator dbegin();
  desc_iterator dend();
  multi_iterator mbegin();
  multi_iterator mend();
  multi_iterator mabegin();
  multi_iterator maend();
  multi_reverse_iterator mrbegin();
  multi_reverse_iterator mrend();
  multi_reverse_iterator mrdbegin();
  multi_reverse_iterator mrdend();
  // public:
  //     template <typename iter>
  //     typename std::enable_if<std::is_base_of<const_iterator, iter>::value ||
  //                               std::is_base_of<const_asc_iterator, iter>::value ||
  //                               std::is_base_of<const_multi_iterator, iter>::value,
  //              iter>::type
  //     insert(iter pos, const_reference val) { //O(1)
  //         return insert_def(pos, val);
  //     }

  //     template <typename iter>
  //     typename std::enable_if<std::is_base_of<const_reverse_iterator, iter>::value ||
  //                               std::is_base_of<const_desc_iterator, iter>::value ||
  //                               std::is_base_of<const_multi_reverse_iterator, iter>::value,
  //              iter>::type
  //     insert(iter pos, const_reference val) { //O(1)
  //         return insert_rev(pos, val);
  //     }
  // private:
  //     private:
  //     template <typename iter>
  //     iter insert_def(iter pos, const_reference val)
  //     {

  //     }

  //     template <typename iter>
  //     iter insert_rev(iter pos, const_reference val)
  //     {

  //     }
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
      Node *ptr = tmp;
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
      Node *ptr = tmp;
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
