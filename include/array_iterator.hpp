#ifndef __STACK_ARRAY_ITERATOR__
#define __STACK_ARRAY_ITERATOR__ 1

namespace memory
{

  namespace array_iterator
  {

    template<class T>
    class iterator
    {
    public:
      using pointer           = T*;
      using reference         = T&;
      using iterator_category = std::forward_iterator_tag;
      using difference_type   = std::ptrdiff_t;
    private:
      pointer m_element;
    public:
      iterator(pointer ptr) : m_element (ptr) {}

      reference operator*() const noexcept { return *m_element; }

      pointer operator->() const noexcept { return m_element; }
      
      iterator& operator++() noexcept { ++m_element; return *this; }

      iterator& operator++(std::int32_t) noexcept { iterator tmp (*this); ++m_element; return tmp; }

    };
    
    template<class T>
    class const_iterator
    {
    public:
      using pointer           = T*;
      using const_pointer     = const T* const;
      using const_reference   = const T&;
      using iterator_category = std::forward_iterator_tag;
      using difference_type   = std::ptrdiff_t;
    private:
      pointer m_element;
    public:
      const_iterator(pointer ptr) : m_element (ptr) {}

      const_reference operator*() const noexcept { return *m_element; }

      pointer operator->() const noexcept { return static_cast<const_pointer>(m_element); }

      const_iterator& operator++() noexcept { ++m_element; return *this; }

      const_iterator& operator++(std::int32_t) noexcept { const_iterator tmp (*this); ++m_element; return tmp; }

    };

  }
}

template<class T>
bool operator==(const memory::array_iterator::iterator<T>& lhs, const memory::array_iterator::iterator<T>& rhs)
{
  return *lhs == *rhs;
}

template<class T>
bool operator!=(const memory::array_iterator::iterator<T>& lhs, const memory::array_iterator::iterator<T>& rhs)
{
  return !(*lhs == *rhs);
}

template<class T>
bool operator==(const memory::array_iterator::const_iterator<T>& lhs, const memory::array_iterator::const_iterator<T>& rhs)
{
  return *lhs == *rhs;
}

template<class T>
bool operator!=(const memory::array_iterator::const_iterator<T>& lhs, const memory::array_iterator::const_iterator<T>& rhs)
{
  return !(*lhs == *rhs);
}

#endif