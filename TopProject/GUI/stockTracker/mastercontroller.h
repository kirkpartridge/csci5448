#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include "logincontroller.h"
#include "stockcontroller.h"
#include "./StockModel.h"

/** Master controller. Controls the sub controllers
 * */
class MasterController : public QWidget
{
public:
    ///Constructor
    MasterController(QWidget *parent = 0);
    ///Deconstructor
    ~MasterController();
    ///Checks if the login is complete
    void loginComplete();


private:
    ///Private sub controllers
    LoginController * loginController;
    StockController * stockController;
    ///Internal model
    StockModel * stockModel;
};

#endif // MASTERCONTROLLER_H
