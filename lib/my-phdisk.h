//
// Created by tonye on 2019-06-08.
//

#ifndef MY_PHDISK_H
#define MY_PHDISK_H


#include "my-iusb.h"

//注册类
#define MY_TYPE_PHDISK (my_phdisk_get_type())
//obj对象类型强制转换为MY_TYPE_PHDSIK实例结构体类型
#define MY_PHDISK(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MY_TYPE_PHDISK, MyPhdisk))

typedef struct _MyPhdisk MyPhdisk;
struct _MyPhdisk{
    GObject parent;
    GString *data;
};


typedef struct _MyPhdiskClass MyPhdiskClass;
struct _MyPhdiskClass{
    GObjectClass parent_class;
};



GType my_phdisk_get_type(void);


#endif //MY_PHDISK_H
