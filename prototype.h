#include <iostream>

template <typename T>
class Stack 
{

	T* m_ptr;
	size_t m_size;
	size_t m_capacity;

	void reallocator ()
	{
		if (m_capacity == 0){
			
			m_capacity = 10;
			m_ptr = new T [m_capacity];
			
		} else {
		
			m_capacity *= 2;
			T* tmp = new T [m_capacity];
			for (int i = 0; i < m_size; ++i){
				
				tmp [i] = m_ptr[i];
			}
			delete [] m_ptr;
			m_ptr = tmp;
			tmp = nullptr;
		}
		
	}

	public:
	
	Stack();
	Stack (const Stack&);
	Stack (Stack&&);
	~Stack();

	bool empty();
	size_t size();
	T& top();
	void push(const T&);
	void pop ();
	void print ();
	
	std::ostream& operator << (std::ostream& os) 
	{
		for (int i = 0; i < m_size; ++i){
			
			os << m_ptr[i] << " ";
		}
		
		return os;
	}

	Stack& operator=(const Stack& other)
	{
		if (this != &other){
		
			if (m_ptr){

				delete [] m_ptr;
			}

			m_size = other.m_size;
			m_capacity = other.m_capacity;
			m_ptr = new T [m_capacity];
			for (int i = 0; i < m_size; ++i){
			
				m_ptr [i] = other.m_ptr [i];
			}

		}
		return *this;
	}

	Stack& operator=(Stack&& other)
	{
	
		if (this != &other){
		
			if (m_ptr){
				
				delete [] m_ptr;
			}

			m_ptr = other.m_ptr;
		       	m_size = other.m_size;
			m_capacity = other.m_capacity;
			
			other.m_ptr = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;	
		}

		return *this;
	}
};

#include "implementation.hpp"
