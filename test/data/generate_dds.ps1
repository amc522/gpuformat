﻿param (
    [Parameter(Mandatory=$true)][string]$texconvDir
)

if(-not (Test-Path -Path ".\dds" -PathType Container)) {
    try {
        New-Item -Path ".\dds" -ItemType Directory -ErrorAction Stop | Out-Null #-Force
    } catch {
        Write-Error -Message "Unable to create dds directory. Error was: $_" -ErrorAction Stop
    }
}

$local:formats = "R32G32B32A32_FLOAT", "R32G32B32A32_UINT", "R32G32B32A32_SINT", "R32G32B32_FLOAT", "R32G32B32_UINT", "R32G32B32_SINT", "R16G16B16A16_FLOAT", "R16G16B16A16_UNORM", "R16G16B16A16_UINT", "R16G16B16A16_SNORM", "R16G16B16A16_SINT", "R32G32_FLOAT", "R32G32_UINT", "R32G32_SINT", "R10G10B10A2_UNORM", "R10G10B10A2_UINT", "R11G11B10_FLOAT", "R8G8B8A8_UNORM", "R8G8B8A8_UNORM_SRGB", "R8G8B8A8_UINT", "R8G8B8A8_SNORM", "R8G8B8A8_SINT", "R16G16_FLOAT", "R16G16_UNORM", "R16G16_UINT", "R16G16_SNORM", "R16G16_SINT", "R32_FLOAT", "R32_UINT", "R32_SINT", "R8G8_UNORM", "R8G8_UINT", "R8G8_SNORM", "R8G8_SINT", "R16_FLOAT", "R16_UNORM", "R16_UINT", "R16_SNORM", "R16_SINT", "R8_UNORM", "R8_UINT", "R8_SNORM", "R8_SINT", "A8_UNORM", "R9G9B9E5_SHAREDEXP", "BC1_UNORM", "BC1_UNORM_SRGB", "BC2_UNORM", "BC2_UNORM_SRGB", "BC3_UNORM", "BC3_UNORM_SRGB", "BC4_UNORM", "BC4_SNORM", "BC5_UNORM", "BC5_SNORM", "B5G6R5_UNORM", "B5G5R5A1_UNORM", "B8G8R8A8_UNORM", "B8G8R8X8_UNORM", "R10G10B10_XR_BIAS_A2_UNORM", "B8G8R8A8_UNORM_SRGB", "B8G8R8X8_UNORM_SRGB", "BC6H_UF16", "BC6H_SF16", "BC7_UNORM", "BC7_UNORM_SRGB", "B4G4R4A4_UNORM"

$local:texconv = $texconvDir + "\\texconv.exe"

foreach( $local:format in $local:formats) {
     & $texconv -pow2 -fixbc4x4 -f $local:format -sx _$local:format -o .\dds -ft dds -dx10 scarfpile.dds
}