//
// Created by tonye on 2019-06-06.
//

#ifndef MY_IUSB_H
#define MY_IUSB_H

/** 继承常用的宏 P表示项目名称， T表示类名称， PTPrivate表示私有数据结构
 *
 # 仅在使用g_object_new 进行对象实例化的时候使用一次，用于向GObject库的类型系统注册PT类
 #define P_TYPE_T (p_t_get_type())

 # 用于将obj对象的类型强制转换为P_T类的实例结构体类型
 #define P_T(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), P_TYPE_T, PT))

 # 用于判断obj对象的类型是否为P_T类的实例结构体类型
 #define P_IS_T(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), P_TYPE_T))

 # 用于将klass类结构体的类型强制转换为P_T类的类结构体类型
 #define P_T_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), P_TYPE_T, PTClass))

 # 用于判断klass类结构体的类型是否为P_T类的结构体类型
 #define P_IS_T_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass)), P_TYPE_T))

 # 获取obj对象对应的类结构体类型
 #define P_T_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), P_TYPE_T，PTClass))

 # 获取obj对象对应的私有数据
 #define P_T_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), P_TYPE_T, PTPrivate))

 *
 */


/** 接口常用宏: 其中P表示项目名称， T表示类名称，I是接口的缩写

 # 近在接口实现是使用一次，用于向GObject库的类型系统注册PIT接口
 #define P_TYPE_IT (p_t_get_type())

 # 用于将obj对象的类型强制转换为P_IT接口的实例结构体类型
 #define P_IT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), P_TYPE_IT, PIt))

 # 用于判断obj对象的类型是否为P_IT接口的实例结构体列席
 #define P_IS_IT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), P_TYPE_IT))

 # 获取obj对象对应的P_IT接口的类结构体类型
 #define P_IT_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), P_TYPE_IT, PItInterface))


 */


/** 需要确定的按个名称（其中I表示接口):
 类名称: MyIUsb 对应的接口类(结构类）MyIUserInterface(MyIUserClass)
 类型：MY_TYPE_IUSB (一般定义取类名的大写，中间加TYPE组合)
 函数前缀：my_iusb (一般定义取类名的小写，中间加下划线组合）
 */

#include <glib-object.h>

#define MY_TYPE_IUSB (my_iusb_get_type()) //向GObject库的类型系统注册PIT接口
#define MY_IUSB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj),MY_TYPE_IUSB, MyIUsb)) //将obj对象类型强制转换为P_IT接口的实例结构体类型
#define MY_IS_IUSB(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), MY_TYPE_IUSB)) //判断obj对象类型是否为P_IT接口的实例结构体类型
#define MY_IUSB_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), MY_TYPE_IUSB, MyIUsbInterface)) //获取obj对象对应的P_IT

//类结构无需具体的实现
typedef struct _MyIUsb MyIUsb;

typedef struct _MyIUsbInterface MyIUsbInterface;
struct _MyIUsbInterface{
    GTypeInterface parent_interface;

    //接口
    gchar * (*read) (MyIUsb *self);
    void (*write) (MyIUsb *self, const gchar *str);
};

GType my_iusb_get_type (void);

//接口定义
gchar * my_iusb_read (MyIUsb *self);
void my_iusb_write (MyIUsb *self, const gchar *str);

#endif //MY_IUSB_H
