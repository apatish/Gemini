#pragma once
#include <string>

struct Jobcoin
{
    int Size;
    int Weight;
    std::string Received_Time;
    int Lock_Time_Block;
    int Included_In_Blocks;
    int Confirmations;
    double Total_Input;
    double Total_Output;
    double Fees;
};