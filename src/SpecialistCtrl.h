#pragma once

#include "DataBaseCtrl.h"

namespace geology
{

class SpecialistCtrl
{
public:
    SpecialistCtrl(const PGConnection& crConnection);

    std::vector<Order> loadOrderList(int iCnt, const Order& crFilter, const std::string& strSortType);
    Order loadOrder(int iId);

    std::string acceptOrder(const Order& crOrder);
    std::string rejectOrder(const Order& crOrder);
    std::string closeOrder(const Order& crOrder);

private:
    DataBaseCtrl m_DataBaseCtrl;
};

} // namespace geology
