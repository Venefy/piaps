#pragma once
#include <iostream>

class Passenger
{
public:
	Passenger() { std::cout << "Passenger is created\n"; };
	//Passenger &operator=(Passenger&) {};
};

enum Licenze { BCategory, DCategory };

class Driver
{
public:
	Licenze licenze;
	Driver() {};
};

class TaxiDriver : public Driver
{
public:
	TaxiDriver()
	{
		std::cout << "TaxiDriver is created\n";
		licenze = BCategory;
	}
};
class BusDriver : public Driver
{
public:
	BusDriver()
	{
		std::cout << "BusDriver is created\n";
		licenze = DCategory;
	}
};