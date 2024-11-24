#include <stdio.h>
int length=0;

void printSudoku(int A[9][9]) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (i == 3 || i == 6) 
            printf("---------------------------------------------------\n");
        for (int j = 0; j < 9; j++) 
        {
            printf("%4d ", A[i][j]);
            if (j == 2 || j == 5) 
                printf(" |");
        }
        printf("\n");
    }
}
void solvedSudoku(int AS[9][9]) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (i == 3 || i == 6) 
            printf("---------------------------------------------------\n");
        for (int j = 0; j < 9; j++) 
        {
            printf("%4d ", AS[i][j]);
            if (j == 2 || j == 5) 
                printf(" |");
        }
        printf("\n");
    }
}

int sudoku(int A[9][9]) 
{
    int a, b, n;
    
    for (int i = 0;i<length; i++) 
    {
        printf("\tENTER THE NUMBER OF ROW(1-9): ");
        scanf("%d", &a);
        printf("\tENTER THE NUMBER OF COLUMN(1-9): ");
        scanf("%d", &b);

        a--; 
        b--;

        if (a >= 0 && a < 9 && b >= 0 && b < 9) 
        {
            if (A[a][b] == 0) 
            {   
                int valid;
                do
                {
                    valid = 1;
                    printf("ENTER THE NUMBER (1-9): ");
                    scanf("%d", &n);

                    
                    if (n < 1 || n > 9) 
                    {
                        printf("INVALID NUMBER! PLEASE ENTER BETWEEN 1 TO 9.\n");
                        valid = 0;
                        continue;
                    }

                    
                    for (int j = 0; j < 9; j++) 
                    {
                        if (A[a][j] == n) 
                        {
                            printf("THIS NUMBER IS ALREADY IN ROW.\n");
                            valid = 0;
                            break;
                        }
                    }

                    for (int j = 0; j < 9; j++) 
                    {
                        if (A[j][b] == n) 
                        {
                            printf("THIS NUMBER IS ALREADY IN COLUMN.\n");
                            valid = 0;
                            break;
                        }
                    }

                    int Row = a - (a % 3);
                    int Col = b - (b % 3);
                    for (int j = 0; j < 3 && valid; j++) 
                    {
                        for (int k = 0; k < 3; k++) 
                        {
                            if (A[Row + j][Col + k] == n) 
                            {
                                printf("THIS NUMBER IS ALREADY IN 3*3 BOX.\n");
                                valid = 0;
                                break;
                            }
                        }
                    }

                    if (valid) 
                    {
                        A[a][b] = n;
                        printf("NUMBER PLACED SUCCESSFULLY!\n");
                        printSudoku(A);
                    }

                } while (!valid);
            } 
            else 
            {
                printf("THIS PLACE IS ALREADY FILLED WITH %d\n", A[a][b]);
            }
        } 
        else 
        {
            printf("ENTER THE NUMBER BETWEEN 1 TO 9\n");
        }
    }

    return 0;
}

int main() 
{
    int choice;
    int x;
    printf("1. ENTER 1 TO SOLVE EASY\n");
    printf("2. ENTER 2 TO SOLVE MEDIUM\n");
    printf("3. ENTER 3 TO SOLVE HARD\n");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1: 
        {
            int A[9][9] =  {                                                
                                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                {0, 0, 0, 0, 8, 0, 0, 7, 9}
                            };
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(A[i][j]==0)
                    {
                        length++;
                    }

                }
            }
            int AS[9][9]=   {
                                {5, 3, 4, 6, 7, 8, 9, 1, 2},
                                {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                {3, 4, 5, 2, 8, 6, 1, 7, 9}
                            };                
            printSudoku(A);
            sudoku(A);
            
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    
                    x=(A[i][j]!=0)?1:0;
                }
            }
            if(x)
            {
            
            solvedSudoku(AS);
            }
            break;
        }
        case 2: 
        {
            int B[9][9] =  {                                                
                                {0, 0, 9, 0, 0, 0, 0, 0, 0},
                                {7, 0, 0, 0, 2, 0, 0, 0, 0},
                                {0, 1, 0, 3, 0, 0, 0, 6, 5},
                                {0, 0, 0, 0, 0, 4, 1, 0, 0},
                                {0, 0, 0, 0, 6, 0, 0, 0, 0},
                                {0, 0, 3, 0, 0, 0, 0, 4, 0},
                                {1, 4, 0, 0, 0, 7, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 3, 9},
                                {0, 0, 0, 0, 0, 0, 6, 0, 0}
                            };
                            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(B[i][j]==0)
                    {
                        length++;
                    }

                }
            }
            int BS[9][9]=   { 
                                {5, 3, 9, 8, 4, 2, 7, 1, 6},
                                {7, 6, 8, 9, 2, 1, 3, 5, 4},
                                {4, 1, 2, 3, 7, 9, 8, 6, 5},
                                {8, 9, 6, 7, 3, 4, 1, 2, 5},
                                {9, 2, 1, 5, 6, 8, 4, 7, 3},
                                {3, 7, 5, 1, 9, 6, 2, 4, 8},
                                {1, 4, 7, 2, 8, 3, 9, 5, 6},
                                {6, 5, 4, 6, 1, 7, 2, 3, 9},
                                {2, 8, 3, 4, 5, 9, 6, 1, 7}
                            };
            printSudoku(B);
            sudoku(B);
            
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    
                    x=(B[i][j]!=0)?1:0;
                }
            }
            if(x)
            {
                     
                solvedSudoku(BS);

            }
        }
        break;

        case 3: 
        {
            int C[9][9] =  {    
                                {0, 0, 0, 0, 9, 0, 0, 0, 0},
                                {0, 0, 0, 7, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 4, 0},
                                {0, 6, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 8, 0, 0, 0, 0, 2, 0},
                                {0, 0, 0, 0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 6, 0, 0},
                                {0, 0, 0, 0, 0, 3, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 5}
                            };
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(C[i][j]==0)
                    {
                        length++;
                    }

                }
            }
            int CS[9][9] ={
                                {5, 3, 4, 6, 9, 7, 1, 8, 2},
                                {8, 2, 1, 7, 5, 4, 3, 9, 6},
                                {9, 7, 6, 8, 3, 2, 5, 4, 1},
                                {4, 6, 2, 9, 8, 5, 7, 1, 3},
                                {1, 5, 8, 3, 7, 6, 9, 2, 4},
                                {3, 9, 7, 4, 1, 2, 8, 6, 5},
                                {7, 8, 9, 1, 2, 4, 6, 3, 8},
                                {6, 1, 5, 2, 4, 3, 7, 9, 8},
                                {2, 4, 3, 5, 6, 8, 1, 7, 9}
                            };              
            printSudoku(C);
            sudoku(C);
            
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    
                    x=(C[i][j]!=0)?1:0;
            
                    solvedSudoku(CS);
                }
            }
            break;

        }
        default:
            printf("INVALID CHOICE!\n");
            printf("PLEASE ENTER VALID CHOICE");
            break;
    }
    return 0;
}