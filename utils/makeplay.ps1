# Muda o diretório para o diretório do projeto
Set-Location "C:\Users\marco\Documents\Projeto - POO\TopGear"

# Compila o projeto usando o comando g++
g++ -o game.exe src/ASCII_Engine/Core/*.cpp src/ASCII_Engine/utils/*.cpp src/ASCII_Engine/*.cpp src/Objetos/*.cpp src/Game/*.cpp src/Fases/*.cpp src/main.cpp -lsfml-audio

# Verifica se a compilação foi bem-sucedida
if ($LASTEXITCODE -ne 0) {
    Write-Host "A compilacao falhou."
    exit
}

# Exibe uma mensagem de conclusão
Write-Host "Compilacao completa. Iniciando o TopGear - ASCII..."

# Abre o terminal Ubuntu e executa game.exe
Start-Process "ubuntu.exe" -ArgumentList "run", "cd '/mnt/c/Users/marco/Documents/Projeto - POO/TopGear' && ./game.exe"

# Executa o script AutoHotKey para ajustar o zoom
Start-Process "utils/adjust_zoom.ahk"