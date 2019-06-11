# GObject-demo
GObject的demo案例

##################################
## mac 下安装配置glib环境
### 安装
brew install glib

brew install libffi

### 在CMakeLists.txt加入
include_directories(

        /usr/local/Cellar/glib/2.60.3/include/glib-2.0
        /usr/local/Cellar/glib/2.60.3/lib/glib-2.0/include
)

### 在.bash_profile配置
vi .bash_profile

export PKG_CONFIG_PATH=/usr/local/Cellar/libffi/3.2.1/lib/pkgconfig

source .bash_profile

##################################

## 执行
cd /Users/tonye/CLionProjects/CLionProjects-gstreamer/GObject-demo

gcc $(pkg-config --cflags --libs gobject-2.0)  main.c -o test

## 使用glib-genmarshal工具生成g_cclosure_user_marshal_INT__VOID_VOID函数
export PYTHONPATH="/Library/Frameworks/Python.framework/Versions/3.6"

glib-genmarshal --body lib/int__void_void.txt > lib/int__void_void.c.bak

glib-genmarshal --body lib/accumulator/int__string.txt > lib/accumulator/int__string.c.bak

## 使用命令将 G_DEFINE_TYPE 宏 代码展开
gcc `pkg-config --cflags --libs gobject-2.0` -E -P lib/signal/my-file.c > lib/signal/my-file-extend.c.bak