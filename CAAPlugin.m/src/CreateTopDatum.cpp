#include "CAAPlugin.h"

namespace CAAPlugin
{

CATBody *CreateTopDatum(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATGeoFactory::CATDatumId iIdent)
{
    CATBody *Result = NULL;

    CATGeometry const *Geometry = iGeoFactory->GetDatum(iIdent);
    switch (iIdent)
    {
    case CATGeoFactory::O:
        Result = CreateTopVertex(iGeoFactory, iTopData, (CATPoint *)Geometry);
        break;
    case CATGeoFactory::OI:
    case CATGeoFactory::OJ:
    case CATGeoFactory::OK:
        Result = CreateTopWire(iGeoFactory, iTopData, 1, (CATCurve **)&Geometry);
        break;
    case CATGeoFactory::OIJ:
    case CATGeoFactory::OJK:
    case CATGeoFactory::OKI:
        Result = CreateTopSkin(iGeoFactory, iTopData, (CATSurface *)Geometry);
        break;
    default:;
    }

    return Result;
}

} // namespace CAAPlugin
