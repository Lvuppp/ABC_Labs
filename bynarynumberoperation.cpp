#include "bynarynumberoperation.h"

BinaryNumbersOperation::BinaryNumbersOperation()
{

}

int BinaryNumbersOperation::SummaryOfTwoBinaryNumbers(int firstNumber,int secondNumber)
{
    std::bitset<byteFieldSize>firstBinaryNumber = (firstNumber);
    std::bitset<byteFieldSize>secondBinaryNumber = (secondNumber);

    bool isNumbersHadDifferentSign = firstBinaryNumber [byteFieldSize] - secondBinaryNumber[byteFieldSize];

    auto answerNumber = sumOfTwoBinary(firstBinaryNumber,secondBinaryNumber);

    qDebug() << QString::fromStdString(firstBinaryNumber.to_string()) + " + " + QString::fromStdString(secondBinaryNumber.to_string()) + " = "
                + QString::fromStdString(answerNumber.to_string());

//    if(answerNumber.length() >firstBinaryString.length() ||
//            (!isNumbersHadDifferentSign && firstBinaryString.begin()->digitValue() != answerNumber.begin()->digitValue())){
//    //    emit sendAnswerOfTwoBinaryNumbers(answerNumber, true);
//    }

    //emit sendAnswerOfTwoBinaryNumbers(answerNumber, false);
    if(answerNumber[byteFieldSize] == 1){
        return -1 * (sumOfTwoBinary(answerNumber.flip(),std::bitset<byteFieldSize>(1)).to_ulong());
    }

    return answerNumber.to_ulong();
}

int BinaryNumbersOperation::SubstractionOfTwoBinaryNumbers(int firstNumber,int secondNumber)
{
    std::bitset<byteFieldSize>firstBinaryNumber((firstNumber));
    std::bitset<byteFieldSize>secondBinaryNumber((secondNumber));
    qDebug() << QString::fromStdString(secondBinaryNumber.to_string());
    secondBinaryNumber = convertToNegative (secondBinaryNumber);
    auto answerNumber = sumOfTwoBinary(firstBinaryNumber,secondBinaryNumber);

    qDebug() << QString::fromStdString(firstBinaryNumber.to_string()) + " - " + QString::fromStdString(secondBinaryNumber.to_string()) + " = "
                + QString::fromStdString(answerNumber.to_string());


    if(answerNumber[byteFieldSize] == 1){
        return -1 * (sumOfTwoBinary(answerNumber.flip(),std::bitset<byteFieldSize>(1)).to_ulong());
    }

    return answerNumber.to_ulong();

}

QString BinaryNumbersOperation::MultiplicationOfTwoBinaryNumbers(int firstNumber, int secondNumber)
{


    return QString();
}


std::bitset<byteFieldSize> BinaryNumbersOperation::convertToNegative(std::bitset<byteFieldSize> number){
    number.flip();
    return sumOfTwoBinary(number ,std::bitset<byteFieldSize>(1));
}

std::bitset<byteFieldSize> BinaryNumbersOperation::sumOfTwoBinary(std::bitset<byteFieldSize> firstBinaryNumber, std::bitset<byteFieldSize> secondBinaryNumber)
{
    std::bitset<byteFieldSize> answerNumber;
    quint8 digitOverflow = 0;

    for (qsizetype i = 0; i < byteFieldSize; i++) {
        int operationAnswer = firstBinaryNumber [i] + secondBinaryNumber [i] + digitOverflow;
        digitOverflow = 0;

        if(operationAnswer > 1){
            digitOverflow = 1;
            operationAnswer -= 2;
        }

        answerNumber[i] = operationAnswer;
    }

    return answerNumber;
}

//std::bitset<byteFieldSize> BinaryNumbersOperation::(int number)
//{
//    if(number > 0)
//        return std::bitset<byteFieldSize>(number);

//    return sumOfTwoBinary(std::bitset<byteFieldSize>(number ^ MAX), std::bitset<byteFieldSize>(1));
//}
