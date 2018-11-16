#ifndef STOCKCONTROLLER_H
#define STOCKCONTROLLER_H

#include <QWidget>

class MasterController;
class StockController : public QWidget
{
    Q_OBJECT
public:
    explicit StockController(MasterController * _masterPtr, QWidget *parent = nullptr);
    ~StockController();

private:
    MasterController * masterPtr;
};

#endif // STOCKCONTROLLER_H
