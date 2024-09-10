# Muda o diretório para o diretório do projeto
Set-Location "C:\Users\marco\Documents\Projeto - POO\TopGear"

# Compila o projeto usando o comando g++
g++ -o game.exe src/ASCII_Engine/Core/*.cpp src/ASCII_Engine/utils/*.cpp src/ASCII_Engine/*.cpp src/Objetos/*.cpp src/Fases/*.cpp src/main.cpp -lsfml-audio

# Exibe uma mensagem de conclusão
Write-Host "Compilation completed. The output is game.exe."
