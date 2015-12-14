#include <stdio.h>

int posimax, posimin;


void print_grade(char b[9])
{
    printf("%c|%c|%c\n",b[0],b[1],b[2]);
  
    printf("%c|%c|%c\n",b[3],b[4],b[5]);
    
    printf("%c|%c|%c\n",b[6],b[7],b[8]);
}

int checaVitoria(char grade[])
{
    if ((grade[0] == 'X' && grade[1] == 'X' && grade[2] == 'X') ||
        (grade[3] == 'X' && grade[4] == 'X' && grade[5] == 'X') ||
        (grade[6] == 'X' && grade[7] == 'X' && grade[8] == 'X') ||
        (grade[0] == 'X' && grade[3] == 'X' && grade[6] == 'X') ||
        (grade[1] == 'X' && grade[4] == 'X' && grade[7] == 'X') ||
        (grade[2] == 'X' && grade[5] == 'X' && grade[8] == 'X') ||
        (grade[0] == 'X' && grade[4] == 'X' && grade[8] == 'X') ||
        (grade[2] == 'X' && grade[4] == 'X' && grade[6] == 'X'))
    {
        return 1;
    }
    else if((grade[0] == 'O' && grade[1] == 'O' && grade[2] == 'O') ||
            (grade[3] == 'O' && grade[4] == 'O' && grade[5] == 'O') ||
            (grade[6] == 'O' && grade[7] == 'O' && grade[8] == 'O') ||
            (grade[0] == 'O' && grade[3] == 'O' && grade[6] == 'O') ||
            (grade[1] == 'O' && grade[4] == 'O' && grade[7] == 'O') ||
            (grade[2] == 'O' && grade[5] == 'O' && grade[8] == 'O') ||
            (grade[0] == 'O' && grade[4] == 'O' && grade[8] == 'O') ||
            (grade[2] == 'O' && grade[4] == 'O' && grade[6] == 'O'))
    {
        return -1;
    }
    else return 0;
}

int checaEmpate(char grade[])
{
    if ((checaVitoria(grade) == 0) && (grade[0] != ' ') && (grade[1] != ' ') &&
        (grade[2] != ' ') && (grade[3] != ' ') && (grade[4] != ' ') &&
        (grade[5] != ' ') && (grade[6] != ' ') && (grade[7] != ' ') &&
        (grade[8] != ' '))
    {
        return 1;
    }
    else return 0;
}

int minimax(int player, char grade[], int n)
{
    int i, res, j;
    
    int max = -999;
    int min = 999;
    
    int final = checaVitoria(grade);
    if (final == 1)
        return 1;
    else if (final == (-1))
        return -1;
    else if (final = checaEmpate(grade))
        return 0;
    
    for (i = 0; i < 9; i++)
    {
        if(grade[i] == ' ')
        {
            if(player == 2)
            {
                grade[i] = 'O';
                res = minimax(1, grade, n + 1);
                
                grade[i] = ' ';
                if(res < min)
                {
                    min = res;
                    if (n == 0)
                        posimin = i;
                }
            }
            else if (player == 1)
            {
                grade[i] = 'X';
                res = minimax(2, grade, n + 1);
                grade[i] = ' ';
                if (res > max)
                {
                    max = res;
                    if (n == 0)
                        posimax = i;
                }
            }
        }
    }
    
    if (player == 1)
        return max;
    else return min;
}
 


int main()
{
    int i, posicao, final,jogada;
    char grade[9];
    
    for(i = 0; i < 9; i++)
        grade[i] = ' ';
    
    printf("Jogo da Velha:\n");
    print_grade(grade);
    
    for(i = 0; i < 9; i++)
    {
        final = checaVitoria(grade);
        if (final == 1)
        {
            printf("O jogador X ganhou!\n");
            break;
        }
        else if (final == -1)
        {
            printf("O jogador O ganhou!\n");
            break;
        }


        if (i % 2 == 0){            
            printf("Jogada do jogador X:\n");
            scanf("%d", &posicao);
            grade[posicao] = 'X';
            
        }     
        
        
        
        
        if ((final == 0) && (i != 8))
        {
            posimax = -1;
            posimin = -1;
            if(i % 2 == 0)
            {
                jogada = minimax(1, grade, 0);
                //printf("A melhor jogada para o jogador X e: %d\n", posimax);
            }
            else
            {
                jogada = minimax(2, grade, 0);
                grade[posimin] = 'O';
                print_grade(grade);
                
            }
        }
        else{
            printf("Deu velha!\n");
            print_grade(grade);
        }

    }
    return 0;
}

