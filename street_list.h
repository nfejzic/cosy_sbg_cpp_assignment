#ifndef STREET_LIST_H
#define STREET_LIST_H

#include "street.h"
#include <set>
#include <vector>

using namespace std;

class StreetList {
public:
  /** Constructor
   * - stream - reference to input stream of file with street data
   * - cities - list containing relevant cities
   */
  StreetList(ifstream &stream, CityList &cities);

  /** Inserts given street into the list
   */
  void insertStreet(Street street);

  /** Finds the path from the start city to the end city.
   * Start and end cities are provided as program arguments
   */
  vector<City *> getPath() const;

  // Prints the list - each street will be printed in a separate line
  void printSelf() const;
  //   ~StreetList(); // nothing to destructure

private:
  // set<Street> streets;
  std::vector<Street> streets;
  CityList *cities; // list with cities for the given streets

  // Finds the closest city (by distance) on the path from the given city
  // - fromCity - Pointer to the starting city whose nearest city on the path
  // should be found
  City *getNearestCity(City *fromCity) const;
};

#endif