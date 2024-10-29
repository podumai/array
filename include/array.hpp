#ifndef __STACK_ARRAY__
#define __STACK_ARRAY__ 1

#include <initializer_list>
#include <cstddef>

namespace mpl
{

  namespace memory
  {

    template <class T, std::size_t init_size>
    class array
    {
      using size_type = std::size_t;
      using value_type = T;
      using pointer = T*;
      using reference = T&;

    private:
      class iterator
      {
      public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

      private:
        pointer m_element;

      public:
        iterator(pointer ptr)
          : m_element(ptr)
        {}

        [[nodiscard]] reference operator*() const noexcept
        {
          return *m_element;
        }

        [[nodiscard]] pointer operator->() const noexcept
        {
          return m_element;
        }

        iterator& operator++() noexcept
        {
          ++m_element;
          return *this;
        }

        iterator& operator++(std::int32_t) noexcept
        {
          iterator tmp(*this);
          ++m_element;
          return tmp;
        }

        [[nodiscard]] bool operator==(const iterator& other) const noexcept
        {
          return m_element == other.m_element;
        }

        [[nodiscard]] bool operator!=(const iterator& other) const noexcept
        {
          return !(*this == other.m_element);
        }
      };

      class const_iterator
      {
      public:
        using const_pointer = const T*;
        using const_reference = const T&;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

      private:
        pointer m_element;

      public:
        const_iterator(pointer ptr)
          : m_element(ptr)
        {}

        [[nodiscard]] const_reference operator*() const noexcept
        {
          return *m_element;
        }

        [[nodiscard]] pointer operator->() const noexcept
        {
          return static_cast<const_pointer>(m_element);
        }

        const_iterator& operator++() noexcept
        {
          ++m_element;
          return *this;
        }

        const_iterator& operator++(std::int32_t) noexcept
        {
          const_iterator tmp(*this);
          ++m_element;
          return tmp;
        }

        [[nodiscard]] bool operator==(const const_iterator& other) const noexcept
        {
          return m_element == other.m_element;
        }

        [[nodiscard]] bool operator!=(const const_iterator& other) const noexcept
        {
          return !(*this == other);
        }
      };

    private:
      T m_storage[init_size];

    public:
      constexpr array() = default;

      array(std::initializer_list<T> list)
      {
        if (init_size != list.size())
          throw std::invalid_argument("array:array() -> invalid number of args");

        size_type current_size{};
        for (auto begin{list.begin()}, end{list.end()}; begin != end; ++begin)
          m_storage[current_size++] = *begin;
      }

      constexpr array(const array&) = default;

      constexpr array(array&&) = default;

      [[nodiscard]] constexpr size_type size() const noexcept
      {
        return init_size;
      }

      [[nodiscard]] constexpr size_type max_size() const noexcept
      {
        return init_size;
      }

      [[nodiscard]] constexpr reference operator[](size_type index)
      {
        return m_storage[index];
      }

      [[nodiscard]] constexpr reference at(size_type index) const
      {
        if (index >= init_size)
          std::out_of_range("array:at(size_type) -> invalid index");

        return m_storage[index];
      }

      [[nodiscard]] constexpr reference front() const noexcept
      {
        return *m_storage;
      }

      [[nodiscard]] constexpr reference back() const noexcept
      {
        return m_storage[init_size - 1];
      }

      [[nodiscard]] constexpr pointer data() const noexcept
      {
        return m_storage;
      }

      [[nodiscard]] constexpr bool empty() const noexcept
      {
       return init_size == 0;
      }

      array& operator=(const array&) = default;

      array& operator=(array&&) = default;

      iterator begin() noexcept
      {
       return iterator(m_storage);
      }

      iterator end() noexcept
      {
        return iterator(m_storage + init_size);
      }

      const_iterator cbegin() noexcept
      {
        return const_iterator(m_storage);
      }

      const_iterator cend() noexcept
      {
        return const_iterator(m_storage + init_size);
      }
    };

  }

}

#endif