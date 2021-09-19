#include <iostream>

#include "PGConnectionCtrl.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    try
    {
        geology::PGConnectionCtrl ConnCtrl(3);

        auto spCon = ConnCtrl.connection();

        ConnCtrl.freeConnection(spCon);

        return 0;
    }
    catch (std::runtime_error& rExc)
    {
        std::cout << rExc.what() << std::endl;

        return 1;
    }

}
