========================================================================
    CONSOLE APPLICATION : EnumDevices Project Overview
========================================================================

EnumDevices.vcxproj
    This is the main project file. It contains information about the 
	version of Visual C++ that generated the file, and information about 
	the platforms, configurations, and project features selected with the
    Application Wizard.

EnumDevices.vcxproj.filters
    This file contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

EnumDevices.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Configuration:

Two environment variables are used throughout the project settings.

1) $(EVEREST_ROOT) - Points to the root directory of the SDK installation.
2) $(EVEREST_BIN) - Points to the root directory of the SDK binaries.

/////////////////////////////////////////////////////////////////////////////
Solution Properties:

If you right mouse click on EnumDevices in the Solution Explorer and select
Properties to bring up the EnumDevices Property Pages dialog you can inspect
the project settings.

Two settings to note: 
1) Configuration Properties > C/C++ > General > Additional Include Directory 
1) Configuration Properties > Linker > General > Additional Library Directory 

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named EnumDevices.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
