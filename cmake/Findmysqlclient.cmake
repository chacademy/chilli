    #MESSAGE(STATUS $ENV{HOME}/workspace/chilli/)  
    FIND_PATH(mysqlclient_INCLUDE_DIR mysqlclient /usr/include)  
      
    FIND_LIBRARY(mysqlclient_LIBRARY mysqlclient /usr/lib/x86_64-linux-gnu/)  
      
    IF (mysqlclient_INCLUDE_DIR)  
        MESSAGE(STATUS "FOUND INCLUDE ${mysqlclient_INCLUDE_DIR}")  
    ENDIF (mysqlclient_INCLUDE_DIR)  
      
    IF (mysqlclient_LIBRARY)  
      MESSAGE(STATUS "FOUND LIB  ${mysqlclient_LIBRARY}")  
    ENDIF (mysqlclient_LIBRARY)  
      
    IF (mysqlclient_INCLUDE_DIR AND mysqlclient_LIBRARY)  
      SET(mysqlclient_FOUND TRUE)  
    ENDIF (mysqlclient_INCLUDE_DIR AND mysqlclient_LIBRARY)  
      
    IF (mysqlclient_FOUND)  
      IF (NOT mysqlclient_FIND_QUIETLY)  
        MESSAGE(STATUS "Found mysqlclient: ${HELO_LIBRARY}")  
      ENDIF (NOT mysqlclient_FIND_QUIETLY)  
    ELSE (mysqlclient_FOUND)  
      IF (mysqlclient_FIND_REQUIRED)  
        MESSAGE(FATAL_ERROR "Could not find mysqlclient library")  
      ENDIF (mysqlclient_FIND_REQUIRED)  
    ENDIF (mysqlclient_FOUND)
