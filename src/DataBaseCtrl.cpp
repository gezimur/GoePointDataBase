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

    strInsert += strKeys + strValues;
    return strInsert;
}

std::string make_update(const std::map<std::string, std::string>& mValues, const std::string& strTableName)
{
    std::string strUpdate{"UPDATE "};

    strUpdate += strTableName;

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
    default:
        return DataBaseResponce{"invalid request"};
    }
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
    default:
        return DataBaseResponce{"invalid request"};
    }
}

DataBaseResponce DataBaseCtrl::add(enu_tables eTable, const std::map<std::string, std::string>& mArgs)
{
    switch (eTable) {
    case enu_tables::e_order:
        return add<Order>( Order{mArgs});
    case enu_tables::e_customer:
        return add<Customer>( Customer{mArgs});
    case enu_tables::e_user:
        return add<User>( User{mArgs});
    default:
        return DataBaseResponce{"invalid request"};
    }
}

DataBaseResponce DataBaseCtrl::edit(enu_tables eTable, const std::map<std::string, std::string>& mArgs)
{
    switch (eTable) {
    case enu_tables::e_order:
        return edit<Order>( Order{mArgs});
    case enu_tables::e_customer:
        return edit<Customer>( Customer{mArgs});
    case enu_tables::e_user:
        return edit<User>( User{mArgs});
    default:
        return DataBaseResponce{"invalid request"};
    }
}

} // namespace geology
