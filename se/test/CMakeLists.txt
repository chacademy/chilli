    # FIND_PACKAGE(<name>) 用来调用预定义在 CMAKE_MODULE_PATH 下的 Find<name>.cmake 模块  
    FIND_PACKAGE(hello)
    FIND_PACKAGE(log4cxx)
    FIND_PACKAGE(gtest)


    INCLUDE_DIRECTORIES(${HELLO_INCLUDE_DIR} ${log4cxx_INCLUDE_DIR})  

    ADD_EXECUTABLE(hello main.cpp)  

    TARGET_LINK_LIBRARIES(hello ${HELLO_LIBRARY} ${log4cxx_LIBRARY})  

    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

   # include_directories(${log4cxx_INCLUDE_DIR})
   # target_link_libraries(curltest ${log4cxx_LIBRARY})

