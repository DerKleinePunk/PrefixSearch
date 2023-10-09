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
    //std::map<char,node*> children; 
    std::unordered_map<char,node*> children;

    node();
    ~node();

    void node::GetWords(const std::string& word, std::vector<std::string>& result);
};


