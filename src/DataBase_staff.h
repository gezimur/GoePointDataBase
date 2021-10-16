#pragma once

#include <string>
#include <map>

namespace geology
{

std::string make_lax_filter(const std::pair<std::string, std::string>& prArg);

std::string make_strict_filter(const std::pair<std::string, std::string>& prArg);

} // namespace geology
