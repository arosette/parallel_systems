#ifndef MATRIX_FILE_PARSER
#define MATRIX_FILE_PARSER

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class MatrixFileParser
{
public:
	MatrixFileParser(std::string path);
	~MatrixFileParser();
	static std::vector<std::string> split(std::string aString, char delemiter);
	void parse();
	std::vector< std::vector<float>* > * getMatrix();
private:
	std::fstream _file;
	std::vector< std::vector<float>* > *_matrix;
};

#endif