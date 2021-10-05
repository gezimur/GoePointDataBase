#include "User.h"

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

std::vector<std::string> User::getShortInfoNames()
{
    return {"id", "full_name", "role"};
}

void User::setShortInfo(const std::vector<std::string>& vShortInfo)
{

    m_mValues["id"] = vShortInfo[static_cast<int>(short_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(short_info::full_name)];
    m_mValues["role"] = vShortInfo[static_cast<int>(short_info::role)];
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
