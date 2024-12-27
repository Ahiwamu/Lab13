#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]){
    double summean = 0.0, mean;
    double sumsd = 0.0, sd;
    double multi = 1.0, geo;
    double harmo = 0.0, hm;
    double maxx = -9999999;
    double minn = 9999999;
    for(int i=0; i<n; i++){
        summean += a[i];
        sumsd += a[i]*a[i];
        multi *= a[i];
        harmo += 1.0/a[i];
        if(maxx < a[i]) maxx = a[i];
        if(minn > a[i]) minn = a[i];
    }
    mean = summean / n;
    sd = sqrt((sumsd/n-mean*mean) );
    geo = pow(multi, 1.0 / n);
    hm = n / harmo;

    b[0] = mean;
    b[1] = sd;
    b[2] = geo;
    b[3] = hm;
    b[4] = maxx;
    b[5] = minn; 
}
