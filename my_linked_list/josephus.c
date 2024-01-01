// 23.12.29
// on class : the final class
// 可以先写出代码的主要逻辑框架，再一个个写函数
// by HHC

#include <stdio.h>
#include "ll_linked_list/ll.h"
#include <assert.h>

#define NUM 12

void SitAroundCircle(LinkedList *list, int num);
void KillUntilOne(LinkedList *list);
int GetSurvivor(LinkedList *list);
int GetHeadVal(const LinkedList *list);

int main(void)
{
    printf("I hate the Josephus game!\n");

    LinkedList list;
    Init(&list); // initialize

    // input the people
    SitAroundCircle(&list, NUM);
    Print(&list);

    KillUntilOne(&list);
    int survivor = GetSurvivor(&list);
    printf("%d:%d\n", NUM, survivor);

    return 0;
}

int GetHeadVal(const LinkedList *list)
{
    if (IsEmpty(list))
    {
        return -1;
    }
    return list->head->val;
}

void SitAroundCircle(LinkedList *list, int num)
{
    // TODO
    for (int i = 1; i <= num; i++)
    {
        Append(list, i); // 尾部追加节点
    }
}

void KillUntilOne(LinkedList *list)
{
    // TODO
    Node *node = list->head;

    while (!IsSingleton(list))
    {
        Delete(list, node);
        node = node->next;
    }
}

int GetSurvivor(LinkedList *list)
{
    // TODO
    return GetHeadVal(list);
}