workspace "gpufmt"
    language "C++"
    cppdialect "C++Latest"

    warnings "Extra"

    configurations {
        "Debug",
        "Release",
    }

    platforms {
        "x64"
    }

    flags {
        "NoMinimalRebuild",
        "MultiProcessorCompile"
    }

    characterset "Unicode"

    location("../" .. _ACTION)

    filter {"action:vs*"}
        disablewarnings {"4201"} -- nonstandard extension used : nameless struct/union

    filter {"action:vs*" , "configurations:Debug*"}
        buildoptions {"/JMC"}
    
    filter {"platforms:x64"}
        architecture "x64"

    filter {"configurations:Debug*"}
        runtime "Debug"
        optimize "Off"
        symbols "FastLink"
        
    filter {"configurations:Release*"}
        defines {
            "NDEBUG",
            "_NDEBUG",
        }

        flags {
            "LinkTimeOptimization",
        }

        runtime "Release"
        optimize "Speed"
        symbols "Off"

    filter {"system:windows"}
        defines {
            "WIN32_LEAN_AND_MEAN",
            "NOMINMAX"
        }

    filter {}

    local outputTriplet = "%{cfg.system}_%{cfg.shortname}"
    local binaryPath = "../../build/bin/" .. outputTriplet .. "/"
    local intermediateDir = "../../build/intermediate/" .. outputTriplet

    project "gpufmt"
        kind "StaticLib"

        files {
            "../../include/**.h",
            "../../src/**.cpp",
            "../../thirdparty/astc_dec/**.cpp",
            "../../thirdparty/DirectXTex/**.cpp",
            "../../thirdparty/PowerVR_SDK/**.cpp",
            "../../thirdparty/swiftshader/**.cpp"
        }

        includedirs {
            "../../include",
            "../../thirdparty/astc_dec",
            "../../thirdparty/DirectXTex",
            "../../thirdparty/gl",
            "../../thirdparty/glm",
            "../../thirdparty/khr",
            "../../thirdparty/PowerVR_SDK",
            "../../thirdparty/span/include",
            "../../thirdparty/swiftshader",
        }
        
        targetdir(binaryPath)
        objdir(intermediateDir)

        filter{}

    project "gpufmt_test"
        kind "ConsoleApp"

        files {
            "../../test/**.h",
            "../../test/**.cpp",
        }

        links {
            "gpufmt"
        }

        includedirs {
            "../..",
            "../../include",
            "../../thirdparty/catch2",
            "../../thirdparty/gl",
            "../../thirdparty/glm",
            "../../thirdparty/khr",
            "../../thirdparty/span/include",
        }
        
        targetdir(binaryPath)
        objdir(intermediateDir)

        filter{}