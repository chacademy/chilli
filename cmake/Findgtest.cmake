    MESSAGE(STATUS $ENV{HOME}/workspace/chilli/thirdparty)  
    FIND_PATH(gtest_INCLUDE_DIR gtest $ENV{HOME}/workspace/chilli/thirdparty/gtest/include)  
      
    #FIND_LIBRARY(gtest_LIBRARY NAMES gtest PATHS $ENV{HOME}/workspace/chilli/thirdparty/gtest/lib)  
    FIND_LIBRARY(gtest_LIBRARY gtest $ENV{HOME}/workspace/chilli/thirdparty/gtest/lib)  
      
    IF (gtest_INCLUDE_DIR)  
        MESSAGE(STATUS "FOUND INCLUDE ${gtest_INCLUDE_DIR}")  
    ENDIF (gtest_INCLUDE_DIR)  
      
    IF (gtest_LIBRARY)  
      MESSAGE(STATUS "FOUND LIB  ${gtest_LIBRARY}")  
    ENDIF (gtest_LIBRARY)  
      
    IF (gtest_INCLUDE_DIR AND gtest_LIBRARY)  
      SET(gtest_FOUND TRUE)  
    ENDIF (gtest_INCLUDE_DIR AND gtest_LIBRARY)  
      
    IF (gtest_FOUND)  
      IF (NOT gtest_FIND_QUIETLY)  
        MESSAGE(STATUS "Found gtest: ${HELO_LIBRARY}")  
      ENDIF (NOT gtest_FIND_QUIETLY)  
    ELSE (gtest_FOUND)  
      IF (gtest_FIND_REQUIRED)  
        MESSAGE(FATAL_ERROR "Could not find gtest library")  
      ENDIF (gtest_FIND_REQUIRED)  
    ENDIF (gtest_FOUND)
