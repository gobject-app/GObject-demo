//
// Created by tonye on 2019-06-06.
//

#ifndef MY_UDISK_H
#define MY_UDISK_H

#include "my-iusb.h"


//注册类
#define MY_TYPE_UDISK (my_udisk_get_type())
//obj对象类型转换为MY_TYPE_UDSK实例结构体类型
#define MY_UDISK(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MY_TYPE_UDISK, MyUdisk))
//判读obj对象类型是否为MY_TYPE_UDSK实例结构体类型
#define MY_IS_UDISK(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), MY_TYPE_UDISK))
//将klass类结构类型强转为MY_TYPE_UDISK类结构类型
#define MY_UDISK_CLASSS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), MY_TYPE_UDISK, MyUdiskClass))
//判读klass类结构类型是否为MY_TYPE_UDISK类结构类型
#define MY_IS_UDISK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), MY_TYPE_UDISK))
//获取obj对象对应的类结构类型
#define MY_UDISK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), MY_TYPE_UDISK, MyUdiskClass))


typedef struct _MyUdisk MyUdisk;
struct _MyUdisk{
    GObject parent;
    GString *data;
};

typedef struct _MyUdiskClass MyUdiskClass;
struct _MyUdiskClass{
    GObjectClass parent_class;
};


GType my_udisk_get_type(void);



#endif //MY_UDISK_H
