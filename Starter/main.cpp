#include "application.h"

int main(int argc, char* argv[]) 
{ 
	Application application = Application();
	if (!application.init()) return -1;
	application.mainLoop();
	application.cleanup();
	return 0;
}
