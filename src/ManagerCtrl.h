#pragma once

#include "DataBaseCtrl.h"

namespace geology
{

class ManagerCtrl
{
public:
    ManagerCtrl(const PGConnection& crConnection);

    std::vector<Order> loadOrderList(int iCnt, const Order& crFilter, const std::string& strSortType);
    Order loadOrder(int iId);
    std::string addOrder(const Order& crOrder);
    std::string editOrder(const Order& crOrder);

    std::vector<Customer> loadCustomerList(int iCnt, const Customer& crFilter, const std::string& strSortType);
    Customer loadCustomer(int iId);
    std::string addCustomer(const Customer& crCustomer);
    std::string editCustomer(const Customer& crCustomer);

private:
    DataBaseCtrl m_DataBaseCtrl;
};

} // namespace geology
