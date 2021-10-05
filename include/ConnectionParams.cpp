#include "ConnectionParams.h"

namespace geology
{

const std::string& ConnectionParams::getHots() const noexcept
{
    return m_strHost;
}

int ConnectionParams::getPort() const noexcept
{
    return m_iPort;
}

const std::string& ConnectionParams::getName() const noexcept
{
    return m_strName;
}

const std::string& ConnectionParams::getUser() const noexcept
{
    return m_strUser;
}

const std::string& ConnectionParams::getPass() const noexcept
{
    return m_strPass;
}

} // namespace geology
