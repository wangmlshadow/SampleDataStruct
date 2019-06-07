#include "SqQueue.h"

int main()
{
	std::cout << "Output:" << std::endl;

	SqQueue queue;
	if (queue.SqQueueEmpty())
		std::cout << "A empty queue." << std::endl;

	for (int i = 0; i < 8; i++) {
		queue.SqQueueEn(i);
	}

	std::cout << "Length = " << queue.SqQueueLength() << std::endl;

	SqQueueDataType k;
	queue.SqQueueGetHead(k);
	std::cout << "Head = " << k << std::endl;
	
	std::cout << "Traverse:" << std::endl;
	queue.SqQueueTraverse();

	for (int i = 0; i < 4; i++) {
		int value;
		queue.SqQueueDe(value);
		std::cout << "Delete " << value << std::endl;
	}

	std::cout << "Traverse:" << std::endl;
	queue.SqQueueTraverse();
	
	while (queue.SqQueueEn(99)) {
		std::cout << "Append a ele." << std::endl;
	}

	std::cout << "NO available space." << std::endl;

	std::cout << "Traverse:" << std::endl;
	queue.SqQueueTraverse();

	std::cout << "End..." << std::endl;
	int temp;
	std::cin >> temp;

	return 0;
} 

/*
Output:
A empty queue.
Length = 8
Head = 0
Traverse:
0
1
2
3
4
5
6
7
Delete 0
Delete 1
Delete 2
Delete 3
Traverse:
4
5
6
7
Append a ele.
Append a ele.
Append a ele.
Append a ele.
Append a ele.
Append a ele.
NO available space.
Traverse:
4
5
6
7
99
99
99
99
99
99
End...
*/