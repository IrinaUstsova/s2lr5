#include "QueueList.h"

QueueList::QueueList(const int* arr, size_t size)
{
    _len = size;
    _capacity = size + 10;
    _array = const_cast<int*>(arr);
    _array = (int*) realloc(_array, _capacity * sizeof(int));
}
QueueList::QueueList(QueueList const& other) : _len(other._len), _capacity(other._capacity)
{
    if (_capacity == 1)
        _array = new int[1];
    else
    {
        _array = new int[_capacity];
        for (size_t i = 0; i < _len; ++i)
            _array[i] = other._array[i];

    }
}
QueueList& QueueList::operator=(QueueList const& other){
    if (this != &other)
    {
        if (_capacity != other._capacity)
        {
            delete[] _array;
            _capacity = other._capacity;
            _array = new int[_capacity];
        }
        _len = other._len;
        for (size_t i = 0; i < _len; ++i)
            _array[i] = other._array[i];

    }
    return *this;
}
Iterator operator+(Iterator::difference_type const& diff, Iterator const& it)
{
    return Iterator(it._pos + diff);
}
Iterator QueueList::begin() const
{
    return Iterator(&_array[0]);
}
Iterator QueueList::end() const
{
    return Iterator(&_array[_len]);
}

void QueueList::clear() {
    if(!empty()){
        delete[] _array;
        _len = 0;
        _capacity = 1;
        _array = new int[_capacity];
    }
}

void QueueList::push_back(int a) {
    if ((_len + 1) == _capacity){
        _capacity += 10;
        _array = (int*)realloc(_array, _capacity * sizeof(int));
    }
    _array[_len] = a;
    _len++;
}

int QueueList::pop_front() {
    if(empty())return 0;
    int tmp = _array[0];
    int* newarray = new int[_capacity];
    for (int i = 1; i < _len; ++i) {
        newarray[i - 1] = _array[i];
    }
    delete[] _array;
    _array = newarray;
    return tmp;
}
