#include <iostream>

#include <windows.h>

#include "include/IDataBaseCtrl.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    try
    {
        auto upCtrl = geology::make_ctrl(geology::ConnectionParams{});

        auto Res = upCtrl->load(geology::IDataBaseCtrl::e_user, 1, {{"username", "zgm_manger"}, {"password", "123"}}, "");

        Res = upCtrl->load(geology::IDataBaseCtrl::e_order, 10, {}, "");

        Res = upCtrl->load(geology::IDataBaseCtrl::e_customer, 10, {}, "");

        return 0;
    }
    catch (std::runtime_error& rExc)
    {
        std::cout << rExc.what() << std::endl;

        return 1;
    }

}
