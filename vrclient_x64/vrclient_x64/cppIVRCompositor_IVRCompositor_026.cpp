/* This file is auto-generated, do not edit. */
#include "unix_private.h"

NTSTATUS IVRCompositor_IVRCompositor_026_SetTrackingSpace( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SetTrackingSpace_params *params = (struct IVRCompositor_IVRCompositor_026_SetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->SetTrackingSpace( params->eOrigin );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetTrackingSpace( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetTrackingSpace_params *params = (struct IVRCompositor_IVRCompositor_026_GetTrackingSpace_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetTrackingSpace(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_WaitGetPoses( void *args )
{
    struct IVRCompositor_IVRCompositor_026_WaitGetPoses_params *params = (struct IVRCompositor_IVRCompositor_026_WaitGetPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->WaitGetPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetLastPoses( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetLastPoses_params *params = (struct IVRCompositor_IVRCompositor_026_GetLastPoses_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetLastPoses( params->pRenderPoseArray, params->unRenderPoseArrayCount, params->pGamePoseArray, params->unGamePoseArrayCount );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetLastPoseForTrackedDeviceIndex( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetLastPoseForTrackedDeviceIndex_params *params = (struct IVRCompositor_IVRCompositor_026_GetLastPoseForTrackedDeviceIndex_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetLastPoseForTrackedDeviceIndex( params->unDeviceIndex, params->pOutputPose, params->pOutputGamePose );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_Submit( void *args )
{
    struct IVRCompositor_IVRCompositor_026_Submit_params *params = (struct IVRCompositor_IVRCompositor_026_Submit_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->Submit( params->eEye, params->pTexture, params->pBounds, params->nSubmitFlags );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ClearLastSubmittedFrame( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ClearLastSubmittedFrame_params *params = (struct IVRCompositor_IVRCompositor_026_ClearLastSubmittedFrame_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ClearLastSubmittedFrame(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_PostPresentHandoff( void *args )
{
    struct IVRCompositor_IVRCompositor_026_PostPresentHandoff_params *params = (struct IVRCompositor_IVRCompositor_026_PostPresentHandoff_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->PostPresentHandoff(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetFrameTiming( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetFrameTiming_params *params = (struct IVRCompositor_IVRCompositor_026_GetFrameTiming_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->GetFrameTiming( params->pTiming, params->unFramesAgo );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetFrameTimings( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetFrameTimings_params *params = (struct IVRCompositor_IVRCompositor_026_GetFrameTimings_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetFrameTimings( params->pTiming, params->nFrames );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetFrameTimeRemaining( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetFrameTimeRemaining_params *params = (struct IVRCompositor_IVRCompositor_026_GetFrameTimeRemaining_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (float)iface->GetFrameTimeRemaining(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetCumulativeStats( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetCumulativeStats_params *params = (struct IVRCompositor_IVRCompositor_026_GetCumulativeStats_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->GetCumulativeStats( params->pStats, params->nStatsSizeInBytes );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_FadeToColor( void *args )
{
    struct IVRCompositor_IVRCompositor_026_FadeToColor_params *params = (struct IVRCompositor_IVRCompositor_026_FadeToColor_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->FadeToColor( params->fSeconds, params->fRed, params->fGreen, params->fBlue, params->fAlpha, params->bBackground );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetCurrentFadeColor( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetCurrentFadeColor_params *params = (struct IVRCompositor_IVRCompositor_026_GetCurrentFadeColor_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    *params->_ret = iface->GetCurrentFadeColor( params->bBackground );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_FadeGrid( void *args )
{
    struct IVRCompositor_IVRCompositor_026_FadeGrid_params *params = (struct IVRCompositor_IVRCompositor_026_FadeGrid_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->FadeGrid( params->fSeconds, params->bFadeIn );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetCurrentGridAlpha( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetCurrentGridAlpha_params *params = (struct IVRCompositor_IVRCompositor_026_GetCurrentGridAlpha_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (float)iface->GetCurrentGridAlpha(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_SetSkyboxOverride( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SetSkyboxOverride_params *params = (struct IVRCompositor_IVRCompositor_026_SetSkyboxOverride_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->SetSkyboxOverride( params->pTextures, params->unTextureCount );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ClearSkyboxOverride( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ClearSkyboxOverride_params *params = (struct IVRCompositor_IVRCompositor_026_ClearSkyboxOverride_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ClearSkyboxOverride(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_CompositorBringToFront( void *args )
{
    struct IVRCompositor_IVRCompositor_026_CompositorBringToFront_params *params = (struct IVRCompositor_IVRCompositor_026_CompositorBringToFront_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->CompositorBringToFront(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_CompositorGoToBack( void *args )
{
    struct IVRCompositor_IVRCompositor_026_CompositorGoToBack_params *params = (struct IVRCompositor_IVRCompositor_026_CompositorGoToBack_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->CompositorGoToBack(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_CompositorQuit( void *args )
{
    struct IVRCompositor_IVRCompositor_026_CompositorQuit_params *params = (struct IVRCompositor_IVRCompositor_026_CompositorQuit_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->CompositorQuit(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_IsFullscreen( void *args )
{
    struct IVRCompositor_IVRCompositor_026_IsFullscreen_params *params = (struct IVRCompositor_IVRCompositor_026_IsFullscreen_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->IsFullscreen(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetCurrentSceneFocusProcess( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetCurrentSceneFocusProcess_params *params = (struct IVRCompositor_IVRCompositor_026_GetCurrentSceneFocusProcess_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetCurrentSceneFocusProcess(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetLastFrameRenderer( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetLastFrameRenderer_params *params = (struct IVRCompositor_IVRCompositor_026_GetLastFrameRenderer_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetLastFrameRenderer(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_CanRenderScene( void *args )
{
    struct IVRCompositor_IVRCompositor_026_CanRenderScene_params *params = (struct IVRCompositor_IVRCompositor_026_CanRenderScene_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->CanRenderScene(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ShowMirrorWindow( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ShowMirrorWindow_params *params = (struct IVRCompositor_IVRCompositor_026_ShowMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ShowMirrorWindow(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_HideMirrorWindow( void *args )
{
    struct IVRCompositor_IVRCompositor_026_HideMirrorWindow_params *params = (struct IVRCompositor_IVRCompositor_026_HideMirrorWindow_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->HideMirrorWindow(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_IsMirrorWindowVisible( void *args )
{
    struct IVRCompositor_IVRCompositor_026_IsMirrorWindowVisible_params *params = (struct IVRCompositor_IVRCompositor_026_IsMirrorWindowVisible_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->IsMirrorWindowVisible(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_CompositorDumpImages( void *args )
{
    struct IVRCompositor_IVRCompositor_026_CompositorDumpImages_params *params = (struct IVRCompositor_IVRCompositor_026_CompositorDumpImages_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->CompositorDumpImages(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ShouldAppRenderWithLowResources( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ShouldAppRenderWithLowResources_params *params = (struct IVRCompositor_IVRCompositor_026_ShouldAppRenderWithLowResources_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->ShouldAppRenderWithLowResources(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ForceInterleavedReprojectionOn( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ForceInterleavedReprojectionOn_params *params = (struct IVRCompositor_IVRCompositor_026_ForceInterleavedReprojectionOn_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ForceInterleavedReprojectionOn( params->bOverride );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ForceReconnectProcess( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ForceReconnectProcess_params *params = (struct IVRCompositor_IVRCompositor_026_ForceReconnectProcess_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ForceReconnectProcess(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_SuspendRendering( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SuspendRendering_params *params = (struct IVRCompositor_IVRCompositor_026_SuspendRendering_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->SuspendRendering( params->bSuspend );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetMirrorTextureD3D11( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetMirrorTextureD3D11_params *params = (struct IVRCompositor_IVRCompositor_026_GetMirrorTextureD3D11_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetMirrorTextureD3D11( params->eEye, params->pD3D11DeviceOrResource, params->ppD3D11ShaderResourceView );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ReleaseMirrorTextureD3D11( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ReleaseMirrorTextureD3D11_params *params = (struct IVRCompositor_IVRCompositor_026_ReleaseMirrorTextureD3D11_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ReleaseMirrorTextureD3D11( params->pD3D11ShaderResourceView );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetMirrorTextureGL( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetMirrorTextureGL_params *params = (struct IVRCompositor_IVRCompositor_026_GetMirrorTextureGL_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetMirrorTextureGL( params->eEye, params->pglTextureId, params->pglSharedTextureHandle );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ReleaseSharedGLTexture( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ReleaseSharedGLTexture_params *params = (struct IVRCompositor_IVRCompositor_026_ReleaseSharedGLTexture_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->ReleaseSharedGLTexture( params->glTextureId, params->glSharedTextureHandle );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_LockGLSharedTextureForAccess( void *args )
{
    struct IVRCompositor_IVRCompositor_026_LockGLSharedTextureForAccess_params *params = (struct IVRCompositor_IVRCompositor_026_LockGLSharedTextureForAccess_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->LockGLSharedTextureForAccess( params->glSharedTextureHandle );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_UnlockGLSharedTextureForAccess( void *args )
{
    struct IVRCompositor_IVRCompositor_026_UnlockGLSharedTextureForAccess_params *params = (struct IVRCompositor_IVRCompositor_026_UnlockGLSharedTextureForAccess_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->UnlockGLSharedTextureForAccess( params->glSharedTextureHandle );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetVulkanInstanceExtensionsRequired( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetVulkanInstanceExtensionsRequired_params *params = (struct IVRCompositor_IVRCompositor_026_GetVulkanInstanceExtensionsRequired_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetVulkanInstanceExtensionsRequired( params->pchValue, params->unBufferSize );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetVulkanDeviceExtensionsRequired( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetVulkanDeviceExtensionsRequired_params *params = (struct IVRCompositor_IVRCompositor_026_GetVulkanDeviceExtensionsRequired_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetVulkanDeviceExtensionsRequired( params->pPhysicalDevice, params->pchValue, params->unBufferSize );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_SetExplicitTimingMode( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SetExplicitTimingMode_params *params = (struct IVRCompositor_IVRCompositor_026_SetExplicitTimingMode_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->SetExplicitTimingMode( params->eTimingMode );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_SubmitExplicitTimingData( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SubmitExplicitTimingData_params *params = (struct IVRCompositor_IVRCompositor_026_SubmitExplicitTimingData_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->SubmitExplicitTimingData(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_IsMotionSmoothingEnabled( void *args )
{
    struct IVRCompositor_IVRCompositor_026_IsMotionSmoothingEnabled_params *params = (struct IVRCompositor_IVRCompositor_026_IsMotionSmoothingEnabled_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->IsMotionSmoothingEnabled(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_IsMotionSmoothingSupported( void *args )
{
    struct IVRCompositor_IVRCompositor_026_IsMotionSmoothingSupported_params *params = (struct IVRCompositor_IVRCompositor_026_IsMotionSmoothingSupported_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->IsMotionSmoothingSupported(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_IsCurrentSceneFocusAppLoading( void *args )
{
    struct IVRCompositor_IVRCompositor_026_IsCurrentSceneFocusAppLoading_params *params = (struct IVRCompositor_IVRCompositor_026_IsCurrentSceneFocusAppLoading_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->IsCurrentSceneFocusAppLoading(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_SetStageOverride_Async( void *args )
{
    struct IVRCompositor_IVRCompositor_026_SetStageOverride_Async_params *params = (struct IVRCompositor_IVRCompositor_026_SetStageOverride_Async_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->SetStageOverride_Async( params->pchRenderModelPath, params->pTransform, params->pRenderSettings, params->nSizeOfRenderSettings );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_ClearStageOverride( void *args )
{
    struct IVRCompositor_IVRCompositor_026_ClearStageOverride_params *params = (struct IVRCompositor_IVRCompositor_026_ClearStageOverride_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    iface->ClearStageOverride(  );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetCompositorBenchmarkResults( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetCompositorBenchmarkResults_params *params = (struct IVRCompositor_IVRCompositor_026_GetCompositorBenchmarkResults_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (bool)iface->GetCompositorBenchmarkResults( params->pBenchmarkResults, params->nSizeOfBenchmarkResults );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetLastPosePredictionIDs( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetLastPosePredictionIDs_params *params = (struct IVRCompositor_IVRCompositor_026_GetLastPosePredictionIDs_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetLastPosePredictionIDs( params->pRenderPosePredictionID, params->pGamePosePredictionID );
    return 0;
}

NTSTATUS IVRCompositor_IVRCompositor_026_GetPosesForFrame( void *args )
{
    struct IVRCompositor_IVRCompositor_026_GetPosesForFrame_params *params = (struct IVRCompositor_IVRCompositor_026_GetPosesForFrame_params *)args;
    struct u_IVRCompositor_IVRCompositor_026 *iface = (struct u_IVRCompositor_IVRCompositor_026 *)params->linux_side;
    params->_ret = (uint32_t)iface->GetPosesForFrame( params->unPosePredictionID, params->pPoseArray, params->unPoseArrayCount );
    return 0;
}

