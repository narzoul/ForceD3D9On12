#include "../ForceD3D9On12/ForceD3D9On12.h"

const char* const g_moduleName = "d3d8.dll";

CREATE_WRAPPER_FUNC(DebugSetMute)
CREATE_WRAPPER_FUNC(Direct3DCreate8)
CREATE_WRAPPER_FUNC(ValidatePixelShader)
CREATE_WRAPPER_FUNC(ValidateVertexShader)
