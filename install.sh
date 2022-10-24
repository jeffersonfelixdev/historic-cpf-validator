#!/bin/bash
#INSTALAÇÃO DO GERADOR DE CPF V1.0 FOR LINUX

if [ ! -d ~/bin/ ]; then mkdir ~/bin/; fi
g++ cpf.cpp -o ~/bin/cpf -lncurses
