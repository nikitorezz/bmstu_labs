#pragma once
#include "TCarnivora.h"
class TLeo : // dodelat
	public TCarnivora{

public:
	TLeo(const std::string &name)
		:TCarnivora(name){
	}
	virtual int Live(float time) override {
		std::cout << GetName() << " ";
		if (((int)time % 24 < 7) && ((int)time % 24 > 23)) {
			std::cout << "is walking" << std::endl;
		}
		else if (((int)time % 12 >= 8) && ((int)time % 12 <= 11)) {
			std::cout << "is eating" << std::endl;
		}
		else {
			std::cout << "is sleeping" << std::endl;
		}
		GettingOlder(time);

		if (IsBreedingTime()) {
			if (((rand() % 5) == 0) && (an_qty[4] > 1)) {
				return 4;
			}
		}
		if (GetAge() > 2) {
			return -1;
		}
		return 0;
	}


	virtual int GetClass() {
		return 4;
	}

	virtual bool IsBreedingTime() override {
		return GetAge() > 1;
	}

};
