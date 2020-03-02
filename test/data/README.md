# Test Data Generation

This is a guide to generate images in a variaty of formats to use for testing gpuformat.

## DDS Generation
**Requirements**
- Download and build https://github.com/microsoft/DirectXTex. texconv.exe is used to generate the DDS textures.
- Download the test images archive from https://www.hellogpu.com/gpuformat.

###Generating Images
Run `generate-dds.ps1 <path to texconv.exe>`. Images will be created in a dds folder.

## KTX GENERATION
**Requirements**
- Download https://www.imgtec.com/developers/powervr-sdk-tools/pvrtextool/. PVRTexToolCLI.exe is used to generate the KTX textures.
- Download the test images archive from https://www.hellogpu.com/gpuformat.

###Generating Images
Run `generate-ktx.ps1 <path to PVRTexToolCLI.exe>`. Images will be created in a ktx folder.