/* LinkList.c*/
/*线性表的单链表示：函数实现*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


LinkList  createNullList_link( void )
/* 创建一个带头结点的空链表 */
{
    LinkList  llist = (LinkList)malloc( sizeof( struct Node ) );/*申请表头结点空间*/
 	if( llist != NULL ){
        llist->link = NULL;
 	}
    else printf("Out of space! \n");  /*创建失败*/
    return (llist);
}


int  isNullList_link( LinkList  llist) {
/* 判断带有头结点的单链表llist是否是空链表 */
 	return (llist->link == NULL);
}

int insertPost_link(LinkList  llist, PNode p, DataType x)
/* 在llist带头结点的单链表中,p所指结点后面插入元素x */
{
    PNode q = (PNode)malloc( sizeof( struct Node ) );	/* 申请新结点 */
    if( q == NULL ) {
        printf( "Out of space!!!\n");
        return 0;
    }
    else {
        q->info = x;
        q->link = p->link;
        p->link = q;
        return 1;
    }
}

PNode  locatePre_link(LinkList  llist, PNode p ) {
/*在单链表中求p所指结点的前驱结点*/
    PNode p1;
    if (llist==NULL)  return(NULL);
    p1 = llist;
    while( p1 != NULL && p1->link != p )  p1 = p1->link;
    return (p1);
}
