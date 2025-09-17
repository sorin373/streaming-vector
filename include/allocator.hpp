#pragma once

#include <new>

namespace strm
{
    template <typename T>
    struct allocator
    {
        typedef T value_type;
        typedef T* pointer;

        typedef void* void_pointer;
        typedef const void* const_void_pointer;

        template <typename U>
        struct rebind { typedef allocator<U> other; };
        
        allocator() noexcept { }
        
        pointer allocate(unsigned int size, const_void_pointer hint = nullptr)
        {
            if (size == 0)
                return nullptr;

            pointer ptr = static_cast<pointer>(::operator new(size * sizeof(value_type)));

            if (ptr == nullptr)
                throw std::bad_alloc();

            return ptr;
        }

        void deallocate(pointer ptr, unsigned int)
        {
            ::operator delete(ptr);
        }
        
        ~allocator() noexcept { }
    };

    template <typename TypeI, typename TypeII>
    bool operator==(const allocator<TypeI>&, const allocator<TypeII>&) throw() { return true; }

    template <typename TypeI, typename TypeII>
    bool operator!=(const allocator<TypeI>&, const allocator<TypeII>&) throw() { return false; }
}


