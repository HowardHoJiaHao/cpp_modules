#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <iostream>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void addNumber(int number);

		int shortestSpan() const;
		int longestSpan() const;

		unsigned int size() const;
		unsigned int maxSize() const;
		std::vector<int> getNumbers() const;


		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

		template <typename T>
		void printVector(const std::vector<T>& v)
		{
			for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

};


#endif