#include "Order.h"

#include "DataBase_staff.h"

namespace geology
{

Order::Order(const std::map<std::string, std::string>& mVal)
    : IDataType(mVal)
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

std::string Order::makeFilterString() const
{
    if (m_mValues.empty())
        return "";

    std::string strRes;

    auto it = m_mValues.find("id");
    if (m_mValues.end() != it)
        strRes += make_strict_filter(*it);

    it = m_mValues.find("work_class");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("work_type");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("order_date");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("deadline");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("place");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("space");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("status");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("email");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

//    it = m_mValues.find("executor");
//    if (m_mValues.end() != it)
//        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

//    it = m_mValues.find("customer");
//    if (m_mValues.end() != it)
//        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    return " WHERE " + strRes;
}

std::vector<std::string> Order::getFullInfoNames()
{
    return {"id", "work_type", "work_class", "order_date", "deadline", "place", "space", "status", "ingeneer", "fielder", "customer"};
}

void Order::setFullInfo(const std::vector<std::string>& vFullInfo)
{
    m_mValues["id"] = vFullInfo[static_cast<int>(full_info::id)];
    m_mValues["work_class"] = vFullInfo[static_cast<int>(full_info::work_class)];
    m_mValues["work_type"] = vFullInfo[static_cast<int>(full_info::work_type)];
    m_mValues["order_date"] = vFullInfo[static_cast<int>(full_info::order_date)];
    m_mValues["deadline"] = vFullInfo[static_cast<int>(full_info::deadline)];
    m_mValues["place"] = vFullInfo[static_cast<int>(full_info::place)];
    m_mValues["space"] = vFullInfo[static_cast<int>(full_info::space)];
    m_mValues["status"] = vFullInfo[static_cast<int>(full_info::status)];
    m_mValues["ingeneer"] = vFullInfo[static_cast<int>(full_info::ingeneer)];
    m_mValues["fielder"] = vFullInfo[static_cast<int>(full_info::fielder)];
    m_mValues["customer"] = vFullInfo[static_cast<int>(full_info::customer)];
}

} // namespace geology
