# SRC_COM = $(wildcard huawei_online/*.cc)

# SRC = test_huawei.cc $(SRC_COM)

SRC_COM = $(wildcard search_alg_impls/*.cc)

SRC = test_search.cc $(SRC_COM)

# $@  表示目标文件
# $^  表示所有的依赖文件
# $<  表示第一个依赖文件
# $?  表示比目标还要新的依赖文件列表

CXX = g++
CXXFLAGS = -std=c++11 -g -O0
TARGET = test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf test test.dSYM

.PHONY: clean