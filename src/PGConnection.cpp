#include "PGConnection.h"

namespace geology
{

PGConnection::PGConnection(const ConnectionParams& crParams) ///@todo connect disconnect
{
    m_spConnection.reset( PQsetdbLogin(crParams.getHots().c_str(),
                                       std::to_string(crParams.getPort()).c_str(),
                                       nullptr,
                                       nullptr,
                                       crParams.getName().c_str(),
                                       crParams.getUser().c_str(),
                                       crParams.getPass().c_str()),
                          &PQfinish );

    if (PQstatus( m_spConnection.get() ) != CONNECTION_OK && PQsetnonblocking(m_spConnection.get(), 1) != 0 )
    {
       throw std::runtime_error( PQerrorMessage( m_spConnection.get() ) );
    }

}

std::shared_ptr<PGconn> PGConnection::connection() const noexcept
{
    return m_spConnection;
}

PGconn* PGConnection::get() const
{
    return m_spConnection.get();
}

} // namespace geology
