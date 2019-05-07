#include "Board.h"
#include "Driver.h"

class BoardBuilder
{
protected:
	BoardAnyCar* p;
public:
	BoardBuilder(): p(nullptr) {}
	virtual void createBoard() = 0;
	virtual void buildAdult() = 0;
	virtual void buildBeneficiary() = 0;
	virtual void buildChild() = 0;
	virtual void buildDriver() = 0;
	BoardAnyCar* getBoard() { return p; }
};

class BoardTaxiBuilder : public BoardBuilder
{
public:
	void createBoard() { p = new BoardTaxi; }
	void buildDriver() { p->BoardDriver(); }
	void buildAdult() { p->BoardPassenger(new Adult()); }
	void buildChild() { p->BoardPassenger(new Child()); p->childSafetySeat++; }
	void buildBeneficiary() {};
};

class BoardBusBuilder : public BoardBuilder
{
public:
	void createBoard() { p = new BoardBus; }
	void buildDriver() { p->BoardDriver(); }
	void buildAdult() { p->BoardPassenger(new Adult()); }
	void buildChild() { p->BoardPassenger(new Child()); }
	void buildBeneficiary() { p->BoardPassenger(new Beneficiary);	}
};

class Director
{
public:
	BoardAnyCar* createBoard(BoardBuilder& builder, size_t AdultNum=1, size_t ChildNum=1, size_t BeneficiaryNum=0)
	{
		builder.createBoard();
		builder.buildDriver();
		for (size_t i = 0; i < AdultNum; i++)
			builder.buildAdult();
		for (size_t i = 0; i < ChildNum; i++)
			builder.buildChild();
		for (size_t i = 0; i < BeneficiaryNum; i++)
			builder.buildBeneficiary();
		return builder.getBoard();
	}
};