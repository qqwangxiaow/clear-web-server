CMAKE_MINIMUM_REQUIRED( VERSION 2.8 ) #设定使用的cmake的版本
PROJECT(clear-web-server) #设定项目或工程名
SET( CMAKE_CXX_COMPILER "Clang") #设定编译器
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #设定编译后生成的可执行二进制文件所在的目录
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) #设定编译后生成的库文件所在的目录
LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib) #并且把该目录设为链接目录
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include) #设定头文件所在的目录
ADD_SUBDIRECTORY( ${PROJECT_SOURCE_DIR}/src) #如果希望进入源代码文件夹仍可以继续使用cmake，则需增加文件夹







