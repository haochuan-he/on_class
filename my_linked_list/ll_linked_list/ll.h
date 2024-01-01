//
// 23.12.29
// by HHC

// macro （宏）
#ifndef ll_2023_12_29
#define ll_2023_12_29

#include <stdbool.h>

// TODO : adding code here

// (1) define data type: circular singly linked list
typedef struct node
{
    int val;
    struct node *next;
    // Node *next;   //--WRONG--
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} LinkedList;

// (2) functions on linked list(declarations)
void Init(LinkedList *list); // 链表时，通常用指针来传，效率高，易于修改
void Free(LinkedList *list);

bool IsEmpty(const LinkedList *list);
bool IsSingleton(const LinkedList *list);

void Delete(LinkedList *list, Node *prev);

void Print(const LinkedList *list);

void Append(LinkedList *list, int val);

// 其他常用函数
void Insert(LinkedList *list, Node *prev, int val);
Node *Search(LinkedList *list, int val);

#endif // ll_2023_12_29