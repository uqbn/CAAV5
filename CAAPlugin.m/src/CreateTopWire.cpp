#include "CAAPlugin.h"

// GeometricObjects
#include <CATCrvLimits.h>
#include <CATCurve.h>

// GMOperatorsInterfaces
#include <CATICGMTopWire.h>

namespace CAAPlugin
{

CATBody *CreateTopWire(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATLONG32 iNbCurves, CATCurve **iCurves)
{
    CATBody *Result = NULL;

    CATCrvLimits *iLimits = new CATCrvLimits[iNbCurves];
    CATOrientation *iOrientations = new CATOrientation[iNbCurves];
    for (CATLONG32 i = 0; i < iNbCurves; ++i)
    {
        iCurves[i]->GetLimits(iLimits[i]);
        iOrientations[i] = 1;
    }

    CATICGMTopWire *Opr = ::CATCGMCreateTopWire(iGeoFactory, iTopData, iNbCurves, iCurves, iLimits, iOrientations);
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
    delete[] iOrientations;
    delete[] iLimits;

    return Result;
}

} // namespace CAAPlugin
