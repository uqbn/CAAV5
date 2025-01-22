#include "CAAPlugin.h"

namespace CAAPlugin
{

void RemoveCGM(CATGeoFactory *iGeoFactory, CATICGMObject *iObject, CATICGMContainer::CATRemovingDependancies iHow)
{
    iGeoFactory->Remove(iObject, iHow);
}

} // namespace CAAPlugin
