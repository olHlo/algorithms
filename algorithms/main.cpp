#include "stdlib.h"
#include "stdio.h"

// 定义数据结构
#define MAX_SIZE 20
#define STATUS_FAILED -1
#define STATUS_OK 0

// 定义int别名ElementType
typedef int ElementType;

typedef struct LNode *Node;
struct LNode{
    ElementType Data[MAX_SIZE];
    int Last;
};
Node Init()
{
    // 初始化指针
    Node p = (Node)malloc(sizeof(struct LNode));
    p->Last = -1;
    return p;
}

int Insert(Node p, int index, ElementType X)
{
    // 边界判定
    // 1.列表满了没
    if(MAX_SIZE == p->Last + 1) return STATUS_FAILED;
    // 2.索引位置不对
    if(index < 0 || index > p->Last + 1) return STATUS_FAILED;
    // 3.移动元素::针对从插入索引index到最后元素【实际上，最后元素之后也能插入，但是没有元素移动了】
    for(int i = p->Last; i >= index; i--) {
        p->Data[i+1] = p->Data[i];
    }
    // 4.插入以后，列表的结构变化
    p->Data[index] = X;
    p->Last++;
    return STATUS_OK;
}

int Delete(Node p, int index)
{
    // 边界判定
    if(index < 0 || index > p->Last + 1) return STATUS_FAILED;
    for(int i = index; i < p->Last; i++)
    {
        p->Data[i] = p->Data[i + 1];
    }
    p->Last--;
    return STATUS_OK;
}

void Traverse(Node p)
{
    for (int i = 0; i <= p->Last; i++)
    {
        printf("遍历列表，索引-%d，值-%d\n", i, p->Data[i]);
    }
}

int Length(Node p)
{
    return p->Last + 1;
}


int main()
{
    Node p = Init();
    Insert(p, 0, 90);
    Insert(p, 1, 2);
    Insert(p, 2, 23);
    Insert(p, 3, 73);
    Insert(p, 4, 274);
    Insert(p, 5, 253);
    Insert(p, 3, 213);
    Traverse(p);
    printf("表长:%d\n", Length(p));
    Delete(p, 0);
    Traverse(p);
    
}
