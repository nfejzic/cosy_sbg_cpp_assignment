#include "street_list.h"
#include "street.h"
#include <climits>
#include <fstream>
#include <iostream>

// using namespace std;

StreetList::StreetList(ifstream &stream, CityList &cities) {
  this->cities = &cities;

  do {
    Street newStreet(stream, cities);

    this->insertStreet(newStreet);
  } while (!stream.eof());
}

void StreetList::insertStreet(Street s) { streets.push_back(s); }

void StreetList::printSelf() const {
  for (auto &street : this->streets) {
    street.printSelf();
  }
}

std::vector<City *> StreetList::getPath() const {
  vector<City *> path;
  City *end = nullptr;

  City *toCity = cities->getCity(cities->getToCityId());

  vector<Street> copy = streets;

  int currentStep = 0;
  // used to check if there is a potential shorter path to the start city
  int bestDistance = INT_MAX;
  bool shorterPathExists = true;

  while (currentStep < cities->getCount()) {
    for (auto street = copy.begin(); street != copy.end(); street++) {

      City *currentCity = street->getCityByStep(currentStep);
      if (currentCity == nullptr)
        continue;

      City *other = street->getConnectedCity(*currentCity);
      if (other == nullptr) // no connection with this city
        continue;

      if (other->getVisitedStep() < 0) { // only not yet visited cities
        int distance = currentCity->getDistance() + street->getLength();
        other->setDistance(distance);

        shorterPathExists = distance < bestDistance;

        if (other->getVisitedStep() == -1) {
          other->setVisitedStep(currentStep + 1); // visited

        } else if (other->getVisitedStep() == -2) {
          // here we won't set visited. There may be shorter path
          end = other; // Ich glaube, man könnte die while-Schleife abbrechen,
                       // sobald end gesetzt ist, oder nicht?  Rade

          // Loesung - beste Entfernung verwenden.
          // Im nächsten Durchlauf wird geschaut ob es möglich kleinere
          // Entfernung gibt. Wenn nein, while Schleife wird abgebrochen
          bestDistance = end->getDistance();
        }
      }

      copy.erase(street--); // remove visited street
    }

    if (!shorterPathExists)
      break;

    currentStep++;
  }

  if (end != nullptr) {
    path.push_back(end);
    while (end != toCity) {
      end = getNearestCity(end);
      path.push_back(end);
    }
  }

  return path;
}

City *StreetList::getNearestCity(City *fromCity) const {
  City *result = nullptr;

  for (auto &s : streets) {
    if (!s.connectedToCity(*fromCity)) // street isn't linked with fromCity
      continue;

    City *city = s.getConnectedCity(*fromCity);
    if (city == nullptr)
      continue;

    // if we get here, we should consider city, they are connected
    if (result == nullptr || city->getDistance() < result->getDistance()) {
      // has shortest distance to goal
      result = city;
    }
  }

  return result;
}
