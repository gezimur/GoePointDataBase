#include "DataBaseCtrl.h"

namespace geology
{

std::string make_select(const std::vector<std::string>& vNames, const std::string& strTableName)
{
    std::string strSelect{"SELECT "};

    auto itName = vNames.cbegin();
    strSelect += *itName;

    ++itName;
    for (; itName != vNames.end(); ++itName)
        strSelect += ", " + *itName;

    strSelect += " FROM " + strTableName;
    return strSelect;
}

std::string make_inner_join()
{
    return " LEFT JOIN customer ON orders.customer = customer.passport_number";
}

std::string make_filter(const std::map<std::string, std::string>& mFilter)
{
    if (mFilter.empty())
        return "";

    std::string strFilter{" WHERE "};

    auto itColumn = mFilter.cbegin();
    strFilter += itColumn->first + " = '" + itColumn->second + "'";

    ++itColumn;
    for (; itColumn != mFilter.cend(); ++itColumn)
        strFilter += " and " + itColumn->first + " = '" + itColumn->second + "'";

    return strFilter;
}

std::string make_sort(const std::string& strSortType)
{
    if (strSortType.empty())
        return "";

    return " ORDER BY " + strSortType;
}

std::string make_limit(int iCnt)
{
    return " LIMIT " + std::to_string(iCnt);
}

std::string make_insert(const std::map<std::string, std::string>& mValues, const std::string& strTableName)
{
    std::string strInsert{"INSERT INTO "};

    std::string strKeys{strTableName + "("};
    std::string strValues{" VALUES("};

    auto itValue = mValues.cbegin();
    strKeys += itValue->first;
    strValues += "'" + itValue->second + "'";

    ++itValue;
    for (; itValue != mValues.cend(); ++itValue)
    {
        strKeys += ", " + itValue->first;
        strValues += ", '" + itValue->second + "'";
    }

    strKeys += ")";
    strValues += ")";

    std::string strOnConflict = " ON CONFLICT ON CONSTRAINT " + strTableName + "_key DO " + make_update(mValues);

    strInsert += strKeys + strValues + strOnConflict;
    return strInsert;
}

std::string make_update(const std::map<std::string, std::string>& mValues)
{
    std::string strUpdate{"UPDATE "};

    strUpdate += " SET ";

    auto itValue = mValues.cbegin();
    strUpdate += itValue->first + " = '" + itValue->second + "'";

    ++itValue;
    for (; itValue != mValues.cend(); ++itValue)
        strUpdate += ", " + itValue->first + " = '" + itValue->second + "'";

    return strUpdate;
}

DataBaseCtrl::DataBaseCtrl(const PGConnection& crConnection)
    : m_Connection(crConnection)
{

}

DataBaseResponce DataBaseCtrl::load(enu_tables eTable, int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType)
{
    switch (eTable) {
    case enu_tables::e_order:
        return load<Order>(iCnt, Order{mFilter}, strSortType);
    case enu_tables::e_customer:
        return load<Customer>(iCnt, Customer{mFilter}, strSortType);
    case enu_tables::e_user:
        return load<User>(iCnt, User{mFilter}, strSortType);
    case enu_tables::e_oblast:
        return load<Oblast>(iCnt, Oblast{mFilter}, strSortType);
    case enu_tables::e_raion:
        return load<Raion>(iCnt, Raion{mFilter}, strSortType);
    case enu_tables::e_poselenie:
        return load<Poselenie>(iCnt, Poselenie{mFilter}, strSortType);
    default:
        return DataBaseResponce{"invalid request"};
    }
}

DataBaseResponce DataBaseCtrl::loadOrderGreedy(int iCnt, const std::map<std::string, std::string>& mFilter, const std::string& strSortType)
{
    std::vector<std::string> vSelect{"orders.id", "orders.work_type", "orders.work_class", "orders.order_date", "orders.deadline", "orders.place", "orders.status",
                        "(select users.full_name from users where users.id = orders.ingeneer) as ingeneer",
                        "(select users.full_name from users where users.id = orders.fielder) as fielder",
                        "customer.full_name as customer", "customer.passport_number", "customer.passport_gived", "customer.passport_date", "customer.snils", "customer.phone", "customer.email"};

    auto strRequest = make_select(vSelect, "Orders");
    strRequest += make_inner_join();
    strRequest += make_filter(mFilter);
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

DataBaseResponce DataBaseCtrl::loadById(enu_tables eTable, int iId)
{
    switch (eTable) {
    case enu_tables::e_order:
        return loadById<Order>(iId);
    case enu_tables::e_customer:
        return loadById<Customer>(iId);
    case enu_tables::e_user:
        return loadById<User>(iId);
    case enu_tables::e_oblast:
        return loadById<Oblast>(iId);
    case enu_tables::e_poselenie:
        return loadById<Poselenie>(iId);
    case enu_tables::e_raion:
        return loadById<Raion>(iId);
    default:
        return DataBaseResponce{"invalid request"};
    }
}

DataBaseResponce DataBaseCtrl::write(enu_tables eTable, const std::map<std::string, std::string>& mArgs)
{
    switch (eTable) {
    case enu_tables::e_order:
        return write<Order>( Order{mArgs});
    case enu_tables::e_customer:
        return write<Customer>( Customer{mArgs});
    case enu_tables::e_user:
        return write<User>( User{mArgs});
    case enu_tables::e_oblast:
        return write<Oblast>(Oblast{mArgs});
    case enu_tables::e_poselenie:
        return write<Poselenie>(Poselenie{mArgs});
    case enu_tables::e_raion:
        return write<Raion>(Raion{mArgs});
    default:
        return DataBaseResponce{"invalid request"};
    }
}

} // namespace geology
