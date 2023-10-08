#pragma once
#include <map>
#include <vector>
#include <string>
#include <unordered_map>


class node
{
private:
    /* data */
public:
    bool isEndOfWord;
    std::map<char,node*> children; 
    //std::unordered_map<char,node*> children;

    node();
    ~node();

    const std::vector<std::string> GetWords(const std::string& word);
};


