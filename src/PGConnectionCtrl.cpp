#include "PGConnectionCtrl.h"

namespace geology
{

PGConnectionCtrl::PGConnectionCtrl(int iPoolSize)
    : m_iMaxPoolSize(iPoolSize)
{
    createPool();
}

std::shared_ptr<PGConnection> PGConnectionCtrl::connection()
{
    std::unique_lock<std::mutex> Lock(m_Mutex);

    while(m_qPool.empty())
    {
        m_Condition.wait(Lock);
    }

    auto Conn = m_qPool.front();
    m_qPool.pop();

    return Conn;
}

void PGConnectionCtrl::freeConnection(std::shared_ptr<PGConnection> spConn)
{
    std::unique_lock<std::mutex> Lock(m_Mutex);
    m_qPool.push(spConn);
    Lock.unlock();

    m_Condition.notify_one();
}

void PGConnectionCtrl::createPool()
{
    std::lock_guard<std::mutex> Locker(m_Mutex);

    for (int i = 0; i < m_iMaxPoolSize; ++i)
        m_qPool.push(std::make_shared<PGConnection>(ConnectionParams()));
}

} // namespace geology
