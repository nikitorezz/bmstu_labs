#pragma once
#include "TCarnivora.h"
class TTigris : 
	public TCarnivora{

public:
	TTigris(const std::string & name) 
		:TCarnivora(name){
	}
	virtual int Live(float time) override {
		std::cout << GetName() << " ";
		if (((int)time % 24 < 4) && ((int)time % 24 > 20)) {
			std::cout << "is walking" << std::endl;
		}
		else if (((int)time % 12 >= 4) && ((int)time % 12 <= 8)) {
			std::cout << "is eating" << std::endl;
		}
		else {
			std::cout << "is sleeping" << std::endl;
		}
		GettingOlder(time);

		if (IsBreedingTime()) {
			if ((rand() % 5)==0 && an_qty[6] > 1) {
				return 2;
			}
		}
		if (GetAge() > 2) {
			return -1;
		}
		return 0;
	}


	virtual int GetClass() {
		return 6;
	}

	virtual bool IsBreedingTime() override {
		return GetAge() > 1;
	}

};
