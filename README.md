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
