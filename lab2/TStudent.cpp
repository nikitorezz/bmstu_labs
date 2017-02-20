#include "TStudent.h"



TStudent::TStudent()
{
	fio = "";
	for (int i = 0; i < 4; i++) {
		marks[i] = 0;
	}
}

TStudent::TStudent(std::string in_fio, int in_marks[])
{
	fio = in_fio;
	for (int i = 0; i < 4; i++) {
		marks[i] = in_marks[i];
	}
}

TStudent::~TStudent()
{
}

double TStudent::Average()
{
	return (marks[0] + marks[1] + marks[2] + marks[3])/4.0;
}

void TStudent::SetMarks(int in_marks[])
{
	for (int i = 0; i < 4; i++) {
		marks[i] = in_marks[i];
	}
}

void TStudent::SetName(std::string in_fio)
{
	fio = in_fio;
}

std::ostream& operator<<(std::ostream &out, const TStudent &std)
{
	out << std.fio << " grades: " << std.marks[0] << ", " << std.marks[1] << ", " << std.marks[2] << ", " << std.marks[3] << "." << std::endl;
	return out;
}
