#include "ConnectionParams.h"

#include <fstream>
#include <iostream>

namespace geology
{

ConnectionParams::ConnectionParams(const std::string& strConfigPath)
{
    std::ifstream Ifstream(strConfigPath.c_str());
    if (!Ifstream.is_open())
        std::cout << "Open config failed" << std::endl;

    Ifstream >> m_iPort >> m_strName >> m_strUser >> m_strPass;

    Ifstream.close();
}

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
