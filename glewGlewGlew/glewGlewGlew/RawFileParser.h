#ifndef RAW_FILE_PARSER
#define RAW_FILE_PARSER

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ios>

class RawFileParser
{
public:
	RawFileParser(std::string image_path, int width, int height, int depth);
	~RawFileParser();
	std::vector< std::vector<char>* >* getNextPlan();
	std::vector< std::vector<float>* >* getNextPlanOpenglFormatted();
	int getWidth();
	int getHeight();
private:
	std::fstream _image_file;
	int _width;
	int _height;
	int _depth;
	int _current_plan;
};


#endif