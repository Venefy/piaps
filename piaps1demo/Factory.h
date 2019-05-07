#pragma once
#include <iostream>
#pragma once
#include "Driver.h"
#include "Board.h"
#include <iostream>

class AbstractFactory
{
public:
	virtual Driver* createDriver() = 0;
	Passenger* createPassenger() { return new Passenger(); }
	virtual ~AbstractFactory() {}
	virtual BoardAnyCar* createBoard() = 0;
};

class BusFactory: public AbstractFactory
{
public:
	BusDriver* createDriver() override
	{
		return new BusDriver();
	}
	BoardBus* createBoard() override
	{
		return new BoardBus();
	}
};

class TaxiFactory : public AbstractFactory
{
public:
	TaxiDriver* createDriver() override
	{
		return new TaxiDriver();
	}
	BoardTaxi* createBoard() override
	{
		return new BoardTaxi();
	}

};