setlocal
@echo off

@rem PrimaryPackage�̐���
..\nuget.exe pack PrimaryPackage.nuspec -OutputDirectory pkg\Primary

@rem SymbolPackage�̐���
..\nuget.exe pack SymbolPackage.nuspec -OutputDirectory pkg\Symbol -Symbols

pause