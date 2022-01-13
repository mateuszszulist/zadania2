#include <iostream>

struct space {
    int value;
    bool shown;
};

space board[10][10];

bool generate_board()
{
    for (int x = 0; x<10; x++)
        for (int y = 0; y<10; y++)
        {
            board[x][y].value = 0;
            board[x][y].shown = false;
        }
    return true;
}

bool generate_bomb (int position_x, int position_y)
{
    if (board[position_x][position_y].value!=9)
    {
        board[position_x][position_y].value = 9;
        
        for (int k = -1; k<2; k++)
            for (int l = -1; l<2; l++)
            {
                if ((position_x+l)<0 || (position_y+k)<0 ) continue;
                if ((position_x+l)>9 || (position_y+k)>9 ) continue;
                
                if (board[position_x+l][position_y+k].value==9) continue;
                board[position_x+l][position_y+k].value += 1;
            }
    }
    
    return true;
}

void generate_position()
{
    time_t t;
    int position_x, position_y;
    int value = 10;
    
    srand((unsigned)time(&t));
    
    while (value>0)
    {
        position_x = rand()%10;
        position_y = rand()%10;
        
        if (board[position_x][position_y].value!=9)
        {
            generate_bomb(position_x,position_y);
            value--;
        }
    }
}

void print_board()
{
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for(auto x = 0; x<10; x++)
    {
        std::cout << x;
        for(auto y = 0; y<10; y++)
        {
            std::cout << "|";
            space field = board[x][y];
            if(field.shown == true)
            {
                if(field.value == 0)
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << field.value;
                }
            }
            else
            {
                std::cout << ".";
            }           
        }        
        std::cout << "|" << std::endl;
    }
}

bool finished()
{
    int bombs = 0;
    for(auto x = 0; x<10; x++)
    {
        for(auto y = 0; y<10; y++)
        {
            if(board[x][y].shown == false)
            {
                bombs++;
            }
        }
    }
    if(bombs == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool show_board(int x, int y)
{
    if (x<0 || x>9) return true;
    if (y<0 || y>9) return true;
    if (board[x][y].shown == true) return true;

    if(board[x][y].value != 9 && board[x][y].shown == false)
    {
        board[x][y].shown = true;
    }

    if(board[x][y].value == 9)
    {
        return false;
    }

    if (board[x][y].value != 0) 
    {
        return true;
    }
    
    show_board(x-1,y-1);
    show_board(x-1,y);
    show_board(x-1,y+1);
    show_board(x+1,y-1);
    show_board(x+1,y);
    show_board(x+1,y+1);
    show_board(x,y-1);
    show_board(x,y);
    show_board(x,y+1);

    return true;
}

int main()
{
    generate_board();
    generate_position();

    int x = 0, y = 0;
    while(!finished())
    {
        print_board();
        std::cout << "Podaj współrzędne (x y): ";
        std::cin >> y >> x;
        if (show_board(x,y) == false)
        {
            std::cout << "Trafiono na minę! Przegrana." << std::endl;
            return 0;
        }
    }

    std::cout << "Gratulacje! Wygrana." << std::endl;
    return 0;
}