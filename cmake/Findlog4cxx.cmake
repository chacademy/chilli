    MESSAGE(STATUS $ENV{HOME}/workspace/chilli/thirdparty)  
    FIND_PATH(log4cxx_INCLUDE_DIR log4cxx $ENV{HOME}/workspace/chilli/thirdparty/log4cxx/include)  
      
    #FIND_LIBRARY(log4cxx_LIBRARY NAMES log4cxx PATHS $ENV{HOME}/workspace/chilli/thirdparty/log4cxx/lib)  
    FIND_LIBRARY(log4cxx_LIBRARY log4cxx $ENV{HOME}/workspace/chilli/thirdparty/log4cxx/lib)  
      
    IF (log4cxx_INCLUDE_DIR)  
        MESSAGE(STATUS "FOUND INCLUDE ${log4cxx_INCLUDE_DIR}")  
    ENDIF (log4cxx_INCLUDE_DIR)  
      
    IF (log4cxx_LIBRARY)  
      MESSAGE(STATUS "FOUND LIB  ${log4cxx_LIBRARY}")  
    ENDIF (log4cxx_LIBRARY)  
      
    IF (log4cxx_INCLUDE_DIR AND log4cxx_LIBRARY)  
      SET(log4cxx_FOUND TRUE)  
    ENDIF (log4cxx_INCLUDE_DIR AND log4cxx_LIBRARY)  
      
    IF (log4cxx_FOUND)  
      IF (NOT log4cxx_FIND_QUIETLY)  
        MESSAGE(STATUS "Found log4cxx: ${HELO_LIBRARY}")  
      ENDIF (NOT log4cxx_FIND_QUIETLY)  
    ELSE (log4cxx_FOUND)  
      IF (log4cxx_FIND_REQUIRED)  
        MESSAGE(FATAL_ERROR "Could not find log4cxx library")  
      ENDIF (log4cxx_FIND_REQUIRED)  
    ENDIF (log4cxx_FOUND)
