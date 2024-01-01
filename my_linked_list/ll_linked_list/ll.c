//
// 23.12.29
// by HHC

// #include <ll.h> //尖括号，系统路径
#include "ll.h" //双引号，会先到本工程文件找，再到系统文件去找
#include <stdlib.h>
#include <stdio.h>

// TODO: functions on linked list (implementations)

void Init(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void Free(LinkedList *list)
{
    // TODO
    while (!IsEmpty(list))
    {
        Delete(list, list->head);
    }
}

bool IsEmpty(const LinkedList *list)
{
    return list->head == NULL;
}

bool IsSingleton(const LinkedList *list)
{
    return !IsEmpty(list) && (list->head == list->tail);
}

void Print(const LinkedList *list)
{
    if (IsEmpty(list))
    {
        return;
    }

    Node *node = list->head;

    do
    {
        printf("%d ", node->val);
        node = node->next;
    } while (node != NULL);
}

void Append(LinkedList *list, int val)
{
    Node *node = malloc(sizeof(*node));
    if (node == NULL)
    {
        printf("malloc failed in function Append\n");
        return;
    }
    node->val = val;

    // 特别考虑空链表和只有一个节点的链表
    if (IsEmpty(list))
    {
        list->head = node;
        // list->tail = node;//特殊情况和一般情况有公共部分，可以合并
        // list->tail->next = list->head;
    }
    else
    {
        // 以下三句注意不可交换顺序
        list->tail->next = node;
    }
    list->tail = node;
    // node->next = list->head;
    list->tail->next = list->head;
}

void Delete(LinkedList *list, Node *prev)
{
    // 空链表
    if (IsEmpty(list))
    {
        return;
    }
    // 只有一个节点
    if (IsSingleton(list))
    {
        free(list->head);
        Init(list);
        return;
    }

    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next = next;

    // 删除的是头节点或者尾节点

    if (cur == list->head)
    {
        list->head = next;
    }
    if (cur == list->tail)
    {
        list->tail = prev;
    }

    free(cur);
}