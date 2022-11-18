var source = Path.Join(Directory.GetCurrentDirectory(), "/input");
var destination = Path.Join(Directory.GetCurrentDirectory(), "/output");

Directory.CreateDirectory(source);
if (Directory.Exists(destination))
{
    Directory.Delete(destination, true);
}
Directory.CreateDirectory(destination);

CopyFilesRecursively(source, destination);

var files = Directory.GetFiles(destination, "*.c", SearchOption.AllDirectories);

foreach (var file in files)
{
    MakeFileUnique(file);
}

Console.WriteLine("Done. Randomised {0} files", files.Length);
Console.ReadKey();


void MakeFileUnique(string path)
{
    var fileLines = File.ReadAllLines(path).ToList();
    
    // append comment to every line

    var randomisedLines = fileLines.Select(l =>
    {
        if (l.Contains("/")) return l;
        return l + "//" + RandomString(20);
    });
    
    File.Delete(path);
    File.WriteAllLines(path, randomisedLines);
    
    Console.WriteLine(Path.GetFileName(path) + ": Randomised");
}

static string RandomString(int length)
{
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return new string(Enumerable.Repeat(chars, length)
        .Select(s => s[Random.Shared.Next(s.Length)]).ToArray());
}

static void CopyFilesRecursively(string sourcePath, string targetPath)
{
    //Now Create all of the directories
    foreach (string dirPath in Directory.GetDirectories(sourcePath, "*", SearchOption.AllDirectories))
    {
        Directory.CreateDirectory(dirPath.Replace(sourcePath, targetPath));
    }

    //Copy all the files & Replaces any files with the same name
    foreach (string newPath in Directory.GetFiles(sourcePath, "*.*",SearchOption.AllDirectories))
    {
        File.Copy(newPath, newPath.Replace(sourcePath, targetPath), true);
    }
}