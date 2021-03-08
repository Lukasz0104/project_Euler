param (
    [int]$Nr
)

$file = Get-Item ".\src\project_euler_$Nr.*";

$ext = $file.Extension;

if ($ext -eq ".cpp")
{
    g++ -o ".\executables\project_euler_$Nr" ".\src\project_euler_$Nr.cpp"; if ($?) {& ".\executables\project_euler_$Nr.exe";}
    exit 0;
}
elseif ($ext -eq ".py")
{
    python ".\src\project_euler_$Nr.py"
    exit 0;
}

