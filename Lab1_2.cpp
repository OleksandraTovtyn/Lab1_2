#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double a, b, c;  
    double A, B, C;  

public:
    
    Triangle() {}

    
    void input() {
        cout << "Введiть сторону a: ";
        cin >> a;

        cout << "Введiть сторону b: ";
        cin >> b;

        cout << "Введiть сторону c: ";
        cin >> c;

        //Перевірка допустимості значень сторін
        if (!isValidSides()) {
            cerr << "Недопустимi значення сторiн трикутника!" << endl;
            exit(EXIT_FAILURE);
        }

        //Обчислення кутів
        calculateAngles();
    }

    //Перевірка допустимості значень сторін
    bool isValidSides() {
        return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
    }

    //Обчислення кутів трикутника
    void calculateAngles() {
        A = acos((b * b + c * c - a * a) / (2 * b * c));
        B = acos((a * a + c * c - b * b) / (2 * a * c));
        C = acos((a * a + b * b - c * c) / (2 * a * b));

        //Переведення радіан в градуси
        A = A * 180.0 / (atan(1.0) * 4.0);
        B = B * 180.0 / (atan(1.0) * 4.0);
        C = C * 180.0 / (atan(1.0) * 4.0);
    }

    //Обчислення площі трикутника за формулою Герона
    double getArea() {
        double s = getPerimeter() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }


    //Периметр
    double getPerimeter() {
        return a + b + c;
    }

    //Вирахувати висоти трикутника
    double getHeightA() {
        return (2 * getArea()) / a;
    }

    double getHeightB() {
        return (2 * getArea()) / b;
    }

    double getHeightC() {
        return (2 * getArea()) / c;
    }

    //Визначення типу трикутника
    void determineTriangleType() {
        if (a == b && b == c) {
            cout << "Трикутник рiвносторонній." << endl;
        }
        else if (a == b || b == c || a == c) {
            cout << "Трикутник рiвнобедрений." << endl;
        }
        else {
            cout << "Трикутник не є рiвностороннiм або рiвнобедреним." << endl;
        }

        if (A == 90 || B == 90 || C == 90) {
            cout << "Трикутник прямокутний." << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    Triangle triangle;

    triangle.input();

    cout << "Периметр: " << triangle.getPerimeter() << endl;
    cout << "Площа: " << triangle.getArea() << endl;
    cout << "Висота до сторони a: " << triangle.getHeightA() << endl;
    cout << "Висота до сторони b: " << triangle.getHeightB() << endl;
    cout << "Висота до сторони c: " << triangle.getHeightC() << endl;

    triangle.determineTriangleType();

    return 0;
}
