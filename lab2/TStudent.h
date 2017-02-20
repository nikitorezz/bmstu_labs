#pragma once
#include <iostream>;
#include <string>;


class TStudent
{
	std::string fio;
	int marks[4];

public:
	TStudent();

	TStudent(std::string fio, int marks[]);

	~TStudent();
	
	double Average();

	void SetMarks(int marks[]);

	void SetName(std::string fio);

	friend std::ostream& operator<<(std::ostream &, const TStudent &);

};

std::ostream& operator<<(std::ostream &out, const TStudent &stud);
