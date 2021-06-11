#include "city_list.h"
#include "city.h"
#include <iostream>
#include <ostream>

using namespace std;

CityList::CityList(istream &s, string fromCity, string toCity) {
  map<int, City> cities;

  do {
    City newCity(s);

    // fromCity and toCity are different.
    // This modification is needed for path finding
    // When we encounter visitedStep -2 we have succesfully found path between
    // fromCity and toCity
    if (newCity.getName() == fromCity) {
      newCity.setVisitedStep(-2);
      newCity.setDistance(-1);

      this->fromCityId = newCity.getId();
    } else if (newCity.getName() == toCity) {
      newCity.setVisitedStep(0);
      newCity.setDistance(0);

      this->toCityId = newCity.getId();

      // all cities between the from and to city are marked for pathfinding
    } else {
      newCity.setVisitedStep(-1);

      newCity.setDistance(-1);
    }

    this->insertCity(newCity.getId(), newCity);

  } while (s.peek() != EOF);
}

void CityList::insertCity(unsigned int id, City city) {
  // insert into cities map
  cities.insert(pair<unsigned int, City>(id, city));
}

City *CityList::getCity(unsigned int id) { return &cities[id]; }

const unsigned int &CityList::getFromCityId() const { return this->fromCityId; }
const unsigned int &CityList::getToCityId() const { return this->toCityId; }
const unsigned int CityList::getCount() const { return this->cities.size(); }

// print all cities with their information
void CityList::printSelf() {
  for (auto &entry : cities) {
    entry.second.printCity();
  }
}
