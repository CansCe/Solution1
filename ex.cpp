#include"ex12.cpp"
#include"ex13.cpp"


int main(){
    Ship* ships[2];
    ships[0] = new CruiseShip("Cruise Ship", "2019", 100);
    ships[1] = new CargoShip("Cargo Ship", "2018", 200);
    for(int i = 0; i < 2; i++){
        ships[i]->display();
        cout << endl;
    }
    BasicShape *shapes[2];
    shapes[0] = new Circle(10);
    shapes[1] = new Rectangle(10, 20);
    for(int i = 0; i < 2; i++){
        shapes[i]->calcArea();
        cout << endl;
    }
    return 0;
}
