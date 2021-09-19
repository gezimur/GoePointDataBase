#pragma once

#include <memory>
#include <mutex>

#include "libpq-fe.h"

#include "ConnectionParams.h"

namespace geology
{

class PGConnection
{
public:
    explicit PGConnection(const ConnectionParams& crParams);

    std::shared_ptr<PGconn> connection() const noexcept;

    PGconn* get() const;

private:
    std::shared_ptr<PGconn>  m_spConnection;

};

} // namespace geology
