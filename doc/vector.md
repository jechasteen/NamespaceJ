# Vector

A vector is a sequential container that, in some ways, emulates a traditional array.
The vector differs from an array primarily in that a vector's size is variable.
But, like an array, a vector's elements live in contiguous memory locations and are, therefore, iterable via standard pointer incrementation.

In order to implement class Vector, I had to learn about the following topics:

* [Vector Basics](http://www.cplusplus.com/reference/vector/vector/)
* `std::unique_ptr`
* operator[] overloading

At time of writing, I was not able to configure a custom iterator for this class, so this class is limited to using `Vector::size()` to build a for loop.

Implementing dynamic memory management, so `shrink_to_fit`, `assign`, `swap`, and a few other methods are not implemented.
In order to implements some of these reassign/restructure methods, I'll have to spend some time learning about overloading `operator=` and maybe re-thinking the way that we handle the container itself.

## Details

The `dynamic` memory allocation procedure used here is naive.
We allocate memory in chunks, the size of which is designated by the constant `VECTOR_SIZE_INCREMENT`.
Each time we need more space, we allocate an additional `VECTOR_SIZE_INCREMENT` slots in a brand new array.

The private container variable is a `std::unique_ptr`, each time we have to expand or contract the size we have to create a new instance, populate it, and `std::move` it into `m_container`.
This has a downside in the sense that it creates complications when trying to overload `operator=`, we can't handle the move necessary in the class itself.

The class resizes itself in one direction only, upward in steps of `VECTOR_SIZE_INCREMENT`.
I suppose it would be good practice to check if the difference between size and max six are greater than the increment any time an item is removed.
We size up by creating a new `unique_ptr<T[]>` with the size incremented, then we move all of the old contents over by iterating through the array.
Finally we move the newly created container to the master container.

Operator[] is implemented very simply by returning requested index of the master container.
If the index passed is out of range, we throw an exception.

## Conclusion

I'm not sure why I decided to try tackling something as involved as a vector, but it was actually an informative experience.
Even though I was not able to actually implement a custom iterator, I learned a lot about the process and what it involves.
While trying to get some of the 'unimplemented' methods working, I ran in to a very frustrating (and uninformative) error message from gcc.

```
malloc(): corrupted top size
```

The error stems from my bone-headed misunderstanding of how to manage pointers to arrays, and how to handle assignment from one array to another.
In other words, I was trying to create a new `unique_ptr` array, put some stuff into it, and then move it to the master container array.
This doesn't work and, to be honest, I still don't know why.
The takeaway is that I need to hit the books, take some time to really understand the intricacies of a pointer-to-array.

Despite the memory-allocation-related woes, I actually learned a couple of very useful techniques by attempting (and almost failing) to implement a Vector.

* The `unique_ptr` can be used as a lazy 'garbage collection' method for pointers. Once ownership is lost, the pointer is deleted.
    - Trying to reassign a `unique_ptr` via `std::move()` is not as simple as it would seem
* `operator[]` can be overloaded to provide custom element access. This is a pretty simple process and I was very excited when it worked.
