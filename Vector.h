#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <LogStream.h>

const int VECTOR_SIZE_INCREMENT = 4;

namespace J {

template <typename T>
class Vector
{
    std::unique_ptr<T[]> m_container = std::make_unique<T[]>(VECTOR_SIZE_INCREMENT);
    unsigned int m_size {0};
    unsigned int m_total_size = VECTOR_SIZE_INCREMENT;
public:
    Vector() {}

    ~Vector() {}

    // Capacity
    unsigned int size() { return m_size; }
    unsigned int max_size() { return m_total_size; }
    bool is_empty() { return m_size == 0; }

    void resize(unsigned int n, T value = T())
    {
        if (n == m_total_size) return;

        std::unique_ptr<T[]> temp_container = std::make_unique<T[]>(n);
        if (n < m_total_size)
        {
             for (unsigned int i = 0; i < n; i++)
             {
                temp_container[i] = m_container[i];
             }
             m_container = std::move(temp_container);
             m_size = n;
             m_total_size = n;
        }
        else
        {
            for (unsigned int i = 0; i < n; i++)
            {
                if (i < m_size)
                {
                    temp_container[i] = m_container[i];
                }
                else
                {
                    temp_container[i] = value;
                }
            }
            m_container = std::move(temp_container);
        }
    }

    void shrink_to_fit() { J::dbg() << "Vector::shink_to_fit() not implemented"; }

    // Modifiers
    void push_back(T element)
    {
        if (m_size < m_total_size)
        {
            m_container[m_size] = element;
            m_size++;
        }
        else
        {
            m_total_size = m_total_size + VECTOR_SIZE_INCREMENT;
            resize(m_total_size);
            m_container[m_size] = element;
            m_size++;
        }
    }

    T pop_back()
    {
        --m_size;
        T retval = m_container[m_size];
        m_container[m_size] = T();
        return retval;
    }

    void assign(unsigned int n, const T val) { J::dbg() << "Vector::assign not implemented"; }
    void swap(Vector<T> vec) { J::dbg() << "Vector::swap() not implemented"; }
    
    // Element Access

    T &operator[](unsigned int index)
    {
        if (index < m_size)
        {
            return m_container[index];
        }
        else
        {
            J::dbg() << "Vector[] index out of range.";
            throw std::out_of_range("Vector[] index out of range");
        }
    }

    T at(unsigned int index) 
    { 
        if (index < m_size)
            return m_container[index];
        else
        {
            J::dbg() << "Vector::at() index out of range!";
            throw std::out_of_range("Vector::at() index out of range!");
        }
    }

    T front() { return m_container[0]; }
    T back() { return m_container[m_size - 1]; }
    T *data() { return m_container.get(); }
};

}

#endif // Vector.h
