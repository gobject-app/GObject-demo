//
// Created by tonye on 2019-06-10.
//

#ifndef SIGNAL_DEMO_H
#define SIGNAL_DEMO_H

#include <glib-object.h>
#define SIGNAL_TYPE_DEMO (signal_demo_get_type())
#define SIGNAL_DEMO(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), SIGNAL_TYPE_DEMO, SignalDemo))
#define SIGNAL_DEMO_CLASS(obj) (G_TYPE_CHECK_CLASS_CAST((obj), SIGNAL_TYPE_DEMO))


typedef struct _SignalDemo SignalDemo;
struct _SignalDemo{
    GObject parent;
};

typedef struct _SignalDemoClass SignalDemoClass;
struct _SignalDemoClass{
    GObjectClass parent_class;
    void (*default_handler) (gpointer instance, const gchar *buffer, gpointer userdata);
};


GType signal_demo_get_type(void);

#endif //SIGNAL_DEMO_H
