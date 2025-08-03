workspace "Lacerta-Engine"
    startproject "Sandbox"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lacerta-Engine"
    location "Lacerta-Engine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        systemversion "latest"
        defines {
            "LCT_PLATFORM_WINDOWS",
            "LCT_BUILD_DLL"
        }
        buildoptions { "/utf-8" }

postbuildcommands {
    '{COPY} "%{cfg.buildtarget.relpath}" "%{wks.location}/bin/' .. outputdir .. '/Sandbox/"'
}

    filter "configurations:Debug"
        defines "LCT_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "LCT_RELEASE"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "LCT_DIST"
        optimize "On"
        runtime "Release"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Lacerta-Engine/vendor/spdlog/include",
        "Lacerta-Engine/src"
    }

    links {
        "Lacerta-Engine"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "LCT_PLATFORM_WINDOWS" }
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "LCT_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "LCT_RELEASE"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "LCT_DIST"
        optimize "On"
        runtime "Release"
