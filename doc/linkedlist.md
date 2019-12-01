# Linked List

## Singly linked list

The Singly-linked list (SLL) is a simple data type where each item consists of

* Data (of a certain type)
* A pointer to the next item

In order to implement an SLL, I had to learn about the following topics:

* [SLL basics](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list)
* C++ class templates
* Iteration using pointers (terminated with `nullptr`)

The downside of the SLL is that iteration can be time consuming.
In order to find an element in the list, one must run through all of the items in the list before it.
The only easy to retrieve items are the head and tail, they are held in class member variables, accessable via getters.
Also, the SLL is iterable in one direction only: from head to tail.

In the SinglyLinkedList class, I have implemented function that can add a node at the beginning or end, add a node after a particular node, delete a node at beginning or end ("pop"ping it off and returning the value), and deleting a particular node.

### struct sll_node

Each entry in a linked list is called a node.
For the SLL class, I have created a struct to represent a node:

```cpp
template <typename T>
struct sll_node
{
    T data;
    sll_node<T> *next;
}
```

In C++, the template keyword allows us to specify generic function, classes, structs, or what-have-you such that `typename T` is replaces by whatever the user defines.
So in this case, we have a struct that represents our node where `T` would be replaced by whatever type is specified.
e.g. `sll_node<unsigned int> *new_node = new sll_node<unsigned int>`

Each node in the list follows this specification and can not stray from it.
The sll_node struct is public `J::sll_node<T>`, but one doesn't use it directly, as will be covered shortly.

### class SinglyLinkedList

The class also uses a template, for the very same reason as the struct.
We must pass values of the same type specified at instantiation, otherwise the compiler will complain.

There are two private variables here, `m_head` and `m_tail`, which represent the beginning and end of the list.
If we instantiate by `J::SinglyLinkedList<T> sll;` then we have an empty list, i.e. a list where both the head and tail are `nullptr`.
We can also instantiate by passing a value of type `T` to the constructor `J::SinglyLinkedList<T> sll(somevalueoftypeT)`.
The second option sets both the head and tail to the same node.

After we have instantiated an SLL, we can then begin adding, inserting, and removing items from it.
Each of these operations can take place at 3(ish) locations: beginning, end, or somewhere in the middle.

The most basic operation is `create_node`, which simply creates a new node of type T, adds it after the tail, and makes it the new tail (which the old tail now points to).
If the head is `nullptr`, we have to make a special consideration here, the same that was mentioned above.
That is, we set both the head *and* the tail to the same node that was just created;
Now, the head and the tail hold the same data, and they both point to `nullptr` as the next item.

We can also insert a node at the beginning, end, or middle of the chain.
The method `insert_end` simply calls `create_node` with the passed value.
`insert_begin` is a bit more complicated, but still very simple.
We just simply make the newly-created node point to the old head, then assign the head to be the new node.
Inserting in the middle finds a node that matches the passed value, then jams a newly-created node in between.
The node that will go before points to the new node, and the new node points to where the node before *used to* point to.

I decided to make removal operations returned the value of the removed node.
This is simply for convenience, the value could very well be disregarded by the calling context.
`sll.pop()` comes in two overloaded forms: one that pops the tail, the other pops a node matching the passed value.
Either way, we have to iterate through the whole list so it will be an expensive operation.
Since this is a singly linked list, we don't have any information about a node's predecessor, therefore in order to get that information we have to traverse the whole list.

Popping off of the front is substantially easier.
We just have to make the second node the new head and delete the old one.

### Conclusion

This is my first time using a linked list of any kind, let alone implementing it myself.
The biggest thing I learned by creating the SLL is the power of C++ templates.
I can write one whatever and it can be used to create an instance that follows whatever type I need.
This is particularly useful in this case.
We don't want to have to write special code to handle `int`s, `char`s, etc, we want to write it once and forget it.

One thing I am left wondering about after having "finished" this exercise is how do I go about iterating over this in a simple way.
In my testing I used an atrociously verbose for loop:

```cpp
for (sll_node<T> *it = sll.begin(); it != nullptr; it = it->next)
{
    ...
}
```
This works, but it is horrible to type and is very ugly.