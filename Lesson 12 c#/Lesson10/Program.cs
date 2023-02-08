using Lesson10;

Console.WriteLine("Enter string");

var str = Console.ReadLine();
MyClass mycls = new MyClass(str);
Function funcDell = new Function(mycls.Space);
funcDell += mycls.Reverse;

Run run = new Run();
run.runFunc(funcDell, str);