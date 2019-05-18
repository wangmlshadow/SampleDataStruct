#include "stack.h"

int main()
{
	std::cout << "Output: " << std::endl;
	std::cout << "Create a Stack with five ele..." << std::endl;
	Stack stack(5);

	std::cout << "Traverse..." << std::endl;
	stack.StackTraverse();

	if (!stack.StackEmpty())
		std::cout << "length = " << stack.StackLength() << std::endl;
	else
		std::cout << "Empty" << std::endl;

	StackDataType value = 0;
	stack.StackGetTop(value);

	std::cout << "The top ele is " << value << std::endl;

	std::cout << "Push two ele..." << std::endl;
	stack.StackPush(6);
	stack.StackPush(7);

	std::cout << "Traverse..." << std::endl;
	stack.StackTraverse();

	StackDataType pop;
	
	if (stack.StackPop(pop))
		std::cout << "Pop ele " << pop << std::endl;

	std::cout << "Pop two ele..." << std::endl;
	stack.StackPop();
	stack.StackPop();

	std::cout << "Traverse..." << std::endl;
	stack.StackTraverse();


	int temp;
	std::cout << "Ending..." << std::endl;
	std::cin >> temp;

	return 0;
}

/*
Output:
Create a Stack with five ele...
1
2
3
4
5
Traverse...
1
2
3
4
5
length = 5
The top ele is 5
Push two ele...
Traverse...
1
2
3
4
5
6
7
Pop ele 7
Pop two ele...
Traverse...
1
2
3
4
Ending...
*/