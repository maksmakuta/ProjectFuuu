#include <QtCore>

int main(){
    QTextStream cout (stdout);
    QTextStream cin  (stdin );
    QString num;
    cin >> num;
    QChar c;

    c = num[0];
    num[0] = num[2];
    num[2] = c;
    cout << num << "\n";
}
