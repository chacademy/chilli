SHELL = /bin/sh

OBJ_DIR = obj
TARGET_DIR = .#bin

INCLUDE = -I./include -I/usr/include
LIBS = -lmysqlclient

SOURCE = $(wildcard source/*.cpp) 
SOURCE+= $(wildcard test/*.cpp)
OBJS = $(SOURCE:%.cpp=$(OBJ_DIR)/%.o)
#  <=> $(addprefix $(OBJ_DIR)/, $(SOURCE:%.cpp=%.o))

CXXFLAGS = -ggdb
CXXFLAGS+= $(INCLUDE)
LDFLAGS = $(LIBS)

TARGET = $(TARGET_DIR)/auth.exe

$(TARGET) : $(OBJS)
	-@mkdir -p $(TARGET_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS) 
	@echo done

#obj/source/x.o : source/x.cpp
$(OBJS) : $(OBJ_DIR)/%.o : %.cpp
	-@mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

echo:
	@echo INCLUDE=$(INCLUDE)
	@echo SOURCE=$(SOURCE)
	@echo OBJS=$(OBJS)

.PHONY : clean

clean : 
	-@rm -rf $(OBJ_DIR)/*
	-@rm -f $(TARGET)

