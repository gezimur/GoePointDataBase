#pragma once

#include <queue>
#include <condition_variable>
#include <functional>

#include "PGConnection.h"

namespace geology
{

class PGConnectionCtrl
{

public:
    PGConnectionCtrl(int iPoolSize);
    std::shared_ptr<PGConnection> connection();
    void freeConnection(std::shared_ptr<PGConnection> spConn);

private:
    void createPool();

    std::mutex m_Mutex;
    std::condition_variable m_Condition;
    std::queue<std::shared_ptr<PGConnection>> m_qPool;

    int m_iMaxPoolSize;
};

} // namespace geology
