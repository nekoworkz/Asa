#include <'math.h'>
//beep boop meow!

// root graphics function. Creates and draws entire frame
int drawFrame (
	uintptr_t	frameBuffer,		// Pointer to framebuffer
	uint16_t	numOfObjects		// Number of objects in scene
	uintptr_t	objectX,		// Pointer to object X position array, elements in float
	uintptr_t	objectY,		// Pointer to object Y position array, elements in float
	uintptr_t	objectZ,		// Pointer to object Z position array, elements in float
	uintptr_t	objectYaw,		// Pointer to object yaw array, elements in int32_t
	uintptr_t	objectRoll,		// Pointer to object roll array, elements in int32_t
	uintptr_t	objectPitch,		// Pointer to object pitch array, elements in int32_t
	uintptr_t	objectScale,		// Pointer to object scaling array, elements in float
	uintptr_t	objectNumPoly,		// Pointer to object number of polygons array, elements in uint32_t
	uintptr_t	objectPolygonP,		// Pointer to object P polygon array pointer array, elements in uintptr_t
	uintptr_t	objectPolygonQ,		// Pointer to object Q polygon array pointer array, elements in uintptr_t
	uintptr_t	objectPolygonR,		// Pointer to object R polygon array pointer array, elements in uintptr_t
	uintptr_t	objectNumVert,		// Pointer to object number of vertices array, elements in uint32_t
	uintptr_t	objectVerticesX,	// Pointer to object X vertex array pointer array, elements in uintptr_t
	uintptr_t	objectVerticesY,	// Pointer to object Y vertex array pointer array, elements in uintptr_t
	uintptr_t	objectVerticesZ,	// Pointer to object Z vertex array pointer array, elements in uintptr_t
	uintptr_t	objectTexture,		// Pointer to object texture pointer array, elements in uintptr_t
	int32_t		cameraYaw,		// Camera Yaw angle in scaled units, 8LSB is ignored
	int32_t		cameraRoll,		// Camera Roll angle in scaled units, 8LSB is ignored
	int32_t		cameraPitch		// Camera Pitch angle in scaled units, 8LSB is ignored
	)
{
		
		// Calculate maximum number of polygons and vertices
		uint32_t maxNumPoly = sum ( numOfObjects, objectNumPoly );	// Calculate potential polygons
		uint32_t maxNumVert = sum ( numOfObjects, objectnumVert );	// Calculate potential vertices
		
		// Declare scene polygon arrays
		uint32_t scenePolygonsP [ maxNumPoly ];
		uint32_t scenePolygonsQ [ maxNumPoly ];
		uint32_t scenePolygonsR [ maxNumPoly ];
		
		// Declare scene vertice arrays
		uint32_t sceneVerticesX [ maxNumVert ];
		uint32_t sceneVerticesY [ maxNumVert ];
		uint32_t sceneVerticesZ [ maxNumVert ];
		
		// Populate scene polygon arrays
		importObjectPoly ( maxNumPoly, scenePolygonsP, numOfObjects, objectNumPoly, objectPolygonP, objectNumVert );	// Copy all P indices
		importObjectPoly ( maxNumPoly, scenePolygonsQ, numOfObjects, objectNumPoly, objectPolygonQ, objectNumVert );	// Copy all Q indices
		importObjectPoly ( maxNumPoly, scenePolygonsR, numOfObjects, objectNumPoly, objectPolygonR, objectNumVert );	// Copy all R indices
		
		// Populate scene vertice arrays
		importObjectVert ( maxNumVert, sceneVerticesX, numOfObjects, objectNumVert, )
		
		// Translate Object Vertices
		translate ();
		
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
