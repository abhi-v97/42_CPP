#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>

class Span
{

	public:

		Span();
		Span( Span const & src );
		Span(int N);
		~Span();

		void addNumber(int n);

		template <typename Iter>
		void addRange(Iter begin, Iter end);
		int shortestSpan();
		int longestSpan();
		Span &operator=( Span const & rhs );
		std::vector<int> getVect() const;

		class isFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class invalidSizeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		int			m_maxN;
		std::vector<int>	vect;
};

template <typename Iter>
void Span::addRange(Iter begin, Iter end)
{
	for (Iter i = begin; i != end; i++)
		addNumber(*i);
}
std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */
