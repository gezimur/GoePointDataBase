#pragma once

#include "IDataType.h"

namespace geology
{

class Oblast: public IDataType
{
public:


    enum class full_info
    {
        id = 0,
        full_name
    };

    Oblast() = default;

    explicit Oblast(const std::map<std::string, std::string>& mVal);

    const std::string& getId() const final;

    static std::string getTableName();

    std::string makeFilterString() const final;

    static std::vector<std::string> getFullInfoNames();
    void setFullInfo(const std::vector<std::string>& vFullInfo) final;

};

} // namespace geology
