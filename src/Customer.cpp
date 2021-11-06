#include "Customer.h"

#include "DataBase_staff.h"

namespace geology
{

Customer::Customer(const std::map<std::string, std::string>& mVal)
    : IDataType(mVal)
{

}

const std::string& Customer::getId() const
{
    return m_mValues.at("passport_number");
}

std::string Customer::getTableName()
{
    return "customer";
}

std::string Customer::makeFilterString() const
{
    if (m_mValues.empty())
        return "";

    std::string strRes;

    auto it = m_mValues.find("full_name");
    if (m_mValues.end() != it)
        strRes += make_lax_filter(*it);

    it = m_mValues.find("passport_number");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("passport_gived");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("passport_date");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("snils");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("phone");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("email");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    return " WHERE " + strRes;
}

std::vector<std::string> Customer::getFullInfoNames()
{
    return {"full_name", "passport_number", "passport_gived", "passport_date", "snils", "phone", "email"};
}

void Customer::setFullInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["full_name"] = vShortInfo[static_cast<int>(full_info::full_name)];
    m_mValues["passport_number"] = vShortInfo[static_cast<int>(full_info::passport_number)];
    m_mValues["passport_gived"] = vShortInfo[static_cast<int>(full_info::passport_gived)];
    m_mValues["passport_date"] = vShortInfo[static_cast<int>(full_info::passport_date)];
    m_mValues["snils"] = vShortInfo[static_cast<int>(full_info::snils)];
    m_mValues["phone"] = vShortInfo[static_cast<int>(full_info::phone)];
    m_mValues["email"] = vShortInfo[static_cast<int>(full_info::email)];
}

} // namespace geology
