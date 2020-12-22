#pragma once
#include <string>

typedef int value_type;
class LinkedList {
    
    struct Node {
        value_type value;
        Node* prev;
        Node* next;

        Node();
        explicit Node(value_type val);
        explicit Node(value_type val, Node* prev, Node* next);
    };

    Node* tail;
    int capacity = 0;

public:

    class iterator {
        
        Node* curInList;
    public:
        iterator();
        explicit iterator(Node* node);
        iterator & operator=(const iterator & other);
        bool operator!=(const iterator & other) const;
        bool operator==(const iterator & other) const;

        value_type & operator*();

        value_type * operator->();

        iterator & operator++();
        iterator operator++(int);
        iterator & operator--();
        iterator operator--(int);
        iterator operator+(int shift);
        iterator operator-(int shift);

        Node* getCurInList();
    };
    class const_iterator {
        Node* curInList;
    public:
        const_iterator();
        explicit const_iterator(Node* node);
        const_iterator & operator=(const const_iterator & other);
        bool operator!=(const const_iterator & other) const;
        bool operator==(const const_iterator & other) const;
        const value_type & operator*() const;
        const value_type * operator->() const;

        const_iterator & operator++();
        const_iterator operator++(int);
        const_iterator & operator--();
        const_iterator operator--(int);
        const_iterator operator+(int shift);
        const_iterator operator-(int shift);

        Node* getCurInList();
    };

    LinkedList();
    LinkedList(const LinkedList & other);
    LinkedList(LinkedList && other) noexcept ;


    ~LinkedList();


    LinkedList & operator=(const LinkedList & other);
    LinkedList & operator=(LinkedList && other);


    iterator begin();
    const_iterator cbegin() const;

    iterator end();
    const_iterator cend() const;


    int size() const;
    bool empty() const;


    value_type & front();
    const value_type & front() const;

    value_type & back();
    const value_type & back() const;


    iterator erase(iterator position);

    iterator erase(iterator begin, iterator end);

    int remove(const value_type & value);

    void clear();


    void pop_back();

    void pop_front();

    void push_back(const value_type & value);

    void push_front(const value_type & value);

    iterator insert(iterator before, const value_type & value);


    LinkedList & operator+=(const LinkedList & other);


    friend bool operator!=(const LinkedList & left, const LinkedList & right);
    friend bool operator==(const LinkedList & left, const LinkedList & right);

};


bool operator!=(const LinkedList & left, const LinkedList & right);
bool operator==(const LinkedList & left, const LinkedList & right);

LinkedList operator+(const LinkedList & left, const LinkedList &right);

