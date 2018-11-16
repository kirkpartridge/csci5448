#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include "logincontroller.h"
#include "stockcontroller.h"

class MasterController : public QWidget
{
public:
    MasterController(QWidget *parent = 0);
    ~MasterController();
    void loginComplete();


private:
    LoginController * loginController;
    StockController * stockController;
};

#endif // MASTERCONTROLLER_H
