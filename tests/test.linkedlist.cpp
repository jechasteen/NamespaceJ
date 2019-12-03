#include <LogStream.h>
#include <LinkedList.h>
#include <iostream>

template <typename T>
void print_sll(J::sll_node<T> *node)
{
    while (node != nullptr)
    {
        std::cout << node->data << std::endl;
        node = node->next;
    }
}

void test_singly_linked_list()
{
    J::dbg() << "Singly Linked List";
    J::SinglyLinkedList<int> int_sll;

    J::dbg() << "Ints: 1 2 3";
    int_sll.create_node(1);
    int_sll.create_node(2);
    int_sll.create_node(3);

    J::sll_node<int> *int_node = int_sll.begin();

    print_sll(int_node);

    J::dbg() << "Test singly linked list insert_begin()";
    int_sll.insert_begin(0);

    int_node = int_sll.begin();

    print_sll(int_node);

    J::dbg() << "Test singly linked list insert_end()";
    int_sll.insert_end(4);

    int_node = int_sll.begin();

    print_sll(int_node);

    J::dbg() << "Test singly linked list insert_after()";
    int_sll.insert_after(0, 999);

    print_sll(int_node);

    J::dbg() << "Test singly linked list pop_front()";
    int popped = int_sll.pop_front();
    J::dbg() << "Popped value: " << popped;
    print_sll(int_sll.begin());

    J::dbg() << "Test singly linked list pop()";
    popped = int_sll.pop();
    J::dbg() << "Popped value: " << popped;
    print_sll(int_sll.begin());

    J::dbg() << "Test singly linked list pop(2)";
    popped = int_sll.pop(2);
    J::dbg() << "Popped value: " << popped;
    print_sll(int_sll.begin());

    J::dbg() << "Test singly linked list iteration";
    for (J::sll_node<int> *it = int_sll.begin(); it != nullptr; it = it->next)
    {
        J::dbg() << it->data;
    }
}

int main()
{
    J::dbg() << "Testing linked list";
    test_singly_linked_list();

    return 0;
}
