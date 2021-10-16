#pragma once

#include <iostream>

#include <vector>

#include "Order.h"
#include "Customer.h"
#include "User.h"
#include "PGConnection.h"
#include "IDataBaseCtrl.h"

namespace geology
{

std::string make_select(const std::vector<std::string>& vNames, const std::string& strTableName);

std::string make_inner_join();

std::string make_filter(const std::map<std::string, std::string>& mFilter);

std::string make_sort(const std::string& strSortType);

std::string make_limit(int iCnt);

std::string make_insert(const std::map<std::string, std::string>& mValues, const std::string& strTableName);

std::string make_update(const std::map<std::string, std::string>& mValues);

class DataBaseCtrl: public IDataBaseCtrl
{

public:   
    DataBaseCtrl(const PGConnection& crConnection);

    DataBaseResponce load(enu_tables eTable, int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType) final;

    DataBaseResponce loadOrderGreedy(int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType) final;

    DataBaseResponce loadById(enu_tables eTable, int iId) final;

    DataBaseResponce write(enu_tables eTable, const std::map<std::string, std::string>& mArgs) final;

private:
    template<typename t_Table>
    DataBaseResponce load(int iCnt, const t_Table& crFilter, const std::string& strSortType)
    {
        auto strRequest = make_select(t_Table::getFullInfoNames(), t_Table::getTableName());
        strRequest += crFilter.makeFilterString();
        strRequest += make_sort(strSortType);
        strRequest += make_limit(iCnt);
        strRequest += ";";

        auto pRes = PQexec(m_Connection.get(), strRequest.c_str());

        std::vector<std::map<std::string, std::string>> vRes;
        auto iRows = PQntuples(pRes);        
        auto iCols = PQnfields(pRes);
        for (int iRow = 0; iRow < iRows; ++iRow)
        {
            std::map<std::string, std::string> mSelected;
            for (int iCol = 0; iCol < iCols; ++iCol)
                mSelected[PQfname(pRes, iCol)] = PQgetvalue(pRes, iRow, iCol);

            vRes.push_back(mSelected);
        }

        if (vRes.empty())
            return DataBaseResponce{PQerrorMessage(m_Connection.get())};

        return DataBaseResponce{"", vRes};
    }

    template<typename t_Table>
    DataBaseResponce loadById(int iId)
    {
        std::string strRequest = make_select(t_Table::getFullInfoNames(), t_Table::getTableName());
        strRequest += make_filter({{"id", std::to_string(iId)}});
        strRequest += make_limit(1);
        strRequest += ";";

        auto pRes = PQexec(m_Connection.get(), strRequest.c_str());

        auto iRows = PQntuples(pRes);
        if (iRows != 1)
            return DataBaseResponce{PQerrorMessage(m_Connection.get())};

        auto iCols = PQnfields(pRes);
        std::map<std::string, std::string> mSelected;
        for (int iCol = 0; iCol < iCols; ++iCol)
            mSelected[PQfname(pRes, iCol)] = PQgetvalue(pRes, 0, iCol);

        return DataBaseResponce{"", {mSelected}};
    }

    template<typename t_Table>
    DataBaseResponce write(const t_Table& crValue)
    {
        std::string strRequest = make_insert(crValue.getValuesMap(), t_Table::getTableName());
        strRequest += ";";

        auto pRes = PQexec(m_Connection.get(), strRequest.c_str());

        if (PQresultStatus(pRes) != PGRES_COMMAND_OK)
            return DataBaseResponce{PQerrorMessage(m_Connection.get())};

        return DataBaseResponce{};
    }

private:
    PGConnection m_Connection;
};

} // namespace geology
