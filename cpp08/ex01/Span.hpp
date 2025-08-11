#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span();
		Span( Span const & src );
		Span(int N);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		Span &		operator=( Span const & rhs );

	private:
		int	m_maxN;
		std::vector<int> vect;
};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */