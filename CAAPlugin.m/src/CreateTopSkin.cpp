#include "CAAPlugin.h"

// GeometricObjects
#include <CATSurLimits.h>
#include <CATSurface.h>

// GMOperatorsInterfaces
#include <CATICGMTopSkin.h>

namespace CAAPlugin
{

CATBody *CreateTopSkin(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATSurface *iSurface)
{
    CATBody *Result = NULL;

    CATSurLimits iLimits;
    iSurface->GetLimits(iLimits);

    CATICGMTopSkin *Opr = ::CATCGMCreateTopSkin(iGeoFactory, iTopData, iSurface, &iLimits);
    if (Opr == NULL) { goto OprIsNULL; }

    CATTry
    {
        Opr->Run();
        Result = Opr->GetResult();
    }
    CATCatch(CATError, e) { std::cerr << __FUNCTION__ << ": " << e->GetNLSMessage() << '\n'; }
    CATEndTry;

    Opr->Release();

OprIsNULL:

    return Result;
}

} // namespace CAAPlugin
