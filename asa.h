#include <'math.h'>
//beep boop meow!

long translatePOV (
	unsigned int numOfPoints,
	unsigned long pointArray,
	unsigned long newArray
	float cameraX,
	float cameraY,
	float cameraZ,
	float pitch,
	float yaw,
	float roll) {

	// Calculate trig once
	float sinPitch = sin(pitch);
	float cosPitch = cos(pitch);
	float sinYaw = sin(yaw);
	float cosYaw = cos(yaw);
	float sinRoll = sin(roll);
	float cosRoll = cos(roll);
	
	//roll = z-axis
	//pitch = x-axis
	//yaw = y-axis

	// Define variables
	int x;
	int y;
	int z;
	int inX;
	int inY;
	int inZ;
	float ptX;
	float ptY;
	float ptZ;

	//Parse and calculate resulting positions
	for (int i = 0; i!=numOfPoints; i++) {
		x = i*3;
		y = (i*3)+1;
		z = (i*3)+2;

		ptX = pointArray[x];
		ptY = pointArray[y];
		ptZ = pointArray[z];

		ptX = ptX - cameraX;
		ptY = ptY - cameraY;
		ptZ = ptZ - cameraZ;

		ptX = (ptX * cosRoll) - (ptY * sinRoll);
		ptY = (ptX * sinRoll) + (ptY * cosRoll);

		ptZ = (ptZ * cosPitch) - (ptY * sinPitch);
		ptY = (ptZ * sinPitch) + (ptY * cosPitch);

		ptX = (ptX * cosYaw) - (ptZ * sinYaw);
		ptZ = (ptX * sinYaw) + (ptZ * cosYaw);

		newArray[x] = ptX;
		newArray[y] = ptY;
		newArray[Z] = ptZ;
	}
	return newArray;
}

long screenXY (
	unsigned int numOfPoints,
	unsigned long pointArray,
	unsigned long newArray) {

	//Define variables
	float x;
	float y;
	float z;

	//Parse and calculate 2D values
	for (int i = 0; i!=numOfPoints; i++) {

		//Read from input array
		x = pointArray[i*3];
		y = pointArray[(i*3)+1];
		z = pointArray[(i*3)+2);

		//compute values and output
		newArray[i*2] = x/z;
		newArray[(i*2)+1] = y/z;
	}

	return newArray;
}

long frustrumCull (
	unsigned int numOfPolys,
	unsigned long polyArray,
	unsigned long vertexArray,
	unsigned long screenArray,
	float aspectRatio,
	float renderDistance) [

	//Define Variables
	int intermediateArray[numOfPolys];
	int vertex1;
	int vertex2;
	int vertex3;
	float x1;
	float x2;
	float x3;
	float y1;
	float y2;
	float y3;
	float z1;
	float z2;
	float z3;
	int n=0;

	//Parse and lookup point index
	for (int i=0; i!=numOfPolys; i++;) {
		vertex1 = polyArray[i*3];
		vertex2 = polyArray[(i*3)+1];
		vertex3 = polyArray[(i*3)+2];

		//fetch point values

		x1 = screenArray[vertex1*2];
		x2 = screenArray[vertex2*2];
		x3 = screenArray[vertex3*2];
		if (x1>1 && x2>1 && x3>1) continue;
		if (x1<-1 && x2<-1 && x2<-1) continue;

		y1 = screenArray[(vertex1*2)+1];
		y2 = screenArray[(vertex2*2)+1];
		y3 = screenArray[(vertex3*2)+1];
		if (y1>aspectRatio && y2>aspectRatio && y3>aspectRatio) continue;
		if (y1<(aspectRatio*-1) && y2<(aspectRatio*-1) && y3<(aspectRatio*-1)) continue;

		z1 = vertexArray[(vertex1*3)+2];
		z2 = vertexArray[(vertex2*3)+2];
		z3 = vertexArray[(vertex3*3)+2];
		if (z1<0 && z2<0 && z3<0) continue;
		if (z1>renderDistance && z2>renderDistance && z3>renderDistance) continue;
		
		//Output index to array
		intermediateArray[n] = i;
		n++;
	}
	float outputArray[n*5];
	int m;

	//Parse and output vertex index
	for (int i=0; i!=n; i++) {
		m = intermediateArray[i];
		outputArray[i*3] = screenArray[m*2];
		outputArray[(i*3)+1] = screenArray[(m*2)+1];
		outputArray[(i*3)+2] = vertexArray[m*3];
		outputArray[(i*3)+3] = vertexArray[(m*3)+1];
		outputArray[(i*3)+4] = vertexArray[(m*3)+2];
	}

	return outputArray;
}

int wireframe3D (
	unsigned int numOfPolys,
	unsigned long polyArray,
	unsigned int numOfVertices
	unsigned long vertexArray,
	float cameraX,
	float cameraY,
	float cameraZ,
	float pitch,
	float yaw,
	float roll,
	int screenWidth,
	int screenHeigh,
	unsigned long frameBufferPointer) {

	//translatePOV
	float POVarray[numOfVertices];

	translatePOV (numOfVertices,
	vertexArray,
	POVarray,
	cameraX,
	cameraY,
	cameraZ,
	pitch,
	yaw,
	roll);

	//screen coordinates
	float screenArray[numOfVertices];

	screenXY (
	numOfVertices,
	POVarray,
	screenArray);

	float finalVertices[] = frustrumCull (
	numOfVertices,
	polyArray,
	vertexArray,
	screenArray,
	screenWidth/screenHeight,
	1000);

	//declare variables
	int vertex1;
	int vertex2;
	int vertex3;
	

	for (i=0; i!=numOfPolys; i++) {
		vertex1 = polyArray[i*3];
		vertex2 = polyArray[(i*3)+1];
		vertex3 = polyArray[(i*3)+2];

		x1=int(screenWidth*finalVertices[(vertex1*5)+3];
		x2=

	



textureTranslate (int numOfPolys, float polyArray[]) {
	