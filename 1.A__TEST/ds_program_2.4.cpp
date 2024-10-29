#include <string.h>
#include <stdio.h>
#include <iostream>

class Car
{
    protected:
        int speed;
        char name[40];

public:
    int gear;
    Car(){ }
    ~Car(){ }

    Car(int s, int g, char* n)
    : speed(s), gear(g)
    {
        strcpy(name, n);
    }
    void changeGear(int g=4)
    {
        gear = g;
    }
    void speedUp()
    {
        speed += 5;
    }
    void display()
    {
        printf("[%s] : 기어 %d단, 속도 = %dkmph\n", name, gear, speed);
    }
    void whereAmI() { printf("객체 주소 = %x\n", this); }
    int Compare( Car & b)
    {
        return speed - b.speed;
    }
};

class SportsCar : public Car
{
    public :
    bool bTurbo = 0;
    
    SportsCar(int s, int g, char* n) : Car(s, g, n)
    {
    }
    void setTurbo(bool bTur)
     {
        bTurbo = bTur;
        }
    void speedUp()
    {
        if( bTurbo) 
            speed += 20;
        else Car::speedUp();
    }
};

int main (void)
{
    using namespace std;

    SportsCar myCar(20, 5, "Porsche 911");
    myCar.changeGear(10);
    myCar.speedUp();
    myCar.setTurbo(1);
    myCar.speedUp();
    myCar.speedUp();
    myCar.display();
    myCar.whereAmI();
    
    Car yourCar(65, 5, "Sonata");
    if( yourCar.Compare(myCar) == 0)
    {
        printf("속도가 같음");
    }
    else if (yourCar.Compare(myCar) > 1)
    {
        printf("당신의 차가 더 빠름");
    }
    else if (yourCar.Compare(myCar) < 1)
    {
        printf("내 차가 더 빠름");
    }
    return 0;
}