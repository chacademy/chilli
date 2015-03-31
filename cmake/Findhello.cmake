    MESSAGE(STATUS $ENV{HOME}/workspace/chilli/hello)  
    FIND_PATH(HELLO_INCLUDE_DIR hello.h $ENV{HOME}/workspace/chilli/hello/include)  
      
    #FIND_LIBRARY(HELLO_LIBRARY NAMES hello PATHS $ENV{HOME}/workspace/chilli/hello/lib)  
    FIND_LIBRARY(HELLO_LIBRARY hello $ENV{HOME}/workspace/chilli/hello/lib)  
      
    IF (HELLO_INCLUDE_DIR)  
      MESSAGE(STATUS "FOUND HELLO.H  ${HELLO_INCLUDE_DIR}")  
    ENDIF (HELLO_INCLUDE_DIR)  
      
    IF (HELLO_LIBRARY)  
      MESSAGE(STATUS "FOUND HELLO LIB  ${HELLO_LIBRARY}")  
    ENDIF (HELLO_LIBRARY)  
      
    IF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)  
      SET(HELLO_FOUND TRUE)  
    ENDIF (HELLO_INCLUDE_DIR AND HELLO_LIBRARY)  
      
    IF (HELLO_FOUND)  
      IF (NOT HELLO_FIND_QUIETLY)  
        MESSAGE(STATUS "Found Hello: ${HELO_LIBRARY}")  
      ENDIF (NOT HELLO_FIND_QUIETLY)  
    ELSE (HELLO_FOUND)  
      IF (HELLO_FIND_REQUIRED)  
        MESSAGE(FATAL_ERROR "Could not find hello library")  
      ENDIF (HELLO_FIND_REQUIRED)  
    ENDIF (HELLO_FOUND)
