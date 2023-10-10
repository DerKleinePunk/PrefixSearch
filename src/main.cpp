#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>

#include "trie/trie.hpp"
#include "trie/trieNode.hpp"

int main(int, char**) {
    std::cout << "Hello, from prefixSearch!\n";

    std::string line;
    std::vector<std::string> wortlist;

    std::ifstream myfile ("wortliste.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line) )
        {
            //std::cout << line << std::endl;
            wortlist.push_back(line);
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        return 99;
    }

    std::cout << wortlist.size() << " words loaded" << std::endl;

    trie testTrie;
    for(auto word : wortlist) {
        testTrie.add(word);
    }

    std::cout << "trie erstellt" << std::endl;

    const auto start_time = std::chrono::high_resolution_clock::now();
    auto result = testTrie.Search("Text");
    const auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "search time = " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "[us]" << std::endl;

    /*
    for(auto entry : result) {
        std::cout << entry << std::endl;
    }*/
}
