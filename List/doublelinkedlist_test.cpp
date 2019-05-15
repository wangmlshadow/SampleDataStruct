#include "DoubleLinkedList.h"
/*
int main()
{
	DoubleLinkedList list(5);

	int len = list.DListLength();
	std::cout << "InitLen = " << len << std::endl;

	if (list.DListEmpty())
		std::cout << "Empty List!" << std::endl;

	std::cout << std::endl << "First Traverse: " << std::endl;

	list.DListTraverse();

	std::cout << std::endl << "Insert two Node!" << std::endl;

	DuLNode *node = new DuLNode(0, nullptr, nullptr);

	if (!node)
		std::cout << "new Error!" << std::endl;

	DuLNode *node_2 = new DuLNode(6, nullptr, nullptr);

	if (!node_2)
		std::cout << "new Error!" << std::endl;

	list.DListInsert(0, node);
	list.DListInsert(6, node_2);

	len = list.DListLength();
	std::cout << "CurLen = " << len << std::endl;

	std::cout << std::endl << "Second Traverse: " << std::endl;
	list.DListTraverse();

	std::cout << "Get Node's Data!" << std::endl;
	DuLNode *node_pos_3 = nullptr;
	list.GetNode(3, &node_pos_3);

	std::cout << "node_pos_3: " << "data = " << node_pos_3->data << std::endl;

	DuLNode node_del;
	if (list.DListDelete(3, &node_del)) {
		std::cout << "Delete Node: " << "data = " << node_del.data << std::endl;
	}

	len = list.DListLength();
	std::cout << "CurLen = " << len << std::endl;

	std::cout << std::endl << "Third Traverse: " << std::endl;
	list.DListTraverse();

	ElemType locate = 4;
	DuLNode *lnode = nullptr;

	if (list.LocateNode(locate, &lnode))
		std::cout << std::endl << "The number " << locate << " in the list" << std::endl;

	std::cout << "End..." << std::endl;
	int temp;
	std::cin >> temp;

	return 0;
}
*/
/*
Output:
1
2
3
4
5
InitLen = 5

First Traverse:
1
2
3
4
5

Insert two Node!
CurLen = 7

Second Traverse:
0
1
2
3
4
5
6
Get Node's Data!
node_pos_3: data = 2
Delete Node: data = 2
CurLen = 6

Third Traverse:
0
1
3
4
5
6

The number 4 in the list
End...
*/