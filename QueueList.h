#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <algorithm>
#include <iterator>

class Iterator {
    int* _pos;
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = int;
            using difference_type = int;
            using pointer = int*;
            using reference = int&;
            Iterator(int* pos) : _pos(pos) {}
            bool operator==(Iterator const& other) const
            {
                return _pos == other._pos;
            }
            bool operator!=(Iterator const& other) const
            {
                return _pos != other._pos;
            }
            reference operator*() const
            {
                return *_pos;
            }
            pointer operator->() const
            {
                return _pos;
            }
            Iterator& operator++()
            {
                ++_pos;
                return *this;
            }
            Iterator operator++(int)
            {
                Iterator tmp = *this;
                ++_pos;
                return tmp;
            }
            Iterator& operator--()
            {
                --_pos;
                return *this;
            }
            Iterator operator--(int)
            {
                Iterator tmp = *this;
                --_pos;
                return tmp;
            }
            reference operator[](size_t index) const
            {
                return _pos[index];
            }
            Iterator operator+(difference_type const& diff) const
            {
                return Iterator(_pos + diff);
            }
            friend inline Iterator operator+(difference_type const& diff, Iterator const& it);
            Iterator operator-(difference_type const& diff) const
            {
                return Iterator(_pos - diff);
            }
            difference_type operator-(Iterator const& other) const
            {
                return std::distance(other._pos, _pos);
            }
            Iterator& operator+=(difference_type const& diff){
                _pos += diff;
                return *this;
            }
            Iterator& operator-=(difference_type const& diff){
                _pos -= diff;
                return *this;
            }
            bool operator>(Iterator const& other) const
            {
                return _pos > other._pos;
            }
            bool operator<(Iterator const& other) const
            {
            return _pos < other._pos;
            }
            bool operator>=(Iterator const& other) const
            {
                return _pos >= other._pos;
            }
            bool operator<=(Iterator const& other) const
            {
                return _pos <= other._pos;
            }
        };

class QueueList {
    int* _array;
    size_t _len;
    size_t _capacity;
        public:
            QueueList(const int* arr, size_t size);
            size_t length() const
            {
                return _len;
            }
            size_t size() const
            {
                return _len;
            }
            size_t capacity() const
            {
                return _capacity - 1;
            }
            int front() const
            {
                return _array[0];
            }
            int back() const
            {
                return _array[_len - 1];
            }
            bool empty()
            {
                return !_len;
            }
            void clear();
            void push_back(int a);
            int pop_front();
            ~QueueList()
            {
                delete[] _array;
            }
            QueueList(QueueList const& other);
            QueueList& operator=(QueueList const& other);
            Iterator begin() const;
            Iterator end() const;
        };

#endif