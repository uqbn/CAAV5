#include "CAAPlugin.h"

// GMOperatorsInterfaces
#include <CATICGMTopVertex.h>

namespace CAAPlugin
{

CATBody *CreateTopVertex(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATPoint *iPoint)
{
    CATBody *Result = NULL;

    CATICGMTopVertex *Opr = ::CATCGMCreateTopVertex(iGeoFactory, iTopData, iPoint);
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
