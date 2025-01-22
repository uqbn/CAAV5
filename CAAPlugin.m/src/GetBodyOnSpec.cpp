#include "CAAPlugin.h"

// MecModInterfaces
#include <CATIGeometricalElement.h>

namespace CAAPlugin
{

CATBody_var GetBodyOnSpec(CATISpecObject_var iSpec)
{
    CATIGeometricalElement_var iGeometricalElement = iSpec;
    if (iGeometricalElement != NULL)
    {
        return iGeometricalElement->GetBodyResult();
    }
    return NULL_var;
}

} // namespace CAAPlugin
