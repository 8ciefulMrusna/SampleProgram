setlocal
@echo off

@rem SymbolPackage�̐���
..\nuget.exe pack SymbolPackage.nuspec -OutputDirectory pkg -Symbols

@rem PrimaryPackage�̐����i�㏑���j
..\nuget.exe pack PrimaryPackage.nuspec -OutputDirectory pkg

pause