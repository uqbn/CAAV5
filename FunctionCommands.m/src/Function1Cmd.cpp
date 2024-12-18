// COPYRIGHT Dassault Systemes 2024
//===================================================================
//
// Function1Cmd.cpp
// The state chart based command: Function1Cmd
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2024  Creation: Code generated by the CAA wizard  root
//===================================================================
#include "Function1Cmd.h"

#include "CATCreateExternalObject.h"
CATCreateClass(Function1Cmd);

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
Function1Cmd::Function1Cmd()
    : CATStateCommand("Function1Cmd", CATDlgEngOneShot, CATCommandModeExclusive)
// Valid states are CATDlgEngOneShot and CATDlgEngRepeat
{
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
Function1Cmd::~Function1Cmd()
{
}

#include <iostream>

struct vector3
{
    double x_, y_, z_;
    vector3(double x = 0, double y = 0, double z = 0)
        : x_(x)
        , y_(y)
        , z_(z)
    {
    }
    friend std::ostream &operator<<(std::ostream &s, vector3 const &v)
    {
        s << "(" << v.x_ << "," << v.y_ << "," << v.z_ << ")";
        return s;
    }
};

typedef void(__stdcall *CXX11_cross)(vector3 const *a, vector3 const *b, vector3 *c);

//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void Function1Cmd::BuildGraph()
{
    vector3 a(1, 2, 3), b(3, 2, 1), c;
    CXX11_cross cross;

    HMODULE hmodule = LoadLibrary(L"CXX11");
    if (hmodule == 0)
    {
        std::cout << "could not load the dynamic library" << std::endl;
        goto fail;
    }

    cross = (CXX11_cross)GetProcAddress(hmodule, "CXX11_cross");
    if (cross == 0)
    {
        std::cout << "could not locate the function" << std::endl;
        goto fail;
    }

    cross(&a, &b, &c);
    std::cout << a << "^" << b << "=" << c << std::endl;

fail:
    FreeLibrary(hmodule);
    RequestDelayedDestruction();
}
