#include <iostream>

#include <windows.h>

#include "include/IDataBaseCtrl.h"

void print_res(const geology::DataBaseResponce& crRes)
{
    std::cout << "message: " << crRes.getMsg() << std::endl;
    std::cout << "table: " << std::endl;
    for (const auto& Row : crRes.getTable())
    {
        for (const auto& prCell : Row)
        {
            std::cout << prCell.first << ": " << prCell.second << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "Hello World!" << std::endl;

    try
    {
        auto upCtrl = geology::make_ctrl(geology::ConnectionParams{});

        auto Res = upCtrl->load(geology::IDataBaseCtrl::e_user, 1, {{"username", "zgm_manager"}, {"password", "123"}}, "");

        print_res(Res);

        Res = upCtrl->loadOrderGreedy(10, {{"orders.id", "9"}}, "id");

        print_res(Res);

        Res = upCtrl->write(geology::IDataBaseCtrl::e_customer, {{"full_name", "gena ziganshin"}, {"passport_number", "123456 1234"}, {"passport_gived", "by man"}, {"passport_date", "11-05-2015"}});

        print_res(Res);

        Res = upCtrl->write(geology::IDataBaseCtrl::e_order, {{"work_type", "simple work"}, {"place", "forest"}, {"customer", "123456 1234"}});

        print_res(Res);

        Res = upCtrl->load(geology::IDataBaseCtrl::e_order, 10, {{"work_type", "simple work"}}, "");

        print_res(Res);

        return 0;
    }
    catch (std::runtime_error& rExc)
    {
        std::cout << rExc.what() << std::endl;

        return 1;
    }

}
