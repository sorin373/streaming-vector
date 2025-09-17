#pragma once

#include "allocator.hpp"

namespace strm
{
    namespace __details
    {
        typedef typeof(sizeof(0))   size_t;

        template <typename Key, typename T, typename Allocator = strm::allocator<T>>
        class mem_chunks
        {
            using bucket_allocator = typename Allocator::template rebind<stl::pair_node<Key, T>*>::other;

        public:
            typedef T mapped_type;
            typedef Key key_type;
            typedef size_t size_type;

        mem_chunks()
            : m_table(nullptr), m_size(0), m_capacity(16) { }

        private:
            mapped_type** m_table;
            size_type m_size;
            size_type m_capacity;

            void m_default_init(const size_type bucket_count);
        };
    }

    template <typename T, typename Allocator>
    class vector 
    {
        
    public:
        typedef T                   value_type;
        typedef __details::size_t   size_type;
        
    private:
        size_type m_elem;
        size_type m_chunk;
        char      m_path[101];
    };
};