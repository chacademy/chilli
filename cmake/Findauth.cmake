    MESSAGE(STATUS $ENV{HOME}/workspace/chilli/thirdparty)  
    FIND_PATH(auth_INCLUDE_DIR auth $ENV{HOME}/workspace/chilli/auth/include)  
      
    #FIND_LIBRARY(auth_LIBRARY NAMES auth PATHS $ENV{HOME}/workspace/chilli/thirdparty/auth/lib)  
    FIND_LIBRARY(auth_LIBRARY auth $ENV{HOME}/workspace/chilli/auth/lib)  
      
    IF (auth_INCLUDE_DIR)  
        MESSAGE(STATUS "FOUND INCLUDE ${auth_INCLUDE_DIR}")  
    ENDIF (auth_INCLUDE_DIR)  
      
    IF (auth_LIBRARY)  
      MESSAGE(STATUS "FOUND LIB  ${auth_LIBRARY}")  
    ENDIF (auth_LIBRARY)  
      
    IF (auth_INCLUDE_DIR AND auth_LIBRARY)  
      SET(auth_FOUND TRUE)  
    ENDIF (auth_INCLUDE_DIR AND auth_LIBRARY)  
      
    IF (auth_FOUND)  
      IF (NOT auth_FIND_QUIETLY)  
        MESSAGE(STATUS "Found auth: ${HELO_LIBRARY}")  
      ENDIF (NOT auth_FIND_QUIETLY)  
    ELSE (auth_FOUND)  
      IF (auth_FIND_REQUIRED)  
        MESSAGE(FATAL_ERROR "Could not find auth library")  
      ENDIF (auth_FIND_REQUIRED)  
    ENDIF (auth_FOUND)
