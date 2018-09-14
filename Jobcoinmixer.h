#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <random>
#include <algorithm>
#include <iterator>
#include "Jobcoin.h"

class JobCoinMixer
{
public:
    JobCoinMixer();
    ~JobCoinMixer();
    void addAddresses(std::string uuid, std::shared_ptr <std::vector<std::shared_ptr<std::string>>> newAddresses);
    std::string getDepositAddress();
    void printAddresses(std::string uuid);
    void transferJobCoins(std::shared_ptr<Jobcoin> jcoin);
private:
    std::unordered_map<std::string, std::shared_ptr <std::vector<std::shared_ptr<std::string>>>> _addresses;
};

JobCoinMixer::JobCoinMixer()
{}

JobCoinMixer::~JobCoinMixer()
{
}

void JobCoinMixer::addAddresses(std::string uuid, std::shared_ptr<std::vector<std::shared_ptr<std::string>>> newAddresses)
{
    _addresses.insert(std::make_pair(uuid, newAddresses));
}

std::string JobCoinMixer::getDepositAddress()
{
    //Generate new deposit address
    // Hard coding it for presentation purposes.
    return "1EHNa6Q4Jz2uvNExL497mE43ikXhwF6kZm";
}

void JobCoinMixer::printAddresses(std::string uuid)
{
    auto adrs = _addresses.find(uuid);
    if (adrs != _addresses.end())
    {
        for (auto & singleAddress : *(adrs->second))
            std::cout << *singleAddress << std::endl;
    }
}

void JobCoinMixer::transferJobCoins(std::shared_ptr<Jobcoin> jcoin)
{
    //The mixer will detect your transfer by watching or polling the P2P Bitcoin network;
    //The mixer will transfer your bitcoin from the deposit address into a big “house account” along with all the other bitcoin currently being mixed; and
    //Then, over some time the mixer will use the house account to dole out your bitcoin in smaller increments to the withdrawal addresses that you provided, possibly after deducting a fee.
}