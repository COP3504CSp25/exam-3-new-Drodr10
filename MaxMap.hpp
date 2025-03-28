#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    if(data.find(search_term) == data.end())
        return -1;
    
    auto list = data.at(search_term);
    float max = list.at(0);
    for(size_t i = 1; i < list.size(); ++i){
        max = (list.at(i) > max) ? list.at(i) : max;
    }
    return max;
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    std::map<std::string, float> maxMap;
    
    auto iter = in_map.begin();
    
    std::string name;
    float max;
    for(iter; iter != in_map.end(); ++iter){
        name = iter -> first;
        max = iter -> second.at(0);
        for(size_t i = 1; i < iter->second.size(); ++i){
            max = (iter->second.at(i) > max) ? iter->second.at(i) : max;
        }
        maxMap.emplace(name, max);
    }

    return maxMap;
}