#include "../ForceD3D9On12/ForceD3D9On12.h"

const char* const g_moduleName = "ddraw.dll";

CREATE_WRAPPER_FUNC(AcquireDDThreadLock)
CREATE_WRAPPER_FUNC(CompleteCreateSysmemSurface)
CREATE_WRAPPER_FUNC(D3DParseUnknownCommand)
CREATE_WRAPPER_FUNC(DDGetAttachedSurfaceLcl)
CREATE_WRAPPER_FUNC(DDInternalLock)
CREATE_WRAPPER_FUNC(DDInternalUnlock)
CREATE_WRAPPER_FUNC(DSoundHelp)
CREATE_WRAPPER_FUNC(DirectDrawCreate)
CREATE_WRAPPER_FUNC(DirectDrawCreateClipper)
CREATE_WRAPPER_FUNC(DirectDrawCreateEx)
CREATE_WRAPPER_FUNC(DirectDrawEnumerateA)
CREATE_WRAPPER_FUNC(DirectDrawEnumerateExA)
CREATE_WRAPPER_FUNC(DirectDrawEnumerateExW)
CREATE_WRAPPER_FUNC(DirectDrawEnumerateW)
CREATE_WRAPPER_FUNC(DllCanUnloadNow)
CREATE_WRAPPER_FUNC(DllGetClassObject)
CREATE_WRAPPER_FUNC(GetDDSurfaceLocal)
CREATE_WRAPPER_FUNC(GetOLEThunkData)
CREATE_WRAPPER_FUNC(GetSurfaceFromDC)
CREATE_WRAPPER_FUNC(RegisterSpecialCase)
CREATE_WRAPPER_FUNC(ReleaseDDThreadLock)
CREATE_WRAPPER_FUNC(SetAppCompatData)
