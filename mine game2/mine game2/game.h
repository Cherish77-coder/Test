#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROW 16
#define COL 16
#define ROWS (ROW+2)
#define COLS (COL+2)
#define easy_count 40
void Initboard(char board[ROWS][COLS], int rows, int cols, char ret);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int x, int y);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void FlagMine( char show[ROW][COL], int row, int col);