#ifndef BYNARYNUMBEROPERATION_H
#define BYNARYNUMBEROPERATION_H
#define byteFieldSize 32
#define MAX INT_MAX

#include<math.h>
#include<bitset>
#include <QObject>
#include <QDebug>

class BinaryNumbersOperation : public QObject
{
    Q_OBJECT

public:
    BinaryNumbersOperation();

    int SummaryOfTwoBinaryNumbers( int,  int);
    int SubstractionOfTwoBinaryNumbers( int,  int);
    QString MultiplicationOfTwoBinaryNumbers( int,  int);
    QString DivideOfTwoBinaryNumbers( int,  int);

signals:
    void sendAnswerOfTwoBinaryNumbers(QString,bool);

private:
    std::bitset<byteFieldSize> convertToAdditionalNumber(int);
    std::bitset<byteFieldSize> convertToNegative(std::bitset<byteFieldSize>);
    std::bitset<byteFieldSize> sumOfTwoBinary(std::bitset<byteFieldSize>,std::bitset<byteFieldSize>);
};

#endif // BYNARYNUMBEROPERATION_H
