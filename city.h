#ifndef CITY_H
#define CITY_H
#include <istream>
#include <string>

class City {
public:
  /** Constructor.
   * - istream - reference to the input stream of the file containing city data
   */
  City(std::istream &s);

  // Default constructor, needed for map
  City();

  // Returns the current accumulated distance value of the city from the end
  // (goal) city
  const int &getDistance() const;

  // Returns the current visited step value of the city. Visited step value is
  // the number of visited cities from the goal city up to this point (including
  // goal city) Needed for path calculation
  const int &getVisitedStep() const;

  // Sets the visited step value. Needed for path calculation
  // - step - the step value. Can be negative.
  void setVisitedStep(int step);

  // Sets the accumulated distance of the city from the end city
  void setDistance(int distance);

  // Returns the Unique ID of the city
  unsigned int const &getId() const;

  // Returns the name of the city
  std::string const &getName() const;

  // Simple display of the city data
  void printCity();

  // Destructor
  // ~City(); // nothing to destructure

private:
  // all of these are positive numbers
  unsigned int id;
  unsigned int population;
  unsigned int areaID;
  unsigned int elevation;

  // this is used for path calculating algorithm. Not visited cities have value
  // -1. Start and Goal city have -2
  int visitedStep;
  int distance;
  std::string name;
};

#endif