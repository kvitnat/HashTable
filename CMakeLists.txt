cmake_minimum_required(VERSION 3.15)
project(HashTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(HashTable main.cpp classes/Tree.h checker/Checker.cpp checker/VectorChecker.cpp checker/TreeChecker.cpp checker/HashChecker.cpp checker/MyHashChecker.cpp checker/HashTable.cpp classes/Trie.cpp checker/TrieChecker.cpp)