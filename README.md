# Battleship Game

## Description

This is a text-based implementation of the classic game **Battleship**. The game is played on a 5x5 grid where both the player and the computer randomly place ships. The objective of the game is to sink all of the opponents ships by guessing their coordinates. In this version the computer places its ships randomly, and the player guesses where the ships are located. Each turn, the player inputs coordinates (row and column), and the program will indicate whether the guess is a **HIT!** or **MISS!**. The game continues until all of the computer's ships are sunk, and the number of attempts is shown at the end.

## Features

- A 5x5 grid representing the battlefield.
- 3 randomly placed ships for the computer.
- Player can guess the coordinates to try and hit the ships.
- Each guess results in a hit or miss, and the grid is updated accordingly.
- Game continues until all ships are sunk.

## Game Rules

1. The player has 3 attempts to sink the computer's ships.
2. The computer randomly places ships on the grid.
3. The player guesses the row and column (both between 0 and 4).
4. The game ends when all ships are sunk or the player runs out of attempts.

## How to Play

1. When you start the game, you will be prompted to guess the row and column of the computer's ships.
2. Input your guess as two integers representing the row and column. For example, "2 3" for row 2 and column 3.
3. The game will tell you if your guess was a **hit** (you sunk a ship) or a **miss**.
4. Continue guessing until you have sunk all the computer's ships.
