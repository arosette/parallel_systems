
#include <iostream>
#include <cassert>
#include <cmath>
#include "MatrixFileParser.h"

void test();
void showMatrix(std::vector<std::vector<float>*>* matrix);
void gaussJordan(std::vector<std::vector<float>*>* matrixA, std::vector<float>* vectorB);

int main(int argc, char** argv)
{
	test();
	
	MatrixFileParser parser1("matA.txt");
	parser1.parse();

	MatrixFileParser parser2("vecB.txt");
	parser2.parse();

	gaussJordan(parser1.getMatrix(), parser2.getMatrix()->at(0));


	return 0;
}

void test()
{
	std::string aString = "1 2 3 4";
	char delimiter = ' ';
	std::vector<std::string> result;
	std::vector<std::string> correct_result;

	correct_result.push_back("1");
	correct_result.push_back("2");
	correct_result.push_back("3");
	correct_result.push_back("4");

	result = MatrixFileParser::split(aString, delimiter);


	assert(result == correct_result);
}

void showMatrix(std::vector<std::vector<float>*>* matrix)
{
	for (int i = 0; i < matrix->size(); ++i)
	{
		for (int j = 0; j < matrix->at(0)->size(); ++j)
		{
			std::cout << matrix->at(i)->at(j) << " ";
		}
		std::cout << std::endl;
	}
}

void showMatrix(std::vector<float>* matrix)
{
	for (int i = 0; i < matrix->size(); ++i)
	{
		std::cout << matrix->at(i) << " ";
	}
	std::cout<<std::endl;
}

int indexOfMaxInColumn(std::vector<std::vector<float>*>* matrixA, int column)
{
	float maxi = 0;
	int max_line = -1;

	for (int i = 0; i < matrixA->size(); ++i)
	{
		if (abs(matrixA->at(i)->at(column)) > abs(maxi))
		{
			maxi = matrixA->at(i)->at(column);
			max_line = i;
		}
	}
	
	return max_line;
}


void gaussJordan(std::vector<std::vector<float>*>* matrixA, std::vector<float>* vectorB)
{
	int nb_lines = matrixA->size();
	int nb_columns = matrixA->at(0)->size();

	for (int current_col = 0; current_col < nb_columns; ++current_col)
	{
		int line_of_pivot = current_col;
		if (line_of_pivot == -1 || matrixA->at(line_of_pivot)->at(current_col) == 0)
		{
			std::cout << "erreur choix pivot" << std::endl;
		}

		// diviser la ligne du pivot par celui ci
		float pivot = matrixA->at(line_of_pivot)->at(current_col);
		std::cout << "pivot : " << pivot << std::endl;
		for (int j2 = 0; j2 < nb_columns; ++j2)
		{
			matrixA->at(line_of_pivot)->at(j2) = matrixA->at(line_of_pivot)->at(j2) / pivot;
		}
		vectorB->at(line_of_pivot) = vectorB->at(line_of_pivot) / pivot;

		
		
		for (int i = 0; i < nb_lines; ++i)
		{
			// pas la ligne du pivot
			if (i != line_of_pivot)
			{
				float coef = matrixA->at(i)->at(current_col);
				for (int j2 = 0; j2 < nb_columns; ++j2)
				{
					matrixA->at(i)->at(j2) = matrixA->at(i)->at(j2) - coef * matrixA->at(line_of_pivot)->at(j2);
				}
				vectorB->at(i) = vectorB->at(i) - coef * vectorB->at(line_of_pivot);

			}
			showMatrix(matrixA);
			showMatrix(vectorB);
			std::cout << std::endl;
			
		}
	}

	

}