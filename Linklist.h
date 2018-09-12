#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

/*LinkList.h*/
/* 线性表的单链表示：类型和界面定义*/

/* 定义顺序表的元素类型。应根据需要修改 */
typedef struct
{
    double x,y;
    double vx,vy;
    double ax,ay;
    double m;
}
DataType;

struct  Node;					/* 单链表结点类型 */
typedef  struct Node * PNode;	/* 结点指针类型 */
struct  Node 	{				/* 单链表结点结构 */
DataType  info;
PNode    link;
};
typedef  struct Node * LinkList;  /* 单链表类型 */

/* 创建一个带头结点的空链表 */
LinkList  createNullList_link( void );

/* 判断带有头结点的单链表llist是否是空链表 */
int  isNullList_link( LinkList  llist) ;

/* 在llist带有头结点的单链表中找第一个值为x的结点存储位置 */
PNode  locate_link(LinkList  llist, DataType x );

/* 在llist带头结点的单链表中,p所指结点后面插入元素x */
int insertPost_link(LinkList  llist, PNode p, DataType x);

/*在带头结点的单链表llist中，p所指结点前面插入值为ｘ的新结点*/
int  insertPre_link( LinkList  llist, PNode  p, DataType x );

/* 在llist带有头结点的单链表中删除第一个值为x的结点 */
int  deleteV_link(LinkList  llist, DataType x );

/*在带头结点的单链表llist中,删除p所指的结点*/
int  deleteP_link(LinkList  llist, PNode p );


#endif // LINKLIST_H_INCLUDED
