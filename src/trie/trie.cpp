#include "trie.hpp"

trie::trie(/* args */)
{
}

trie::~trie()
{
}

void trie::add(const std::string& word)
{
    auto currentNode = &root;

    for(const auto buchstabe : word) {
        if(currentNode->children.find(buchstabe) == currentNode->children.end()) {
            currentNode->children.insert(std::pair<char, node*>(buchstabe, new node()));
        }
        currentNode = currentNode->children[buchstabe];
    }
    currentNode->isEndOfWord = true;
}

std::vector<std::string> trie::Search(const std::string& word)
{
    auto currentNode = &root;
    for(const auto buchstabe : word) {
        if(currentNode->children.find(buchstabe) == currentNode->children.end()) {
            break;
        }
    }

    return currentNode->GetWords(word);
}