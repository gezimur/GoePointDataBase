#include "Order.h"

namespace geology
{

Order::Order(const std::map<std::string, std::string>& mVal)
    : m_mValues(mVal)
{

}

const std::string& Order::getId() const
{
    return m_mValues.at("id");
}

std::string Order::getTableName()
{
    return "orders";
}

std::vector<std::string> Order::getShortInfoNames()
{
    return {"id", "work_type", "order_date", "place"};
}

void Order::setShortInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(short_info::id)];
    m_mValues["work_type"] = vShortInfo[static_cast<int>(short_info::work_type)];
    m_mValues["order_date"] = vShortInfo[static_cast<int>(short_info::order_date)];
    m_mValues["place"] = vShortInfo[static_cast<int>(short_info::place)];
}

std::vector<std::string> Order::getFullInfoNames()
{
    return {"id", "work_type", "order_date", "deadline", "place", "status", "executor", "customer"};
}

void Order::setFullInfo(const std::vector<std::string>& vFullInfo)
{
    m_mValues["id"] = vFullInfo[static_cast<int>(full_info::id)];
    m_mValues["work_type"] = vFullInfo[static_cast<int>(full_info::work_type)];
    m_mValues["order_date"] = vFullInfo[static_cast<int>(full_info::order_date)];
    m_mValues["deadline"] = vFullInfo[static_cast<int>(full_info::deadline)];
    m_mValues["place"] = vFullInfo[static_cast<int>(full_info::place)];
    m_mValues["status"] = vFullInfo[static_cast<int>(full_info::status)];
    m_mValues["executor"] = vFullInfo[static_cast<int>(full_info::executor)];
    m_mValues["customer"] = vFullInfo[static_cast<int>(full_info::customer)];
}

const std::map<std::string, std::string>& Order::getValuesMap() const noexcept
{
    return m_mValues;
}

} // namespace geology
