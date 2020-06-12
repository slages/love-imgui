import "io" for File

var file = File.open("test/io/file/file.txt")
System.print(file.size) // expect: 19
file.close()
