#pragma once

#include <string>

namespace geology
{

class ConnectionParams
{
public:

    const std::string& getHots() const noexcept;
    int getPort() const noexcept;
    const std::string& getName() const noexcept;
    const std::string& getUser() const noexcept;
    const std::string& getPass() const noexcept;

private:
    std::string m_strHost = "localhost";
    int m_iPort = 5432;
    std::string m_strName = "geology";
    std::string m_strUser = "postgres";
    std::string m_strPass = "12345";
};

} // namespace geology

