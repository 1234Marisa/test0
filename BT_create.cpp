#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define list_length 100

typedef struct leaf
{
	int visit_num;
	int data;
	leaf* LLeaf;
	leaf* RLeaf;
}BT_leaf;
BT_leaf* root = NULL;
typedef struct queue
{
	BT_leaf* list[list_length];
	int end ;
	int begin ;
	int is_empty;//1:empty;0:full;2:!empty&&!full
}que;
void BT_perfect_create(int num_node)
{
	if (num_node == 0)
	{
		printf("the BT is empty!");
		exit(0);
	}
	que que_record = { {NULL},0,0,1 };

	if ((root = (BT_leaf*)malloc(sizeof(BT_leaf))) == NULL)//create the frist node
	{
		printf("the space is full!!");
		exit(1);
	}
	int i = 1;
	root->data = 1;
	root->LLeaf = NULL;
	root->RLeaf = NULL;
	root->visit_num = 0;
	que_record.list[que_record.end] = root;
	que_record.end++;
	que_record.is_empty = 2;
	
	while (i < num_node)
	{
			
			if (((BT_leaf*)malloc(sizeof(BT_leaf))) == NULL)
			{
				printf("the space is full!!");
				exit(1);
			}
			else 
			{
				if (que_record.is_empty == 0)
				{
					printf("the queue is empty!");
					exit(1);
				}
				if (que_record.list[que_record.begin]->visit_num == 0)
				{
					que_record.list[que_record.begin]->LLeaf = (BT_leaf*)malloc(sizeof(BT_leaf));
					i++;
					que_record.list[que_record.begin]->visit_num = 1;
					if (que_record.is_empty != 0)
					{
						que_record.list[que_record.end] = que_record.list[que_record.begin]->LLeaf;
						que_record.list[que_record.end]->data = i;
						que_record.list[que_record.end]->LLeaf = NULL;
						que_record.list[que_record.end]->RLeaf = NULL;
						que_record.list[que_record.end]->visit_num = 0;
						que_record.end = (que_record.end + 1) % list_length;
						if (que_record.begin == que_record.end)
						{
							que_record.is_empty = 0;
						}
					}
				}
				else if (que_record.list[que_record.begin]->visit_num == 1)
				{
					que_record.list[que_record.begin]->RLeaf = (BT_leaf*)malloc(sizeof(BT_leaf));
					i++;
					que_record.list[que_record.begin]->visit_num = 2;
					if (que_record.is_empty != 0)
					{
						que_record.list[que_record.end] = que_record.list[que_record.begin]->RLeaf;
						que_record.list[que_record.end]->data = i;
						que_record.list[que_record.end]->LLeaf = NULL;
						que_record.list[que_record.end]->RLeaf = NULL;
						que_record.list[que_record.end]->visit_num = 0;
						que_record.end = (que_record.end + 1) % list_length;
						if (que_record.begin == que_record.end)
						{
							que_record.is_empty = 0;
						}
					}
				}
				else
				{
					que_record.begin = (que_record.begin + 1) % list_length;
					if (que_record.begin == que_record.end)
					{
						que_record.is_empty = 1;
					}
				}
			}
	}
}
//void BT_all_print()
//{
//	BT_leaf* list[list_length] = { NULL };
//	int i = 0;//i records the number of the nodes
//	int begin = 0;
//	int end = 0;
//	int is_empty = 1;//is_empty=1,the queue_list is empty;is_empty =0,the queue_list is full
//	list[end] = root;
//	end++;
//	
//	while (end != begin)
//	{
//		int s = begin;
//		printf("%d ", list[begin]->data);
//		begin = (begin + 1) % list_length;
//		if (list[s]->LLeaf != NULL)
//		{
//			list[end] = list[s]->LLeaf;
//			end = (end + 1) % list_length;
//		}
//		if (end == begin && is_empty == 0)
//		{
//			printf("the queue is full!!please define a bigger one!!");
//			exit(1);
//		}
//		else
//		{
//			if (list[s]->RLeaf != NULL)
//			{
//				list[end] = list[s]->RLeaf;
//				end = (end + 1) % list_length;
//			}
//			
//			if (end == begin)
//			{
//				is_empty = 0;
//			}
//		}
//	}
//}
//void BT_pre_visit(BT_leaf* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	printf("%d ", root->data);
//	BT_pre_visit(root->LLeaf);
//	BT_pre_visit(root->RLeaf);
//}
int main_1()
{
	int num_node = 0;
	scanf("%d", &num_node);
	BT_perfect_create(num_node);
	//BT_all_print();
	//BT_pre_visit(root);
	return 0;
}