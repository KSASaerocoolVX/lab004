#include<iostream>
#include <windows.h>

using namespace std;

float dayAverage(float * row, int h) {
    float sum = 0;
    for (int i = 0; i < h; i++) {
        sum+=*(row+i);
    }
    return sum/h;
}

float overallAverage(float**p, int d,int h) {
    float sum = 0;
    for (int i = 0; i < d; i++) {
        float currsum=0;
        float *currentRow=*(p+i);
        for (int j = 0; j < h; j++) {
            currsum+=*currentRow;
            currentRow++;
        }
        currsum/=h;
        sum+=currsum;
    }
    return sum/d;
}


void showHotDays(float ** p, int d, int h) {
    float average=overallAverage(p,d,h);
    cout << "Теплые дни: ";
    for (int i = 0; i < d; i++) {
        float *currentRow=*(p+i);
        float currenttemperature=dayAverage(currentRow,h);
        if (currenttemperature>average) {
            cout<<"День "<<i+1<<" " << "(среднее = "<< currenttemperature << ")" << endl;
        }

    }
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int d,h;
    cout << "Введите количество дней: ";
    cin>>d;
    cout << endl;
    cout << "Введите количество измерений в дне: ";
    cin >> h;
    cout << endl;
    float ** data = new float *[d];
    for (int i = 0; i < d; i++) {
        *(data+i) = new float[h];
        float *currentRow=*(data+i);
        cout << "День "<< i+1 << ":";
        for (int j = 0; j < h; j++) {
            float currt;
            cin >> currt;
            *(currentRow+j) = currt;
        }
        cout << endl;
    }
    cout <<"Общая средняя температура: " << overallAverage(data,d,h) << endl;
    showHotDays(data,d,h);
    for (int i = 0; i < d; i++) {
        delete[] *(data+i);
    }
    delete[] data;
    return 0;
}
