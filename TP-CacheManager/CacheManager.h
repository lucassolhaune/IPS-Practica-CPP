#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

template<class T>
class CacheManager {
    map <string, pair<T, int>> cache_data;
    int capacity;
    int MRU = 1;
    bool isKeyUsed(string);
    bool isCacheFull();
    string getLruKey();
    bool writeFile();
public:
    CacheManager(int cap);
    ~CacheManager();
    void _insert(string key, T obj);
    void printCache();
    T get(string key);
};