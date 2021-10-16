#include "DataBase_staff.h"

namespace geology
{

std::string make_lax_filter(const std::pair<std::string, std::string>& prArg)
{
    return "position('" + prArg.second + "' in " + prArg.first + ")>0";
}

std::string make_strict_filter(const std::pair<std::string, std::string>& prArg)
{
    return prArg.first + " = '" + prArg.second + "'";
}

} // namespace geology

