## Create a new plugin folder for X-Plane
In the X-Plane install folder, go to X-Plane/Resources/plugins and create a new folder for the new plugin, in this case called 'XPNet.Logger'

## Dotnet required files
Download the dotnet SDK binaries here https://www.microsoft.com/net/download/thank-you/dotnet-sdk-2.1.200-windows-x64-binaries

Add a folder to the X-Plane plugin folder (X-Plane/Resources/plugins/XPNet.Logger/) called 'dotnet' and unzip the dotnet SDK files to that folder.

Copy the following DLL's from dotnet/store/x64/netcoreapp2.0 to the plugin folder

Microsoft.Extensions.Configuration.Abstractions.dll
Microsoft.Extensions.Configuration.dll
Microsoft.Extensions.Configuration.FileExtensions.dll
Microsoft.Extensions.Configuration.Json.dll
Microsoft.Extensions.FileProviders.Abstractions.dll
Microsoft.Extensions.FileProviders.Physical.dll
Microsoft.Extensions.FileSystemGlobbing.dll
Microsoft.Extensions.Primitives.dll
Newtonsoft.Json.dll

## Add the config file
Create a file called "xpnetcfg.json" and place it in teh plugin folder, it should contain the reference config content

## Add select files from the Build output folder
From the build folder, copy the follwoing files to the plugin folder

XPNet.CLR.dll
XPNet.LoggerPlugin.dll  <-(this file will change based on what the plugin is called)
XPNet.Native.dll  <-(Rename this one to 'win.xpl')

## Test
When you run X-Plane a log file called 'xpnet.txt' will be created in the plugin folder.  If everything loads ok, you will see something liek this:

**********
[5/23/2018 11:33:57 AM] Logging Started
[11:33:57 A] XPNet CLR: Start
[11:33:57 A] XPNet CLR: Looking for plugin in (C:\Users\Jarrod Barker\Desktop\X-Plane 11\Resources\plugins\XPNet.Logger\64).
[11:33:57 A] XPNet CLR: Inspecting plugin candidate: (Path = C:\Users\Jarrod Barker\Desktop\X-Plane 11\Resources\plugins\XPNet.Logger\64\XPNet.LoggerPlugin.dll).
[11:33:57 A] LoggerPlugin: Started
[11:33:57 A] XPNet CLR: Enable
[11:33:57 A] LoggerPlugin: Enabled
[11:35:36 A] XPNet CLR: Disable
[11:35:36 A] LoggerPlugin: Disabled
[11:35:36 A] XPNet CLR: Stop
[11:35:36 A] LoggerPlugin: Stopped

You can also check the log.txt file in the X-Plane root folder, it should show somethign like this:

XPNet: Loading plugins from C:/Users/Jarrod Barker/Desktop/X-Plane 11/Resources/plugins/XPNet.Logger/64
Will load CLR from: C:/Users/Jarrod Barker/Desktop/X-Plane 11/Resources/plugins/XPNet.Logger/64/dotnet/shared/Microsoft.NETCore.App/2.0.7/coreclr.dll
XPNet: ClrPluginStart Result = 1.
Loaded: C:\Users/Jarrod Barker/Desktop/X-Plane 11/Resources/plugins/XPNet.Logger/64/win.xpl (qbaum.plugins.logger).




