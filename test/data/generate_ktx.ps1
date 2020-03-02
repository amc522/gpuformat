param (
    [Parameter(Mandatory=$true)][string]$pvrtexltoolcliDir
)

if(-not (Test-Path -Path ".\ktx" -PathType Container)) {
    try {
        New-Item -Path ".\ktx" -ItemType Directory -ErrorAction Stop | Out-Null #-Force
    } catch {
        Write-Error -Message "Unable to create ktx directory. Error was: $_" -ErrorAction Stop
    }
}

$local:pvrtextool = Join-Path $pvrtexltoolcliDir "PVRTexToolCLI.exe"

# Encode Format:
# REQUIRED
# Sets the format to encode to.
# First argument (required) is the format, which can be either a compressed format (see Usage for a list) or a non-compressed format in the form 'r8g8b8a8'. Any number of channels up to 4 can be specified, but must be matched with a size (in bits) at all times. Valid channel names are 'r','g','b','a','i','l' or 'x'. Valid sizes range from 1 to 32, but the total of all sizes must be a multiple of 8 (byte aligned).
# The second argument is the channel type. This is optional - defaults to Normalised Unsigned Byte. Specifying a type is generally not required for compressed formats, but generally is for uncompressed formats. See usage table for valid values.
# The third and final argument specifies the colour space, which will accept either sRGB or lRGB - default is lRGB for linear rgb.
# Usage
#         -f [format],<variabletype>,<colourspace>
# Example
#         -f PVRTC1_2,UBN,lRGB

# -Valid Formats: PVRTC1_2, PVRTC1_4, PVRTC1_2_RGB, PVRTC1_4_RGB, PVRTC2_2, PVRTC2_4, ETC1, BC1, BC2, BC3,UYVY, YUY2, 1BPP, RGBE9995, RGBG8888, GRGB8888, ETC2_RGB, ETC2_RGBA, ETC2_RGB_A1, EAC_R11, EAC_RG11, ASTC_4x4, ASTC_5x4, ASTC_5x5, ASTC_6x5, ASTC_6x6, ASTC_8x5, ASTC_8x6, ASTC_8x8, ASTC_10x5, ASTC_10x6, ASTC_10x8, ASTC_10x10, ASTC_12x10, ASTC_12x12, ASTC_3x3x3, ASTC_4x3x3, ASTC_4x4x3, ASTC_4x4x4, ASTC_5x4x4, ASTC_5x5x4, ASTC_5x5x5, ASTC_6x5x5, ASTC_6x6x5, ASTC_6x6x6

# -Valid Variable Types: UB, UBN, SB, SBN, US, USN, SS, SSN, UI, UIN, SI, SIN, UF, SF.

#  - Key:
#  - First Char- S=Signed, U=Unsigned.
#  - Second Char- B=Byte, S=Short, I=Integer, F=Float.
#  - Third Character (optional) N=Normalised.
# -Valid Colourspaces: lRGB, sRGB.

class PVRTexToolFormat {
    [string]$format
    [string]$variabletype
    [string]$colorspace

    PVRTexToolFormat([string]$format, [string]$variabletype, [string]$colorspace) {
        $this.format = $format
        $this.variabletype = $variabletype
        $this.colorspace = $colorspace
    }
}

