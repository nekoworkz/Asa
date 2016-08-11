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
	uintptr_t	objectPolygons,	// Pointer to object polygon array pointer array, elements in uintptr_t
	uintptr_t	objectVertices,	// Pointer to object vertex array pointer array, elements in uintptr_t
	uintptr_t	objectTexture,	// Pointer to object texture pointer array, elements in uintptr_t
	int32_t		cameraYaw,	// Camera Yaw angle in scaled units, 8LSB is ignored
	int32_t		cameraRoll,	// Camera Roll angle in scaled units, 8LSB is ignored
	int32_t		cameraPitch	// Camera Pitch angle in scaled units, 8LSB is ignored
	) {
		
		// Cull Vertices not in scene
		
		cullInScene ();
		
	}
