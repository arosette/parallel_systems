#include "MatrixFileParser.h"

MatrixFileParser::MatrixFileParser(std::string path) :
_file(), _matrix(new std::vector< std::vector<float>* >)
{
	_file.open(path, std::ios::in);
}

MatrixFileParser::~MatrixFileParser()
{
	_file.close();
}

std::vector<std::string> MatrixFileParser::split(std::string aString, char delemiter)
{
	std::vector<std::string> result;
	std::string temp;
	for (int i = 0; i < aString.length(); ++i)
	{
		if (aString[i] == delemiter)
		{
			if (temp.length() > 0)
			{
				result.push_back(temp);
				temp = "";
			}
			
		}
		else
		{
			temp.push_back(aString[i]);
		}
	}

	if (temp.length() > 0)
	{
		result.push_back(temp);
		temp = "";
	}
	return result;
}

void MatrixFileParser::parse()
{
	std::string line;
	std::vector<float> *splitted_line;
	while (std::getline(_file, line))
	{

		if (line != "")
		{
			splitted_line = new std::vector < float > ;
			std::vector<std::string> temp = split(line, ' ');
			for (int i = 0; i < temp.size(); ++i)
			{
				float number = (float) std::atof(temp[i].c_str());
				splitted_line->push_back(number);
			}
			_matrix->push_back(splitted_line);
		}
		
	}
}


std::vector< std::vector<float>* > * MatrixFileParser::getMatrix()
{
	return _matrix;
}