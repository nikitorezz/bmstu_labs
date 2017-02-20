#include "TString.h";

TString::~TString() {
	delete[] Data;
}

TString::TString() {
	Data = new char[1];
	Data[0] = '\0';
}

TString::TString(const TString& rhs) {
	delete[] Data;
	int ssize = rhs.Size();
	Data = new char[ssize + 1];
	for (int i = 0; i <= ssize; i++) {
		Data[i] = rhs.Data[i];
	}
}

TString::TString(const char* data) {
	int size = 0;
	while (data[size] != '\0') {
		size++;
	}
	size++;
	Data = new char[size];
	for(int i = 0; i < size; i++) {
		Data[i] = data[i];
	}
}

TString& TString::operator=(const TString& rhs) {
	if (Data == rhs.Data) {
		return *this;
	}
	if (Data != nullptr) {
		delete[] Data;
	}
	int ssize = rhs.Size();
	Data = new char[ssize + 1];
	for (int i = 0; i <= ssize; i++) {
		Data[i] = rhs.Data[i];
	}
	return *this;
}

TString& TString::operator+=(const TString& rhs) {
	int ssize = Size() + rhs.Size();
	char* temp = new char[ssize + 1];
	int i = 0;
	for (; i < ssize - rhs.Size(); i++) {
		temp[i] = Data[i];
	}
	for (int j = 0; i < ssize + 1; i++, j++) {
		temp[i] = rhs.Data[j];
	}
	delete[] Data;
	Data = temp;
	return *this;
}

bool TString::operator==(const TString& rhs) const{
	if (Data[0] == '\0') {
		if (rhs.Data[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}
	int i = 0;
	while (Data[i]==rhs.Data[i]) {
		if (Data[i] == '\0') {
			return true;
		}
		i++;
	}
	return false;
}

bool TString::operator<(const TString& rhs)const {
	int i = 0;
	while (true) {
		if (rhs.Data[i] == '0') {
			return false;
		}
		else if (Data[i] == '0') {
			return true;
		}
		if (Data[i] < rhs.Data[i]) {
			return true;
		}
		else if(Data[i] > rhs.Data[i]) {
			return false;
		}
		i++;
	}
}

size_t TString::Find(const TString& rhs)const {
	if (rhs.Size() > Size()) {
		return -1;
	}
	int pos = 0, i = 0, j = 0;
	while (pos != Size()) {
		i = pos;
		j = 0;
		while (Data[i] == rhs.Data[j]) {
			if (j == rhs.Size()-1) {
				return pos;
			}
			i++;
			j++;
		}
		pos++;
	}
	return -1;
}

void TString::Replace(char oldSymbol, char newSymbol) {
	for (int i = 0; i < Size(); i++) {
		if (Data[i] == oldSymbol) {
			Data[i] = newSymbol;
		}
	}
}

size_t TString::Size() const {
	int size = 0;
	while (Data[size] != '\0') {
		size++;
	}
	return size;
}

bool TString::Empty()const {
	return Data[0] == '\0';
}

char TString::operator[](size_t index) const {
	return Data[index];
}

char& TString::operator[](size_t index) {
	return Data[index];
}

void TString::RTrim(char symbol) {
	int i = Size() - 1;
	int count = 0;
	while (Data[i] == symbol) {
		i--;
		count++;
	}
	int ssize = Size() - count + 1;
	char* temp = new char[ssize];
	for (int j = 0; j < ssize - 1; j++) {
		temp[j] = Data[j];
	}
	temp[ssize - 1] = '\0';
	delete[] Data;
	Data = temp;
}

void TString::LTrim(char symbol) {
	int i = 0;
	int count = 0;
	while (Data[i] == symbol) {
		i++;
		count++;
	}
	int ssize = Size() - count+1;
	char* temp = new char[ssize];
	for (int i = 0; i < ssize; i++) {
		temp[i] = Data[i+count];
	}
	delete[] Data;
	Data = temp;
}

std::ostream& operator<<(std::ostream& outer, const TString& rhs) {
	outer << rhs.Data;
	return outer;
}

TString operator+(const TString& a, const TString& b) {
	TString res = a;
	res += b;
	return res;
}

bool operator!=(const TString & a, const TString & b) {
	return !(a == b);
}

bool operator>(const TString & a, const TString & b) {
	return !(a < b || a == b);
}
