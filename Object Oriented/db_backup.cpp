#include <iostream>
#include <random>
using namespace std;

//Define grid size
const int gridRows = 5;
const int gridCols = 5;

//Random number initialization (static -> only once)
random_device rd;
mt19937 gen(rd());

uniform_int_distribution<int> gridPlaceDist(0, gridCols - 1); //nums form 0 to 19, works for square grids

class Organism{

    int row;
    int col;
    int breedTime;
    char marker;

    public:
    Organism(int row, int col, int breedTime, char marker): row(row), col(col), breedTime(breedTime),
    marker(marker){}
    //Setters
    void setRow(int row){ this->row = row; }
    void setCol(int col){ this->col = col; }
    void setbreedTime(int breedTime){ this->breedTime = breedTime; }
    void setMarker(char marker){ this->marker = marker; }
    //Getters
    int getRow(){ return row; }
    int getCol(){ return col; }
    int getBreedTime(){ return breedTime; }
    int getMarker(){ return marker; }

    //Other fx
    void move(Organism& o, char (&arr)[gridRows][gridCols]){
        int row = o.getRow();
        int col = o.getCol();
        cout << "Before moving: " << o.getRow() << ", " << o.getCol() << endl;

        arr[row][col] = '-'; //Make empty space where org was

        if(row - 1 >= 0 && arr[row - 1][col] == '-'){ //Move up
            o.setRow(row - 1);//Set coordinates to new space
            cout<<"Up"<<endl;
        }else if(row + 1 < gridRows && arr[row + 1][col] == '-'){ //Move down
            o.setRow(row + 1);
            cout<<"Down"<<endl;
        }else if(col - 1 >= 0 && arr[row][col - 1] == '-'){ //Move left
            o.setCol(col - 1);
            cout<<"Left"<<endl;
        }else if(col + 1 < gridCols && arr[row][col + 1] == '-'){ //Move right
            o.setCol(row + 1);
            cout<<"Right"<<endl;
        }
        
        arr[o.getRow()][o.getCol()] = o.getMarker(); //Marker for new org position 
        cout << "After moving: " << o.getRow() << ", " << o.getCol() << endl;

    }

    virtual void breed(Organism& o, char (&arr)[gridRows][gridCols], int time, vector<Organism>& organisms) {
    cout << "Breeding organism at: " << row << ", " << col << endl;
    int row = o.getRow();
    int col = o.getCol();
    int babyRow = -1;
    int babyCol = -1;
    
        if (row - 1 >= 0 && arr[row - 1][col] == '-') { // Check up
            babyRow = row - 1;
            babyCol = col;
        } else if (row + 1 < gridRows && arr[row + 1][col] == '-') { // Check down
            babyRow = row + 1;
            babyCol = col;
        } else if (col - 1 >= 0 && arr[row][col - 1] == '-') { // Check left
            babyRow = row;
            babyCol = col - 1;
        } else if (col + 1 < gridCols && arr[row][col + 1] == '-') { // Check right
            babyRow = row;
            babyCol = col + 1;
        }

        if (babyRow != -1 && babyCol != -1) { // Space available for a new baby
            Organism baby(babyRow, babyCol, o.breedTime, o.marker);
            organisms.push_back(baby);
            arr[babyRow][babyCol] = 'o'; // Marker
            cout << "Baby placed at: " << babyRow << ", " << babyCol << endl;
        }
    }
    virtual ~Organism() {} // Virtual destructor for cleanup
};

class Ant : public Organism{  
    public:
    Ant(int row, int col, int breedTime, char marker) : Organism(row, col, breedTime, marker) {}
}; 

class Doodlebug : public Organism {
    public:
    Doodlebug(int row, int col, int breedTime, char marker) : Organism(row, col, breedTime, marker) {}
};



//Creates 20 x 20 grid filled in with ' - ' 
void createGrid(char arr[][gridCols], int rows);
//Prints grid
void printGrid(char arr[][gridCols], int rows);
//Places the initial number of ants and doodlebugs in random position in the grid
void initialSpawn(int antNum, int doodleNum, char arr[][gridCols], vector <Organism>& ants, vector <Organism>& doodlebugs);



int main(){

    char grid[gridRows][gridCols];
    createGrid(grid, gridCols); 
    
    int antNum = 2;
    int doodleNum = 3;

    vector <Organism> ants;
    vector <Organism> doodlebugs;
    initialSpawn(antNum, doodleNum, grid, ants, doodlebugs); //Place initial number of ants and dbugs on grid

    int i = 0;
    while (true){
        cout << "World at time: " << i << endl;
        if(i == 0){
        printGrid(grid, gridCols);
        }else if(i > 0){
            for(auto& db : doodlebugs){ //Move each doodlebug
                db.move(db ,grid);
            }

            for(auto& ant : ants){ //Move each ant
                ant.move(ant ,grid);
            }

            if(i % doodlebugs[0].getBreedTime() == 0){
                for(auto& db : doodlebugs){ //Each doodlebug breeds
                    db.breed(db, grid, i, doodlebugs);
                }
            }
            if(i % ants[0].getBreedTime() == 0){
                for(auto& ant : ants){ //Each doodlebug breeds
                    ant.breed(ant, grid, i, ants);
                }
            }
            printGrid(grid, gridCols);

          /*   for (auto& o : organisms) { // Breed each org
                o.breed(o, grid, i, organisms);
            } */
            
        /*     for(auto& o : organisms){ //Print coordinates
            cout<<o.getRow()<<", "<<o.getCol()<<endl;
            }   */  
        }   
        cout<<"Press enter to continue"<<endl;
        cin.get();     // Waits for Enter
        i ++;
    }

    return 0;
}

void createGrid(char arr[][gridCols], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < gridCols; j++){
            arr[i][j] = '-';
        }
    }
}

void printGrid(char arr[][gridCols], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < gridCols; j++){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

void initialSpawn(int antNum, int doodleNum, char arr[][gridCols], vector <Organism>& ants, 
vector <Organism>& doodlebugs){
    
    //Ants placement
    for(int i = 0; i < antNum; i++){
        int row = gridPlaceDist(gen);
        int col = gridPlaceDist(gen);

        while(arr[row][col] != '-'){ //if the coordinates are occpied, regenerate
            row = gridPlaceDist(gen);         //new coordinates
            col = gridPlaceDist(gen);
        }
        arr[row][col] = 'o'; //Marker in grid
        Ant ant(row, col, 3, 'o'); //Create organism
        ants.push_back(ant); //Add to organism vector
    }

    //Doodlebugs placement
    for(int i = 0; i < doodleNum; i++){
        int row = gridPlaceDist(gen);
        int col = gridPlaceDist(gen);

        while(arr[row][col] != '-'){ 
            row = gridPlaceDist(gen);
            col = gridPlaceDist(gen);
        }
        arr[row][col] = 'X';
        Doodlebug db(row, col, 8, 'X');
        doodlebugs.push_back(db);
    }
}
