//
// Created by tonye on 2019-06-09.
//

#include <math.h>
#include <glib-object.h>


#define g_marshal_value_peek_boolean(v)  g_value_get_boolean (v)
#define g_marshal_value_peek_char(v)     g_value_get_schar (v)
#define g_marshal_value_peek_uchar(v)    g_value_get_uchar (v)
#define g_marshal_value_peek_int(v)      g_value_get_int (v)
#define g_marshal_value_peek_uint(v)     g_value_get_uint (v)
#define g_marshal_value_peek_long(v)     g_value_get_long (v)
#define g_marshal_value_peek_ulong(v)    g_value_get_ulong (v)
#define g_marshal_value_peek_int64(v)    g_value_get_int64 (v)
#define g_marshal_value_peek_uint64(v)   g_value_get_uint64 (v)
#define g_marshal_value_peek_enum(v)     g_value_get_enum (v)
#define g_marshal_value_peek_flags(v)    g_value_get_flags (v)
#define g_marshal_value_peek_float(v)    g_value_get_float (v)
#define g_marshal_value_peek_double(v)   g_value_get_double (v)
#define g_marshal_value_peek_string(v)   (char*) g_value_get_string (v)
#define g_marshal_value_peek_param(v)    g_value_get_param (v)
#define g_marshal_value_peek_boxed(v)    g_value_get_boxed (v)
#define g_marshal_value_peek_pointer(v)  g_value_get_pointer (v)
#define g_marshal_value_peek_object(v)   g_value_get_object (v)
#define g_marshal_value_peek_variant(v)  g_value_get_variant (v)

/* WARNING: This code accesses GValues directly, which is UNSUPPORTED API.
 *          Do not access GValues directly in your code. Instead, use the
 *          g_value_get_*() functions
 */
#define g_marshal_value_peek_boolean(v)  (v)->data[0].v_int
#define g_marshal_value_peek_char(v)     (v)->data[0].v_int
#define g_marshal_value_peek_uchar(v)    (v)->data[0].v_uint
#define g_marshal_value_peek_int(v)      (v)->data[0].v_int
#define g_marshal_value_peek_uint(v)     (v)->data[0].v_uint
#define g_marshal_value_peek_long(v)     (v)->data[0].v_long
#define g_marshal_value_peek_ulong(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_int64(v)    (v)->data[0].v_int64
#define g_marshal_value_peek_uint64(v)   (v)->data[0].v_uint64
#define g_marshal_value_peek_enum(v)     (v)->data[0].v_long
#define g_marshal_value_peek_flags(v)    (v)->data[0].v_ulong
#define g_marshal_value_peek_float(v)    (v)->data[0].v_float
#define g_marshal_value_peek_double(v)   (v)->data[0].v_double
#define g_marshal_value_peek_string(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_param(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_boxed(v)    (v)->data[0].v_pointer
#define g_marshal_value_peek_pointer(v)  (v)->data[0].v_pointer
#define g_marshal_value_peek_object(v)   (v)->data[0].v_pointer
#define g_marshal_value_peek_variant(v)  (v)->data[0].v_pointer


void
g_cclosure_user_marshal_INT__VOID_VOID (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint G_GNUC_UNUSED,
                                        gpointer      marshal_data)
{
    typedef gint (*GMarshalFunc_INT__VOID_VOID) (gpointer data1,
                                                 gpointer data2);
    GCClosure *cc = (GCClosure *) closure;
    gpointer data1, data2;
    GMarshalFunc_INT__VOID_VOID callback;
    gint v_return;

    g_return_if_fail (return_value != NULL);
    g_return_if_fail (n_param_values == 1);

    if (G_CCLOSURE_SWAP_DATA (closure))
    {
        data1 = closure->data;
        data2 = g_value_peek_pointer (param_values + 0);
    }
    else
    {
        data1 = g_value_peek_pointer (param_values + 0);
        data2 = closure->data;
    }
    callback = (GMarshalFunc_INT__VOID_VOID) (marshal_data ? marshal_data : cc->callback);

    v_return = callback (data1,
                         data2);

    g_value_set_int (return_value, v_return);
}


static void
compare3(GCClosure *closure, void *b){
    GValue return_value = {0};
    GValue param_value = {0};
    g_value_init(&return_value, G_TYPE_INT);
    g_value_init(&param_value, G_TYPE_POINTER);

    g_value_set_pointer(&param_value, b);

    g_closure_invoke(closure, &return_value, 1, &param_value, NULL);
    gint r = g_value_get_init(&return_value);

    if(r == -1){
        g_print("a < b\n");
    }else if(r == 0){
        g_print("a = b\n");
    }else{
        g_print("a > b\n");
    }

    g_value_unset(&return_value);
    g_value_unset(&param_value);

}

static gint
float_compare3(void *a, void *b){
    gfloat *f1 = a;
    gfloat *f2 = b;

    if(*f1 > *f2){
        return 1;
    }else if(fabs(*f1 - *f2) <= 10E-6){
        return 0;
    }else{
        return -1;
    }

}

static gint
str_compare3(void *a, void *b){
    size_t len1 = g_utf8_strlen((gchar *)a, -1);
    size_t len2 = g_utf8_strlen((gchar *)b, -1);

    if(len1 > len2){
        return 1;
    }else if(len1 == len2){
        return 0;
    }else{
        return -1;
    }
}