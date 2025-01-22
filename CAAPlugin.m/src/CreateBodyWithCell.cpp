#include "CAAPlugin.h"

namespace CAAPlugin
{

CATBody *CreateBodyWithCell(CATGeoFactory *iGeoFactory, CATCell *iCell)
{
    short iDimension = iCell->GetDimension();
    CATBody *oBody = iGeoFactory->CreateBody();
    CATDomain *oDomain = oBody->CreateDomain(iDimension);
    oBody->AddDomain(oDomain);
    oDomain->AddCell(iCell);
    return oBody;
}

} // namespace CAAPlugin
