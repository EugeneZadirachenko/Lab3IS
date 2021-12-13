#include <iostream>

using namespace std;

class neuron         //класс, обозначающий наш нейрон
{
    double w = rand() % 2; //значение веса

public:

    double ProccesInputdata(double input)     //метод, отвечающий за вывод значения, просчитанного нейроном == вход*вес
    {
        return (input * w);
    }
    double  RestoreInputData(double output) //обратный метод вывода, для получения из выхода значение входа
    {
        return (output / w);
    }
    void Train(double input, double expected)                //метод тренировки нейрона
    {
        double actresult = input * w;                       //результат, полученный нерйоном на данный момент
        LastError = expected - actresult;                  //величина ошибки на данный момент
        double correct = (LastError / actresult) * speed; //величина требуемой корректировки на данный момент
        w += correct;                                    //изменение веса на величину корректировки
    }

    double LastError;
    double speed = 0.000001; //скорость обучения нейрона. Чем ниже - тем качественнее, но медленнее.
};

int main()
{
    double USD[5] = { 1,7,12,15,28 };                   //"учитель", обозначающий 
    double EU[5] = { 0.82, 5.79, 9.91, 12.38, 23.11 };    //настоящее значение
    neuron n;            //создание объекта "нейрон"
    int r = rand() % 5;
    int i = 0;
    while (n.LastError > n.speed || n.LastError < -n.speed) //цикл обучения
    {
        i++;
        n.Train(USD[r], EU[r]);
        if (i % 1000000 == 0)        //вывод информации об обучении: попытка и значение ошибки
        {
            cout << "error's number: " << i << " Error: " << n.LastError << endl;
        }
    }

    cout << "100 dollar equals " << n.ProccesInputdata(100) << " euro" << endl;       //результаты  
    cout << "10 euro equals " << n.RestoreInputData(10) << " dollars" << endl;
    cout << "40 dollars equals " << n.ProccesInputdata(40) << " euro" << endl;
    cout << "50 euro equals " << n.RestoreInputData(50) << " dollars" << endl;
    cout << "3 dollars equals " << n.ProccesInputdata(3) << " euro" << endl;
    cout << "356 euro equals " << n.RestoreInputData(356) << " dollars" << endl;
}

