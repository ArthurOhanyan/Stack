#include <iostream>
#include "prototype.h"

int main ()
{
	
	Stack<int> obj;
	for (int i = 0; i < 10; ++i){
		
		obj.push(i);
	
	}

	obj.top() = 17;
	std::cout << obj << std::endl;
	std::cout << " size () == " << obj.size() << std::endl;
	obj.pop();
	std::cout << " size() == " << obj.size() << std::endl;
	std::cout << std::boolalpha << " empty () " << obj.empty() << std::endl;

	

	
}
