#cmake 01--构建包含自定义头文件、源文件的项目
#cd ./build
#cmake -D USE_NONRVO=ON|OFF -D USE_SWITCH=0|1../
#make
#make install

#1.cmake版本
cmake_minimum_required(VERSION 2.6)
#2.项目名
project (CPPTypeConvert) 

#3.设置cmake外部宏(cmake缓存条目)--方法一：设置option()+./config.h.in文件
#configure_file()配置头文件，用于处理 CMake 对源码的设置.
#在config.h.in文件添加一行#cmakedefine USE_RVO。config.h自动生成(只有一句 #define USE_RVO)
#${PROJECT_SOURCE_DIR} == CMakeLists 所在路径---${PROJECT_BINARY_DIR} == ./build (即cmake命令调用路径)
#message(STATUS "${PROJECT_SOURCE_DIR}---${PROJECT_BINARY_DIR}")
#configure_file (
#"${PROJECT_SOURCE_DIR}/config.h.in"
#"${PROJECT_BINARY_DIR}/config.h"
#)

#3.设置cmake外部宏变量(cmake缓存条目)--方法二:采用option()+add_defiitions()分别设置cmake缓存条目(cmake 宏)、源文件宏
#USE_NONRVO  0 0 1 1 
#USE_SWITCH  0 1 0 1
#option()设置cmake缓存条目-注释-默认值(默认值改了后,cmake -UUSE_NONRVO ../ 才重新生效)
#cmake -D tab键 显示所有缓存条目
#option (USE_NONORVO "gcc use RVO" OFF)
#message(STATUS "USE_NONRVO = ${USE_NONRVO}")
##USE_NONRVO = ON ON =1 
#if(USE_NONRVO)
##则定义该宏(源文件宏)，那么.cpp .h 文件可以直接ifdef USE_NONRVO
#    add_definitions(-DUSE_NONRVO)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -fno-elide-constructors -Wall -O0 -Wno-unused-variable ")
#    #OFF则不定义该宏
#else(USE_NONRVO)
#    #显式不定义
#    #add_definitions(-UUSE_NONRVO)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0 -Wno-unused-variable ")
#endif(USE_NONRVO)
#
#option(USE_SWITCH "gcc condition compile" OFF)
#message(STATUS "USE_SWITCH = ${USE_SWITCH}")
#if(USE_SWITCH EQUAL 0)
##=两边不能有空格
#        add_definitions(-DUSE_SWITCH=0)
#elseif(USE_SWITCH EQUAL 1)
#        add_definitions(-DUSE_SWITCH=1)
#else()
#    message(STATUS "the value USE_NONRVO = ${USE_SWITCH} is not defined")
#endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -O0 -Wno-unused-variable ")

#设置待编译源文件列表变量:
#当前路径./ 为CMakeLists.txt所在路径
aux_source_directory(./src SRC_DIR)
#输出变量:
#message(STATUS,"${SRC_DIR}    ${CMAKE_INSTALL_BINDIR}    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

#设置头文件路径：针对第三方头文件(第三方库头文件和自定义头文件)不易寻找时
#include"Test.h" gcc默认是以main.cpp所在路径为相对路径进行查找的。
#标准库头文件路径就不用设置，gcc自动寻找
#CMAKE_CURRENT_SOURCE_DIR 为CMakeLists所在路径
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

#设置生成可执行文件的位置--".../bin"是相对于Makefile文件的位置，因此是../bin
#CMAKE_RUNTIME_OUTPUT_DIRECTORY == 空 (但这表示安装在Makefile文件所在路径下)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

#编译-生成可执行文件
add_executable(mytest ${SRC_DIR})


#安装-将可执行文件安装到CMAKE_INSTALL_PREFIX路径下的CMAKE_INSTALL_BINDIR文件夹
#默认情况：CMAKE_INSTALL_PREFIX == /usr/local ;(可执行文件runtime)CMAKE_INSTALL_BINDIR == 空 （但默认是bin）
#这里"../"相对Makefile文件位置
set(CMAKE_INSTALL_PREFIX "../")
install(TARGETS mytest
       RUNTIME DESTINATION bin
)

