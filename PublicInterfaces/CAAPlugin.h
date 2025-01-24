#ifndef CAAPlugin_H
#define CAAPlugin_H

#include <CATErrorMacros.h>

// GeometricObjects
#include <CATGeoFactory.h>

// GMModelInterfaces
#include <CATBody.h>
#include <CATCell.h>
#include <CATDomain.h>

// Mathematics
#include <CATMathTransformation.h>

// ObjectSpecsModeler
#include <CATISpecObject.h>

// System
#include <CATUnicodeString.h>

#ifdef _WINDOWS_SOURCE
#ifdef __CAAPlugin
#define ExportedByCAAPlugin __declspec(dllexport)
#else
#define ExportedByCAAPlugin __declspec(dllimport)
#endif
#else
#define ExportedByCAAPlugin
#endif

namespace CAAPlugin
{

ExportedByCAAPlugin CATBody *CreateTopDatum(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATGeoFactory::CATDatumId iIdent);
ExportedByCAAPlugin CATBody *CreateTopVertex(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATPoint *iPoint);
ExportedByCAAPlugin CATBody *CreateTopWire(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATLONG32 iNbCurves, CATCurve **iCurves);
ExportedByCAAPlugin CATBody *CreateTopSkin(CATGeoFactory *iGeoFactory, CATTopData *iTopData, CATSurface *iSurface);

ExportedByCAAPlugin CATBody *CreateBodyWithCell(CATGeoFactory *iGeoFactory, CATCell *iCell);

ExportedByCAAPlugin CATBody_var GetBodyOnSpec(CATISpecObject_var iSpec);

ExportedByCAAPlugin CATBody *CreateSewSkin(CATGeoFactory *iGeoFactory, CATTopData *iTopData,
    CATBody *iTrimmingBody, CATBody *iSkinBody, CATBoolean iSimplifMode = TRUE, double iTolerance = 0.1);

ExportedByCAAPlugin void AttachDomain(CATTopObject *oObject, CATTopObject *iObject);

ExportedByCAAPlugin void RemoveCGM(CATGeoFactory *iGeoFactory, CATICGMObject *iObject,
    CATICGMContainer::CATRemovingDependancies iHow = CATICGMContainer::RemoveDependancies);

ExportedByCAAPlugin void SaveCGM(CATGeoFactory *iFactory, CATUnicodeString iName);
ExportedByCAAPlugin void SaveCGM(CATICGMObject *iObject, CATUnicodeString iName);

} // namespace CAAPlugin

#include <iostream>
// clang-format off
#define IF_ERR(expr,exec) \
    if(expr){::std::cerr<<"ERROR: "<<__FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<": "<<#expr<<"\n";exec;}
#define IF_BUG(expr,exec) \
    if(expr){::std::cout<<"DEBUG: "<<__FILE__<<":"<<__LINE__<<" "<<__FUNCTION__<<": "<<#expr<<"\n";exec;}
#define IF_LOG(expr,info,exec) \
    if(expr){::std::cout<<info<<"\n";exec;}
// clang-format on

#endif /* CAAPlugin.h */
