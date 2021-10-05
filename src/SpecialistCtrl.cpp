#include "SpecialistCtrl.h"

namespace geology
{

SpecialistCtrl::SpecialistCtrl(const PGConnection& crConnection)
    : m_DataBaseCtrl(crConnection)
{

}

std::vector<Order> SpecialistCtrl::loadOrderList(int iCnt, const Order& crFilter, const std::string& strSortType)
{
    return m_DataBaseCtrl.load<Order>(iCnt, crFilter, strSortType);
}

Order SpecialistCtrl::loadOrder(int iId)
{
    return m_DataBaseCtrl.loadById<Order>(iId);
}

std::string SpecialistCtrl::acceptOrder(const Order& crOrder)
{
    return m_DataBaseCtrl.edit(crOrder);
}

std::string SpecialistCtrl::rejectOrder(const Order& crOrder)
{
    return m_DataBaseCtrl.edit(crOrder);
}

std::string SpecialistCtrl::closeOrder(const Order& crOrder)
{
    return m_DataBaseCtrl.edit(crOrder);
}

} // namespace geology
