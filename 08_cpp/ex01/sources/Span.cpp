#include "../includes/Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <random>

Span::Span(void) : _n(0), _size(0), _arr(nullptr) {}

Span::Span(unsigned int n) : _n(n), _size(0), _arr(new int[n]) {}

Span::Span(Span const &source) : _n(source._n), _size(source._size), _arr(new int[source._n])
{
    std::copy(source._arr, source._arr + source._size, _arr);
}

Span::~Span(void)
{
    delete[] _arr;
}

Span &Span::operator=(Span const &source)
{
    if (this != &source)
    {
        delete[] _arr;
        _n = source._n;
        _size = source._size;
        _arr = new int[source._n];
        std::copy(source._arr, source._arr + source._size, _arr);
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_size >= _n)
        throw std::out_of_range("Span is full");
    _arr[_size++] = n;
}

int Span::shortestSpan(void)
{
    if (_size <= 1)
        throw std::out_of_range("Span is too small");
    std::sort(_arr, _arr + _size);
    int shortest = _arr[1] - _arr[0];
    for (unsigned int i = 2; i < _size; i++)
    {
        int diff = _arr[i] - _arr[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan(void)
{
    if (_size <= 1)
        throw std::out_of_range("Span is too small");
    std::sort(_arr, _arr + _size);
    return _arr[_size - 1] - _arr[0];
}

void Span::addRange(int start, int end)
{
    if (_size + (end - start + 1) > _n)
        throw std::out_of_range("Span is full");
    for (int i = start; i <= end; i++)
        _arr[_size++] = i;
}

void Span::addRandom(int amount)
{
    if (_size + amount > _n)
        throw std::out_of_range("Span is full");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < amount; i++)
        _arr[_size++] = dis(gen);
}
