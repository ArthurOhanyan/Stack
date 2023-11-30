#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& os, Stack<T>& st)
{
	return st.operator<<(os);
}

template <typename T>

Stack<T>::Stack()
{
	m_ptr = nullptr;
	m_size = 0;
	m_capacity = 0;

}

template <typename T>
Stack<T>::~Stack()
{
	if (!m_ptr){
	
		delete [] m_ptr;
	}

	m_size = 0;
	m_capacity = 0;
}

template <typename T>
Stack<T>::Stack (const Stack& obj)
{
	m_size = obj.m_size;
	m_capacity = obj.m_capacity;

	m_ptr = new T [m_capacity];
	for (int i = 0; i < m_size; ++i){
		
		m_ptr [i] = obj.m_ptr[i]; 
	}

}

template <typename T>
Stack<T>::Stack (Stack&& obj)
{

	m_size = 0;
	m_capacity = 0;
	m_ptr = nullptr;

	m_size = obj.m_size;
	m_capacity = obj.m_capacity;
	m_ptr = obj.m_ptr;
	
	obj.m_ptr = nullptr;
	obj.m_size = 0;
	obj.m_capacity = 0;
}

template <typename T>
void Stack<T>::push(const T& val)
{
	if (m_capacity == 0 || m_size == m_capacity){
		
		Stack::reallocator();
	}
	
	m_ptr[m_size++] = val;

}

template <typename T>
void Stack<T>::pop()
{
	if (!m_ptr){
		
		std::cout << " pop() ::nullptr " << std::endl;
		exit (0);
	}
	if (m_size > 0){
		
		--m_size;
		
	}

}

template <typename T>
T& Stack<T>::top ()
{
	if (!m_ptr){
		
		std::cout << " top () :: nullptr " << std::endl;
		exit(0);
	}

	return m_ptr[m_size - 1];
}

template <typename T>
bool Stack<T>::empty ()
{

	return m_size == 0 ? true : false;

}

template <typename T>
size_t Stack<T>::size ()
{
	return m_size;
}

template <typename T>
void Stack<T>::print ()
{
	if (!m_ptr){
		
		std::cout << " print () :: nullptr " << std::endl;
	}

	for (int i = 0; i < m_size; ++i){
	
		std::cout << " " << m_ptr [i];	
	}
	std::cout << std::endl;

}
