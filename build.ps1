param(
    [string]$task
)

function LocateMsBuild {
    param ()
    $candidates = @(
        "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\MSBuild\15.0\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\15.0\Bin\MSBuild.exe",
        "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\MSBuild\15.0\Bin\MSBuild.exe"
    )
    for ($i = 0; $i -le $candidates.length; $i += 1) {
        if (Test-Path $candidates[$i] -PathType Leaf) {
            return $candidates[$i]
        }
    }
    throw "Error: Could not find msbuild"
}

$msbuild = LocateMsBuild

if ($task -like "server") {
    iex 'bazel build --cpu x86_32_windows --crosstool_top @windows_cc_config//:toolchain //server:app --verbose_failures'
    exit $LASTEXITCODE
} elseif ($task -like "tsf-win32") {
    iex 'bazel build --cpu x86_32_windows --crosstool_top @windows_cc_config//:toolchain //tsf:yptsf.dll --verbose_failures'
    exit $LASTEXITCODE
} elseif ($task -like "tsf-win64") {
    iex 'bazel build --cpu x64_windows --crosstool_top @windows_cc_config//:toolchain //tsf:yptsf.dll --verbose_failures'
    exit $LASTEXITCODE
} elseif ($task -like "help") {
    Write-Host "Usage: ./build.ps1 <command>"
} elseif ($task -like "predeploy") {
    remove-item -Force -Recurse "./bundle" -ErrorAction Ignore
    mkdir "./bundle"
    cp -Force "./bazel-out/x86_32_windows-fastbuild/bin/tsf/yptsf.dll" -Destination "./bundle/lib32.dll"
    cp -Force "./bazel-out/x64_windows-fastbuild/bin/tsf/yptsf.dll" -Destination "./bundle/lib64.dll"
    cp -Force "./resource/icon.ico" -Destination "./bundle/"
} elseif ($task -like "startserver") {
    iex "./bundle/app.exe"
    Write-Host "Started Server."
} elseif ($task -like "quitserver") {
    iex "./bundle/app.exe /q"
    Write-Host "Quitted Server."
} elseif ($task -like "packserver") {
    cp -Force -Recurse "./data" -Destination "./bundle"
    cp -Force -Recurse "./bazel-out/x86_32_windows-fastbuild/bin/server/rime.dll" -Destination "./bundle/"
    cp -Force -Recurse "./bazel-out/x86_32_windows-fastbuild/bin/server/app.exe" -Destination "./bundle/"
} elseif ($task -like "zip") {
    Compress-Archive -Force -Path ./bundle/* -CompressionLevel Optimal -DestinationPath ./test.zip
} elseif ($task -like "installer") {
    remove-item -Force -Recurse "./installer-build" -ErrorAction Ignore
    mkdir "./installer-build"
    iex 'dotnet restore ./deploy/TSF-TypeLib/TSF.TypeLib/TSF.TypeLib.csproj'
    & $msbuild @("/p:Configuration=Release", "deploy\YngPing.Installer\YngPing.Installer.csproj")
    cp -Force -Recurse "deploy\YngPing.Installer\bin\Release\*" "./installer-build/"
} elseif ($task -like "msi") {
    remove-item -Force -Recurse "./msi/bin" -ErrorAction Ignore
    remove-item -Force -Recurse "./msi/obj" -ErrorAction Ignore
    & $msbuild @("/p:Configuration=Release", "msi\default.wixproj")
    exit $LASTEXITCODE
} else {
    Write-Host "Unknown command: $($task)"
    exit -1
}
