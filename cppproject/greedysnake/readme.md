/工作目录
    |————CMakeLists.txt
    /*格式1：一种简约风格
    |————src/       ".cpp
    |————include/   "第三方库的头文件.h
    |————lib/       ".h对应的第三方库:.a、.so
    */
    /*格式2：一种不用第三库，而用自己定义的底层基础源文件(可以选择编译为库)
    |--chatseversrc/    "该项目的第一个可执行文件对应的源码:.h , .cpp
    |--fileseversrc/    "第二个可执行文件
    |--net/             "自定义底层基础1，网络基础
    |---utils/          "基础2,通用工具
     
     */
    |————etc/            "配置文件
    |————build/          "项目构建结果临时存放位置。cd ./build;cmake ../CMakeLists.txt生成在这
    |————script/
    |————bin/            "可执行文件
    |————doc/            "帮助文档
    |————readme.md       "项目目录结构;项目编译安装介绍；可执行文件使用介绍。
