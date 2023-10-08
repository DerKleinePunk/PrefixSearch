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

const std::vector<std::string> node::GetWords(const std::string& word)
{
    std::vector<std::string> result;
    if(isEndOfWord) {
        result.push_back(word);
    }
    for(const auto entry : children) {
        auto nextPrefix = word + entry.first;
		auto next = entry.second->GetWords(nextPrefix);
        result.insert(result.end(), next.begin(), next.end());
	}
    return result;
}