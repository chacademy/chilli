# 添加头文件的查找目录  
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)  

# 指定可执行文件的输出目录，输出到bin下面  
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  

# ---- 指定可执行文件名和相关源文件   
#ADD_EXECUTABLE(auth.exe *.cpp)  

# 指定库文件输出路径  
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)  

# ---- 生成动态库  
# 注意，前面已经使用target文件名auth，这里不能再用。  

FILE(GLOB_RECURSE auth_SRC *.cpp)

ADD_LIBRARY(auth 
    SHARED 
    ${auth_SRC}) 

# 设置库输出名为 hello => libhello.so  
SET_TARGET_PROPERTIES(auth PROPERTIES OUTPUT_NAME "auth")  

# ---- 生成静态库  
# 注意，前面已经使用target文件名hello，这里不能再用。  
#ADD_LIBRARY(auth_a STATIC *.cpp)  

# 设置输库出名为 hello => libhello.a  
#SET_TARGET_PROPERTIES(hello_a PROPERTIES OUTPUT_NAME "hello")  
