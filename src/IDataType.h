#pragma once

#include <vector>
#include <map>
#include <string>

namespace geology
{

struct IDataType
{
    virtual ~IDataType() = default;

    virtual const std::string& getId() const = 0;

    static std::string getTableName();

    static std::vector<std::string> getShortInfoNames();
    virtual void setShortInfo(const std::vector<std::string>& vShortInfo) = 0;

    static std::vector<std::string> getFullInfoNames();
    virtual void setFullInfo(const std::vector<std::string>& vFullInfo) = 0;

    virtual const std::map<std::string, std::string>& getValuesMap() const noexcept = 0;
};

} // namespace geology
