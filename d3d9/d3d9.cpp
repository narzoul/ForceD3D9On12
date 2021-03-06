#include "../ForceD3D9On12/ForceD3D9On12.h"

const char* const g_moduleName = "d3d9.dll";

CREATE_WRAPPER_FUNC(D3DPERF_BeginEvent)
CREATE_WRAPPER_FUNC(D3DPERF_EndEvent)
CREATE_WRAPPER_FUNC(D3DPERF_GetStatus)
CREATE_WRAPPER_FUNC(D3DPERF_QueryRepeatFrame)
CREATE_WRAPPER_FUNC(D3DPERF_SetMarker)
CREATE_WRAPPER_FUNC(D3DPERF_SetOptions)
CREATE_WRAPPER_FUNC(D3DPERF_SetRegion)
CREATE_WRAPPER_FUNC(DebugSetLevel)
CREATE_WRAPPER_FUNC(DebugSetMute)
CREATE_WRAPPER_FUNC(Direct3DCreate9)
CREATE_WRAPPER_FUNC(Direct3DCreate9Ex)
CREATE_WRAPPER_FUNC(Direct3DCreate9On12)
CREATE_WRAPPER_FUNC(Direct3DCreate9On12Ex)
CREATE_WRAPPER_FUNC(Direct3DShaderValidatorCreate9)
CREATE_WRAPPER_FUNC(PSGPError)
CREATE_WRAPPER_FUNC(PSGPSampleTexture)
