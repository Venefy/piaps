#pragma once
#include "Factory.h"
class BusStation
{
public:
	BoardAnyCar* createBoard(AbstractFactory& factory)
	{
		BoardAnyCar * Board = factory.createBoard();
		Board->BoardDriver(factory.createDriver());
		for (size_t i = 0; i < Board->maxPassengers; i++)
			Board->BoardPassenger(factory.createPassenger());
		return Board;
	}
};