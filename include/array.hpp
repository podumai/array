#ifndef __STACK_ARRAY__
#define __STACK_ARRAY__ 1

#include <initializer_list>
#include <cstddef>
#include "array_iterator.hpp"

namespace memory
{

  template<typename T, std::size_t init_size>
  class array
  {
    using size_type  = std::size_t;
    using value_type = T;
    using pointer    = T*;
    using reference  = T&;
  private:
    T m_storage[init_size];
  public:
    array() = default;

    constexpr array(std::initializer_list<T> list)
    {
      if (init_size != list.size()) throw std::invalid_argument("array:array() -> invalid number of args");

      size_type current_size {};
      for (auto begin {list.begin()}, end {list.end()}; begin != end; ++begin)
        m_storage[current_size++] = *begin;
    }
    size_type size() const noexcept { return init_size; }

    size_type max_size() const noexcept { return init_size; }

    reference operator[](size_type index) { return m_storage[index]; }

    reference at(size_type index) const
    {
      if (index >= init_size)
        std::out_of_range("array:at(size_type) -> invalid index");
      
      return m_storage[index];
    }

    reference front() const noexcept { return *m_storage; }

    reference back() const noexcept { return m_storage[init_size - 1]; }
    
    pointer data() const noexcept { return m_storage; }
    
    constexpr bool empty() const noexcept { return init_size == 0; }

    array_iterator::iterator<T> begin() noexcept { return array_iterator::iterator<T>(m_storage); }

    array_iterator::iterator<T> end() noexcept { return array_iterator::iterator<T>(m_storage + init_size); }

    array_iterator::const_iterator<T> cbegin() noexcept { return array_iterator::const_iterator<T>(m_storage); }

    array_iterator::const_iterator<T> cend() noexcept { return array_iterator::const_iterator<T>(m_storage + init_size); }

  };

}

#endif