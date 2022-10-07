//
// Created by w1z4Rd on 2022/10/3.
//

struct Status {
    int code;
    char *message;
};

struct DuLinkList {
    int data;
    struct DuLinkList *prior;
    struct DuLinkList *next;
};

struct ElemType {
    int data;
};

#include <cstdio>

int main() {

}

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e)
{//在带头结点的双向链表L中第i个位置之前插入元素e
    if (!(p = GetElem_DuL(L, i)))              //在L中确定第i个元素的位置指针p
        return ERROR;                       //p为NULL时，第i个元素不存在
    s = new DuLNode;                         //生成新结点*s
    s->data = e;                             //将结点*s数据域置为e
    s->prior = p->prior;                     //将结点*s的前驱指针指向p的前驱
    p->prior->next = s;                      //将结点*p的前驱的后继指针指向s
    s->next = p;                             //将结点*s的后继指针指向p
    p->prior = s;                            //将结点*p的前驱指针指向s
    return OK;
}
