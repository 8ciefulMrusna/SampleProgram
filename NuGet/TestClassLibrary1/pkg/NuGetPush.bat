setlocal
@echo off

@rem ApiKey��o�^
..\..\nuget.exe SetApiKey [ApiKey]

@rem nuget.org��PrimaryPackage��o�^(SymbolPackage��o�^���ɍs���ăG���[�ɂȂ邪�A����͖���)
..\..\nuget.exe push OssCons.DotNetSubcommittee.TestClassLibrary*.nupkg -source https://www.nuget.org/

@rem symbolsource.org��SymbolPackage��o�^
..\..\nuget.exe push OssCons.DotNetSubcommittee.TestClassLibrary*.symbols.nupkg -source https://nuget.smbsrc.net/

pause