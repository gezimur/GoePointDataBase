#include "Poselenie.h"

#include "DataBase_staff.h"

namespace geology {

Poselenie::Poselenie(const std::map<std::string, std::string>& mVal)
    : IDataType(mVal)
{

}

const std::string& Poselenie::getId() const
{
    return m_mValues.at("id");
}

std::string Poselenie::getTableName()
{
    return "Poselenie";
}

std::string Poselenie::makeFilterString() const
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

    it = m_mValues.find("type");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    it = m_mValues.find("raion");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    return " WHERE " + strRes;
}

std::vector<std::string> Poselenie::getFullInfoNames()
{
    return {"id", "full_name", "type", "raion"};
}

void Poselenie::setFullInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(full_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(full_info::full_name)];
    m_mValues["type"] = vShortInfo[static_cast<int>(full_info::type)];
    m_mValues["raion"] = vShortInfo[static_cast<int>(full_info::raion)];
}

} // namespace geology
