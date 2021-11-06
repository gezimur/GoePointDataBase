#pragma once

#include "IDataType.h"

namespace geology
{

class Customer: public IDataType
{
public:

    enum class short_info
    {
        full_name = 0,
        phone,
        email,
        info_cnt
    };

    enum class full_info
    {
        full_name = 0,
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

    std::string makeFilterString() const final;

    static std::vector<std::string> getFullInfoNames();
    void setFullInfo(const std::vector<std::string>& vFullInfo) final;
};

} // namespace geology
