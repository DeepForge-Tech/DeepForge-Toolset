# Add Kotlin Path
$path2add = ';C:\eclipse'
$systemPath = [Environment]::GetEnvironmentVariable('Path');
If (!$systemPath.contains($path2add)) {
    $systemPath += $path2add
    $systemPath = $systemPath 
    [Environment]::SetEnvironmentVariable('Path', $systemPath);
    # SETX PATH $systemPath
}

# Clean system variable
$systemPath = [Environment]::GetEnvironmentVariable('Path');
while ($systemPath.contains(';;')) {
    $systemPath = $systemPath.replace(';;', ';')
}
[Environment]::SetEnvironmentVariable('Path', $systemPath);
SETX PATH $systemPath
