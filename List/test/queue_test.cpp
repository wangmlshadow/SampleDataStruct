#include "queue.h"

int main()
{
	std::cout << "Qutput..." << std::endl;
	Queue queue(5);

	if (!queue.QueueEmpty())
		std::cout << "The queue is not Empty, and its length is " << queue.QueueLength() << std::endl;

	std::cout << "Insert two ele..." << std::endl;
	queue.QueueEn(6);
	queue.QueueEn(7);

	std::cout << "Traverse..." << std::endl;
	queue.QueueTraverse();

	QueueDataType head;
	queue.QueueGetHead(head);
	std::cout << "The head = " << head << std::endl;

	QueueDataType del;
	queue.QueueDe(del);
	std::cout << "Delete ele " << del << std::endl;

	std::cout << "Delete two ele..." << std::endl;
	queue.QueueDe();
	queue.QueueDe();

	std::cout << "Traverse..." << std::endl;
	queue.QueueTraverse();

	queue.QueueClear();

	if (queue.QueueEmpty())
		std::cout << "The queue was cleared." << std::endl;

	std::cout << "End..." << std::endl;
	int temp;
	std::cin >> temp;

	return 0;
}

/*
Qutput...
1
2
3
4
5
The queue is not Empty, and its length is 5
Insert two ele...
Traverse...
1
2
3
4
5
6
7
The head = 1
Delete ele 1
Delete two ele...
Traverse...
4
5
6
7
The queue was cleared.
End...
*/