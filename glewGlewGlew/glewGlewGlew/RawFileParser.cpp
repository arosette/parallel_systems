#include "RawFileParser.h"

RawFileParser::RawFileParser(std::string image_path, int width, int height, int depth) :
_image_file(), _width(width), _height(height), _depth(depth), _current_plan(0)
{
	_image_file.open(image_path, std::ios::in | std::ios::binary);
	_image_file.seekg(0);
}

RawFileParser::~RawFileParser()
{
	_image_file.close();
}

std::vector< std::vector<char>* >* RawFileParser::getNextPlan()
{
	if (_current_plan >= _depth)
	{
		// Lancer une exception
	}
	std::vector< std::vector<char>* >* result = new std::vector< std::vector<char>* >;
	for (int i = 0; i < _width; ++i)
	{
		std::vector<char> *line = new std::vector<char>;
		for (int j = 0; j < _height; ++j)
		{
			char vertex;
			_image_file.get(vertex);
			std::cout << (int)vertex << std::endl;
			line->push_back(vertex);
		}
		result->push_back(line);
		
	}
	return result;
}

std::vector< std::vector<float>* >* RawFileParser::getNextPlanOpenglFormatted()
{
	std::vector< std::vector<float>* >* result = new std::vector< std::vector<float>* >;
	// le 1er vecteur contient les coordonnées, le second les couleurs
	result->push_back(new std::vector<float>);
	result->push_back(new std::vector<float>);
	std::vector< std::vector<char>* >* temp = getNextPlan();
	for (int i = 0; i < _width; ++i)
	{
		for (int j = 0; j < _height; ++j)
		{
			char value = temp->at(i)->at(j);
			
			if (value > 0)
			{
				result->at(0)->push_back((i - ((_width-1) / 2.0)) / ((_width-1)/2.0));
				result->at(0)->push_back((j - ((_height-1) / 2.0)) / ((_height-1)/2.0));

				result->at(1)->push_back(1.0);
				result->at(1)->push_back(0.0);
				result->at(1)->push_back(0.0);
			}
			
		}
	}

	return result;
}

int RawFileParser::getWidth()
{
	return _width;
}

int RawFileParser::getHeight()
{
	return _height;
}