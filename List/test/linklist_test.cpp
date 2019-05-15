#include "link_list.h"
/*
int main()
{
	//LNode node(5);
	//if (node.next == nullptr)
		//std::cout << "next = nullptr, data = " << node.data << std::endl;

	LinkList list(5);
	//LinkList list;

	int len = list.LListLength();
	std::cout << "InitLen = " << len << std::endl;

	if (list.LListEmpty())
		std::cout << "Empty List!" << std::endl;

	std::cout << std::endl << "First Traverse: " << std::endl;

	list.LListTraverse();

	std::cout << std::endl << "Insert two Node!" << std::endl;

	LNode *node = new LNode(0);

	if (!node)
		std::cout << "new Error!" << std::endl;

	LNode *node_2 = new LNode(6);

	if (!node_2)
		std::cout << "new Error!" << std::endl;

	list.LListInsert(0, node);
	list.LListInsert(6, node_2);

	len = list.LListLength();
	std::cout << "CurLen = " << len << std::endl;

	std::cout << std::endl << "Second Traverse: " << std::endl;
	list.LListTraverse();

	std::cout << "Get Node's Data!" << std::endl;
	LNode *node_pos_3 = nullptr;
	list.GetNode(3, &node_pos_3);

	std::cout << "node_pos_3: " << "data = " << node_pos_3->data << std::endl;
	
	LNode node_del;
	if (list.LListDelete(3, &node_del)) {
		std::cout << "Delete Node: " << "data = " << node_del.data << std::endl;
	}

	len = list.LListLength();
	std::cout << "CurLen = " << len << std::endl;

	std::cout << std::endl << "Third Traverse: " << std::endl;
	list.LListTraverse();

	std::cout << "End..." << std::endl;
	int temp;
	std::cin >> temp;

	return 0;
}
*/
/*
 ‰≥ˆ–≈œ¢£∫
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
End...
*/