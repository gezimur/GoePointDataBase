#pragma once

#include <string>
#include <map>
#include <vector>

namespace geology
{

class DataBaseResponce
{
    using table_type = std::vector<std::map<std::string, std::string>>;

public:
    DataBaseResponce() = default;
    explicit DataBaseResponce(const std::string& strMsg);
    explicit DataBaseResponce(const std::string& strMsg, const table_type& vTable);

    void setMsg(const std::string&& strMsg);
    const std::string& getMsg() const noexcept;

    void setTable(const table_type& vTable);
    const table_type& getTable() const noexcept;

private:
    std::string m_strMsg;
    table_type m_vTable;
};

} // namespace geology
