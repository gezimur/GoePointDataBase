#include "IDataBaseCtrl.h"

#include "DataBaseCtrl.h"

namespace geology
{

std::unique_ptr<IDataBaseCtrl> make_ctrl(const ConnectionParams& crParams)
{
    return std::unique_ptr<DataBaseCtrl>(new DataBaseCtrl(PGConnection{crParams}));
}

} // namespace geology
