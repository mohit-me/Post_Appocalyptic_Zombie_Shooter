#include "Zombie.h"

#ifndef HEADEATER_H_
#define HEADEATER_H_

/*Zombie type
  This is one type of a zombie.
  It inherits from the Zombie class.
*/
class HeadEater : public Zombie {
public:
	//Constructor
	HeadEater();

	// Destructor
	virtual ~HeadEater();
};



#endif /* HEADEATER_H_ */
