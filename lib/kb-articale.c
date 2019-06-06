//
// Created by tonye on 2019-06-04.
//

#include "kb-articale.h"

//注册类型 继承
G_DEFINE_TYPE(KbArticle, kb_article, KB_TYPE_BIBTEX)

//对象的私有属性
#define KB_ARTICLE_GET_PRIVATE(object)(\
    G_TYPE_INSTANCE_GET_PRIVATE((object), KB_TYPE_ARTICLE, KbArticlePrivate))

typedef struct _KbArticlePrivate KbArticlePrivate;
struct _KbArticlePrivate{
    GString *journal;
    GString *volume;
    GString *number;
    GString *pages;
};

//注：PROPERTY_A_0 和 N_PROPERTIES_A 和父类的 enum要区分
enum PROPERTY_ARTICLE{
    PROPERTY_A_0,
    PROPERTY_JOURNAL,
    PROPERTY_VOLUME,
    PROPERTY_NUMBER,
    PROPERTY_PAGES,
    N_PROPERTIES_A
};

//对象私有属性的外部访问
static void
kb_article_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec){
    KbArticle *self = KB_ARTICLE(object);
    KbArticlePrivate *priv = KB_ARTICLE_GET_PRIVATE(self);

    switch(property_id){
        case PROPERTY_JOURNAL:
            if(priv->journal){
                g_string_free(priv->journal, TRUE);
            }
            priv->journal = g_string_new(g_value_get_string(value));
            break;
        case PROPERTY_VOLUME:
            if(priv->volume){
                g_string_free(priv->volume, TRUE);
            }
            priv->volume = g_string_new(g_value_get_string(value));
            break;
        case PROPERTY_NUMBER:
            if(priv->number){
                g_string_free(priv->number, TRUE);
            }
            priv->number = g_string_new(g_value_get_string(value));
            break;
        case PROPERTY_PAGES:
            if(priv->pages){
                g_string_free(priv->pages, TRUE);
            }
            priv->pages = g_string_new(g_value_get_string(value));
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}

static void
kb_article_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec){

    KbArticle *self = KB_ARTICLE(object);
    KbArticlePrivate *priv = KB_ARTICLE_GET_PRIVATE(self);

    switch(property_id){
        case PROPERTY_JOURNAL:
            g_value_set_string(value, priv->journal->str);
            break;
        case PROPERTY_VOLUME:
            g_value_set_string(value, priv->volume->str);
            break;
        case PROPERTY_NUMBER:
            g_value_set_string(value, priv->number->str);
            break;
        case PROPERTY_PAGES:
            g_value_set_string(value, priv->pages->str);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
            break;
    }
}


//类结构体初始化函数
static void
kb_article_class_init(KbArticleClass *klass){

    g_type_class_add_private(klass, sizeof(KbArticlePrivate));

    GObjectClass *base_class = G_OBJECT_CLASS(klass);

    base_class->set_property = kb_article_set_property;
    base_class->get_property = kb_article_get_property;

    GParamSpec *properties[N_PROPERTIES_A] = {NULL,};
    properties[PROPERTY_JOURNAL] =
            g_param_spec_string("journal",
                                "Journal",
                                "",
                                NULL,
                                G_PARAM_READWRITE | G_PARAM_CONSTRUCT
                                //备注：定义为 G_PARAM_CONSTRUCT 在定义对象实例的时候可以不用设置该属性 否则报错Segmentation fault: 11
            );
    properties[PROPERTY_VOLUME] =
            g_param_spec_string("volume",
                                "Volume",
                                "",
                                NULL,
                                G_PARAM_READWRITE
            );
    properties[PROPERTY_NUMBER] =
            g_param_spec_string("number",
                                "Number",
                                "",
                                NULL,
                                G_PARAM_READWRITE);
    properties[PROPERTY_PAGES] =
            g_param_spec_string("pages",
                              "Pages",
                              "",
                              NULL,
                              G_PARAM_READWRITE);

    g_object_class_install_properties(base_class, N_PROPERTIES_A, properties);


}


//实例结构体初始化函数
static void
kb_article_init(KbArticle *self){
    g_printf("\tKbArticle 实例结构体初始化！\n");
}



void
kb_article_printf(KbArticle *self){
    kb_bibtex_printf(&self->parent);

    gchar *journal, *volume, *number, *pages;


    g_object_get(G_OBJECT(self),
                 "journal", &journal,
                 "volume", &volume,
                 "number", &number,
                 "pages", &pages,
                 NULL);


    g_printf(" Journal: %s\n"
             " Volume: %s\n"
             " Number: %s\n"
             " Pages: %s\n", journal, volume, number, pages);


    g_free(journal);
    g_free(volume);
    g_free(number);
    g_free(pages);

}