
#include <math.h>
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x1, x2, y1, y2, r1, r2;
	cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;
	double l = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double a = (((pow(r1, 2) - pow(r2, 2) + pow(l, 2))) / (2 * l));
	double h = sqrt(pow(r1, 2) - pow(a, 2));
	double x3 = x1 + (a / l) * (x2 - x1);
	double y3 = y1 + (a / l) * (y2 - y1);
	if ((l > (r1 + r2)) || ((l == 0) && (r1 != r2 )) || (((l < r1) || (l < r2)) && ((r1 > (r2 + l)) || (r2 > (r1 + l))) || (l > (r1 + r2)))) {
		cout << "они не пересекаются, 0 точек пересеечения" << endl;

}
 else if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
 cout << "окружности совпадают , беcконечное множество точек пересечения" << endl;
 }
 else if ((r1 < (r2 + l)) && (r2 < (r1 + l)) && (l < (r1 + r2))) {
 double x4 = x3 + (h / l) * (y2 - y1);
 double y4 = y3 - (h / l) * (x2 - x1);
 double x5 = x3 - (h / l) * (y2 - y1);
 double y5 = y3 + (h / l) * (x2 - x1);
 cout << "Две точки персечения" << endl;
 cout << "X1= " << x4 << "Y1= " << y4 << "X2= " << x5 << "Y2= " << y5 << endl;
 }
 else if ((r1 + r2) == l) {
 double x4 = x3 + (h / l) * (y2 - y1);
 double y4 = y3 - (h / l) * (x2 - x1);
 cout << "Одна точка персечения" << " X= " << x4 << " " << " Y= " << y4 << endl;
 }

 else if (((r1 == l + r2) || (r2 == r1 + l)) && ((l < r1) || (l < r2))) {
 double x4 = x3 + (h / l) * (y2 - y1);
 double y4 = y3 - (h / l) * (x2 - x1);
 cout << " Одна окружность внутри другой , 1 точка пересечения " << " X= " << x4 << " Y= " << y4 << endl;
 }



 //double x4 = x3 + (h / l) * (y2 - y1);
 //double y4 = y3 - (h / l) * (x2 - x1);
 //double x5 = x3 - (h / l) * (y2 - y1);
 //double y5 = y3 + (h / l) * (x2 - x1);



 return 0;





}

