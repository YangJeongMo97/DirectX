#include "RandPoint.h"

RECT RandPoint(int xSize, int ySize) {
	RECT rc;
	rc.left = rand() % xSize;
	rc.top = rand() % ySize;
	rc.right = rand() % xSize;
	rc.bottom = rand() % ySize;
	while(rc.left > rc.right || rc.top > rc.bottom){
		rc.right = rand() % xSize;
		rc.bottom = rand() % ySize;
	}
	return rc;
}