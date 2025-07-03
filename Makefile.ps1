rm main.exe

g++ `
(Get-ChildItem -Recurse -Filter *.cpp | ForEach-Object { $_.FullName }) `
-std=c++20 -g -O0 -Wall -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm  `
-o main.exe

./main.exe