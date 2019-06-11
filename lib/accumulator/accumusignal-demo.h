//
// Created by tonye on 2019-06-10.
//

#ifndef ACCUMUSIGNAL_DEMO_H
#define ACCUMUSIGNAL_DEMO_H

#include <glib-object.h>

#define ACCUMUSIGNAL_TYPE_DEMO (accumusignal_demo_get_type())
#define ACCUMUSIGNAL_DEMO(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), ACCUMUSIGNAL_TYPE_DEMO, AccumusignalDemo))
#define ACCUMUSIGNAL_DEMO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), ACCUMUSIGNAL_TYPE_DEMO, AccumusignalDemoClass))



typedef struct _AccumusignalDemo AccumusignalDemo;
struct _AccumusignalDemo{
    GObject parent;
};

typedef struct _AccumusignalDemoClass AccumusignalDemoClass;
struct _AccumusignalDemoClass{
    GObjectClass parent_class;
    void (*default_handler)(gpointer instance, const gchar *buffer, gpointer userdata);
};

GType accumusignal_demo_get_type(void);


#endif //ACCUMUSIGNAL_DEMO_H
