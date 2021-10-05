#pragma once

#include <memory>
#include <vector>
#include <map>

#include "ConnectionParams.h"
#include "DataBaseResponce.h"

namespace geology
{

struct IDataBaseCtrl
{
    enum enu_tables
    {
        e_customer = 0,
        e_order,
        e_user,
        e_tables_cnt
    };

    virtual ~IDataBaseCtrl() = default;

    virtual DataBaseResponce load(enu_tables eTable, int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType) = 0;

    virtual DataBaseResponce loadOrderGreedy(int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType) = 0;

    virtual DataBaseResponce loadById(enu_tables eTable, int iId) = 0;

    virtual DataBaseResponce write(enu_tables eTable, const std::map<std::string, std::string>& mArgs) = 0;
};

std::unique_ptr<IDataBaseCtrl> make_ctrl(const ConnectionParams& crParams);

} // namespace geology
