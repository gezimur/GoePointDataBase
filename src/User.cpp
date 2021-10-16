#include "User.h"

#include "DataBase_staff.h"

namespace geology
{

User::User(const std::map<std::string, std::string>& mVal)
    : m_mValues(mVal)
{

}

const std::string& User::getId() const
{
    return m_mValues.at("id");
}

std::string User::getTableName()
{
    return "users";
}

std::string User::makeFilterString() const
{
    if (m_mValues.empty())
        return "";

    std::string strRes;

    auto it = m_mValues.find("id");
    if (m_mValues.end() != it)
        strRes += make_strict_filter(*it);

    it = m_mValues.find("full_name");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_lax_filter(*it);

    it = m_mValues.find("role");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("username");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("password");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    return " WHERE " + strRes;
}

std::vector<std::string> User::getFullInfoNames()
{
    return {"id", "full_name", "role", "username", "password"};
}

void User::setFullInfo(const std::vector<std::string>& vFullInfo)
{
    m_mValues["id"] = vFullInfo[static_cast<int>(full_info::id)];
    m_mValues["full_name"] = vFullInfo[static_cast<int>(full_info::full_name)];
    m_mValues["role"] = vFullInfo[static_cast<int>(full_info::role)];
    m_mValues["username"] = vFullInfo[static_cast<int>(full_info::username)];
    m_mValues["password"] = vFullInfo[static_cast<int>(full_info::password)];
}

const std::map<std::string, std::string>& User::getValuesMap() const noexcept
{
    return m_mValues;
}


} // namespace geology
