#include "Oblast.h"

#include "DataBase_staff.h"

namespace geology {

Oblast::Oblast(const std::map<std::string, std::string>& mVal)
    : IDataType(mVal)
{

}

const std::string& Oblast::getId() const
{
    return m_mValues.at("id");
}

std::string Oblast::getTableName()
{
    return "Oblast";
}

std::string Oblast::makeFilterString() const
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

    return " WHERE " + strRes;
}

std::vector<std::string> Oblast::getFullInfoNames()
{
    return {"id", "full_name"};
}

void Oblast::setFullInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(full_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(full_info::full_name)];
}

} // namespace geology
