#include "CAAPlugin.h"

// GeometricObjects
#include <CATCGMContainerMngt.h>
#include <CATTransfoManager.h>

// Mathematics
#include <CATMathTransformation.h>

#include <fstream>

namespace CAAPlugin
{

void SaveCGM(CATGeoFactory *iFactory, CATUnicodeString iName)
{
    if (iName.SearchSubString(".NCGM", 0,
            CATUnicodeString::CATSearchModeBackward) < 0)
        iName.Append(".NCGM");
    try
    {
#ifdef _WINDOWS_SOURCE
        ::std::ofstream filetowrite(iName.ConvertToChar(), ::std::ios::binary);
#else
        ::std::ofstream ofstream filetowrite(iName.ConvertToChar(), ::std::ios::out, ::std::filebuf::openprot);
#endif
        CATTry { ::CATSaveCGMContainer(iFactory, filetowrite); }
        CATCatch(CATError, e) { std::cerr << __FUNCTION__ << ": " << e->GetNLSMessage() << '\n'; }
        CATEndTry;
        filetowrite.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void SaveCGM(CATICGMObject *iObject, CATUnicodeString iName)
{
    CATGeoFactory *iFactory = ::CATCreateCGMContainer();

    CATTry
    {
        CATMathTransformation iMathTransfo;
        CATTransfoManager TransfoManager(iMathTransfo, iFactory);
        TransfoManager.Add(iObject);
        TransfoManager.Run();
    }
    CATCatch(CATError, e) { std::cerr << __FUNCTION__ << ": " << e->GetNLSMessage() << '\n'; }
    CATEndTry;

    SaveCGM(iFactory, iName);

    ::CATCloseCGMContainer(iFactory);
}

} // namespace CAAPlugin
