#include "Raion.h"

#include "DataBase_staff.h"

namespace geology {

Raion::Raion(const std::map<std::string, std::string>& mVal)
    : IDataType(mVal)
{

}

const std::string& Raion::getId() const
{
    return m_mValues.at("id");
}

std::string Raion::getTableName()
{
    return "Raion";
}

std::string Raion::makeFilterString() const
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

    it = m_mValues.find("oblast");
    if (m_mValues.end() != it)
        strRes += (strRes.empty()? "" : " and ") + make_strict_filter(*it);

    return " WHERE " + strRes;
}

std::vector<std::string> Raion::getFullInfoNames()
{
    return {"id", "full_name", "type", "oblast"};
}

void Raion::setFullInfo(const std::vector<std::string>& vShortInfo)
{
    m_mValues["id"] = vShortInfo[static_cast<int>(full_info::id)];
    m_mValues["full_name"] = vShortInfo[static_cast<int>(full_info::full_name)];
    m_mValues["type"] = vShortInfo[static_cast<int>(full_info::type)];
    m_mValues["oblast"] = vShortInfo[static_cast<int>(full_info::oblast)];
}

} // namespace geology
