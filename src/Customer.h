#pragma once

#include "IDataType.h"

namespace geology
{

class Customer: public IDataType
{
public:

    enum class short_info
    {
        id = 0,
        full_name,
        phone,
        email,
        info_cnt
    };

    enum class full_info
    {
        id = 0,
        full_name,
        passport_number,
        passport_gived, // rename gave
        passport_date,
        snils,
        phone,
        email,
        info_cnt
    };

    Customer() = default;

    explicit Customer(const std::map<std::string, std::string>& mVal);

    const std::string& getId() const final;

    static std::string getTableName();

    static std::vector<std::string> getShortInfoNames();
    void setShortInfo(const std::vector<std::string>& vShortInfo) final;

    static std::vector<std::string> getFullInfoNames();
    void setFullInfo(const std::vector<std::string>& vFullInfo) final;

    const std::map<std::string, std::string>& getValuesMap() const noexcept final;

private:
    std::map<std::string, std::string> m_mValues;
};

} // namespace geology
