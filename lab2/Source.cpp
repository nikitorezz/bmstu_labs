#include "TStudent.h";


int main() {
	int num = 0;
	std::cout << "type in amount of students" << std::endl;
	std::cin >> num;
	TStudent *arr = new TStudent[num];
	for (int i = 0; i < num; i++) {
		std::string fio = "";
		std::cout << "type in name" << std::endl;
		getline(std::cin,fio);
		arr[i].SetName(fio);
		int marks[4] = {rand()%6,rand() % 6,rand() % 6,rand() % 6};
		arr[i].SetMarks(marks);
		std::cout << arr[i];
	}
	std::cout << "3 best students: ";
	if (num <= 3) {
		for (int i = 0; i < num; i++) {
			std::cout << arr[i];
		}
	}
	else {
		int mas[3] = { -1,-1,-1 };
		for (int j = 0; j < 3; j++) {
			int max = 0;
			for (int i = 0; i < num; i++) {
				if ((mas[0] != i) && (mas[1] != i) && (mas[2] != i)) {
					if (arr[i].Average() > max) {
						max = arr[i].Average();
						mas[j] = i;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			std::cout << arr[mas[i]] << " (average = " << arr[mas[i]].Average() << ")" << std::endl;
		}
	}
  delete[] arr;
}
