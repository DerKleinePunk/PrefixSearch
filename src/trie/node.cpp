#include "node.hpp"

node::node(/* args */)
{
    isEndOfWord = false;
}

node::~node()
{
    for(auto entry : children) {
        delete entry.second;
    }

    children.clear();
}

void node::GetWords(const std::string& word, std::vector<std::string>& result)
{
    if(isEndOfWord) {
        result.push_back(word);
    }

    for(const auto &entry : children) {
        auto nextPrefix = word + entry.first;
		entry.second->GetWords(nextPrefix, result);
	}
}