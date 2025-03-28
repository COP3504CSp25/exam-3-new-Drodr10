#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
  auto file = std::ifstream(filename);

  if(!file.is_open()){
    std::cout << -1 << std::endl;
  }

  std::map<std::string, int> trafficData;

  char* data;
  std::string airport = "";
  int passengerNumber = 0;
  
  while(true){
    file.read(data, 3);
    if(data == "")
      break;
    airport = data;
    
    //Throw out comma
    file.read(data, 1);
    data = "";
    
    file.read(data, 8);
    passengerNumber = std::stoi(std::string(data));

    trafficData.emplace(airport, passengerNumber);
  }
  
  file.close();

  return trafficData;
}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
  auto file = std::ifstream(filename);

  if(!file.is_open()){
    std::cout << -1 << std::endl;
  }

  char* data;
  std::string airport = "";
  int passengerNumber = 0;
  
  while(true){
    file.read(data, 3);
    if(data == "")
      break;
    airport = data;
    
    //Throw out comma
    file.read(data, 1);
    data = "";
    
    file.read(data, 8);
    passengerNumber = std::stoi(std::string(data));

    dataMap[airport] = passengerNumber;
  }
  
  file.close();
}