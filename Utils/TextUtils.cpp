#include "TextUtils.h"
#include "Macro.h"
#include <fstream>
#include <sstream>
std::string TextUtils::ReadText(const char* fileLocation)
{
	std::ifstream fileStream;
	fileStream.open(fileLocation, std::ifstream::in);
	if (!fileStream)
		PRINT("Error Opening file " + *fileLocation);

	std::stringstream stringStream;
	stringStream << fileStream.rdbuf();
	std::string content = stringStream.str();
	return content;
}

