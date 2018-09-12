#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

/*LinkList.h*/
/* ���Ա�ĵ�����ʾ�����ͺͽ��涨��*/

/* ����˳����Ԫ�����͡�Ӧ������Ҫ�޸� */
typedef struct
{
    double x,y;
    double vx,vy;
    double ax,ay;
    double m;
}
DataType;

struct  Node;					/* ������������ */
typedef  struct Node * PNode;	/* ���ָ������ */
struct  Node 	{				/* ��������ṹ */
DataType  info;
PNode    link;
};
typedef  struct Node * LinkList;  /* ���������� */

/* ����һ����ͷ���Ŀ����� */
LinkList  createNullList_link( void );

/* �жϴ���ͷ���ĵ�����llist�Ƿ��ǿ����� */
int  isNullList_link( LinkList  llist) ;

/* ��llist����ͷ���ĵ��������ҵ�һ��ֵΪx�Ľ��洢λ�� */
PNode  locate_link(LinkList  llist, DataType x );

/* ��llist��ͷ���ĵ�������,p��ָ���������Ԫ��x */
int insertPost_link(LinkList  llist, PNode p, DataType x);

/*�ڴ�ͷ���ĵ�����llist�У�p��ָ���ǰ�����ֵΪ�����½��*/
int  insertPre_link( LinkList  llist, PNode  p, DataType x );

/* ��llist����ͷ���ĵ�������ɾ����һ��ֵΪx�Ľ�� */
int  deleteV_link(LinkList  llist, DataType x );

/*�ڴ�ͷ���ĵ�����llist��,ɾ��p��ָ�Ľ��*/
int  deleteP_link(LinkList  llist, PNode p );


#endif // LINKLIST_H_INCLUDED
