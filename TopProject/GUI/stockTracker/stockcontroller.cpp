#include "stockcontroller.h"

#include "mastercontroller.h"

StockController::StockController(MasterController * _masterPtr, QWidget *parent) : QWidget(parent)
{
    masterPtr = _masterPtr;
}

StockController::~StockController()
{

}
