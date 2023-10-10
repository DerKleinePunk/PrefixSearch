#include "trie.hpp"

trie::trie(/* args */)
{
    root = new trieNode();
}

trie::~trie() = default;

void trie::add(const std::string& word) const
{
    auto currentNode = root;

    for(const auto buchstabe : word) {
        if(currentNode->children.find(buchstabe) == currentNode->children.end()) {
            currentNode->children.insert(std::pair<char, trieNode*>(buchstabe, new trieNode()));
        }
        currentNode = currentNode->children[buchstabe];
    }
    currentNode->isEndOfWord = true;
}

std::vector<std::string> trie::Search(const std::string& word)
{
    std::vector<std::string> result;
    trieNode *current = root;
    for (char c : word)
    {
        if (current->children.find(c) == current->children.end())
        {
            return result; // Prefix not found
        }
        current = current->children[c];
    }
    current->GetWords(word, result);
    return result;
}