$local:uncompressedFormats = @(
[PVRTexToolFormat]::new("r4g4b4a4","USN","lRGB"),

[PVRTexToolFormat]::new("r5g6b5","USN","lRGB"),

[PVRTexToolFormat]::new("r5g5b5a1","USN","lRGB"),
#[PVRTexToolFormat]::new("a1r5g5b5","USN","lRGB"), #pvrtextool has support for this format under the vulkan api, but doesn't output to ktx with valid formats

[PVRTexToolFormat]::new("r8","UB","lRGB"),
[PVRTexToolFormat]::new("r8","SB","lRGB"),
[PVRTexToolFormat]::new("r8","UBN","lRGB"),
[PVRTexToolFormat]::new("r8","SBN","lRGB"),

[PVRTexToolFormat]::new("a8","UBN","lRGB"),

[PVRTexToolFormat]::new("r8g8","UB","lRGB"),
[PVRTexToolFormat]::new("r8g8","SB","lRGB"),
[PVRTexToolFormat]::new("r8g8","UBN","lRGB"),
[PVRTexToolFormat]::new("r8g8","SBN","lRGB"),

[PVRTexToolFormat]::new("r8g8b8","UBN","lRGB"),
[PVRTexToolFormat]::new("r8g8b8","UBN","sRGB"),
[PVRTexToolFormat]::new("r8g8b8","SBN","lRGB"),
[PVRTexToolFormat]::new("r8g8b8","UB","lRGB"),
[PVRTexToolFormat]::new("r8g8b8","SB","lRGB"),

[PVRTexToolFormat]::new("r8g8b8a8","UBN","lRGB"),
[PVRTexToolFormat]::new("r8g8b8a8","UBN","sRGB"),
[PVRTexToolFormat]::new("r8g8b8a8","UB","lRGB"),
[PVRTexToolFormat]::new("r8g8b8a8","SB","lRGB"),
[PVRTexToolFormat]::new("r8g8b8a8","SBN","lRGB"),

[PVRTexToolFormat]::new("b8g8r8a8","UBN","lRGB"),
[PVRTexToolFormat]::new("b8g8r8a8","UBN","sRGB"),

[PVRTexToolFormat]::new("a2b10g10r10","UIN","lRGB"),
[PVRTexToolFormat]::new("a2b10g10r10","UI","lRGB"),

[PVRTexToolFormat]::new("b10g11r11","UF","lRGB"),

[PVRTexToolFormat]::new("r16","SF","lRGB"),
[PVRTexToolFormat]::new("r16","US","lRGB"),
[PVRTexToolFormat]::new("r16","SS","lRGB"),
[PVRTexToolFormat]::new("r16","USN","lRGB"),
[PVRTexToolFormat]::new("r16","SSN","lRGB"),

[PVRTexToolFormat]::new("r16g16","SF","lRGB"),
[PVRTexToolFormat]::new("r16g16","US","lRGB"),
[PVRTexToolFormat]::new("r16g16","SS","lRGB"),
[PVRTexToolFormat]::new("r16g16","USN","lRGB"),
[PVRTexToolFormat]::new("r16g16","SSN","lRGB"),

[PVRTexToolFormat]::new("r16g16b16","SF","lRGB"),
[PVRTexToolFormat]::new("r16g16b16","US","lRGB"),
[PVRTexToolFormat]::new("r16g16b16","SS","lRGB"),
[PVRTexToolFormat]::new("r16g16b16","USN","lRGB"),
[PVRTexToolFormat]::new("r16g16b16","SSN","lRGB"),

[PVRTexToolFormat]::new("r16g16b16a16","SF","lRGB"),
[PVRTexToolFormat]::new("r16g16b16a16","US","lRGB"),
[PVRTexToolFormat]::new("r16g16b16a16","SS","lRGB"),
[PVRTexToolFormat]::new("r16g16b16a16","USN","lRGB"),
[PVRTexToolFormat]::new("r16g16b16a16","SSN","lRGB"),

[PVRTexToolFormat]::new("r32","SF","lRGB"),
[PVRTexToolFormat]::new("r32","UI","lRGB"),
[PVRTexToolFormat]::new("r32","SI","lRGB"),

[PVRTexToolFormat]::new("r32g32","SF","lRGB"),
[PVRTexToolFormat]::new("r32g32","UI","lRGB"),
[PVRTexToolFormat]::new("r32g32","SI","lRGB"),

[PVRTexToolFormat]::new("r32g32b32","SF","lRGB"),
[PVRTexToolFormat]::new("r32g32b32","UI","lRGB"),
[PVRTexToolFormat]::new("r32g32b32","SI","lRGB"),

[PVRTexToolFormat]::new("r32g32b32a32","SF","lRGB"),
[PVRTexToolFormat]::new("r32g32b32a32","UI","lRGB"),
[PVRTexToolFormat]::new("r32g32b32a32","SI","lRGB")
)

foreach( $local:format in $local:uncompressedFormats ) {
    & $pvrtextool -i scarfpile.ktx -o "ktx/scarfpile_$($local:format.format)_$($local:format.variabletype)_$($local:format.colorspace).ktx" -pot - -f $local:format.format,$local:format.variabletype,$local:format.colorspace
}

$local:pvrtcCompressedFormats = @(
"PVRTC1_2",
"PVRTC1_4",
"PVRTC1_2_RGB",
"PVRTC1_4_RGB",
"PVRTC2_2",
"PVRTC2_4"
)

foreach( $local:format in $local:pvrtcCompressedFormats ) {
	& $pvrtextool -i scarfpile.ktx -o "ktx/scarfpile_$($local:format).ktx" -pot - -f $local:format -q pvrtcfastest
}

$local:etcCompressedFormats = @(
"ETC1",
"ETC2_RGB",
"ETC2_RGBA",
"ETC2_RGB_A1",
"EAC_R11",
"EAC_RG11"
)

foreach( $local:format in $local:etcCompressedFormats ) {
	& $pvrtextool -i scarfpile.ktx -o "ktx/scarfpile_$($local:format).ktx" -pot - -f $local:format -q etcfast
}

$local:astcCompressedFormats = @(
"ASTC_4x4",
"ASTC_5x4",
"ASTC_5x5",
"ASTC_6x5",
"ASTC_6x6",
"ASTC_8x5",
"ASTC_8x6",
"ASTC_8x8",
"ASTC_10x5",
"ASTC_10x6",
"ASTC_10x8",
"ASTC_10x10",
"ASTC_12x10",
"ASTC_12x12"
)

foreach( $local:format in $local:astcCompressedFormats ) {
	& $pvrtextool -i scarfpile.ktx -o "ktx/scarfpile_$($local:format).ktx" -pot - -f $local:format -q astcveryfast
}

$local:miscCompressedFormats = @(
"BC1",
"BC2",
"BC3",
"RGBE9995"
)

foreach( $local:format in $local:miscCompressedFormats ) {
	& $pvrtextool -i scarfpile.ktx -o "ktx/scarfpile_$($local:format).ktx" -pot - -f $local:format
}