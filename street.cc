#include "street.h"
#include "city_list.h"
#include <iostream>

using namespace std;

Street::Street(istream &stream, CityList &cities) {
  // if end of file, return
  if (!stream) {
    cerr << "File is empty. Could not read street information! Aborting!"
         << std::endl;
    return;
  }

  stream >> fromCityId >> toCityId >> length;

  // if there is a street which contains ID from city which doesn't exist
  // in our little world the program will exit
  this->fromCity = cities.getCity(fromCityId);
  this->toCity = cities.getCity(toCityId);
}

City *Street::getCityByStep(int currentStep) const {
  if (this->fromCity->getVisitedStep() == currentStep) {
    return this->fromCity;
  } else if (this->toCity->getVisitedStep() == currentStep) {
    return this->toCity;
  } else {
    return nullptr;
  }
}

bool Street::connectedToCity(const City &city) const {
  return this->fromCityId == city.getId() || this->toCityId == city.getId();
}

City *Street::getConnectedCity(const City &city) const {
  if (city.getId() == this->fromCityId) {
    return this->toCity;
  } else if (city.getId() == this->toCityId) {
    return this->fromCity;
  } else {
    return nullptr;
  }
}

const unsigned int Street::getLength() const { return this->length; }

void Street::printSelf() const {
  cout << "Street between " << this->fromCity->getName() << " to "
       << this->toCity->getName() << endl;
}