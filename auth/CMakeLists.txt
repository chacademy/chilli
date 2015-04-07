cmake_minimum_required(VERSION 2.8)  

PROJECT(auth)  

# CMAKE_MODULE_PATH定义必须放到前面  
SET(CMAKE_MODULE_PATH $ENV{HOME}/workspace/chilli/cmake)  
MESSAGE(STATUS $ENV{HOME}/workspace/chilli/cmake)

ADD_SUBDIRECTORY(src)  
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(unittest)
