#include "Customer.h"

namespace geology
{

Customer::Customer(const std::map<std::string, std::string>& mVal)
    : m_mValues(mVal)
{

}

const std::string& Customer::getId() const
{
    return m_mValues.at("id");
}

std::string Customer::getTableName()
{
    return "Customer";
}

std::vector<std::string> Customer::getShortInfoNames()
{
    return {"id", "full_name", "phone", "email"};
}

void Customer::setShortInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(short_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(short_info::full_name)];
    m_mValues["phone"] = vShortInfo[static_cast<int>(short_info::phone)];
    m_mValues["email"] = vShortInfo[static_cast<int>(short_info::email)];
}

std::vector<std::string> Customer::getFullInfoNames()
{
    return {"id", "full_name", "passport_number", "passport_gived", "passport_date", "snils", "phone", "email"};
}

void Customer::setFullInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(full_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(full_info::full_name)];
    m_mValues["passport_number"] = vShortInfo[static_cast<int>(full_info::passport_number)];
    m_mValues["passport_gived"] = vShortInfo[static_cast<int>(full_info::passport_gived)];
    m_mValues["passport_date"] = vShortInfo[static_cast<int>(full_info::passport_date)];
    m_mValues["snils"] = vShortInfo[static_cast<int>(full_info::snils)];
    m_mValues["phone"] = vShortInfo[static_cast<int>(full_info::phone)];
    m_mValues["email"] = vShortInfo[static_cast<int>(full_info::email)];
}

const std::map<std::string, std::string>& Customer::getValuesMap() const noexcept
{
    return m_mValues;
}


} // namespace geology
