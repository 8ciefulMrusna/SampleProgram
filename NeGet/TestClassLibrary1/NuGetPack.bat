setlocal
@echo off

@rem SymbolPackage�̐���
..\nuget.exe pack OssCons.DotNetSubcommittee.TestClassLibrary1.nuspec -OutputDirectory pkg -Symbols

@rem PrimaryPackage�̐����i�㏑���j
..\nuget.exe pack OssCons.DotNetSubcommittee.TestClassLibrary1.nuspec -OutputDirectory pkg

pause