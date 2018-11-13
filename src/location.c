#include "location.h"
#include <stdlib.h>

// A constuctor for a location object.
// Returns a location pointer.
Location * new_location(int x, int y){
  Location * loc = malloc(sizeof(Location));
  loc->x = x;
  loc->y = y;
  return (Location *) loc;
}
