#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <memory>
#include "Jobcoinmixer.h"

extern JobCoinMixer jcm;

//Using template for future expansion(if different validation needed
template<typename CoinAddressValiator>
class Menu
{
public:
    Menu();
    ~Menu();
    void run(CoinAddressValiator cav);
    std::string getCustomerID()
    {
        std::srand(std::time(nullptr));
        return std::to_string(rand());
    }
private:

};

template<typename CoinAddressValiator>
Menu<CoinAddressValiator>::Menu()
{}

template<typename CoinAddressValiator>
Menu<CoinAddressValiator>::~Menu()
{}

template<typename CoinAddressValiator>
void Menu<CoinAddressValiator>::run(CoinAddressValiator cav)
{
    std::cout << "Welcome to the Jobcoin mixer!\n" << std::endl;
    while (true)
    {
        std::cout << "Please enter a comma-separated list of new, unused Jobcoin ";
        std::cout << "addresses where your mixed Jobcoins will be sent." << std::endl;
        auto inputPtr = std::make_shared<std::string>("");

        std::getline(std::cin, *inputPtr);
        if (*inputPtr == "" || *inputPtr == "quit" || *inputPtr == "exit")
        {
            break;
        }

        std::vector<std::shared_ptr<std::string>> * dAddrPtr = new std::vector<std::shared_ptr<std::string>>();
        std::shared_ptr<std::vector<std::shared_ptr<std::string>>> deposit_address = std::make_shared<std::vector<std::shared_ptr<std::string>>>(*dAddrPtr);
        std::stringstream line(*inputPtr);
        std::string each;
        while (std::getline(line, each, ','))
        {
            each.erase(remove_if(each.begin(), each.end(), isspace), each.end());
            if (cav.validate(each))
            { 
                std::string * singleAddrs = new std::string(each);
                std::shared_ptr<std::string> addrsPtr = std::make_shared<std::string>(*singleAddrs);
                deposit_address->push_back(addrsPtr);
            }
        }
        jcm.addAddresses(getCustomerID(), std::move(deposit_address));
        std::cout << "\nYou may now send Jobcoins to address " << jcm.getDepositAddress() << std::endl;
        std::cout << "They will be mixed and sent to your destination addresses:" << std::endl;
        jcm.printAddresses(getCustomerID());
        // Hardcoding Jobcoin
        std::shared_ptr<Jobcoin> jcoin = std::make_shared<Jobcoin>(*(new Jobcoin));
        jcoin->Size = 225;
        jcoin->Weight = 900;
        jcoin->Received_Time = "2016 - 06 - 17 16:35 : 14";
        jcoin->Lock_Time_Block = 416720;
        jcoin->Included_In_Blocks = 416731;
        jcoin->Confirmations = 124567;
        jcoin->Total_Input = 2.90466;
        jcoin->Total_Output = 2.90366;
        jcoin->Fees = 0.001;

        jcm.transferJobCoins(jcoin);
    }
}