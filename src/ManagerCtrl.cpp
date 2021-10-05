#include "ManagerCtrl.h"

namespace geology
{

ManagerCtrl::ManagerCtrl(const PGConnection& crConnection)
    : m_DataBaseCtrl(crConnection)
{

}

std::vector<Order> ManagerCtrl::loadOrderList(int iCnt, const Order& crFilter, const std::string& strSortType)
{
    return m_DataBaseCtrl.load<Order>(iCnt, crFilter, strSortType);
}

Order ManagerCtrl::loadOrder(int iId)
{
    return m_DataBaseCtrl.loadById<Order>(iId);
}

std::string ManagerCtrl::addOrder(const Order& crOrder)
{
    return m_DataBaseCtrl.add<Order>(crOrder);
}

std::string ManagerCtrl::editOrder(const Order& crOrder)
{
    return m_DataBaseCtrl.edit<Order>(crOrder);
}

std::vector<Customer> ManagerCtrl::loadCustomerList(int iCnt, const Customer& crFilter, const std::string& strSortType)
{
    return m_DataBaseCtrl.load<Customer>(iCnt, crFilter, strSortType);
}

Customer ManagerCtrl::loadCustomer(int iId)
{
    return m_DataBaseCtrl.loadById<Customer>(iId);
}

std::string ManagerCtrl::addCustomer(const Customer& crCustomer)
{
    return m_DataBaseCtrl.add<Customer>(crCustomer);
}

std::string ManagerCtrl::editCustomer(const Customer& crCustomer)
{
    return m_DataBaseCtrl.edit<Customer>(crCustomer);
}

} // namespace geology
