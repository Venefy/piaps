#pragma once
#include <vector>
#include "Driver.h"

class BoardException{};
class NullException{};

class BoardAnyCar
{
protected:
	Driver *driver = nullptr;
	std::vector<Passenger*> passengers;
public:
	unsigned maxPassengers = 0;
	~BoardAnyCar()
	{
		if(driver)
			delete driver;
		for(auto p : passengers)
			delete p;
	}
	bool isReady()
	{
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		return true;
	}
	void BoardPassenger(Passenger* p) 
	{
		if (passengers.size() == maxPassengers)
			throw BoardException();
		else
			passengers.push_back(p);
	}
	void BoardDriver(Driver* d)
	{
		if (d)
			driver = d;
		else
			throw NullException();
	}
};

class BoardTaxi: public BoardAnyCar
{
public:
	BoardTaxi() 
	{ 
		maxPassengers = 3;
		std::cout << "BoardTaxi is created\n";
	}	
	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus() 
	{ 
		maxPassengers = 20;
		std::cout << "BoardBus is created\n";
	}
	~BoardBus() {};
};
