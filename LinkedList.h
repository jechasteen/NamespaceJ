#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace J
{

template <typename T>
struct sll_node
{
    T data;
    sll_node<T> *next;
};

template <typename T>
class SinglyLinkedList
{
    sll_node<T> *m_head;
    sll_node<T> *m_tail;
public:
    SinglyLinkedList()
    {
        m_head = nullptr;
        m_tail = nullptr;
    }

    SinglyLinkedList(T value)
    {
        m_head->value = value;
        m_head->next = nullptr;
        m_tail = m_head;
    }

    void create_node(T value)
    {
        sll_node<T> *temp = new sll_node<T>;
        temp->data = value;
        temp->next = nullptr;
        if (m_head == nullptr)
        {
            m_head = temp;
            m_tail = temp;
            temp = nullptr;
        }
        else
        {
            m_tail->next = temp;
            m_tail = temp;
        }
        
    }

    void insert_begin(T value)
    {
        sll_node<T> *temp = new sll_node<T>;
        temp->data = value;
        temp->next = m_head;
        m_head = temp;
    }

    void insert_end(T value) { create_node(value); }

    void insert_after(T match, T value)
    {
        sll_node<T> *temp = m_head;
        while (temp != nullptr)
        {
            if (temp->data == match)
            {
                sll_node<T> *new_node = new sll_node<T>;
                new_node->data = value;
                new_node->next = temp->next;
                temp->next = new_node;
                break;
            }
        }
    }

    T pop()
    {
        sll_node<T> *current = new sll_node<T>;
        sll_node<T> *previous = new sll_node<T>;
        current = m_head;
        // Using current->next here because we actually want to stop at the last entry not step through it
        while(current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        m_tail = previous;
        m_tail->next = nullptr;
        T return_data = current->data;
        delete current;
        return return_data;
    }

    T pop(T node_data)
    {
        sll_node<T> *previous = new sll_node<T>;
        sll_node<T> *current = new sll_node<T>;
        current = m_head;
        while (current != nullptr)
        {
            previous = current;
            current = current->next;
            if (current->data == node_data)
            {
                break;
            }
        }
        previous->next = current->next;
        return current->data;
    }

    T pop_front()
    {
        sll_node<T> *new_head = m_head->next;
        sll_node<T> *cur_head = m_head;
        T return_data = cur_head->data;
        m_head = new_head;
        delete cur_head;
        return return_data;
    }

    sll_node<T> *begin() { return m_head; }
    sll_node<T> *end() { return m_tail; }
};

}

#endif // LinkedList.h
