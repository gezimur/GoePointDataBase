#pragma once

#include <vector>
#include <map>
#include <string>

namespace geology
{

struct IDataType
{
    IDataType() = default;

    explicit IDataType(const std::map<std::string, std::string>& mVal)
        : m_mValues(mVal)
    {

    }

    virtual ~IDataType() = default;

    virtual const std::string& getId() const = 0;

    static std::string getTableName();

    virtual std::string makeFilterString() const = 0;

    static std::vector<std::string> getFullInfoNames();
    virtual void setFullInfo(const std::vector<std::string>& vFullInfo) = 0;

    const std::map<std::string, std::string>& getValuesMap() const noexcept
    {
        return m_mValues;
    }

protected:
    std::map<std::string, std::string> m_mValues;
};

} // namespace geology
