#include <String.hpp>
#include <iostream>

class String
{
	char *m_str;
	size_t m_size;

public:
	String(char *s)
	{
		std::cout << "Constr" << std::endl;
		m_size = strlen(s) + 1;
		m_str = new char[m_size];
		std::copy(s, s + m_size, m_str);
	}

	String(const String &other) : String(other.m_str)
	{
		std::cout << "Copy constr" << std::endl;
		/*
		Без делегирующего конструктора
		m_size = other.m_size;
		m_str = new char[m_size];
		std::copy(other.m_str, other.m_str + other.m_size, m_str);
		*/
	}
	// слева - this, справа - other;
	// s2 = (s2 = s1);
private:
	void Swap(String s)
	{
		std::swap(m_str, s.m_str);
		std::swap(m_size, s.m_size);
	}

public:
	/*String& operator=(const String &other)
	{
		std::cout << "Copy operator" << std::endl;
		String copy = other;
		Swap(copy);

		delete[] m_str;
		m_size = other.m_size;
		m_str = new char[m_size];
		std::copy(other.m_str, other.m_str + other.m_size, m_str);
		return *this;
	}*/
	String &operator=(String copy)
	{
		std::cout << "Copy operator v2.0" << std::endl;
		Swap(copy);
		return *this;
	}

	void Print()
	{
		std::cout << m_str << std::endl;
	}

	~String()
	{
		delete[] m_str;
		std::cout << "Destr" << std::endl;
	}
};

int main()
{
	String s1("abc");
	std::cout << "s1 = ";
	s1.Print();
	String s2 = s1;
	String s3("Hello");
	s2.Print();
	s3 = s2 = s1;
	std::cout << "s2 = ";
	s2.Print();
	std::cout << "s3 = ";
	s3.Print();
	return 0;
}