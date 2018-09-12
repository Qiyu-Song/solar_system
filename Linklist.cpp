/* LinkList.c*/
/*���Ա�ĵ�����ʾ������ʵ��*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


LinkList  createNullList_link( void )
/* ����һ����ͷ���Ŀ����� */
{
    LinkList  llist = (LinkList)malloc( sizeof( struct Node ) );/*�����ͷ���ռ�*/
 	if( llist != NULL ){
        llist->link = NULL;
 	}
    else printf("Out of space! \n");  /*����ʧ��*/
    return (llist);
}


int  isNullList_link( LinkList  llist) {
/* �жϴ���ͷ���ĵ�����llist�Ƿ��ǿ����� */
 	return (llist->link == NULL);
}

int insertPost_link(LinkList  llist, PNode p, DataType x)
/* ��llist��ͷ���ĵ�������,p��ָ���������Ԫ��x */
{
    PNode q = (PNode)malloc( sizeof( struct Node ) );	/* �����½�� */
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
/*�ڵ���������p��ָ����ǰ�����*/
    PNode p1;
    if (llist==NULL)  return(NULL);
    p1 = llist;
    while( p1 != NULL && p1->link != p )  p1 = p1->link;
    return (p1);
}
