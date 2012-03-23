#ifndef _GTGSHP_H_
#define _GTGSHP_H_

#include "Eci.h"
#include "CoordGeodetic.h"
#include "Observer.h"
#include "gtg.h"
#include "shapefil.h"

class ShapefileWriter
{
public:

	ShapefileWriter(const char *basepath, enum output_feature_type features,
			double latitude, double longitude, double altitude);
	
	~ShapefileWriter()
	{
	}
	
	int output(Eci *loc, Eci *nextloc = NULL, bool split = false);
		
	void close(void);

private:

	void outputAttributes(int index, Eci *loc, CoordGeodetic *geo);
	
	int shpFormat_;
	SHPHandle shp_;
	DBFHandle dbf_;
	Observer *obs_;
};

#endif
