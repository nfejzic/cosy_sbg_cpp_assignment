#include "city.h"
#include <iostream>
#include <istream>

City::City(std::istream &s) {
  if (!s) {
    std::cerr << "File is empty. Could not read city information! Aborting!"
              << std::endl;
    return;
  }
  s >> id >> name >> population >> areaID >> elevation;
}

City::City() {
  this->id = 0;
  this->name = "???";
  this->population = 0;
  this->areaID = 0;
  this->elevation = 0;
}

unsigned int const &City::getId() const { return id; }
std::string const &City::getName() const { return name; }

const int &City::getDistance() const { return this->distance; }
const int &City::getVisitedStep() const { return this->visitedStep; }

void City::setVisitedStep(int step) { this->visitedStep = step; }
void City::setDistance(int distance) { this->distance = distance; }

void City::printCity() {
  std::cout << "This city is " << this->name;
  std::cout << " with id " << this->id << ", population " << this->population;
  std::cout << ", areaID " << this->areaID << " and elevation "
            << this->elevation << std::endl;
}