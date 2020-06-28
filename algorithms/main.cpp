//
//  Created by lemonair on 2020/5/18.
//  Copyright © 2020年 lemonair. All rights reserved.
//

// C 实现线性表 - 1. array list

#include "stdio.h"

#include "stdlib.h"

#define MAX_SIZE 20

typedef int ElementType;

// list的数据结构
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAX_SIZE];
    int Last;
};

// 初始化 - 创建一张空表
List MakeEmpty()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

// 查找
int Find(ElementType X, List Ptrl)
{
    int i = 0;
    while(i <= Ptrl->Last && Ptrl->Data[i]!=X)
        i++;
    if (i > Ptrl->Last) return -1;
    else return i;
}

// 插入
void Insert()
{
    
}

// list action
int main()
{
    
}
