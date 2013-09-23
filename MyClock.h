#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGFobject.h"
#include "Math.h"

class MyClock : public CGFobject {
	int slices;
	
public:
	 float angmin,anghour,angsec;
		MyClock();
		void drawClock();
		void update(bool stat);

		
};



#endif