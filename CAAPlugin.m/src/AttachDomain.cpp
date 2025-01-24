#include "CAAPlugin.h"

namespace CAAPlugin
{

void AttachDomain(CATTopObject *oObject, CATTopObject *iObject)
{
    CATLONG32 n = iObject->GetNbDomains();
    for (CATLONG32 i = 1; i <= n; ++i)
    {
        CATLocation iLocation = CATLocationIn3DSpace;
        CATDomain *iDomain = iObject->GetDomain(i, &iLocation);
        oObject->AddDomainWithLocation(iDomain, iLocation);
    }
}

} // namespace CAAPlugin
