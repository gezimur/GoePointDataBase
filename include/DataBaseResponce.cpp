#include "DataBaseResponce.h"

namespace geology
{

DataBaseResponce::DataBaseResponce(const std::string& strMsg)
    : m_strMsg(strMsg)
{

}

DataBaseResponce::DataBaseResponce(const std::string& strMsg, const table_type& vTable)
    : m_strMsg(strMsg),
      m_vTable(vTable)
{

}

void DataBaseResponce::setMsg(const std::string&& strMsg)
{
    m_strMsg = strMsg;
}

const std::string& DataBaseResponce::getMsg() const noexcept
{
    return m_strMsg;
}

void DataBaseResponce::setTable(const table_type& vTable)
{
    m_vTable = vTable;
}

const DataBaseResponce::table_type& DataBaseResponce::getTable() const noexcept
{
    return m_vTable;
}

} // namespace geology
