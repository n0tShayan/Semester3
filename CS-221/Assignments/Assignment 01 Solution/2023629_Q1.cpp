#include <iostream>
using namespace std;

struct UniverseCoordinate
{
    int s_number , x_position , y_position;
    bool is_snake;
};

void print(UniverseCoordinate grid[4][5]){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if(grid[i][j].is_snake){
                cout<<" Snake # "<<grid[i][j].s_number<<"  ";
            }
            else{
                cout<<"Empty"<<"  ";
            }
        }
        cout<<endl;
    }
}

int main(){

    UniverseCoordinate plane[4][5];

    int snake_postition [4][5] = {
        {1,2,3,0,0},
        {4,5,0,0,0},
        {6,0,7,0,0},
        {8,0,9,0,0}
    };

    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            plane[i][j].x_position = j+1;
            plane[i][j].y_position = i+1;

            if(snake_postition[i][j] != 0){
                plane[i][j].is_snake = true;
                plane[i][j].s_number = snake_postition[i][j];
            }
            else{
                plane[i][j].is_snake = false;
                plane[i][j].s_number = 0;
            }
        }
    }

    print(plane);

    return 0;
}