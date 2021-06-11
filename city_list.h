#ifndef CITY_LIST_H
#define CITY_LIST_H
#include "city.h"
#include <map>

using namespace std;

class CityList {
public:
  /**
   * Constructor - reads the file containing city data, constructs cities and
   * stores them into a map
   * - &s - istream of the file containing city data
   * - fromCity - string of the city from which should the path be calculated
   * - toCity - string of the city to which should the path be calculated
   */
  CityList(istream &s, string fromCity, string toCity);

  // Returns the city with the given id
  // - id - Unique ID of the city
  City *getCity(unsigned int id);

  // Returns the ID of the start city
  const unsigned int &getFromCityId() const;

  // Returns the ID of the goal city
  const unsigned int &getToCityId() const;

  // Returns the total number of cities contained
  const unsigned int getCount() const;

  // Prints all the cities - one city per line
  void printSelf();

  // Destructor
  // ~CityList(); // nothing to destructure

private:
  // for faster search
  map<unsigned int, City> cities;
  unsigned int fromCityId;
  unsigned int toCityId;

  void insertCity(unsigned int id, City city);
};

#endif