# include <exception>
# include <iostream>
# include <cstddef>

template<typename T>
Array<T>::Array(void) : m_array(NULL), m_size(0) {

}

template<typename T>
Array<T>::Array(unsigned int n) : m_array(new T[n]), m_size(n)
{
}

template<typename T>
Array<T>::Array(Array const &obj) : m_array(new T[obj.m_size]), m_size(obj.m_size)
{
	for (size_t i = 0; i < this->m_size; i++)
		this->m_array[i] = obj.m_array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] m_array;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &src)
{
	{
		if (this->m_size != src.m_size)
		{
			delete [] m_array;
			this->m_size = src.m_size;
			this->m_array = new T[this->m_size];
		}
		for (size_t i = 0; i < this->m_size; i++)
			this->m_array[i] = src.m_array[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->m_size)
		throw(OutofBoundsException());
	return (this->m_array[index]);
}

template<typename T>
size_t Array<T>::size() const
{
	return (this->m_size);
}

template <typename T>
std::ostream &operator<<(std::ostream &outf, Array<T> &obj)
{
	size_t len = obj.size();

	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << obj[i];
		if (i < len - 1)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
	return (outf);
}

