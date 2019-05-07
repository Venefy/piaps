#include "BusStation.h"
#include <vector>
#include <iostream>
int main()
{
	auto BS = new BusStation();
	auto BF = BusFactory();
	auto TF = TaxiFactory();
	BoardAnyCar* BBus = BS->createBoard(BF);
	BoardAnyCar* BTaxi = BS->createBoard(TF);
	std::cout<< BBus->isReady() << std::endl;
	std::cout << BTaxi->isReady() << std::endl;
	system("pause");
	delete BS;
	delete BBus;
	delete BTaxi;
	return 0;
}
