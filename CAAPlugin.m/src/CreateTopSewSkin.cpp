#include "CAAPlugin.h"

// GMOperatorsInterfaces
#include <CATCGMCreateSewSkin.h>
#include <CATICGMTopSewSkin.h>

namespace CAAPlugin
{

CATBody *CreateSewSkin(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATBody *iTrimmingBody, CATBody *iSkinBody, CATBoolean iSimplifMode, double iTolerance)
{
    CATBody *Result = NULL;

    CATICGMTopSewSkin *Opr = ::CATCGMCreateSewSkin(iGeoFactory, iTopData, iTrimmingBody, iSkinBody);
    if (Opr == NULL) { goto OprIsNULL; }

    CATTry
    {
        Opr->SetSimplificationMode(iSimplifMode);
        Opr->SetTolerance(iTolerance);
        Opr->Run();
        Result = Opr->GetResult(iTopData->GetJournal());
    }
    CATCatch(CATError, e) { std::cerr << __FUNCTION__ << ": " << e->GetNLSMessage() << '\n'; }
    CATEndTry;

    Opr->Release();

OprIsNULL:

    return Result;
}

} // namespace CAAPlugin
