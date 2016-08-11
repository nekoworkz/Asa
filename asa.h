#include <'math.h'>
//beep boop meow!

// root graphics function. draws entire frame
int drawFrame (
	uintptr_t	frameBuffer,	// Pointer to framebuffer
	uint16_t	numOfObjects	// Number of objects in scene
	uintptr_t	objectX,	// Pointer to object X position array, elements in float
	uintptr_t	objectY,	// Pointer to object Y position array, elements in float
	uintptr_t	objectZ,	// Pointer to object Z position array, elements in float
	uintptr_t	objectYaw,	// Pointer to object yaw array, elements in int32_t
	uintptr_t	objectRoll,	// Pointer to object roll array, elements in int32_t
	uintptr_t	objectPitch,	// Pointer to object pitch array, elements in int32_t
	uintptr_t	objectScale,	// Pointer to object scaling array, elements in float
	uintptr_t	objectNumPoly,	// Pointer to object number of polygons array, elements in uint32_t
	uintptr_t	objectPolygons,	// Pointer to object polygon array pointer array, elements in uintptr_t
	uintptr_t	objectNumVert,	// Pointer to object number of vertices array, elements in uint32_t
	uintptr_t	objectVertices,	// Pointer to object vertex array pointer array, elements in uintptr_t
	uintptr_t	objectTexture,	// Pointer to object texture pointer array, elements in uintptr_t
	int32_t		cameraYaw,	// Camera Yaw angle in scaled units, 8LSB is ignored
	int32_t		cameraRoll,	// Camera Roll angle in scaled units, 8LSB is ignored
	int32_t		cameraPitch	// Camera Pitch angle in scaled units, 8LSB is ignored
	)
{
		
		// Calculate maximum number of polygons and vertices
		uint32_t maxNumPoly = sum ( numOfObjects, objectNumPoly );
		uint32_t maxNumvert = sum ( numOfObjects, objectnumVert );
		
}


// Calculate sum of data set
uint32_t sum (
	numOfElements,	// Number of elements to sum,
	elementArray	// Pointer to array of elements
	)
{
	
	// Declare accumulator
	uint32_t E = 0;
	
	// Accumulate array elements
	for (uint32_t i = 0; i!=numOfElements; i++;) {
		E = E + elementArray[i];
	}
	
	//Return value
	return E;
}
