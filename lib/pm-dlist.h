//
// Created by tonye on 2019-06-03.
//

#ifndef PM_DLIST_H
#define PM_DLIST_H

/* 必须包含的基类头文件 */
// mac: brew install glib
// ubuntu：sudo apt-get install libglib2.0
#include <glib-object.h>
#include "glib/gprintf.h"

/* 定义子类类型
 * 其中pm_dist字段是用户可以修改的内容,表示这个类的用途，后续所有的函数都必须以pm_dist开头，pm_dlist_get_type()函数在下班定义
 */

#define PM_TYPE_DLIST (pm_dlist_get_type())

/*
 * 普通结构体， 作为实例结构体的成员
 * 双向链表节点的结构体
 */

typedef struct _PMListNode PMDListNode;
struct _PMListNode{
    PMDListNode *prev;
    PMDListNode *next;
    void *data;
};

// 在GObject世界里，类是两个结构体的组合，一个是实例结构体，另一个是类结构体

/*
 * 实例结构体，类似于c++中实例化，每个实例独有的内容，比如成员函数，成员变量等
 * 双向链表的结构体
 */
typedef struct _PMDList PMDList;
struct _PMDList{
    GObject parent_instance;  // 继承GObject类
    PMDListNode *head;
    PMDListNode *tail;
};

/*类结构体，类似于c++中，属于类的部分, 比如：static成员函数和static成员变量等*/
typedef struct _PMDListClass PMDListClass;
struct _PMDListClass{
    GObjectClass parent_class; // 继承GObject类
};


/*private, 定义获取类型函数，供PM_TYPE_DLIST调用，不建议直接调用*/
//pm_dlist_get_type 函数的作用就是告诉g_object_new有关 PMDList 类的具体结构
GType pm_dlist_get_type(void);

#endif //PM_DLIST_H
