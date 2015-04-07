# FIND_PACKAGE(<name>) 用来调用预定义在 CMAKE_MODULE_PATH 下的 Find<name>.cmake 模块  
FIND_PACKAGE(mysqlclient)
FIND_PACKAGE(log4cxx)
FIND_PACKAGE(gtest)
FIND_PACKAGE(auth)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include ${gtest_INCLUDE_DIR} ${log4cxx_INCLUDE_DIR})  

# FILE(GLOB_RECURSE auth_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

ADD_EXECUTABLE(test.exe main.cpp)  

# 链接顺序为从后往前
TARGET_LINK_LIBRARIES(
    test.exe 
    ${gtest_LIBRARY} 
    ${log4cxx_LIBRARY}
    ${auth_LIBRARY}
    ${mysqlclient_LIBRARY} 
)  

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# include_directories(${log4cxx_INCLUDE_DIR})
# target_link_libraries(curltest ${log4cxx_LIBRARY})

