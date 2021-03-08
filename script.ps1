param (
    [int]$ProblemNumber=0,
    [string]$Language="cpp"
);

if ($ProblemNumber -eq 0)
{
    Write-Output "Nie podano numeru!";
    exit 1;
}

Remove-Item .\src\*.exe -Force;

if (Test-Path ".\src\project_euler_$ProblemNumber.$Language")
{
    $remove = Read-Host -Prompt "Czy chcesz usunac plik i utowrzyc nowy? (y/n)";
    if ($remove -eq "n")
    {
        exit 0;
    }
    Remove-Item ".\src\project_euler_$ProblemNumber.$Language" -Force;
    
}

if ($Language -eq "cpp")
{
    New-Item ".\src\project_euler_$ProblemNumber.$Language" -Value "#include <iostream>`n`nusing namespace std;`n`nint main()`n{`n`t`n}";

    exit 0;
}

New-Item ".\src\project_euler_$ProblemNumber.$Language";
exit 0;
